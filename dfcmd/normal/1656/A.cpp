#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::cout << std::min_element(a.begin(), a.end()) - a.begin() + 1 << " ";
    std::cout << std::max_element(a.begin(), a.end()) - a.begin() + 1 << "\n";
  }
}