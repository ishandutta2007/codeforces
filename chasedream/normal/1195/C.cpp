%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 100005;
long long dp[N][3], n;
int a[N], b[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  
  dp[1][0] = 0; dp[1][1] = a[1], dp[1][2] =  b[1];

  for (int i = 2; i <= n; i++) {
    dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i];
    dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + b[i]; 
  }
  
  printf("%lld\n", max(dp[n][0], max(dp[n][1], dp[n][2])));
  return 0;
}