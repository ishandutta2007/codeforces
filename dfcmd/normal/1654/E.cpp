#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    --a[i];
  }
  int m = *std::max_element(a.begin(), a.end());

  int ans = 0;
  for (int k = 0; k < 2; ++k) {
    const int B = 350;

    std::vector<int> cnt(n * B + m + 1);
    for (int d = 0; d <= B; ++d) {
      for (int i = 0; i < n; ++i) {
        ans = std::max(ans, ++cnt[a[i] + i * d]);
      }
      for (int i = 0; i < n; ++i) {
        cnt[a[i] + i * d] = 0;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n && j <= i + B; ++j) {
        if (a[j] > a[i] && (a[j] - a[i]) % (j - i) == 0) {
          ans = std::max(ans, ++cnt[(a[j] - a[i]) / (j - i)] + 1);
        }
      }
      for (int j = i + 1; j < n && j <= i + B; ++j) {
        if (a[j] > a[i] && (a[j] - a[i]) % (j - i) == 0) {
          cnt[(a[j] - a[i]) / (j - i)] = 0;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      a[i] = m - a[i];
    }
  }
  std::cout << n - ans << "\n";
}