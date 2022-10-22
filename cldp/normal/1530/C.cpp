#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    vector<LL> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> y[i];
    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());
    vector<LL> sumx(n + 1), sumy(n + 1);
    for (int i = 0; i < n; ++i) {
      sumx[i + 1] = sumx[i] + x[i];
      sumy[i + 1] = sumy[i] + y[i];
    }
    int m = n - n / 4;
    if (sumx[m] - sumy[m] >= 0) {
      cout << "0\n";
      continue;
    }
    int L = n, R = 4 * n + 4;
    while (L + 1 < R) {
      int mid = (L + R) >> 1;
      int mm = mid - mid / 4;
      LL xx = 0, yy = 0;
      if (mid - n >= mm) {
        xx = mm * 100;
        mm = 0;
      } else {
        mm -= mid - n;
        xx = (mid - n) * 100 + sumx[mm];
      }
      yy = sumy[min(n, mid - mid / 4)];
      if (xx >= yy) R = mid; else L = mid;
    }
    cout << R - n << "\n";
  }
  return 0;
}