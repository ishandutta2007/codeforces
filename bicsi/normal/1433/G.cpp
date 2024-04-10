#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  vector<vector<pair<int, int>>> graph(n);
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int a, b, c; cin >> a >> b >> c; --a; --b;
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, c);
    edges.emplace_back(a, b);
  }

  vector<int> a(k), b(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i] >> b[i]; --a[i]; --b[i];
  }
  
  auto dijkstra = [&](int src) {
    vector<int> ret(n, 1e9);
    priority_queue<pair<int, int>> q;
    auto push = [&](int node, int d) {
      if (ret[node] <= d) return;
      ret[node] = d;
      q.emplace(-d, node);
    };
    push(src, 0);
    while (q.size()) {
      auto [d, node] = q.top(); q.pop();
      if (ret[node] != -d) continue;
      for (auto [vec, c] : graph[node]) {
        push(vec, ret[node] + c);
      }
    }
    return ret;
  };

  vector<vector<int>> da(k), db(k);
  for (int i = 0; i < k; ++i) {
    da[i] = dijkstra(a[i]);
    db[i] = dijkstra(b[i]);
  }

  int best = 2e9;
  for (int i = 0; i < m; ++i) {
    auto [u, v] = edges[i];
    int total_dist = 0;
    for (int j = 0; j < k; ++j) {
      int dab = min({
        da[j][b[j]], 
        da[j][u] + db[j][v],
        da[j][v] + db[j][u],
      });
      total_dist += dab;
    }
    best = min(best, total_dist);
  }
  cout << best << '\n';

  return 0;
}