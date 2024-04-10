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
    
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> graph(n);
        for (int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b; --a; --b;
            graph[a].push_back(b);
        }
        int ccs = 0;
        vector<int> cats, judges;
        SCC(graph, [&](vector<int> nodes) {
            if (ccs == 0) {
                for (auto x : nodes)
                    judges.push_back(x);
            } else {
                for (auto x : nodes)
                    cats.push_back(x);
            }
            ccs += 1;        
        });
        
        if (ccs == 1) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            sort(judges.begin(), judges.end());
            sort(cats.begin(), cats.end());
            cout << judges.size() << " " << cats.size() << '\n';
            for (auto x : judges) cout << x + 1 << " "; cout << '\n';
            for (auto x : cats) cout << x + 1 << " "; cout << '\n';
        }
    }
    return 0;
}