#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rll RE ll
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i != -1; i = edge[i].nxt)
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

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

const int N = 52;
const int L = 21;
char s[N][L];
long long msk[1 << L];
int n;
double dp[1 << L], ans;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i]);
  }
  
  int len = strlen(s[1]);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int same = 0;
      for (int k = 0; k < len; k++)
        if (s[i][k] == s[j][k])
          same |= 1 << k;
      msk[same] |= (1LL << i - 1) | (1LL << j - 1); 
    }
  }
  
  int all = 1 << len;
  for (int mask = all - 1; mask >= 0; mask--) {
    for (int i = 0; i < len; i++)
      if (mask & 1 << i)
        msk[mask ^ 1 << i] |= msk[mask];
  }
  
  dp[0] = 1;
  for (int mask = 0; mask < all; mask++) {
    int steps = len - __builtin_popcount(mask), one = __builtin_popcountll(msk[mask]);
    for (int i = 0; i < len; i++)
      if (!(mask & 1 << i)) {
        dp[mask ^ 1 << i] += dp[mask] / steps;
      }
    ans += dp[mask] * 1.0 * one;
  }
  printf("%.12lf\n", ans / 1.0 / n);
  return 0;
}