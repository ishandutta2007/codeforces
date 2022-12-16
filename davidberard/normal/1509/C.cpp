#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll dp[2020][2020];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<ll> s(n+1);
  for (int i=1; i<=n; ++i) {
    cin >> s[i];
  }
  sort(s.begin(), s.end());
  dp[1][n] = s[n]-s[1];
  for (int l=n-2; l>=0; --l) {
    for (int i=1; i+l<=n; ++i) {
      int j = i+l;
      dp[i][j] = 0x3f3f3f3f3f3f3f3f;
      if (i>1) {
        dp[i][j] = min(dp[i][j], dp[i-1][j]);
      }
      if (j<n) {
        dp[i][j] = min(dp[i][j], dp[i][j+1]);
      }
      dp[i][j] += s[j]-s[i];
    }
  }
  ll ans = 0x3f3f3f3f3f3f3f3f;
  for (int i=1; i<=n; ++i) {
    ans = min(ans, dp[i][i]);
  }
  cout << ans << "\n";
  return 0;
}