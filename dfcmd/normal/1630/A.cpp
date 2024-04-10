#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    int U = n - 1;
    std::vector<int> a(n / 2), b(n / 2);
    for (int i = 0; i < n / 2; ++i) {
      a[i] = i, b[i] = U ^ i;
    }
    if (k < U) {
      for (int i = 0; i < n / 2; ++i) {
        if (a[i] == k) {
          std::swap(a[i], a[0]);
        }
        if (b[i] == k) {
          std::swap(b[i], a[0]);
        }
      }
    } else if (n >= 8) {
      std::swap(a[0], b[1]);
      std::swap(b[3], a[1]);
    } else {
      std::cout << -1 << "\n";
      continue;
    }
    for (int i = 0; i < n / 2; ++i) {
      std::cout << a[i] << " " << b[i] << "\n";
    }
  }
}