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

int a, b, c;

int main() {
  int T; read(T);
  while (T--) {
    read(a, b, c);
    int tmp = min(min(a, b), c);
    int ans = tmp; a -= tmp, b -= tmp;
    ans += min(min(a, b), (a + b) / 3);
    printf("%d\n", ans);
  }
  return 0;
}