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

int n, m;

void work() {
  read(n);
  int cnt1[2] = {0}, cnt2[2] = {0};
  for (int i = 1; i <= n; i++) {
    int x; read(x);
    cnt1[x % 2] ++;
  }
  read(m);
  for (int i = 1; i <= m; i++) {
    int x; read(x);
    cnt2[x % 2] ++;
  }
  printf("%lld\n", (ll)cnt1[0] * cnt2[0] + (ll)cnt1[1] * cnt2[1]);
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}