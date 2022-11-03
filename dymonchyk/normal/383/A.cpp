#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[200002];

int main() {
  int n;
  scanf("%d", &n);
  int cnt[2] = {0};
  for (int  i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    cnt[arr[i]]++;
  }
  long long ans1 = 0, ans2 = 0;
  int c0 = cnt[0], c1 = cnt[1];
  for (int i = n - 1; i >= 0; --i) {
    if (arr[i] == 0) {
      ans1 += c1;
    } else {
      --c1;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (arr[i] == 1) {
      ans2 += c0;
    } else {
      --c0;
    }
  }
  cout << min(ans1, ans2) << endl;
  return 0;
}