#include <bits/stdc++.h>

using namespace std;

int main() {
  string a, b; cin >> a >> b;
  int n = a.size();

  auto ok = [&](int pos, int i) {
    if (i < 0 || i >= b.size()) return true;
    return b[i] == a[pos];
  };

  const int kMod = 998244353;

  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      int pos = j - i;
      if (pos >= n) continue;
      if (i == j) {
        if (ok(pos, i)) dp[i][i] = 2;
      } else {
        if (ok(pos, i)) dp[i][j] = (dp[i][j] + dp[i + 1][j]) % kMod;
        if (ok(pos, j)) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % kMod;
      }
    }
  }
  
  int ans = 0;
  for (int i = b.size() - 1; i < n; ++i) {
    ans = (ans + dp[0][i]) % kMod;
  }
  cout << ans << endl;

  return 0;
}