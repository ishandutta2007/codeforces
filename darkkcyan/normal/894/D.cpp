#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define all(x) x.begin(), x.end()

#define maxn 1010101
int n, m;
llong l[maxn];
vector<llong> val[maxn][2], sum[maxn][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep1(i, n - 1) cin >> l[i + 1];
  rep1(i, n) {
    llong d = l[i];
    for (int pre = i, p = i / 2; p > 0; d += l[p], pre = p, p >>= 1) {
      val[p][pre & 1].push_back(d);
    }
  }
  rep1(i, n) rep(f, 2) {
    sort(val[i][f].begin(), val[i][f].end());
    sum[i][f].push_back(0);
    for (auto g: val[i][f]) {
      //clog << i << ' ' << f << ' ' << g << endl;
      sum[i][f].push_back(sum[i][f].back() + g);
    }
  }
  while (m--) {
    llong u, h; cin >> u >> h;
    llong ans = h;
    rep(i, 2) {
      int p = upper_bound(all(val[u][i]), h) - val[u][i].begin();
      ans += (llong)p * h - sum[u][i][p];
    }
    //clog << ans << endl;
    h -= l[u];
    for (int p = u / 2; p > 0 and h > 0; h -= l[p], u = p, p >>= 1) {
      ans += h;
      int x = (~u & 1);
      int t = upper_bound(all(val[p][x]), h) - val[p][x].begin();
      ans += (llong)t * h - sum[p][x][t];
      //clog << x << ' ' << t << ' ' << ans << ' ' << h << endl;
    }
    cout << ans << '\n';
  }

  return 0;
}