#include "M5Core2.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "lv_examples/src/lv_demo_widgets/lv_demo_widgets.h"

extern "C" void app_main() {
  m5core2_init();

  {
    std::lock_guard<std::mutex> lk(gui_mutex);
    lv_demo_widgets();
  }

  while (1)
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
