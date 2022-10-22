#include <bits/stdc++.h>

constexpr long long INF = std::numeric_limits<long long>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    long long K = 0, B = 0;
    for (int i = 1; i < n; ++i) {
      K += a[0] + a[i];
      B += a[0] * a[i];
    }
    long long ans = -INF;
    for (int i = 0; i + 1 < n; ++i) {
      if (i > 0) {
        K -= a[0] + a[i];
        B -= a[0] * a[i];
        K += a[n - 1] + a[i];
        B += a[n - 1] * a[i];
      }
      if (i == 0 && K > 0) {
        ans = INF;
      }
      if (i + 2 == n && K < 0) {
        ans = INF;
      }
      ans = std::max(ans, -K * a[i] + B);
      ans = std::max(ans, -K * a[i + 1] + B);
    }
    if (ans == INF) {
      std::cout << "INF\n";
    } else {
      std::cout << ans << "\n";
    }
  }
}