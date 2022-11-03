#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;

int dp[4002], C[4002][4002];

void add(int &r, int a) {
  r += a;
  if (r >= mod)
    r -= mod;
}

int main() {
  int n;
  cin >> n; //n = 4000;
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      if (C[i][j] >= mod)
        C[i][j] -= mod;
    }
  }

  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int sz = 1; i + sz <= n; ++sz) {
      int mult = C[i + sz - 1][sz - 1];
      // cout << sz << " " << mult << endl;
      // if (sz == 1) {
      //   add(dp[i + sz][w], 1LL * dp[i][w] * mult % mod);
      //   add(dp[i + sz][1], 1LL * dp[i][w] * mult % mod);
      // } else {
      add(dp[i + sz], 1LL * dp[i] * mult % mod);
      // }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    add(ans, 1LL * C[n][i] * dp[n - i] % mod);
    // cout << dp[n - i] << endl;
  }
  cout << ans << endl;
  return 0;
}