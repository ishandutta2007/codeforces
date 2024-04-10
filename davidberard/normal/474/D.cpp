#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9+7;
const int N = 100100;
ll dp[N];
ll sum[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t, k;
  cin >> t >> k;
  dp[0] = 1;
  for (int i=1; i<N; ++i) {
    dp[i] = dp[i-1];
    if (i>=k) {
      dp[i] += dp[i-k];
    }
    dp[i] %= MOD;
    sum[i] = (sum[i-1]+dp[i])%MOD;
  }
  for (int i=1; i<=t; ++i) {
    int l, r;
    cin >> l >> r;
    cout << (sum[r]-sum[l-1]+MOD)%MOD << "\n";
  }
  return 0;
}