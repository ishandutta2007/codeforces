#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[200005], used[200005], id;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    --arr[i];
  }
  
  int root = -1, ans = 0;
  for (int i = 0; i < n; ++i)
    if (arr[i] == i) root = i;

  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    ++id;
    int x = i;
    while (true) {
      if (used[x]) {
        if (used[x] == id) {
          if (root == -1) {
            root = x;
            arr[x] = x;
            ++ans;
          } else if (x != root) {
            arr[x] = root;
            ++ans;
          }
        }
        break;
      }
      used[x] = id;
      x = arr[x];
    }
  }

  printf("%d\n", ans);
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i] + 1);
  }
  printf("\n");

  return 0;
}