#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define rem  ((llong)998244353)

#define maxn 2020
int n, k;

llong dp[maxn][maxn][4] = {0};

int getaddition(int u, int v) {
  bool t[2][2] = {{u & 1, !!(u & 2)}, {v & 1, !!(v & 2)}};
  int cnt = 0;
  rep(i, 2) rep(f, 2) rep(x, 2) rep(y, 2) {
    if (i == x and f == y) continue;
    if (i == !x and f == !y) continue;
    cnt += t[x][y] != t[i][f];
  }
  cnt /= 2;
  assert(cnt % 2 == 0);
  if (cnt == 0) cnt = 1;
  return cnt - (t[0][1] != t[0][0]) - 1;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  dp[1][1][0] = dp[1][1][3] = 1;
  dp[1][2][1] = dp[1][2][2] = 1;
  for (int i = 2; i <= n; ++i) {
    rep(u, 4) rep(v, 4) {
      int addi = getaddition(v, u);
      for (int f = 0; f <= 2 * i; ++f) {
        (dp[i][f + addi][u] += dp[i - 1][f][v]) %= rem;
      }
    }
  }
  cout << (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3]) % rem;

  return 0;
}