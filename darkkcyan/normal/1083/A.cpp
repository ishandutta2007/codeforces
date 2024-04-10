#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

template<class x> vector<typename x::value_type> tovec(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> tovec(u a, u b) { return vector<ptrtype(u)>(a, b); }

template<typename x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<typename u, typename v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}/*}}}*/

#define maxn 301010
int n;
llong w[maxn];
vector<pair<int, llong>> gr[maxn];
llong du[maxn], dd[maxn];

int p[maxn];
llong cp[maxn];
vector<int> topo;
void toposort(int r) {
  topo.push_back(r);
  p[r] = r;
  for (int f = 0; f < len(topo); ++f) {
    int u = topo[f];
    for (auto i: gr[u]) {
      int v = i.xx;
      if (p[u] == v) continue;
      topo.push_back(v);
      p[v] = u;
      cp[v] = i.yy;
    }
  }
}

void dfsup() {
  for (int f = len(topo); f-- > 0; ) {
    int u = topo[f];
    du[u] = 0;
    for (auto i: gr[u]) {
      int v = i.xx;
      llong c = i.yy;
      if (v == p[u]) continue;
      du[u] = max(du[u], du[v] - c);
    }
    du[u] += w[u];
  }
}

void dfsdown() {
  dd[topo[0]] = w[topo[0]];
  for (auto u: topo) {
    multiset<llong> mc;
    mc.insert(dd[u]);
    for (auto i: gr[u]) {
      int v = i.xx;
      if (v == p[u]) continue;
      if (du[v] + i.yy < 0) continue;
      mc.insert(du[v] - i.yy + w[u]);
      if (len(mc) > 2) mc.erase(mc.begin());
    }
    
    for (auto i: gr[u]) {
      int v = i.xx;
      if (v == p[u]) continue;
      llong oc = du[v] - i.yy + w[u];
      bool has = mc.count(oc);
      if (has) mc.erase(mc.find(oc));
      dd[v] = max(0ll, *--mc.end() - i.yy) + w[v];
      if (has) mc.insert(oc);
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) cin >> w[i];
  rep(i, n - 1) {
    int u, v, c; cin >> u >> v >> c;
    gr[u].push_back({v, c});
    gr[v].push_back({u, c});
  }

  toposort(1);
  dfsup();
  dfsdown();
  llong ans = 0;
  //clog << tovec(dd + 1, dd + n + 1) << endl;
  //clog << tovec(du + 1, du + n + 1) << endl;
  rep1(i, n) ans = max(ans, max(du[i], dd[i]));
  cout << ans;

  return 0;
}