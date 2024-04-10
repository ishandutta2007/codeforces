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

const int N = 5000004;
char s[N];
int dp[N], cnt[26][26], n, m;

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  for (int i = 1; i < n; i++) {
    cnt[s[i] - 'a'][s[i + 1] - 'a']++;
    cnt[s[i + 1] - 'a'][s[i] - 'a']++;
  }
  for (int i = 0; i < m; i++) cnt[i][i] = 0;
  
  memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
  int all = 1 << m;
  for (int s = 0; s < all; s++) {
    int one = __builtin_popcount(s);
    for (int i = 0; i < m; i++) {
      if (s & 1 << i) continue;
      int sum = 0;
      for (int j = 0; j < m; j++) {
        if (s & 1 << j) sum += cnt[i][j] * one;
        else sum -= cnt[i][j] * one;
      }
      ckmin(dp[s | 1 << i], dp[s] + sum);
    }
  }
  printf("%d\n", dp[all - 1]);
  return 0;
}