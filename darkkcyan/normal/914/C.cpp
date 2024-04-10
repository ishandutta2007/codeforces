#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

#define maxn 1010
#define rem ((llong)1e9 + 7)
int k;
string n;
llong dp[maxn][maxn][2];
llong cal(int i, int f, bool sm = 1) {
  if (f < 0) return 0;
  if (dp[i][f][sm] != -1) return dp[i][f][sm];
  if (i >= len(n)) return f == 0;
  dp[i][f][sm] = 0;
  int m = sm ? n[i] - '0' : 1;
  for (int g = 0; g <= m; ++g) {
    bool ns = g == m and sm;
    (dp[i][f][sm] += cal(i + 1, f - g, ns)) %= rem;
  }
  //clog << i << ' ' << f << ' ' << sm << ' ' << dp[i][f][sm] << endl;
  return dp[i][f][sm];
}

llong ans[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  if (k == 0) {
    cout << 1;
    return 0;
  }
  memset(dp, -1, sizeof(dp));
  ans[1] = -1;
  llong res = 0;
  for (int i = 1; i < maxn; ++i) {
    ans[i] = ans[__builtin_popcount(i)] + 1;
    if (ans[i] + 1 == k) {
      (res += cal(0, i)) %= rem;
      //clog << i << ' ' << cal(0, i) << endl;
    }
  }
  if (k == 1) res = (res - 1 + rem) % rem;
  cout << res;

  return 0;
}