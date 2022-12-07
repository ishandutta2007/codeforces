#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int n,m;
  cin >> n >> m;
  vector<set<int>> g(n);
  vector<int> p(n), indeg(n);
  for (int i =0; i < n; i++)
    cin >> p[i];
  for (int i =0; i < m; i++) {
    int u,v;
    cin >> u >> v;
    u--,v--;
    g[u].insert(v);
    indeg[v]++;
  }


  // Normalize p
  {
    vector<int> vis(n);
    auto norm = [&](auto& self, int s)->void {
      vis[s] = 1;
      for (auto& u : g[s]) {
        if (!vis[u]) self(self, u);
        p[s] = min(p[s], p[u] - 1);
      }
    };
    for (int i =0; i <n; i++){
      if (!vis[i]) norm(norm, i);
    }
  }

  // Find reachability
  vector<vector<int>> reachable(n, vector<int>(n));
  for (int v =0; v < n; v++) {
    auto dfs = [&](auto& self, int s) -> void {
      reachable[v][s] = 1;
      for (auto& u : g[s]) {
        if (reachable[v][u]) continue;
        self(self, u);
      }
    };
    dfs(dfs, v);
  }


  vector<int> valid;
  set<pii> open;
  for (int i =0; i < n;i++) {
    if (!indeg[i]) {
      open.insert({p[i], i});
    }
  }
  while(open.size()) {
    auto [pv, v] = *open.begin();
    open.erase(open.begin());
    assert(pv > valid.size());
    valid.push_back(v);
    for (auto& u : g[v]) {
      indeg[u]--;
      if (!indeg[u]) {
        open.insert({p[u], u});
      }
    }
  }

  vector<int> ans(n, -1);
  for (int v = 0; v < n; v++){
    int pos = 0;
    for (; pos < n; pos++) {
      if (valid[pos] == v) break;
    }
    int sz = 1;
    while(pos != 0) {
      int prv = valid[pos-1];
      if (pos -1 + sz >= p[prv]) break;
      if (reachable[prv][v]) sz++;
      pos--;
    }
    ans[v] = pos + sz-1;
  }
  for (auto& x : ans) cout << x+1 << " ";
}