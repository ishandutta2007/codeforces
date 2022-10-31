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

const int N = 101;
const int del = 1000;

int a[N], b[N];
int f[50001], g[50001];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  } 
  
  memset(f, -0x3f, sizeof(f));
  memset(g, -0x3f, sizeof(g));
  f[0] = g[0] = 0;

  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    b[i] = a[i] - k * b[i];
    if (b[i] < 0) {
      b[i] = -b[i];
      for (int j = 50000; j >= b[i]; j--)
        f[j] = max(f[j], f[j - b[i]] + a[i]);
    }
    else {
      for (int j = 50000; j >= b[i]; j--)
        g[j] = max(g[j], g[j - b[i]] + a[i]);
    }
  }
  
  int ans = -1;
  for (int i = 0; i <= 50000; i++) {
    if (f[i] == 0 && g[i] == 0) continue;
    ans = max(ans, f[i] + g[i]);
  }
  printf("%d\n", ans);
  return 0;
}