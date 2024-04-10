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
    std::sort(a.begin(), a.end());
    bool ok = false;
    for (int i = 0; i < n; ++i) {
      ok |= std::binary_search(a.begin(), a.end(), a[i] + k);
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }
}