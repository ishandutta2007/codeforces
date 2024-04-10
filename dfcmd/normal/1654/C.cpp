#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::map<int, int> S;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      sum += x;
      ++S[x];
    }
    long long now = sum;
    long long cnt[2] = {1, 0};
    int rem = n;
    while (true) {
      for (int k = 0; k < 2; ++k) {
        if (S.count(now + k)) {
          int t = std::min<long long>(cnt[k], S[now + k]);
          S[now + k] -= t;
          cnt[k] -= t;
          rem -= t;
        }
      }
      if (!now) {
        break;
      }
      long long ncnt[2] = {};
      if (now & 1) {
        ncnt[0] = cnt[0];
        ncnt[1] = cnt[0] + 2 * cnt[1];
      } else {
        ncnt[0] = 2 * cnt[0] + cnt[1];
        ncnt[1] = cnt[1];
      }
      cnt[0] = ncnt[0];
      cnt[1] = ncnt[1];
      now /= 2;
    }
    if (!rem) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}