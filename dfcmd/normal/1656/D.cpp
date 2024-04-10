#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    long long n;
    std::cin >> n;
    long long p = 1;
    long long q = n;
    while (q % 2 == 0) {
      p *= 2;
      q /= 2;
    }
    if (q == 1) {
      std::cout << -1 << "\n";
    } else if (q < 2 * p) {
      std::cout << q << "\n";
    } else {
      std::cout << 2 * p << "\n";
    }
  }
}