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
#define pci pair <char, int>
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

const int N = 200005;
const ll inf = 2e9;
ll a[N], b[N];
int n, m;

int main() {
  read(n, m);
  for (int i = 1; i <= n; i++) {
    read(a[i]); 
  }
  for (int i = 1; i <= m; i++) {
    read(b[i]);
  }
  b[0] = -5 * inf, b[++m] = 5 * inf;
  
  ll r = 0;
  int k = 1;
  for (int i = 1; i <= n; i++) {
    while (k <= m && b[k] < a[i]) k++;
    r = max(r, min(b[k] - a[i], a[i] - b[k - 1]));
  }
  printf("%lld\n", r);
  return 0;
}