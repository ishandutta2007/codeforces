#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      --a[i];
    }
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
      --b[i];
    }

    std::vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
      ++cnt[b[i]];
    }
    int max = std::max_element(cnt.begin(), cnt.end()) - cnt.begin();
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n; ++i) {
      if (a[i] != max && b[i] != max) {
        E[a[i]].push_back(b[i]);
      }
    }

    std::vector<bool> vis(n), on(n);

    auto dfs = [&](auto &self, int u) -> bool {
      vis[u] = on[u] = true;
      for (int v : E[u]) {
        if (!vis[v]) {
          if (self(self, v)) {
            return true;
          }
        } else {
          if (on[v]) {
            return true;
          }
        }
      }
      on[u] = false;
      return false;
    };

    auto find_cycle = [&]() {
      for (int i = 0; i < n; ++i) {
        if (!vis[i] && dfs(dfs, i)) {
          return true;
        }
      }
      return false;
    };

    if (find_cycle()) {
      std::cout << "WA\n";
    } else {
      std::cout << "AC\n";
    }
  }
}