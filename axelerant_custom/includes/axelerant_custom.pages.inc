<?php
/**
 * @file
 * Contains custom page callbacks for axelerant_custom module.
 */

/**
 * Page callback: Displays the json output of the nid provided.
 *
 * @see axelerant_custom_menu()
 */
function axelerant_custom_node_json_output($nid) {
  // Set flag $access_denied.
  $access_denied = FALSE;
  // We need to proceed only if the argument passed in numeric.
  if (is_numeric($nid)) {
    // Load the node.
    $node = node_load($nid);
    // We need to display json only if the content type is page.
    if ($node->type == "page") {
      // Json encode the node.
      $json = drupal_json_encode($node);
      // Return the json to handle it in the jquery.
      print $json;
      exit();
    }
    else {
      $access_denied = TRUE;
    }
  }
  else {
    $access_denied = TRUE;
  }
  // Deliver access denied page if the content type is not page or
  // if the argument passed is not numeric.
  if ($access_denied) {
    drupal_access_denied();
  }
}
