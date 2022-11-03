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

void add(int &r, int a) {
  r += a;
  if (r >= mod) r -= mod;
}

int dp[202][202][1002];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
  }
  sort(v.begin(), v.end());

  dp[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int open = 0; open <= n / 2 + 1; ++open) {
      for (int s = 0; s <= k; ++s) {
        if (!dp[i][open][s]) continue;
        // cout << i << "  " << open << "  " << s << ": " << dp[i][open][s] << endl;
        int len = i == 0 ? 0 : (v[i] - v[i - 1]);
        if (s + len * open <= k)
          add(dp[i + 1][open + 1][s + len * open], dp[i][open][s]);
        if (s + len * open <= k && open)
          add(dp[i + 1][open - 1][s + len * open], 1LL * open * dp[i][open][s] % mod);
        if (s + len * open <= k)
          add(dp[i + 1][open][s + len * open], dp[i][open][s]);
        if (s + len * open <= k)
          add(dp[i + 1][open][s + len * open], 1LL * open * dp[i][open][s] % mod);
      }
    }
  }

  int ans = 0;
  for (int j = 0; j <= k; ++j) {
    add(ans, dp[n][0][j]);
  }

  printf("%d\n", ans);
  return 0;
}