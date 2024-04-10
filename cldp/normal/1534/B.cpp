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
    vector<LL> x(n + 2);
    for (int i = 1; i <= n; ++i) cin >> x[i];
    LL ans = 0;
    for (int i = 1; i <= n; ++i) ans += abs(x[i] - x[i - 1]);
    ans += x[n];
    for (int i = 1; i <= n; ++i) {
      if (x[i] > x[i - 1] && x[i] > x[i + 1]) {
        LL low = max(x[i - 1], x[i + 1]);
        ans -= x[i] - low;
        x[i] = low;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}