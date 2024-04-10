#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 1; j <= m; j++) {
        a[i][j] = s[j - 1] - '0';
      }
    }
    struct Info {
      vector<int> x;
      vector<int> y;
    };
    vector<Info> ans;
    auto go = [&](int x, int y, int p) -> void {
      const int dx[4] = {0, 0, 1, 1};
      const int dy[4] = {0, 1, 0, 1};
      int nx = x + dx[p];
      int ny = y + dy[p];
      Info info;
      for (int i = x; i <= x + 1; i++) {
        for (int j = y; j <= y + 1; j++) {
          if (i == nx && j == ny) {
            continue;
          }
          a[i][j] ^= 1;
          info.x.push_back(i);
          info.y.push_back(j);
        }
      }
      ans.push_back(info);
    };
    for (int i = 1; i <= n - 2; i++) {
      for (int j = 1; j + 1 <= m; j += 2) {
        int value = a[i][j] * 2 + a[i][j + 1];
        if (value == 1) {
          go(i, j, 0);
        } else if (value == 2) {
          go(i, j, 1);
        } else if (value == 3) {
          go(i, j, 2);
        }
      }
      if (m & 1) {
        if (a[i][m] == 1) {
          go(i, m - 1, 0);
        }
      }
      for (int j = 1; j <= m; j++) {
        assert(a[i][j] == 0);
      }
    }
    for (int j = 1; j + 1 <= m; j++) {
      int value = a[n - 1][j] * 2 + a[n][j];
      if (value == 1) {
        go(n - 1, j, 0);
      } else if (value == 2) {
        go(n - 1, j, 2);
      } else if (value == 3) {
        go(n - 1, j, 1);
      }
      for (int i = n - 1; i <= n; i++) {
        assert(a[i][j] == 0);
      }
    }
    int value = a[n - 1][m] * 2 + a[n][m];
    if (value == 1) {
      go(n - 1, m - 1, 1);
      go(n - 1, m - 1, 2);
      go(n - 1, m - 1, 0);
    } else if (value == 2) {
      go(n - 1, m - 1, 0);
      go(n - 1, m - 1, 3);
      go(n - 1, m - 1, 2);
    } else if (value == 3) {
      go(n - 1, m - 1, 1);
      go(n - 1, m - 1, 3);
    }
    for (int i = n - 1; i <= n; i++) {
      for (int j = m - 1; j <= m; j++) {
        assert(a[i][j] == 0);
      }
    }
    cout << ans.size() << "\n";
    for (auto info: ans) {
      for (int i = 0; i < 3; i++) {
        cout << info.x[i] << " " << info.y[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}