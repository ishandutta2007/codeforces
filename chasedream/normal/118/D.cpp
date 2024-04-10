#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...); 
}

const int mod = 100000000;
int dp[101][101][11][11];
int n1, n2, k1, k2;

int main() {
  scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
  for (int i = 1; i <= k1; i++) {
    dp[i][0][i][0] = 1;
  } 
  for (int i = 1; i <= k2; i++) {
    dp[0][i][i][1] = 1;
  }
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      for (int p = 1; p <= min(j, k2); p++)
        (dp[i][j][1][0] += dp[i - 1][j][p][1]) %= mod; 
      for (int p = 1; p <= min(i, k1); p++)
        (dp[i][j][1][1] += dp[i][j - 1][p][0]) %= mod;
      for (int p = 2; p <= min(i, k1); p++)
        dp[i][j][p][0] = dp[i - 1][j][p - 1][0];
      for (int p = 2; p <= min(j, k2); p++)
        dp[i][j][p][1] = dp[i][j - 1][p - 1][1];
    }
  }
  
  int ans = 0;
  for (int p = 1; p <= min(n1, k1); p++) {
    (ans += dp[n1][n2][p][0]) %= mod;
  }
  for (int p = 1; p <= min(n2, k2); p++) {
    (ans += dp[n1][n2][p][1]) %= mod;
  }
  printf("%d\n", ans);
  return 0;
}