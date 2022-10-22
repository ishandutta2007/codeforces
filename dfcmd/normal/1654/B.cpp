#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> cnt(26);
    for (int i = 0; i < n; ++i) {
      ++cnt[s[i] - 'a'];
    }
    int p = 0;
    while (p < n) {
      if (--cnt[s[p] - 'a'] == 0) {
        break;
      }
      ++p;
    }
    std::cout << s.substr(p) << "\n";
  }
}