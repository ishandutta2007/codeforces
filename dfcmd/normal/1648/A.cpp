#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }
  long long ans = 0;
  std::map<int, int> cnt;
  cnt.clear();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += 1ll * cnt[a[i][j]] * i;
      ++cnt[a[i][j]];
    }
  }
  cnt.clear();
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      ans += 1ll * cnt[a[i][j]] * j;
      ++cnt[a[i][j]];
    }
  }
  cnt.clear();
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      ans -= 1ll * cnt[a[i][j]] * i;
      ++cnt[a[i][j]];
    }
  }
  cnt.clear();
  for (int j = m - 1; j >= 0; --j) {
    for (int i = n - 1; i >= 0; --i) {
      ans -= 1ll * cnt[a[i][j]] * j;
      ++cnt[a[i][j]];
    }
  }
  std::cout << ans << "\n";
}