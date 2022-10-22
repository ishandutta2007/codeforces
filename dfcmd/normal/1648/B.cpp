#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> cnt(m + 1);
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      ++cnt[x];
    }
    auto sum(cnt);
    sum.push_back(0);
    for (int i = m; i >= 1; --i) {
      sum[i] += sum[i + 1];
    }
    bool ok = true;
    for (int i = 1; i <= m && ok; ++i) {
      if (cnt[i]) {
        for (int j = i; j <= m && ok; j += i) {
          if (sum[j] - sum[std::min(j + i, m + 1)]) {
            if (!cnt[j / i]) {
              ok = false;
            }
          }
        }
      }
    }
    std::cout << (ok ? "Yes\n" : "No\n");
  }
}