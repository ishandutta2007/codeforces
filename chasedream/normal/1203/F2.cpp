%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 105;
 
struct ele {
  int a, b;
  bool operator < (const ele& b) const {
    return a < b.a;
  }
} a[N], b[N];
 
int dp[N][N];
 
bool cmp(ele a, ele b) {
  int sum1 = a.a + a.b;
  int sum2 = b.a + b.b;
  return sum1 > sum2;
}
 
int n, r;
 
void Pro() {
  puts("debug");
  // 
}
 
void DPDP() {
  memset(dp, -63, sizeof(dp));
  dp[0][0] = r;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = r;
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];
      if (dp[i - 1][j - 1] >= a[i].a && dp[i - 1][j - 1] + a[i].b >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i].b);
      }
    }
  }
}
 
int main() {
  scanf("%d%d", &n, &r);
  for (int i = 1; i <= n; i++) { 
    scanf("%d%d", &a[i].a, &a[i].b);
  } 
  
  int ans = 0;
  while (true) {
    int pos = 0;
    sort(a + 1, a + n + 1);
    int pp = upper_bound(a + 1, a + n + 1, (ele){r, 0}) - a - 1;
    bool ok = 0;
    
    for (int i = 1; i <= pp; i++) {
      if (a[i].b >= 0) {
        r += a[i].b;
        ans++; ok = 1; 
      }
      else {
        b[++pos] = a[i];
      }
    }
    
    if (!ok) break;
    for (int i = pp + 1; i <= n; i++) {
      b[++pos] = a[i];
    }
    n = pos;
    for (int i = 1; i <= n; i++) {
      a[i] = b[i];
    }
  }
  
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].a <= r) {
      b[++pos] = a[i];
    }
  }
  
  n = pos;
  for (int i = 1; i <= n; i++) {
    a[i] = b[i];
  }
  
  sort(a + 1, a + n + 1, cmp);
  
  DPDP();
  
  
  int ans2 = 0;
  for (int i = n; i >= 1; i--) {
    if (dp[n][i] >= 0)
      ans2 = max(ans2, i);
  }
  printf("%d\n", ans + ans2);
  return 0;
}