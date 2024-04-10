#include <bits/stdc++.h>

const int N = 1000000;

bool is_prime[N + 1];

void init() {
  for (int i = 2; i <= N; ++i) {
    is_prime[i] = true;
  }
  for (int i = 2; i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i + i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  init();

  int T;
  std::cin >> T;
  while (T--) {
    int n, e;
    std::cin >> n >> e;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    
    std::vector<int> len(n);
    for (int i = n - 1; i >= 0; --i) {
      len[i] = a[i] > 1 ? 0 : (i + e < n ? len[i + e] : 0) + 1;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int p = i + len[i] * e;
      if (p < n && is_prime[a[p]]) {
        ans += (p + e < n ? len[p + e] : 0) + (p > i);
      }
    }
    std::cout << ans << "\n";
  }
}