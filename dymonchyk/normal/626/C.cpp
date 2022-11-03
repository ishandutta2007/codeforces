#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int l = 0, r = 1e+9;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    int cnt6 = mid / 6, cnt2 = mid / 2 - cnt6, cnt3 = mid / 3 - cnt6;
    cnt2 = min(cnt2, n);
    cnt3 = min(cnt3, m);

    if (cnt2 + cnt3 + cnt6 >= n + m) r = mid;
    else l = mid;
  }
  cout << r << endl;
  return 0;
}