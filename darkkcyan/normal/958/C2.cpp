#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 20101
#define maxk 60
int n, k, p;
int a[maxn];

int dp[maxk][maxn] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k >> p;
  rep1(i, n) {
    cin >> a[i];
    a[i] %= p;
    dp[1][i] = (a[i] + dp[1][i - 1]) % p;
  }
  for (int i = 2; i <= k; ++i) {
    int ds[p]; memset(ds, -1, sizeof(ds));
    rep1(f, n) {
      int tds[p]; memcpy(tds, ds, sizeof(ds));
      rep(g, p) ds[(g + a[f]) % p] = tds[g];
      dp[i][f] = -1;
      rep(g, p) {
        if (ds[g] == -1) continue;
        dp[i][f] = max(dp[i][f], ds[g] + g);
      }
      //clog << '[';
      //rep(g, p) clog << ds[g] << ' ';
      //clog << "] ";
      //clog << i << ' ' << f << ' ' << dp[i][f] << endl;;
      ds[0] = max(ds[0], dp[i - 1][f]);
    }
  }
  cout << dp[k][n];

  return 0;
}