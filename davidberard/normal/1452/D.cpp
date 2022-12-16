#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;
const int N = 200200;

const ll half = 499122177;
const ll quarter = half*half%MOD;

ll dp[N];
ll sum[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  sum[0] = dp[0] = 1;
  sum[1] = dp[1] = half;
  for (int i=2; i<=n; ++i) {
    dp[i] = half*sum[i-1]%MOD;
    sum[i] = (quarter*sum[i-2] + dp[i])%MOD;
  }
  cout << dp[n] << "\n";
  return 0;
}