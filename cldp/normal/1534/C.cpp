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

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    vector<int> x(n), px(n);
    vector<int> y(n), py(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
      --x[i];
      px[x[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
      cin >> y[i];
      --y[i];
      py[y[i]] = i;
    }
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      if (x[i] == y[i]) flag = false;
    }
    if (!flag) {
      cout << 0 << '\n';
      continue;
    }
    vector<bool> z(n);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      if (z[i]) continue;
      int t = i;
      z[t] = true;
      while (py[x[t]] != i) {
        t = py[x[t]];
        z[t] = true;
      }
      ans = ans * 2 % MOD;
    }
    cout << ans << '\n';
  }
  
  return 0;
}