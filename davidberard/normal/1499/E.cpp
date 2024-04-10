#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;
const int N = 1010;

char s[N], t[N];
int ns, nt;

ll dp[N][N][2][2][2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> (s+1) >> (t+1);
  ns = strlen(s+1);
  nt = strlen(t+1);
  ll ans = 0;
  for (int i=0; i<=ns; ++i) {
    for (int j=0; j<=nt; ++j) {
      if (i) {
        if (i > 1 && s[i] != s[i-1]) {
          dp[i][j][0][1][0] += dp[i-1][j][0][1][0];
          dp[i][j][0][1][1] += dp[i-1][j][0][1][1];
        }
        if (j && s[i] != t[j]) {
          dp[i][j][0][1][1] += dp[i-1][j][1][0][1];
          dp[i][j][0][1][1] += dp[i-1][j][1][1][1];
        }
        dp[i][j][0][1][0]++;
        dp[i][j][0][1][0] %= MOD;
        dp[i][j][0][1][1] %= MOD;
      }
      if (j) {
        if (i && s[i] != t[j]) {
          dp[i][j][1][1][1] += dp[i][j-1][0][1][1];
          dp[i][j][1][1][1] += dp[i][j-1][0][1][0];
        }
        if (j > 1 && t[j] != t[j-1]) {
          dp[i][j][1][0][1] += dp[i][j-1][1][0][1];
          dp[i][j][1][1][1] += dp[i][j-1][1][1][1];
        }
        dp[i][j][1][0][1]++;
        dp[i][j][1][0][1] %= MOD;
        dp[i][j][1][1][1] %= MOD;
      }
      ans += dp[i][j][0][1][1];
      ans += dp[i][j][1][1][1];
    }
  }
  cout << ans %MOD << "\n";
  return 0;
}