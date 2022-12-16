#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9+7;
const int K = 20100;

ll dp[1010][K];
int a[1010];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  const int ctr = 10005;
  ll ans = 0;
  for (int i=1; i<=n; ++i) {
    for (int j=0; j<K; ++j) {
      if (j-a[i] >= 0) {
        dp[i][j] += dp[i-1][j-a[i]];
      }
      if (j+a[i] < K) {
        dp[i][j] += dp[i-1][j+a[i]];
      }
      dp[i][j] %= MOD;
    }
    if (++dp[i][ctr+a[i]] == MOD) {
      dp[i][ctr+a[i]] = 0;
    }
    if (++dp[i][ctr-a[i]] == MOD) {
      dp[i][ctr-a[i]] = 0;
    }
    ans += dp[i][ctr];
  }
  cout << ans%MOD << "\n";
  return 0;
}