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

const int N = 501;
int dp[N][N], mod;
int n, m, b;

int main() {
  scanf("%d%d%d%d", &n, &m, &b, &mod);
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int x; scanf("%d", &x);
    for (int j = 1; j <= m; j++) {
      for (int k = x; k <= b; k++)
        dp[j][k] = (dp[j][k] + dp[j - 1][k - x]) % mod;
    }
  }
  
  int ans = 0;
  for (int i = 0; i <= b; i++) {
    ans = (ans + dp[m][i]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}