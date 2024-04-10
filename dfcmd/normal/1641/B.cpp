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
    std::map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      ++mp[a[i]];
    }
    bool ok = true;
    for (auto [v, c] : mp) {
      if (c & 1) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      std::cout << -1 << "\n";
      continue;
    }
    std::vector<std::pair<int, int>> ans;
    std::vector<int> seg;
    int now = 0;
    while (!a.empty()) {
      int p = 1;
      while (a[p] != a[0]) {
        ++p;
      }
      for (int i = 1; i < p; ++i) {
        ans.emplace_back(now + p + i, a[i]);
      }
      seg.push_back(2 * p);
      now += 2 * p;
      a.erase(a.begin() + p);
      a.erase(a.begin());
      std::reverse(a.begin(), a.begin() + p - 1);
    }
    std::cout << ans.size() << "\n";
    for (auto [p, v] : ans) {
      std::cout << p << " " << v << "\n";
    }
    std::cout << seg.size() << "\n";
    for (int x : seg) {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
}