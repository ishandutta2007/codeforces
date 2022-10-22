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
      --a[i];
    }
    std::vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
      ++cnt[a[i]];
    }
    int ansl = 0, ansr = n;
    for (int i = 0, j = 0, now = -n; i < n; ++i) {
      while (j < n && now < k) {
        now += 2 * cnt[j];
        ++j;
      }
      if (j - i < ansr - ansl && now >= k) {
        ansl = i, ansr = j;
      }
      now -= 2 * cnt[i];
    }
    std::cout << ansl + 1 << " " << ansr << "\n";
    for (int i = 0, j = 0, now = 0, p = 1; i < n; ++i) {
      now += ansl <= a[i] && a[i] < ansr ? 1 : -1;
      if (i == n - 1 || (now == p && p < k)) {
        std::cout << j + 1 << " " << i + 1 << "\n";
        j = i + 1;
        ++p;
      }
    }
  }
}