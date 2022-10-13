#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

vector<int> val, comp, stk, cont;
int timer, ncomps;

template<class Graph, class Func>
int dfs(int node, Graph& G, Func f) {
  int low = val[node] = ++timer, x; stk.push_back(node);
  for (auto vec : G[node]) if (comp[vec] < 0)
    low = min(low, val[vec] ?: dfs(vec, G, f));
  
  if (low == val[node]) {
    do {
      x = stk.back(); stk.pop_back();
      comp[x] = ncomps;
      cont.push_back(x);
    } while (x != node);
    f(cont); cont.clear();
    ncomps++;
  }
  return val[node] = low;
}

template<class Graph, class Func>
void SCC(Graph& G, Func f) {
  int n = G.size();
  val.assign(n, 0); comp.assign(n, -1);
  timer = ncomps = 0;
  for (int i = 0; i < n; ++i)
    if (comp[i] < 0)
      dfs(i, G, f);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, h; cin >> n >> m >> h;
    vector<int> u(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i];
    }
    
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        if ((u[a] + 1) % h == u[b]) {
            G[a].push_back(b);
        }
        if ((u[b] + 1) % h == u[a]) {
            G[b].push_back(a);
        }
    } 
    
    vector<int> ans;
    SCC(G, [&](vector<int> nodes) {
        for (auto node : nodes) {
            for (auto vec : G[node]) {
                if (comp[vec] != comp[node])
                    return;
            }
        }
        if (ans.empty() or ans.size() > nodes.size()) {
            ans = nodes;
        }
    });
    cout << ans.size() << endl;
    for (auto x : ans) cout << x + 1 << " "; cout << endl;

    return 0;
}