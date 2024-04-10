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
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  vector<LL> fac {1};
  for (int i = 1; i <= 200010; ++i) {
    fac.push_back(fac[i - 1] * i % MOD);
  }
  while (times--) {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
    }
    int andx = x[0];
    for (int i = 1; i < n; ++i) {
      andx &= x[i];
    }
    LL cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (x[i] == andx) ++cnt;
    }
    if (cnt < 2) {
      cout << 0 << endl;
      continue;
    }
    LL ans = cnt * (cnt - 1) % MOD;
    ans = ans * fac[n - 2] % MOD;
    cout << ans << endl;
  }
  return 0;
}