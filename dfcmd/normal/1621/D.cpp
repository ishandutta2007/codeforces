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
    std::vector<std::vector<int>> a(2 * n, std::vector<int>(2 * n));
    for (int i = 0; i < 2 * n; ++i) {
      for (int j = 0; j < 2 * n; ++j) {
        std::cin >> a[i][j];
      }
    }
    long long ans = std::min({
      a[0][n], a[0][2 * n - 1],
      a[n - 1][n], a[n - 1][2 * n - 1],
      a[n][0], a[n][n - 1],
      a[2 * n - 1][0], a[2 * n - 1][n - 1]
    });
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans += a[n + i][n + j];
      }
    }
    std::cout << ans << "\n";
  }
}