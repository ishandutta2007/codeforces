#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;
  std::string s;
  std::cin >> s;

  auto check = [&](int i) {
    return 0 <= i && i + 2 < n && s.substr(i, 3) == "abc";
  };

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += check(i);
  }

  while (q--) {
    int p;
    std::cin >> p;
    --p;
    ans -= check(p - 2);
    ans -= check(p - 1);
    ans -= check(p);
    std::cin >> s[p];
    ans += check(p - 2);
    ans += check(p - 1);
    ans += check(p);
    std::cout << ans << "\n";
  }
}