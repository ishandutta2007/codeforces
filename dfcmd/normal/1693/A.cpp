#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    long long sum = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      sum += x;
      ok &= sum >= 0;
      ok &= i == 0 || sum == 0 || sum - x > 0;
    }
    ok &= sum == 0;
    if (ok) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }
}