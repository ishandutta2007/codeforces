#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> E(n);
  std::vector<int> deg(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    E[v].push_back(u);
    ++deg[u];
  }
  std::priority_queue<std::pair<int, int>> Q;
  std::vector<int> dis(n, m);
  std::vector<bool> vis(n);
  dis[n - 1] = 0;
  Q.emplace(0, n - 1);
  while (!Q.empty()) {
    int u = Q.top().second;
    Q.pop();
    if (vis[u]) {
      continue;
    }
    vis[u] = true;
    for (int v : E[u]) {
      if (dis[u] + deg[v] < dis[v]) {
        dis[v] = dis[u] + deg[v];
        Q.emplace(-dis[v], v);
      }
      --deg[v];
    }
  }
  std::cout << dis[0] << "\n";
}