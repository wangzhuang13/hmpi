/**
* Copyright (C) Huawei Technologies Co., Ltd. 2020.  ALL RIGHTS RESERVED.
*/

#include "ompi/mpi/c/mpi_api_pvars.h"

/* PVARs structure */
ompi_api_pvars_t ompi_api_pvars;

int mpi_api_pvars_init(void)
{
   const char *project = "ompi";
   const char *framework = "ompi";
   const char *component = "mpi_api";
   int ret;

   /* Zero all counters */
   memset(&ompi_api_pvars, 0x00, sizeof(ompi_api_pvars));

   /* register performance variables */
   ret = mca_base_pvar_register(project, framework, component, 
                                "allreduce_same_sendbuf", "Number of times MPI_Allreduce() was called with the same sendbuf consecutively",
                                OPAL_INFO_LVL_3, MCA_BASE_PVAR_CLASS_SIZE,
                                MCA_BASE_VAR_TYPE_UNSIGNED_LONG, NULL, MCA_BASE_VAR_BIND_NO_OBJECT,
                                MCA_BASE_PVAR_FLAG_READONLY | MCA_BASE_PVAR_FLAG_CONTINUOUS,
                                NULL, NULL, NULL, (void *)&ompi_api_pvars.allreduce_same_sendbuf_cnt);

   ret = mca_base_pvar_register(project, framework, component,
                                "allreduce_same_recvbuf", "Number of times MPI_Allreduce() was called with the same recvbuf consecutively",
                                OPAL_INFO_LVL_3, MCA_BASE_PVAR_CLASS_SIZE,
                                MCA_BASE_VAR_TYPE_UNSIGNED_LONG, NULL, MCA_BASE_VAR_BIND_NO_OBJECT,
                                MCA_BASE_PVAR_FLAG_READONLY | MCA_BASE_PVAR_FLAG_CONTINUOUS,
                                NULL, NULL, NULL, (void *)&ompi_api_pvars.allreduce_same_recvbuf_cnt);

   ret = mca_base_pvar_register(project, framework, component, 
                                "reduce_same_sendbuf", "Number of times MPI_Reduce() was called with the same sendbuf consecutively",
                                OPAL_INFO_LVL_3, MCA_BASE_PVAR_CLASS_SIZE,
                                MCA_BASE_VAR_TYPE_UNSIGNED_LONG, NULL, MCA_BASE_VAR_BIND_NO_OBJECT,
                                MCA_BASE_PVAR_FLAG_READONLY | MCA_BASE_PVAR_FLAG_CONTINUOUS,
                                NULL, NULL, NULL, (void *)&ompi_api_pvars.reduce_same_sendbuf_cnt);

   ret = mca_base_pvar_register(project, framework, component,
                                "reduce_same_recvbuf", "Number of times MPI_Reduce() was called with the same recvbuf consecutively",
                                OPAL_INFO_LVL_3, MCA_BASE_PVAR_CLASS_SIZE,
                                MCA_BASE_VAR_TYPE_UNSIGNED_LONG, NULL, MCA_BASE_VAR_BIND_NO_OBJECT,
                                MCA_BASE_PVAR_FLAG_READONLY | MCA_BASE_PVAR_FLAG_CONTINUOUS,
                                NULL, NULL, NULL, (void *)&ompi_api_pvars.reduce_same_recvbuf_cnt);

   ret = mca_base_pvar_register(project, framework, component,
                                "p2p_to_local_rank_cnt", "Number of times P2P communications API functions called with local process/rank",
                                OPAL_INFO_LVL_3, MCA_BASE_PVAR_CLASS_SIZE,
                                MCA_BASE_VAR_TYPE_UNSIGNED_LONG, NULL, MCA_BASE_VAR_BIND_NO_OBJECT,
                                MCA_BASE_PVAR_FLAG_READONLY | MCA_BASE_PVAR_FLAG_CONTINUOUS,
                                NULL, NULL, NULL, (void *)&ompi_api_pvars.p2p_to_local_rank_cnt);

   ret = mca_base_pvar_register(project, framework, component,
                                "p2p_to_remote_rank_cnt", "Number of times P2P communications API functions called with remote process/rank",
                                OPAL_INFO_LVL_3, MCA_BASE_PVAR_CLASS_SIZE,
                                MCA_BASE_VAR_TYPE_UNSIGNED_LONG, NULL, MCA_BASE_VAR_BIND_NO_OBJECT,
                                MCA_BASE_PVAR_FLAG_READONLY | MCA_BASE_PVAR_FLAG_CONTINUOUS,
                                NULL, NULL, NULL, (void *)&ompi_api_pvars.p2p_to_remote_rank_cnt);

   ret = mca_base_pvar_register(project, framework, component,
                                "bcast_last_buffer_ptr_used", "Last buffer used by MPI_Bcast() - For preparing histogram",
                                OPAL_INFO_LVL_3, MCA_BASE_PVAR_CLASS_SIZE,
                                MCA_BASE_VAR_TYPE_UNSIGNED_LONG, NULL, MCA_BASE_VAR_BIND_NO_OBJECT,
                                MCA_BASE_PVAR_FLAG_READONLY | MCA_BASE_PVAR_FLAG_CONTINUOUS,
                                NULL, NULL, NULL, (void *)&ompi_api_pvars.bcast_last_buffer_ptr_used);


   ret = mca_base_pvar_register(project, framework, component,
                                "gatherv_last_send_size_used", "Last send size used by MPI_Gatherv(), variadic size - For preparing histogram",
                                OPAL_INFO_LVL_3, MCA_BASE_PVAR_CLASS_SIZE,
                                MCA_BASE_VAR_TYPE_UNSIGNED_LONG, NULL, MCA_BASE_VAR_BIND_NO_OBJECT,
                                MCA_BASE_PVAR_FLAG_READONLY | MCA_BASE_PVAR_FLAG_CONTINUOUS,
                                NULL, NULL, NULL, (void *)&ompi_api_pvars.gatherv_last_send_size_used);


   return OPAL_SUCCESS;
}
