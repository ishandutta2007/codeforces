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

int main() {
  fast_cin();
  int n; cin >> n;
  vector<string> s(n);
  for (auto& i : s) {
    cin >> i;
  }
  vector<int> val(n), sz(n), mn(n, 0);
  vector<vector<int>> cnt(n), f(n);
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    sz[i] = s[i].size();
    cnt[i].resize(2 * sz[i] + 1, 0);
    f[i].resize(sz[i] + 1, 0);
    for (auto& c : s[i]) {
      cur += (c == '(' ? 1 : -1);
      if (cur < mn[i]) {
        f[i][-mn[i]] = cnt[i][mn[i] + sz[i]];
        mn[i] = cur;
      }
      ++cnt[i][cur + sz[i]];
    }
    for (int v = -mn[i]; v <= sz[i]; ++v) {
      f[i][v] = cnt[i][-v + sz[i]];
    }
    val[i] = cur;
  }
  int tot = (1 << n);
  vector<int> sum(tot, 0), dp(tot, -1);
  for (int mask = 0; mask < tot; ++mask) {
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        sum[mask] += val[i];
      }
    }
  }
  int ans = 0;
  dp[0] = 0;
  for (int mask = 0; mask < tot; ++mask) {
    if (dp[mask] == -1) {
      continue;
    }
    ans = max(ans, dp[mask]);
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        continue;
      }
      if (sum[mask] + mn[i] < 0) {
        ans = max(ans, dp[mask] + f[i][sum[mask]]);
      } else {
        int nmask = mask | (1 << i);
        int add = (sum[mask] <= sz[i] ? f[i][sum[mask]] : 0);
        dp[nmask] = max(dp[nmask], dp[mask] + add);
      }
    }
  }
  cout << ans << endl;
}