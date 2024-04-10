#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;

const int N = 5050;
ll a[N];
ll dp[N][N];
ll sp[N][N]; // sp[i][j] = sum_i<=j dp[k][j];
int q[N];

int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  for (int i=1; i<=n; ++i) {
    dp[i][1] = 1;
    sp[i][1] = i;
  }
  int p = 0;
  for (int i=1; i<=n; ++i) {
    while (a[p+1]*2 <= a[i]) {
      ++p;
    }
    q[i] = p;
  }

    for (int j=2; j<=n; ++j) {
  for (int i=1; i<=n; ++i) {
      dp[i][j] = (sp[q[i]][j-1] + (q[i]-j+2 >= 1 ? dp[i][j-1]*(q[i]-j+2) : 0))%MOD;
      //cerr << " dp[" << i << "][" << j << "] = " << dp[i][j] << " = " << sp[q[i]][j-1] << " " << dp[i][j-1]*(q[i]-j+1) << endl;
      sp[i][j] = (sp[i-1][j]+dp[i][j])%MOD;
    }
  }
  ll ans = 0;
  for (int i=1; i<=n; ++i) {
    ans += dp[i][n];
  }
  cout << ans%MOD << endl;
  return 0;
}