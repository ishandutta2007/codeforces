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

const int N = 505;
int a[N];
int n, ans, draw[N];

int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(a[i]);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (draw[i]) continue;
    ans++;
    for (int j = i + 1; j <= n; j++) {
      if (a[j] % a[i] == 0)
        draw[j] = 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}