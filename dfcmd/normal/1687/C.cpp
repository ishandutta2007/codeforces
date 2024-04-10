#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
    }
    std::vector<std::vector<int>> E(n + 1);
    for (int i = 0; i < m; ++i) {
      int l, r;
      std::cin >> l >> r;
      --l;
      E[l].push_back(r);
      E[r].push_back(l);
    }
    std::vector<long long> sum(n + 1);
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + a[i] - b[i];
    }
    if (sum[n] != 0) {
      std::cout << "NO\n";
      continue;
    }

    std::vector<int> fa(n + 2);
    fa[n + 1] = n + 1;
    for (int i = 0; i <= n; ++i) {
      fa[i] = sum[i] ? i : i + 1;
    }

    auto check = [&](int x) {
      return fa[x] != x;
    };

    std::function<int(int)> find = [&](int x) {
      return fa[x] == x ? x : (fa[x] = find(fa[x]));
    };

    std::vector<std::pair<int, int>> Q;
    for (int u = 0; u <= n; ++u) {
      for (int v : E[u]) {
        if (check(u) && check(v)) {
          Q.emplace_back(u, v);
        }
      }
    }
    for (int k = 0; k < (int)Q.size(); ++k) {
      auto [l, r] = Q[k];
      if (l > r) {
        std::swap(l, r);
      }
      std::vector<int> cand;
      for (int x = find(l); x < r; x = find(x)) {
        fa[x] = x + 1;
        cand.push_back(x);
      }
      for (int u : cand) {
        for (int v : E[u]) {
          if (check(u) && check(v)) {
            Q.emplace_back(u, v);
          }
        }
      }
    }
    if (find(0) == n + 1) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}