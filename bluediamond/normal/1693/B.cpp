#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
const int INF = (int) 1e9 + 7;
int n;
vector<int> g[N];
int low[N], high[N], dp[N];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE


  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
    for (int i = 2; i <= n; i++) {
      int parrent;
      cin >> parrent;
      g[parrent].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      cin >> low[i] >> high[i];
      dp[i] = INF;
    }
    for (int a = n; a >= 1; a--) {
      if (g[a].empty()) {
        dp[a] = 1;
        continue;
      }
      int l = low[a], r = high[a];
      ll s_low = 0, s_high = 0;
      for (auto &b : g[a]) {
        s_low += low[b];
        s_high += high[b];
      }
      r = min((ll) r, s_high);

      if (l > r) {
        dp[a] = 1;
      } else {
        dp[a] = 0;
        assert(l <= r);
        low[a] = l;
        high[a] = r;
      }
      for (auto &b : g[a]) {
        dp[a] += dp[b];
      }
    }
    cout << dp[1] << "\n";
  }


}


/**

**/