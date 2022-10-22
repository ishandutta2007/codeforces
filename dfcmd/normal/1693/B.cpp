#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> fa(n, -1);
    for (int i = 1; i < n; ++i) {
      std::cin >> fa[i];
      --fa[i];
    }
    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> l[i] >> r[i];
    }
    std::vector<long long> sum(n);
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (sum[i] < l[i]) {
        ++ans;
        sum[i] = r[i];
      } else {
        sum[i] = std::min<long long>(sum[i], r[i]);
      }
      if (fa[i] != -1) {
        sum[fa[i]] += sum[i];
      }
    }
    std::cout << ans << "\n";
  }
}