#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      std::cin >> u >> v;
      --u, --v;
      E[u].push_back(v);
      E[v].push_back(u);
    }

    std::vector<int> dep(n);

    auto dfs = [&](auto &self, int u, int fa) -> void {
      for (int v : E[u]) {
        if (v != fa) {
          dep[v] = dep[u] + 1;
          self(self, v, u);
        }
      }
    };

    dfs(dfs, 0, -1);
    for (int i = 0; i < n; ++i) {
      int d = E[i].size();
      if (dep[i] & 1) {
        std::cout << -d << " ";
      } else {
        std::cout << d << " ";
      }
    }
    std::cout << "\n";
  }
}