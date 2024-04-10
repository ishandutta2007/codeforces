#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
const int LG = 19;

int uf[N];
void setup() {
  memset(uf, -1, sizeof uf);
}
int FIND(int u) {
  if (uf[u] == -1) return u;
  return uf[u] = FIND(uf[u]);
}
bool UNION(int u, int v) {
  if (FIND(u) == FIND(v)) {
    return false;
  }
  uf[FIND(u)] = FIND(v);
  return true;
}

int n, m;

const int INF = 0x3f3f3f3f;
int par[N][LG];
int mnw[N][LG];
int h[N];
void build() {
  for (int l=0; l<LG-1; ++l) {
    for (int i=1; i<=n; ++i) {
      par[i][l+1] = par[par[i][l]][l];
      mnw[i][l+1] = min(mnw[i][l], mnw[par[i][l]][l]);
    }
    //cerr << " mnw[2][" << l << "] = " << mnw[2][l] << endl;
  }
}
pair<int, int> swim(int u, int x) {
  int ans = INF;
  for (int i=0; x; x/=2, i++) {
    if (x&1) {
      ans = min(ans, mnw[u][i]);
      u = par[u][i];
    }
  }
  return {u, ans};
}
pair<int, int> lca(int u, int v) {
  if (h[v] < h[u]) {
    swap(u, v);
  }
  auto [vnew, ans] = swim(v, h[v]-h[u]);
  //cerr << " base " << u << "/" << v << " " << ans << endl;
  for (int l=LG-1; l>=0; --l) {
    if (par[u][l] != par[v][l]) {
      ans = min(ans, mnw[u][l]);
      ans = min(ans, mnw[v][l]);
      u = par[u][l];
      v = par[v][l];
    }
  }
  if (u != v) {
    ans = min(ans, mnw[u][0]);
    ans = min(ans, mnw[v][0]);
    u = par[u][0];
    v = par[v][0];
  }
  assert(u == v);
  return {u, ans};
}

vector<pair<int, int>> adj[N];

void dfs(int u, int p, int d) {
  h[u] = d;
  for (auto& [v, w] : adj[u]) {
    if (v == p) continue;
    dfs(v, u, d+1);
    par[v][0] = u;
    mnw[v][0] = w;
  }
}

void solve_mst() {
  int mtrx[1000][1000];
  assert(n < 950);
  memset(mtrx, 0, sizeof mtrx);
  int xv = 0;
  for (int i=1; i<=m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    mtrx[u][v] = mtrx[v][u] = w;
    xv ^= w;
  }
  vector<tuple<int, int, int>> edges;
  for (int i=1; i<=n; ++i) {
    for (int j=i+1; j<=n; ++j) {
      edges.push_back({mtrx[i][j], i, j});
    }
  }
  setup();
  sort(edges.begin(), edges.end());
  ll ans = 0;
  int unused_zero = 0;
  int zcount = 0;
  vector<tuple<int, int, int>> unused;
  for (auto& [w, u, v] : edges) {
    if (w == 0) {
      zcount++;
    }
    if (UNION(u, v)) {
      ans += w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    } else if (w == 0) {
      ++unused_zero;
    } else {
      unused.push_back({w, u, v});
    }
  }
  if (unused_zero || !zcount || xv == 0) {
    cout << ans << "\n";
    return;
  }
  memset(mnw, INF, sizeof mnw);
  dfs(1, 0, 1);
  build();
  ll best = ans + xv;
  for (auto& [w, u, v] : unused) {
    auto [x, z] = lca(u, v);
    //cerr << " u -> v : " << w << " z " << z << endl;
    if (z == 0) {
      best = min(best, ans + w);
    }
  }
  cout << best << "\n";
}

set<int> bdj[N];
set<int> avail;
bool seen[N];

void checker(int u) {
  if (seen[u]) return;
  seen[u] =1;
  vector<int> nbrs;
  avail.erase(u);
  for (auto it = avail.begin(); it != avail.end();) {
    int v = *it++;
    if (!bdj[u].count(v)) {
      nbrs.push_back(v);
      UNION(u, v);
      avail.erase(prev(it));
    }
  }
  for (auto& x : nbrs) {
    checker(x);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  if ((ll) n*(n-1)/2 - m < n+1) { // number of zero edges could be <= n-1 (forest)
    solve_mst();
    return 0;
  }

  vector<tuple<int, int, int>> edges;
  for (int i=1; i<=m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, u, v});
    bdj[u].insert(v);
    bdj[v].insert(u);
  }

  setup();
  for (int i=1; i<=n; ++i) {
    avail.insert(i);
  }
  for (int i=1; i<=n; ++i) {
    checker(i);
  }

  sort(edges.begin(), edges.end());
  ll ans = 0;
  for (auto& [w, u, v] : edges) {
    if (UNION(u, v)) {
      ans += w;
    }
  }
  cout << ans << "\n";

  return 0;
}