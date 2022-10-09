#include <bits/stdc++.h>
using namespace std;
#define llong long long /*{{{*/
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; ) 
#define rep1(i,n) for (int i = 0; i ++ < n; )

template<typename x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<typename u, typename v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}/*}}}*//*}}}*/

#define maxn 101010
#define maxv 201
#define rem ((llong)998244353)
int n;
int a[maxn];
llong dp[maxn][maxv][3] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) cin >> a[i];
  if (a[1] == -1) {
    rep1(i, maxv - 1) dp[1][i][0] = 1;
  } else {
    dp[1][a[1]][0] = 1;
  }

  for (int i = 2; i <= n; ++i) {
    if (a[i] != -1) {
      dp[i][a[i]][1] = (dp[i - 1][a[i]][0] + dp[i - 1][a[i]][1] + dp[i - 1][a[i]][2]) % rem;
      llong u = 0, v = 0;
      rep1(f, a[i] - 1)
        rep(g, 3) (u += dp[i - 1][f][g]) %= rem;
      dp[i][a[i]][0] = u;
      for (int f = a[i] + 1; f < maxv; ++f)
        (v += dp[i - 1][f][1] + dp[i - 1][f][2]) %= rem;
      dp[i][a[i]][2] = v;
      continue;
    }

    rep1(f, maxv - 1)
      dp[i][f][1] = (dp[i - 1][f][0] + dp[i - 1][f][1] + dp[i - 1][f][2]) % rem;
    llong u = 0;
    rep1(f, maxv - 1) {
      dp[i][f][0] = u;
      rep(g, 3) (u += dp[i - 1][f][g]) %= rem;
    }
    u = 0;
    for (int f = maxv; f--; ) {
      dp[i][f][2] = u;
      (u += dp[i - 1][f][2] + dp[i - 1][f][1]) %= rem;
    }
  }

  //clog << vector<llong>(dp[2][1], dp[2][1] + 3) << endl;
  //clog << vector<llong>(dp[2][2], dp[2][2] + 3) << endl;

  llong ans = 0;
  if (a[n] != -1) (ans = dp[n][a[n]][1] + dp[n][a[n]][2]) %= rem;
  else rep1(i, maxv - 1) {
    (ans += dp[n][i][1] + dp[n][i][2]) %= rem;
  }
  cout << ans;


  return 0;
}