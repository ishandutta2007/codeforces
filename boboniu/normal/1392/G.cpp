#include <bits/stdc++.h>
using namespace std;
#define maxN 222222

int n, m, k;
int p[33];
char s[33], t[33];
int dp[(1 << 20) + 1], tmp[(1 << 20) + 1], val[(1 << 20) + 1];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s", s);
  scanf("%s", t);
  for (int i = 0; i < k; i++)
    p[i] = i;
  memset(dp, 0x10, sizeof(dp));
  int ds = 0;
  for (int i = 0; i < k; i++)
    ds += (s[i] - '0') << i;
  dp[ds] = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    swap(p[a], p[b]);
    ds = 0;
    for (int i = 0; i < k; i++)
      ds += (s[i] - '0') << p[i];
    dp[ds] = min(dp[ds], i + 1);
    ds = 0;
    for (int i = 0; i < k; i++)
      ds += (t[i] - '0') << p[i];
    val[i + 1] = ds;
  }
  for (int c = 0; c <= k; c++) {
    for (int i = 1; i <= n; i++) {
      if (dp[val[i]] <= i - m) {
        printf("%d\n%d %d\n", k - c, dp[val[i]] + 1, i);
        return 0;
      }
    }
    for (int i = 0; i < (1 << k); i++) {
      tmp[i] = dp[i];
      for (int j = 0; j < k; j++)
        tmp[i] = min(tmp[i], dp[i ^ (1 << j)]);
    }
    for (int i = 0; i < (1 << k); i++)
      dp[i] = tmp[i];
  }
  assert(0);
}