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

const int maxN = 2005;
ll a[maxN][maxN], sum[maxN][maxN], ans;
pii id;
int N, n, m, k;

int main() {
  read(n, m, k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x; read(x);
      a[i + j - 1][i - j + m] = x;
    }
  }  
  N = n + m - 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++)
      sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
  }
  for (int i = k; i <= n - k + 1; i++) {
    for (int j = k; j <= m - k + 1; j++) {
      ll tar = 0;
      int x = i + j - 1, y = i - j + m;
      for (int _k = 0; _k < k; _k++) {
        tar += sum[x + _k][y + _k] - 
               sum[x - _k - 1][y + _k] - 
               sum[x + _k][y - _k - 1] + 
               sum[x - _k - 1][y - _k - 1];
      }
      if (tar >= ans)
        ans = tar, id = mp(i, j);
    }
  }
  printf("%d %d\n", id.fi, id.se);
  return 0;
}