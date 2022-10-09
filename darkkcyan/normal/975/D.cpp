#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define ll pair<llong, llong>

int n;
llong a, b;

map<llong, map<ll, int>> cnt;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> a >> b;
  rep(i, n) {
    llong x, u, v;
    cin >> x >> u >> v;
    cnt[v - a * u][ll(u, v)]++;
  }
  llong ans = 0;
  for (auto i: cnt) {
    llong s = 0;
    for (auto f: i.yy) s += f.yy;
    for (auto f: i.yy) ans += f.yy * (s - f.yy);
  }
  cout << ans;

  return 0;
}