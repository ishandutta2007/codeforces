#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      --a[i];
    }
    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
      --b[i];
    }
    std::vector<int> cnt(n);
    bool ok = true;
    for (int i = 0, j = -1; i < n; ++i) {
      while (j == -1 || b[i] != a[j] || !cnt[a[j]]) {
        ++j;
        if (j == n) {
          ok = false;
          break;
        }
        ++cnt[a[j]];
      }
      if (!ok) {
        break;
      }
      --cnt[b[i]];
    }
    if (ok) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}