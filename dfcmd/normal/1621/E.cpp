#include <bits/stdc++.h>

const unsigned INF = std::numeric_limits<unsigned>::max() / 2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    std::vector<std::vector<int>> b(m);
    std::vector<long long> sum(m);
    std::vector<int> avg(m);
    for (int i = 0; i < m; ++i) {
      int k;
      std::cin >> k;
      b[i].resize(k);
      for (int j = 0; j < k; ++j) {
        std::cin >> b[i][j];
        sum[i] += b[i][j];
      }
      avg[i] = (sum[i] - 1) / k + 1;
    }

    std::vector<int> id(m);
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int i, int j) {
      return avg[i] < avg[j];
    });
    std::vector<int> rk(m);
    for (int i = 0; i < m; ++i) {
      rk[id[i]] = i;
    }
    std::vector<std::array<int, 3>> pre(m + 1);
    for (int i = 0; i < m; ++i) {
      int p = std::lower_bound(a.begin(), a.end(), avg[id[i]]) - a.begin();
      for (int d = -1; d <= 1; ++d) {
        pre[i + 1][d + 1] = pre[i][d + 1] + (n - p + d >= m - i);
      }
    }

    auto query = [&](int d, int l, int r) {
      return pre[r][d + 1] - pre[l][d + 1];
    };

    for (int i = 0; i < m; ++i) {
      int k = b[i].size();
      int r = rk[i];
      for (int x : b[i]) {
        int n_avg = (sum[i] - x - 1) / (k - 1) + 1;
        int p = std::lower_bound(a.begin(), a.end(), n_avg) - a.begin();
        int l = std::lower_bound(id.begin(), id.end(), n_avg,
                [&](int i, int v) {
                  return avg[i] < v;
                }) - id.begin();
        if (l <= r) {
          if (query(0, 0, l) + query(1, l, r) + query(0, r + 1, m)
              + (n - p >= m - l) == m) {
            std::cout << '1';
          } else {
            std::cout << '0';
          }
        } else {
          if (query(0, 0, r) + query(-1, r + 1, l) + query(0, l, m)
              + (n - p >= m - l + 1) == m) {
            std::cout << '1';
          } else {
            std::cout << '0';
          }
        }
      }
    }
    std::cout << "\n";
  }
}