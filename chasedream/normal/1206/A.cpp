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

int a[1005], b[1005];
int vis[100005];
int n, m;

int main() {
  scanf("%d", &n);
  rep(i, 1, n) {
    scanf("%d", &a[i]);
    vis[a[i]] = 1;
  }
  scanf("%d", &m);
  rep(i, 1, m) {
    scanf("%d", &b[i]);
    vis[b[i]] = 1;
  }
  rep(i, 1, n) rep(j, 1, m) {
    if (!vis[a[i] + b[j]]) {
      printf("%d %d\n", a[i], b[j]);
      exit(0);
    }
  }
  return 0;
}