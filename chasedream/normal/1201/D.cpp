%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 1e6 + 5;
 
long long dp[2][N];
long long ans = 0LL;
 
int a[N];
int l[N], r[N];
int n, m, k, q;
 
void read() {
  for (int i = 0; i < N; i++) {
    l[i] = 1e9, r[i] = -1e9;
  }
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < k; i++) {
    int x, y; scanf("%d%d", &x, &y);
    x--, y--;
    l[x] = min(l[x], y); r[x] = max(r[x], y);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d", &a[i]); a[i]--;
  }
  sort(a, a + q);
}
 
bool ok(int p) {
  return p >= 0 && p < q;
}
 
void DP() {
  if (l[0] <= r[0]) {
    dp[0][0] = (r[0] - l[0]) + r[0];
    dp[1][0] = r[0];
    ans = min(dp[0][0], dp[1][0]);
  }
  else {
    l[0] = r[0] = 0;
    dp[0][0] = dp[1][0] = 0;
  }
  
  for (int i = 1; i < n; i++) {
    if (l[i] <= r[i]) {
      dp[0][i] = dp[1][i] = 1e18;
      for (int x = 0; x <= 1; x++) {
        for (int y = 0; y <= 1; y++) {
          int s, t;
          if (x) s = r[i]; else s = l[i];
          if (y) t = r[i - 1]; else t = l[i - 1];
          
          int j;
          // 1
          j = lower_bound(a, a + q, s) - a;
          if (ok(j) && a[j] <= t) {
            dp[x][i] = min(dp[x][i], dp[y][i - 1] + (t - s));
          }
          
          // 2
          j = lower_bound(a, a + q, t) - a;
          if (ok(j) && a[j] <= s) {
            dp[x][i] = min(dp[x][i], dp[y][i - 1] + (s - t));
          }
          
          // 3
          j = lower_bound(a, a + q, max(s, t)) - a;
          if (ok(j)) {
            dp[x][i] = min(dp[x][i], dp[y][i - 1] + (a[j] - s) + (a[j] - t));
          }
          
          // 4
          j = upper_bound(a, a + q, min(s, t)) - a - 1;
          if (ok(j)) {
            dp[x][i] = min(dp[x][i], dp[y][i - 1] + (s - a[j]) + (t - a[j]));
          }
        }
      }
      long long len = r[i] - l[i] + 1;
      dp[0][i] += (len);
      dp[1][i] += (len);
      
      //printf("dp[%d][%d] = %d\n", 0, i, dp[0][i]);
      //printf("dp[%d][%d] = %d\n", 1, i, dp[1][i]);
      
      ans = min(dp[0][i], dp[1][i]);
      swap(dp[0][i], dp[1][i]); 
    }
    else {
      l[i] = l[i - 1]; r[i] = r[i - 1];
      dp[0][i] = dp[0][i - 1] + 1;
      dp[1][i] = dp[1][i - 1] + 1;
    }
  }
}
 
int main() {
  read(); DP();
  printf("%lld\n", ans);
  return 0;
}