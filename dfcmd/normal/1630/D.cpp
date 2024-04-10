#include <bits/stdc++.h>

template<typename T>
constexpr T INF = std::numeric_limits<T>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    int g = 0;
    for (int i = 0; i < m; ++i) {
      int v;
      std::cin >> v;
      g = std::gcd(g, v);
    }
    long long ans = -INF<long long>;
    for (int k = 0; k < 2; ++k) {
      long long sum = 0;
      for (int i = 0; i < g; ++i) {
        int mn = INF<int>;
        int sgn = 0;
        for (int j = i; j < n; j += g) {
          sum += std::abs(a[j]);
          mn = std::min(mn, std::abs(a[j]));
          sgn ^= a[j] < 0;
        }
        if (sgn != k) {
          sum -= 2 * mn;
        }
      }
      ans = std::max(ans, sum);
    }
    std::cout << ans << "\n";
  }
}