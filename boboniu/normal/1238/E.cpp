#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  string s;
  cin >> n >> m;
  cin >> s;
  vector<vector<int>> cnt(m, vector<int>(m, 0));
  vector<int> pc(1 << m, 0);
  vector<int> dp(1 << m, 0);
  for (int i = 1; i < n; i++) {
    int p = s[i] - 'a', q = s[i - 1] - 'a';
    cnt[p][q]++;
    cnt[q][p]++;
  }

  for (int mask = 1; mask < (1 << m); mask++) {
    int p = __builtin_ctz(mask);
    pc[mask] = pc[mask - (1 << p)];
    for (int q = 0; q < m; q++) {
      if (p == q) continue;
      if (mask & (1 << q)) {
        pc[mask] -= cnt[p][q];
      } else {
        pc[mask] += cnt[p][q];
      }
    }
    dp[mask] = 1 << 30;
    for (int q = 0; q < m; q++) {
      if (mask & (1 << q)) {
        dp[mask] = min(dp[mask], dp[mask - (1 << q)] + pc[mask]);
      }
    }
  }

  printf("%d\n", dp[(1 << m) - 1]);
  return 0;
}