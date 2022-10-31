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

const int N = 200005;

long long dp[N][2];
int p[N];
int n, a, b;

void work() {
  read(n, a, b);
  rep(i, 1, n) scanf("%1d", &p[i]);
  rep(i, 1, n) rep(j, 0, 1) dp[i][j] = 1e15;
  dp[1][0] = a + 2 * b;
  rep(i, 2, n) {
    dp[i][1] = min(dp[i - 1][1] + 2 * b + a, dp[i - 1][0] + 3 * b + 2 * a);
    if (!p[i]) dp[i][0] = min(dp[i - 1][0] + b + a, dp[i - 1][1] + b + 2 * a);
    //printf("%lld %lld\n", dp[i][0], dp[i][1]);
  }
  printf("%lld\n", dp[n][0]);
  return ;
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}