#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 7;
int n;
int m;
int sol;
int dp[N][N];
int dp3[N][N];
string s;
string t;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = -(int) 1e9;
      dp3[i][j] = -(int) 1e9;
    }
  }

  cin >> n >> m >> s >> t;
  s = " " + s;
  t = " " + t;
  for (int i = 1; i <= n; i++) {
    int cur = -(int) 1e9;
    for (int j = 1; j <= m; j++) {
      if (s[i] == t[j]) {
        dp[i][j] = dp3[i - 1][j - 1];
        dp[i][j] = dp[i][j] - i - j + 4;
        dp[i][j] = max(dp[i][j], 2);
        cur = max(cur, dp[i][j] + i + j);
      }
      dp3[i][j] = max(dp3[i - 1][j], cur);
      sol = max(sol, dp[i][j]);
    }
  }
  cout << sol << "\n";
}