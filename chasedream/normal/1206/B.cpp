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

const int N = 100005;

long long dis[N][2], dp[N][2];
int a[N], n;

int Abs(int k) { return k > 0 ? k : -k; } 
int main() {
  read(n);
  rep(i, 1, n) {
    read(a[i]);
    dis[i][0] = Abs(a[i] + 1); // a[i] -> -1
    dis[i][1] = Abs(a[i] - 1); // a[i] -> 1
  }
  
  memset(dp, 0x7f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = min(dp[i - 1][0] + dis[i][1], dp[i - 1][1] + dis[i][0]);
    dp[i][1] = min(dp[i - 1][0] + dis[i][0], dp[i - 1][1] + dis[i][1]);
  }
  printf("%lld\n", dp[n][0]);
  return 0;
}