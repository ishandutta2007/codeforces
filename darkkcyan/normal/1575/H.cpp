#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

vector<int> prefix_function(string s) {
  int n = (int) s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
  return pi;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  vector<int> pi = prefix_function(b);
  b = "#" + b;
  pi.insert(pi.begin(), 0);
  vector<vector<int>> go(m + 1, vector<int>(2, -1));
  function<int(int, int)> go_c = [&](int i, int j) {
    if (go[i][j] != -1) {
      return go[i][j];
    }
    if (i + 1 < (int) a.size() && b[i + 1] == j + '0') {
      return go[i][j] = i + 1;
    } else if (i == 0) {
      return go[i][j] = 0;
    } else {
      return go[i][j] = go_c(pi[i], j);
    }
  };

  vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 2, vector<int>(n + 2, n + 100)));
  a = "#" + a;
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      for (int k = n; k >= 0; k--) {
//        dp[0][pi[j]][k] = min(dp[0][pi[j]][k], dp[0][j][k]);
        int c = a[i] - '0';
        if (j != m) {
          int v = go_c(j, c);
          if (v == m) {
            dp[1][pi[v]][k + 1] = min(dp[1][pi[v]][k + 1], dp[0][j][k]);
          } else {
            dp[1][v][k] = min(dp[1][go_c(j, c)][k], dp[0][j][k]);
          }
          c = 1 - c;
          v = go_c(j, c);
          if (v == m) {
            dp[1][pi[v]][k + 1] = min(dp[1][pi[v]][k + 1], dp[0][j][k] + 1);
          } else {
            dp[1][v][k] = min(dp[1][go_c(j, c)][k], dp[0][j][k] + 1);
          }
        }
      }
    }
    swap(dp[0], dp[1]);
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= n; k++) {
        dp[1][j][k] = n + 100;
      }
    }
  }

  for (int k = 0; k < n - m + 2; k++) {
    int res = n + 100;
    for (int j = 0; j < m; j++) {
      res = min(res, dp[0][j][k]);
    }
    if (res == n + 100) {
      cout << "-1 ";
    } else {
      cout << res << " ";
    }
  }

  return 0;
}