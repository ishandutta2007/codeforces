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

const int N = 1005;
int a[N][N];
int n, m;

bool check() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i][j] >= a[i][j + 1]) return 0;
    }
  } 
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i < n; i++) {
      if (a[i][j] >= a[i + 1][j]) return 0;
    }
  }
  return 1;
}

int main() {
  read(n, m);
  rep(i, 1, n) rep(j, 1, m) read(a[i][j]);
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (a[i][j] == 0)
        a[i][j] = min(a[i][j + 1], a[i + 1][j]) - 1;
    }
  }
  if (check() == 0) {
    puts("-1"); exit(0); 
  } 
  
  long long cnt = 0;
  rep(i, 1, n) rep(j, 1, m) cnt += a[i][j];
  printf("%lld\n", cnt);
  return 0;
}