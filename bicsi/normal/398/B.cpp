#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m; cin >> n >> m;

  vector<vector<double>> dp(n + 1, vector<double>(n + 1));
  for (int i = n; i >= 0; --i) {
    for (int j = n; j >= 0; --j) {
      dp[i][j] = 0;
      if (i == n && j == n) {
        dp[i][j] = 0;
        continue;
      }
      
      double sum = 0;
      if (j < n) sum += dp[i][j + 1] * i * (n - j);
      if (i < n) sum += dp[i + 1][j] * j * (n - i);
      if (i < n && j < n)
        sum += dp[i + 1][j + 1] * (n - i) * (n - j);
      sum /= n * n;
      sum += 1.;
      sum /= (1.0 - 1.0 * i * j / n / n);
      dp[i][j] = sum;
    }
  }

  set<int> a, b;
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    a.insert(x); b.insert(y);
  }
  cout << fixed << setprecision(20) << dp[a.size()][b.size()] << endl;

  return 0;
}