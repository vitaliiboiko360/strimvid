#include "../include/server.h"

// timeout to cleanup expired session
static gboolean
timeout (GstRTSPServer * server)
{
  GstRTSPSessionPool *pool;

  pool = gst_rtsp_server_get_session_pool (server);
  gst_rtsp_session_pool_cleanup (pool);
  g_object_unref (pool);

  return TRUE;
}

GstRTSPServer* create_server() {
  return gst_rtsp_server_new ();
}