#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 10000 + 7;
const int INF = (int) 1e18;
int n, cap, price[N], sell[N], dp[N], dp2[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  for (int i = 0; i < N; i++) dp[i] = dp2[i] = INF;
  cin >> n >> cap;
  for (int i = 1; i <= n; i++) cin >> price[i];
  for (int i = 1; i <= n; i++) cin >> sell[i];

  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int p = price[i], s = sell[i];
    for (int j = 0; j <= n; j++) {
      dp2[j] = min(dp2[j], dp[j] + p + cap * j);
      if (j >= 1) dp2[j] = min(dp2[j], dp[j - 1] + s);
    }
    for (int j = 0; j <= n; j++) {
      dp[j] = dp2[j];
      dp2[j] = INF;
    }
  }
  int sol = INF;
  for (int j = 0; j <= n; j++) {
    sol = min(sol, dp[j]);
  }
  cout << sol << "\n";
}