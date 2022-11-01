%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 2002;
const ll mod = 1e9 + 7;
 
int a[N][N];
int read() {
  for (;;) {
    char op = getchar();
    if (op == 'B' || op == 'W') {
      return op == 'B';
    }
  } 
}
 
int row[N][N];
int col[N][N];
int ok1[N][N];
int ok2[N][N];
int sum1[N][N];
int sum2[N][N];
int dp[N][N];
 
int n, k;
int ans, cnt;
 
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = read();
    }
  } 
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      row[i][j] = row[i][j - 1] + a[i][j];
    if (!row[i][n]) cnt++;
  } 
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++)
      col[i][j] = col[i - 1][j] + a[i][j];
    if (!col[n][j]) cnt++; 
  }
  
  for (int i = 1; i <= n; i++) {
    if (!row[i][n]) continue;
    for (int j = 1; j <= n; j++) {
      if (row[i][min(n, j + k - 1)] - row[i][j - 1] == row[i][n])
        ok1[i][j] = 1;
      else
        ok1[i][j] = 0;
    }
  }
  
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++)
      sum1[i][j] = sum1[i - 1][j] + ok1[i][j]; 
  }
  
  /*
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      printf("%d ", ok1[i][j]);
    putchar('\n');
  } 
  putchar('\n');
  */
  
  for (int j = 1; j <= n; j++) {
    if (!col[n][j]) continue;
    for (int i = 1; i <= n; i++) {
      if (col[min(n, i + k - 1)][j] - col[i - 1][j] == col[n][j])
        ok2[i][j] = 1;
      else 
        ok2[i][j] = 0;
    } 
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      sum2[i][j] = sum2[i][j - 1] + ok2[i][j];
  }
  
  /*
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      printf("%d ", ok2[i][j]);
    putchar('\n');
  }
  */
  
  for (int i = 1; i <= n - k + 1; i++) {
    for (int j = 1; j <= n - k + 1; j++) {
      dp[i][j] = (sum1[i + k - 1][j] - sum1[i - 1][j]) + (sum2[i][j + k - 1] - sum2[i][j - 1]);
      ans = max(ans, dp[i][j]);
    } 
  }
  printf("%d\n", ans + cnt);
  return 0;
}