#include <bits/stdc++.h>
using namespace std;

#define llong long long /* {{{ */
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
// }}}

#define maxn 600010
#define rem ((llong)1e9 + 7)
int n, m, k;
llong a[maxn];
map<llong, vector<ii>> possiblex;

llong p2[maxn];
void genp2() {
  p2[0] = 1;
  rep1(i, maxn - 1) {
    p2[i] = p2[i - 1] * 2 % rem;
  }
}

int dsu[maxn];
int setcnt;
int findp(int u) {
  if (dsu[u] == u) return u;
  return dsu[u] = findp(dsu[u]);
}
void join(int u, int v) {
  if (rand() & 1) swap(u, v);
  u = findp(u); v = findp(v);
  if (u == v) return ;
  dsu[u] = v;
  setcnt --;
}

int main() {
  genp2();
  srand((unsigned)time(0));
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  rep1(i, n) {
    cin >> a[i];
    dsu[i] = i;
  }
  rep(i, m) {
    int u, v; cin >> u >> v;
    possiblex[a[u] ^ a[v]].push_back(ii(u, v));
  }

  llong ans = (p2[k] - len(possiblex) + rem) % rem * p2[n] % rem;
  for (auto& i: possiblex) {
    setcnt = n;
    for (auto& f: i.yy) {
      join(f.xx, f.yy);
    }
    (ans += p2[setcnt]) %= rem;
    for (auto& f: i.yy) {
      dsu[f.xx] = f.xx;
      dsu[f.yy] = f.yy;
    }
  }
  cout << ans;

  return 0;
}