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

#define int long long

ll sum[N], a[N];
int n, k;

bool check(int x) {
  for (int i = 1, j = 1; i <= n; i++) {
    while (j <= n && a[j] <= a[i] + x) j++;
    if (a[i] * (i - 1) - sum[i - 1] + sum[n] - sum[j - 1] - (a[i] + x) * (n - j + 1) <= k)
      return 1;
  }
  for (int i = 1, j = 1; i <= n; i++) {
    while (j <= n && a[j] < a[i] - x) j++;
    if ((a[i] - x) * (j - 1) - sum[j - 1] + sum[n] - sum[i] - a[i] * (n - i) <= k)
      return 1;
  }
  return 0;
}

signed main() {
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  int l = 0, r = a[n] - a[1];
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  printf("%lld\n", l);
  return 0;
}