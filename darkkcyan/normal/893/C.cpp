#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

#define maxn 101010
int n, m;
int a[maxn];

int p[maxn];
int findp(int u) { return p[u] = u == p[u] ? u : findp(p[u]); }
void join(int u, int v) {
  u = findp(u), v = findp(v);
  if (a[u] < a[v]) swap(u, v);
  p[u] = v;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep1(i, n) cin >> a[i];
  rep1(i, n) p[i] = i;
  rep(_, m) {
    int u, v; cin >> u >> v;
    join(u, v);
  }

  llong ans = 0;
  rep1(i, n) {
    if (findp(i) == i) ans += a[i];
  }
  cout << ans;

  return 0;
}