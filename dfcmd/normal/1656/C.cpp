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
    bool ex1 = false;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      ex1 |= a[i] == 1;
    }
    std::sort(a.begin(), a.end());
    bool ex2 = false;
    for (int i = 1; i < n; ++i) {
      ex2 |= a[i] - a[i - 1] == 1;
    }
    if (ex1 && ex2) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
}