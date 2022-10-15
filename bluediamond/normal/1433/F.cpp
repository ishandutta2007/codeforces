#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 70 + 7;
const int INF = (int) 1e9;
int n;
int m;
int k;
int dp[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = 0;
  for (int it = 1; it <= n; it++) {
    for (int i = 1; i <= m; i++) {
      int a;
      cin >> a;
      for (int cnt = m / 2; cnt >= 0; cnt--) {
        for (int x = 0; x < k; x++) if (dp[cnt][x] != -INF) dp[cnt + 1][(x + a) % k] = max(dp[cnt + 1][(x + a) % k], dp[cnt][x] + a);
      }
    }
    /// just reset
    for (int cnt = 1; cnt <= m / 2; cnt++) {
      for (int x = 0; x < k; x++) dp[0][x] = max(dp[0][x], dp[cnt][x]), dp[cnt][x] = -INF;
    }
  }
  cout << dp[0][0] << "\n";
}