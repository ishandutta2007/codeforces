// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rint register int 
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = (x << 3) + (x << 1) + op - '0'; op = getchar(); }
  return neg * x;
}

const int N = 1005;
int a[N], n, m;

int main() {
  int T = read();
  while (T--) {
    n = read(), m = read();
    long long ans = 0ll;
    for (rint i = 1; i <= n; i++) {
      a[i] = read();
      ans += 2 * a[i];
    }
    if (n != m || n == 2) {
      puts("-1");
    }
    else {
      printf("%d\n", ans);
      for (rint i = 1; i <= n; i++) {
        if (i == n) printf("%d 1\n", n);
        else printf("%d %d\n", i, i + 1);
      }
    }
  }
  return 0;
}