#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 111
#define rem ((llong)1e9 + 7)
int n, k, d;
llong dp[maxn][maxn][2];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k >> d;
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  llong ans = 0;
  rep1(i, n) {
    rep(f, maxn) {
      rep1(g, k) {
        int t = min(maxn - 1, f + g);
        (dp[i][t][1] += dp[i - 1][f][1]) %= rem;
        (dp[i][t][g >= d] += dp[i - 1][f][0]) %= rem;
      }
    }
    (ans += dp[i][n][1]) %= rem;
  }
  cout << ans;
  
  return 0;
}