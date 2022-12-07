#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> height(n);
    vector<int> cost(n);
    vector<vector<long long>> dp(n, vector<long long>(3, 1ll << 60));
    for (int i = 0; i < n; i++) {
      cin >> height[i] >> cost[i];
    }
    for (int j = 0; j < 3; j++)
      dp[0][j] = j * cost[0];
    for (int i = 0; i < n - 1; i++)
      for (int j = 0; j < 3; j++) 
        for (int k = 0; k < 3; k++) 
          if (height[i] + j != height[i + 1] + k) {
            dp[i+1][k] = min(dp[i+1][k], dp[i][j] + k * cost[i+1]);
          }
    long long ans = 1ll << 60;
    for (int j = 0; j < 3; j++) {
      ans = min(ans, dp[n-1][j]);
    }
    cout << ans << "\n";
  }
}