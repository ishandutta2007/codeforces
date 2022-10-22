#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> p[i];
    }
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
      int c = 0;
      for (int j = 0; j < i; ++j) {
        a[i][j] = c;
        c += p[j] < p[i];
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int c = 0;
      for (int j = n - 1; j > i; --j) {
        ans += a[j][i] * c;
        c += p[j] < p[i];
      }
    }
    std::cout << ans << "\n";
  }
}