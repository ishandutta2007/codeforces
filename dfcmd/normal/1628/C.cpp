#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cin >> a[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (i & 1) {
        int t = std::min(i, n - i - 1);
        int x = i - t, y = n - i - 1 - t;
        int p = 0;
        while (x < n && y < n) {
          p ^= 1;
          if (p) {
            ans ^= a[x][y] ^ a[x][n - y - 1];
          }
          ++x, ++y;
        }
      }
    }
    std::cout << ans << "\n";
  }
}