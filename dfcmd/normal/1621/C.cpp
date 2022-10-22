#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> p(n, -1);

    auto query = [&](int x) {
      std::cout << "? " << x + 1 << std::endl;
      int res;
      std::cin >> res;
      --res;
      return res;
    };

    for (int i = 0; i < n; ++i) {
      if (p[i] == -1) {
        std::vector<int> c;
        while (1) {
          int t = query(i);
          if (c.empty() || t != c[0]) {
            c.push_back(t);
          } else {
            break;
          }
        }
        for (int j = 0; j < (int)c.size(); ++j) {
          p[c[j]] = c[(j + 1) % c.size()];
        }
      }
    }
    std::cout << "!";
    for (int i = 0; i < n; ++i) {
      std::cout << " " << p[i] + 1;
    }
    std::cout << std::endl;
  }
}