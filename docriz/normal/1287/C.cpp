#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int dp[MAXN][MAXN][MAXN][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int odd = n / 2;
  int even = n / 2;
  if (n & 1) ++odd;
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    if (p[i] == 0) p[i] = -1;
    else {
      p[i] %= 2;
      if (p[i]) --odd; else --even;
    }
  }
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  memset(dp, 127 / 2, sizeof(dp));
  if (p[1] == -1) {
    dp[1][1][0][1] = 0;
    dp[1][0][1][0] = 0;
  } else {
    dp[1][0][0][p[1]] = 0;
  }
  int ans = INT_MAX;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= odd; j++) {
      for (int k = 0; k <= even; k++) {
        if (p[i] == -1) {
          if (k) {
            dp[i][j][k][0] = min(dp[i - 1][j][k - 1][0], dp[i - 1][j][k - 1][1] + 1);
          }
          if (j) {
            dp[i][j][k][1] = min(dp[i - 1][j - 1][k][0] + 1, dp[i - 1][j - 1][k][1]);
          }
        } else {
          dp[i][j][k][p[i]] = min(dp[i - 1][j][k][p[i]], dp[i - 1][j][k][p[i] ^ 1] + 1);
        }
      }
    }
  }
  ans = min(dp[n][odd][even][0], dp[n][odd][even][1]);
  cout << ans << endl;
  return 0;
}