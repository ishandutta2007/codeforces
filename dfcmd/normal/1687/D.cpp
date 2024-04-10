#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  auto safe_sqrt = [&](long long x) {
    long long t = sqrt(x);
    while (t * t > x) {
      --t;
    }
    while ((t + 1) * (t + 1) <= x) {
      ++t;
    }
    return t;
  };
  
  auto check = [&](long long k) {
    if (k < 0) {
      return false;
    }
    long long t = safe_sqrt(a[0] + k);
    while (true) {
      int p = std::upper_bound(a.begin(), a.end(), t * (t + 1) - k) - a.begin();
      if (p == n) {
        return true;
      }
      if (a[p] + k < (t + 1) * (t + 1)) {
        return false;
      }
      ++t;
    }
    return false;
  };

  if (check(0)) {
    std::cout << 0 << "\n";
    return 0;
  }
  long long ans = 4e12;
  for (int i = 0; i < n; ++i) {
    int lim = 2e6;
    if (i > 0) {
      lim = a[i] - a[i - 1] + 1;
    }
    for (int t = 1; t <= lim; ++t) {
      long long k = 1ll * t * t - a[i];
      if (check(k)) {
        ans = std::min(ans, k);
        break;
      }
    }
  }
  std::cout << ans << "\n";
}