/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;
const ll inf = 1e18 + 42;

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    int x; cin >> x;
    for (auto& i : a) {
      i -= x;
    }
    vector<ll> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
      pref[i] = pref[i - 1] + a[i];
    }
    vector<pll> stk;
    stk.pb({-inf, n + 1});
    vector<ll> f(n + 2, n + 1);
    for (int i = n; i >= 1; --i) {
      auto it = lower_bound(stk.begin(), stk.end(), make_pair(pref[i - 1], -inf));
      --it;
      f[i] = min(it->second, f[i + 1]);
      while (stk.back().first >= pref[i]) {
        stk.pop_back();
      }
      stk.pb({pref[i], i});
    }
    vector<ll> dp(n + 3, 0);
    for (int i = n; i >= 1; --i) {
      dp[i] = max(dp[i + 1], f[i] - i + dp[f[i] + 1]);
    }
    cout << dp[1] << '\n';
  }
}