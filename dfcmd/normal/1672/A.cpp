#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      s ^= (x - 1) & 1;
    }
    if (s) {
      std::cout << "errorgorn\n";
    } else {
      std::cout << "maomao90\n";
    }
  }
}