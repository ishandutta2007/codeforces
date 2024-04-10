#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  long long ans = std::numeric_limits<long long>::max();
  for (int i = 0; i < n; ++i) {
    long long now = 0;
    long long sum = 0;
    for (int j = i + 1; j < n; ++j) {
      sum += now / a[j] + 1;
      now = (now / a[j] + 1) * a[j];
    }
    now = 0;
    for (int j = i - 1; j >= 0; --j) {
      sum += now / a[j] + 1;
      now = (now / a[j] + 1) * a[j];
    }
    ans = std::min(ans, sum);
  }
  std::cout << ans << "\n";
}