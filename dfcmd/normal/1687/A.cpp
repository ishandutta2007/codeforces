#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::vector<long long> sum(n + 1);
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + a[i];
    }
    if (k >= n) {
      std::cout << sum[n] + 1ll * k * n - 1ll * n * (n + 1) / 2 << "\n";
      continue;
    }
    long long ans = 0;
    for (int i = k; i <= n; ++i) {
      ans = std::max(ans, sum[i] - sum[i - k] + 1ll * k * (k - 1) / 2);
    }
    std::cout << ans << "\n";
  }
}