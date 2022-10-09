#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define rep(i,n) for (int i =-1; ++i < n; )
#define rep1(i,n) for (int i = 0; ++i <= n; )
#define sgn(x) ((x) < 0 ? -1 : (x) > 0)
#define inf ((llong)1e16)

#define maxn 1111
#define maxk 2222

int n, k;
llong a[maxn], b[maxk];
llong p;

llong dp[maxn][maxk];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k >> p;
  rep(i, n) cin >> a[i];
  rep(i, k) cin >> b[i];
  sort(a, a + n); sort(b, b + k);
  rep(i, n) rep(f, k) dp[i][f] = inf;
  rep(i, n) {
    for (int f = i; f <= k; ++f) {
      dp[i][f] = abs(a[i] - b[f]) + abs(b[f] - p);
      if (i and f) dp[i][f] = max(dp[i][f], dp[i - 1][f - 1]);
      if (f) dp[i][f] = min(dp[i][f - 1], dp[i][f]);
      //clog << i << ' ' << f << ' ' << dp[i][f] << endl;
    }
  }

  cout << dp[n - 1][k - 1];

  return 0;
}