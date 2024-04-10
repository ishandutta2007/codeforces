#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 5e5 + 7;
int n, k, m, t[N];
bool use[N];
vector<pair<int, int>> g[N];
vector<int> me[N], no[N];

int root(int x) {
  if (t[x] == x) return x;
  return t[x] = root(t[x]);
}

void unite(int x, int y) {
  t[root(x)] = root(y);
}

void clr() {
  for (int i = 1; i <= n; i++) t[i] = i;
}

struct edge {
  int a, b, cost;
  bool use;
};

int dep[N], par[N], type[N];

void dfs(int a, int p = -1) {
  par[a] = p;
  for (auto &it : g[a]) {
    int b = it.first;
    if (b == p) continue;
    dep[b] = 1 + dep[a];
    type[b] = it.second;
    dfs(b, a);
  }
}

signed realMain() {
  cin >> n >> k >> m;
  clr();
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    unite(x, y);
    g[x].push_back({y, 1});
    g[y].push_back({x, 1});
  }
  vector<edge> edges(m);
  for (auto &it : edges) {
    cin >> it.a >> it.b >> it.cost;
    if (root(it.a) != root(it.b)) {
      it.use = 1;
      unite(it.a, it.b);
      g[it.a].push_back({it.b, 0});
      g[it.b].push_back({it.a, 0});
    }
  }
  dfs(1);
  clr();
  ll ret = 0, tot = 0;
  for (auto &it : edges) {
    if (it.use) continue;
    int x = root(it.a), y = root(it.b), c = it.cost;
    while (x != y) {
      if (dep[x] < dep[y]) swap(x, y);
      /// cobor pe x
      ret += type[x] * c;
      tot += type[x];
      unite(x, par[x]);
      x = root(x);
    }
  }
  if (tot != k) {
    cout << "-1\n";
    return 0;
  }
  cout << ret << "\n";
  return 0;
}