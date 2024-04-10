#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[50005];
set<int> f;

bool check(int n, int m) {
  f.clear();
  for (int i = 0; i < n; ++i) {
    int x = arr[i];
    while (x > 0 && (x > m || f.count(x))) x >>= 1;
    if (x > 0) {
      f.insert(x);
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  int l = 0, r = 1e+9 + 7;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (check(n, m)) r = m;
    else l = m;
  }

  f.clear();
  check(n, r);
  for (int x : f)
    printf("%d ", x);
  printf("\n");

  return 0;
}