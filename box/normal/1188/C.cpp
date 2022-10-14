#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a) + 1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 998244353;

int ar[1005];
int dp[1005][1005];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  rep(i, n) cin >> ar[i];
  sort(ar, ar + n);
  auto cnt = [&](int gap) {
    if (gap * (k-1) > ar[n - 1])
      return 0;
    int pv = -1;
    rep1(i, k) dp[0][i] = 0;
    rep(i, n) {
      dp[i][1] += 1;
      while (ar[pv + 1] + gap <= ar[i])
        pv++;
      if (pv != -1)
        rep1(j, k)(dp[i][j] += dp[pv][j - 1]) %= MOD;
      rep1(j, k) dp[i + 1][j] = dp[i][j];
    }
    return dp[n][k];
  };
  int ans = 0;
  rep1(i, ar[n - 1]) ans = (ans + cnt(i)) % MOD;
  cout << ans << endl;
}