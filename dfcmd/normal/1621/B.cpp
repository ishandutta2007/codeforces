#include <bits/stdc++.h>

const unsigned INF = std::numeric_limits<unsigned>::max() / 2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    unsigned min = INF, max = 0;
    unsigned L = INF, R = INF, LR = INF;
    for (int i = 0; i < n; ++i) {
      unsigned l, r, c;
      std::cin >> l >> r >> c;
      if (l < min) {
        min = l;
        L = c;
        LR = INF;
      }
      if (r > max) {
        max = r;
        R = c;
        LR = INF;
      }
      if (l == min) {
        L = std::min(L, c);
      }
      if (r == max) {
        R = std::min(R, c);
      }
      if (l == min && r == max) {
        LR = std::min(LR, c);
      }
      std::cout << std::min(L + R, LR) << "\n";
    }
  }
}