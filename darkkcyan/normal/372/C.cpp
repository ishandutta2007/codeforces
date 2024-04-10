#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 150101
int n, m, d;
llong dp[2][maxn] = {0};
int qu[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> d;
  int lastt = 0;
  llong ans = LLONG_MIN;
  while (m--) {
    llong a, b, t; cin >> a >> b >> t;
    llong maxd = d * (t - lastt);
    lastt = t;
    --a;
    int ql = 0, qr = -1;
    bool s = m & 1;
    ans = LLONG_MIN;
    rep(i, n) {
      int ir = min(i + maxd, (llong)n - 1), il = max(i - maxd, 0LL);
      for (int i = ql <= qr ? qu[qr] + 1 : 0; i <= ir; ++i) {
        while (ql <= qr and dp[!s][qu[qr]] <= dp[!s][i]) --qr;
        qu[++qr] = i;
      }
      while (ql <= qr and qu[ql] < il) ++ql;
      dp[s][i] = dp[!s][qu[ql]] + b - abs(a - i);
      ans = max(ans, dp[s][i]);
    }
  }
  cout << ans;
  
  return 0;
}