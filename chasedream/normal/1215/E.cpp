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

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

const int M = 500000;
int cnt[20], a[M];
ll w[20][20], f[1 << 21];
int n, mask, m;

int main() {
  n = 20, mask = 1 << n;
  read(m);
  for (int i = 0; i < m; i++) {
    read(a[i]); a[i]--;
    cnt[a[i]]++;
    for (int j = 0; j < n; j++)
      w[j][a[i]] += cnt[j]; 
  }  
  for (int i = 1; i < mask; i++) {
    f[i] = 1e18;
    for (int u = 0; u < n; u++) {
      if (i & (1 << u)) {
        int j = i ^ (1 << u);
        ll nval = 0LL;
        for (int v = 0; v < n; v++)
          if (j & (1 << v))
            nval += w[u][v];
        f[i] = min(f[i], f[j] + nval);
      }
    }
  }
  
  printf("%lld\n", f[mask - 1]);
  return 0;
}