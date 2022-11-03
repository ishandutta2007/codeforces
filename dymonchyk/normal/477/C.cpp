#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char s[2002], p[505];

int fn[2002];

int dp[2002][2002];

int main() {
  gets(s); gets(p);
  int n = strlen(s), m = strlen(p);
  for (int i = 0; i < n; ++i) {
    int ptr = i - 1;
    for (int j = 0; j < m && ptr < n; ++j) {
      ++ptr;
      while (ptr < n && s[ptr] != p[j]) ++ptr;
      // cout << ptr << endl;
    }
    fn[i] = ptr;
    // cout << ptr << endl;
  }
  memset(dp, -1, sizeof(dp));
  dp[n][0] = 0;
  for (int i = n - 1; i >= 0; --i) {
    for (int x = 0; x <= n; ++x)
      dp[i][x + 1] = dp[i + 1][x];
    for (int x = 0; x <= n; ++x)
      dp[i][x] = max(dp[i][x], dp[i + 1][x]);
    for (int j = 0; j <= n - i; ++j)
      dp[i][j] = max(dp[i][j], 0);
    for (int x = 0; x <= n - i; ++x) {
      int sub = fn[i] - i + 1 - m;
      if (x >= sub && fn[i] != n && dp[fn[i] + 1][x - sub] != -1)
        dp[i][x] = max(dp[i][x], dp[fn[i] + 1][x - sub] + 1);
    }
    // for (int j = 0; j <= n; ++j)
    //   cout << dp[i][j] << " ";
    // cout << endl;
  }
  for (int x = 0; x <= n; ++x)
    cout << dp[0][x] << " ";
  cout << endl;
  return 0;
}