#include <bits/stdc++.h>

const unsigned INF = std::numeric_limits<unsigned>::max() / 2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    if (k > (n + 1) / 2) {
      std::cout << -1 << '\n';
      continue;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j && !(i & 1) && i / 2 < k) {
          std::cout << 'R';
        } else {
          std::cout << '.';
        }
      }
      std::cout << '\n';
    }
  }
}