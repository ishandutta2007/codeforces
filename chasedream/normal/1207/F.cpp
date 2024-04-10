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

const int N = 500005;

long long p[1000][1000];
int a[N], block, n;
int q;

int main() {
  read(q); n = 500000; block = sqrt(n);
  while (q--) {
    int opt, l, r; read(opt, l, r);
    if (opt == 1) {
      a[l] += r;
      for (int i = 1; i <= block; i++)
        p[i][l % i] += r;
    }
    else {
      if (l <= block) {
        printf("%lld\n", p[l][r]);
      }
      else {
        ll ans = 0LL;
        for (int i = (r == 0 ? r + l : r); i <= n; i += l) {
          ans += a[i];
        }
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}