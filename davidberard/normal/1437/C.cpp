#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int t[220];
int dp[220][440];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) 
  {
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
      cin >> t[i];
    }
    sort(t+1, t+n+1);
    //vector<vector<int>> dp = vector<vector<int>>(n+1, vector<int>(n+1));
    int ans = 1e9;
    for (int i=1; i<=n; ++i) {
      dp[i][0] = 1e9;
      for (int j=1; j<=2*n+4; ++j) 
      {
        dp[i][j] = 1e9;
        for (int k=0; k<j; ++k) {
          dp[i][j] = min(dp[i-1][k] + abs(j-t[i]), dp[i][j]);
        }
      }
    }
    for (int i=1; i<=2*n+4; ++i) {
      ans = min(ans, dp[n][i]);
    }
    cout << ans << "\n";
  }

  return 0;
}