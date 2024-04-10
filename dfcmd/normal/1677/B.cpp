#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::vector<bool> vis(m);
    std::vector<int> row(n * m);
    int now = 0, cnt = 0;
    for (int i = 0; i < n * m; ++i) {
      now += s[i] - '0';
      if (i < m) {
        row[i] = now > 0;
      } else {
        now -= s[i - m] - '0';
        row[i] = row[i - m] + (now > 0);
      }
      cnt -= vis[i % m];
      if (s[i] == '1') {
        vis[i % m] = true;
      }
      cnt += vis[i % m];
      std::cout << cnt + row[i] << " \n"[i + 1 == n * m];
    }
  }
}