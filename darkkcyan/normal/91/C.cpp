#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )
#define rem ((llong)1e9+9)
#define maxn 101010
int n;
int cnt[maxn];
int dsu[maxn];
int findp(int u) { return dsu[u] = u == dsu[u] ? u : findp(dsu[u]); }
void join(int u, int v) {
  u = findp(u), v = findp(v);
  if (u == v) return ;
  cnt[u] += cnt[v];
  dsu[v] = u;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  rep1(i, n) cnt[i] = 0, dsu[i] = i;
  llong ans = 1;
  rep(i, m) {
    int u, v; cin >> u >> v;
    u = findp(u), v = findp(v);
    if (u == v) {
      (ans *= 2) %= rem;
      cnt[u] ++;
    } else join(u, v);
    cout << ans - 1 << '\n';
  }
  
  return 0;
}