#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i > 0; i = edge[i].nxt)
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

const int N = 300005;
const long long inf = 1e18;
ll dp[N][3];
int a[N], c[N], n;

void work() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(a[i], c[i]);
    dp[i][0] = dp[i][1] = dp[i][2] = inf;
  }
  a[0] = -1e9, dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2; j++) {
      for (int k = 0; k <= 2; k++) {
        if (a[i] + j != a[i - 1] + k)
          dp[i][j] = min(dp[i][j], dp[i - 1][k] + (ll)j * c[i]);
      } 
    }
  }
  long long ans = inf;
  for (int i = 0; i <= 2; i++)
    ans = min(ans, dp[n][i]);
  printf("%lld\n", ans);
  return ; 
} 

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}