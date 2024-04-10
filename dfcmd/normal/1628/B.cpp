#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    bool flag = false;
    std::set<std::string> S, T;
    for (int i = 0; i < n; ++i) {
      std::string s;
      std::cin >> s;
      flag |= s.front() == s.back();
      if (s.size() >= 2) {
        S.insert(s), T.insert(s.substr(0, 2));
        std::reverse(s.begin(), s.end());
        flag |= S.count(s);
        flag |= T.count(s);
        flag |= S.count(s.substr(0, 2));
      }
    }
    if (flag) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}