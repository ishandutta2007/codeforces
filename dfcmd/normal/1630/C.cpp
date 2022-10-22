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
  std::vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    r[a[i]] = i;
  }
  int p = 0;
  int now = 0;
  int ans = n;
  while (p < n) {
    int max = now;
    for (int i = p; i <= now; ++i) {
      max = std::max(max, r[a[i]]);
    }
    --ans;
    if (max == now) {
      p = now + 1;
      now = now + 1;
    } else {
      p = now;
      now = max;
    }
  }
  std::cout << ans << "\n";
}