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
    std::vector<std::vector<int>> p(n + 1);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
      p[a[i]].push_back(i);
    }
    int now = 0;
    std::vector<int> res;
    while (now < n) {
      int lst = now;
      int x = 0;
      while (!p[x].empty()) {
        now = std::max(now, p[x].back());
        ++x;
      }
      ++now;
      res.push_back(x);
      for (int i = lst; i < now; ++i) {
        p[a[i]].pop_back();
      }
    }
    std::cout << res.size() << "\n";
    for (int x : res) {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
}