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

const int T = 20;
const int N = 1000005;
char s[N]; int n;
int dp[1 << T];
int ans = 0;

int main() {
  scanf("%s", s + 1); n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    int st = 0;
    for (int j = 0; i + j <= n; j++) {
      int ch = s[i + j] - 'a';
      if (st & 1 << ch) break;
      st |= 1 << ch;
      dp[st] = j + 1;
    }
    //printf("dp[%d] = %d\n", st, dp[st]);
  }
  
  for (int i = 0; i < 1 << T; i++) {
    for (int j = 0; j < T; j++) {
      if (i & 1 << j)
        dp[i] = max(dp[i], dp[i ^ 1 << j]);
    }
  }
  
  for (int i = 0; i < 1 << T; i++) {
    ans = max(ans, dp[i] + dp[(1 << T) - 1 - i]);
  }
  printf("%d\n", ans);
  return 0;
}