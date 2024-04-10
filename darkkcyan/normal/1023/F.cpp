#include <bits/stdc++.h>
using namespace std;

#define clogi clog << __PRETTY_FUNCTION__ << " at " << __LINE__ << ": "/*{{{*/
#define llong long long 
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

#define maxn 501010
struct dsu {
  vector<int> par;
  void reset(int N) {
    par.resize(N + 1);
    rep1(i, N) par[i] = i;
  }
  int findp(int u) { return par[u] = u == par[u] ? u : findp(par[u]); }
  bool join(int u, int v) {
    u = findp(u); v = findp(v);
    if (u == v) return false;
    if (rand() & 1) swap(u, v);
    par[u] = v;
    return true;
  }
};

int n, m, k;
vector<int> gr[maxn];
int p[maxn];
int depth[maxn];
void dfs(int u) {
  depth[u] = depth[p[u]] + 1;
  for (auto v: gr[u]) {
    if (v == p[u]) continue;
    p[v] = u;
    dfs(v);
  }
}

struct dsuWithLowest: public dsu {
  vector<int> lowest;
  void reset(int N) {
    dsu::reset(N);
    lowest.resize(N + 1);
    rep1(i, N) lowest[i] = i;
  }

  bool join(int u, int v) {
    int x = lowest[findp(u)], y = lowest[findp(v)];
    if (!dsu::join(u, v)) return false;
    if (depth[x] > depth[y]) swap(x, y);
    lowest[findp(u)] = x;
    return true;
  }

  int getLow(int u) {
    return lowest[findp(u)];
  }
};

dsu normDsu;
dsuWithLowest lowDsu;

int processQuery(int u, int v) {
  //clogi << u << ' ' << v << endl;
  int ans = 0;
  u = lowDsu.getLow(u);
  v = lowDsu.getLow(v);
  while (u != v) {
    while (depth[u] > depth[v] or (depth[u] == depth[v] and u != v)) {
      lowDsu.join(u, p[u]);
      u = lowDsu.getLow(p[u]);
      ++ans;
      //clogi << u << ' ' << v << endl;
    }
    swap(u, v);
  }
  return ans;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  normDsu.reset(n);
  lowDsu.reset(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
    normDsu.join(u, v);
  }

  vector<ii> preJoinList;
  vector<pair<llong, ii>> postJoinList;
  rep(i, k) {
    int u, v; llong c; cin >> u >> v >> c;
    if (normDsu.findp(u) == normDsu.findp(v)) 
      postJoinList.push_back({c, {u, v}});
    else {
      preJoinList.push_back({u, v});
      gr[u].push_back(v);
      gr[v].push_back(u);
      normDsu.join(u, v);
    }
  }

  p[1] = 1;
  depth[1] = 0;
  dfs(1);
  int nEdges = 0;
  llong ans = 0;
  
  for (auto i: preJoinList) {
    nEdges += processQuery(i.xx, i.yy);
  }

  for (auto i: postJoinList) {
    int x = processQuery(i.yy.xx, i.yy.yy);
    ans += x * i.xx;
    nEdges += x;
  }

  if (nEdges != n - 1) {
    cout << -1;
  } else cout << ans;

  return 0;
}