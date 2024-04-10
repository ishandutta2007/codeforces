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

const int N = 100005;
int a[N], n, m;

void work() {
  read(n, m);
  for (int i = 1; i <= n; i++) {
    read(a[i]);
  }
  sort(a + 1, a + n + 1, greater <int> ());
  int now = -1e9, num = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == now) continue;
    if (a[i] <= num) break;
    ans++; num += m; now = a[i];
  }
  printf("%d\n", ans);
}

int main() {
  int T; read(T);
  while (T--) work(); 
  return 0;
}