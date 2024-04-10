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

const int N = 1000005;
int a[N];
ll k, n;

int main() {
  scanf("%lld%lld", &n, &k);
  if (n * (n + 1) / 2 > k) {
    puts("-1"); exit(0);
  }
  long long sum = n * (n + 1) / 2;
  for (int i = 0; i <= n; i++) a[i] = i;
  ll del = k - sum;
  for (int i = n; i >= n / 2 + 1; i--) {
    if (i - (n + 1 - i) <= del) {
      del -= i - (n + 1 - i);
      swap(a[i], a[n + 1 - i]);
    }
    else {
      int pos = i - del;
      //printf("%d\n", pos);
      swap(a[i], a[pos]); del = 0;
      break;
    }
  }
  
  printf("%lld\n", k - del);
  for (int i = 1; i <= n; i++) printf("%d ", i);    putchar('\n');
  for (int i = 1; i <= n; i++) printf("%d ", a[i]); putchar('\n');
  return 0;
}