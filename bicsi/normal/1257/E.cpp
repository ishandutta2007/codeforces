#include <bits/stdc++.h>

using namespace std;

int main() {
  int k1, k2, k3;
  cin >> k1 >> k2 >> k3;
  vector<int> v1(k1), v2(k2), v3(k3);
  vector<int> ap(k1 + k2 + k3);
  for (int i = 0; i < k1; ++i) {
    cin >> v1[i];
    ap[v1[i] - 1] = 0;
  }
  for (int i = 0; i < k2; ++i) {
    cin >> v2[i];
    ap[v2[i] - 1] = 1;
  }
  for (int i = 0; i < k3; ++i) {
    cin >> v3[i];
    ap[v3[i] - 1] = 2;
  }

  int n = k1 + k2 + k3;
  vector<vector<int>> dp(n + 1, vector<int>(3, 1e9));
  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = j; k < 3; ++k) {
        int now = dp[i][j];
        if (ap[i] != k) now += 1;
        dp[i + 1][k] = min(dp[i + 1][k], now);
      }
    }
  }
  cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;
  return 0;
}