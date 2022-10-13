#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m; cin >> n >> m;
  vector<set<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    --u; --v;
    graph[u].insert(v);
    graph[v].insert(u);
  }

  auto get = [&](int u) {
    if (graph[u].empty()) return 1;
    auto v = *prev(graph[u].end());
    if (v < u) return 1;
    return 0;
  };

  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans += get(i);

  int q; cin >> q;
  for (int i = 0; i < q; ++i) {
    int typ; cin >> typ;
    if (typ == 1) {
      int u, v; cin >> u >> v; --u; --v;
      ans -= get(u); ans -= get(v);
      graph[u].insert(v);
      graph[v].insert(u);
      ans += get(u); ans += get(v);
    }
    if (typ == 2) {
      int u, v; cin >> u >> v; --u; --v;
      ans -= get(u); ans -= get(v);
      graph[u].erase(v);
      graph[v].erase(u);
      ans += get(u); ans += get(v);
    }
    if (typ == 3) {
      cout << ans << '\n';
    }
  }

  return 0;
}