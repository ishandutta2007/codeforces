#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 200005;

struct node {
  int x, id;
  bool operator < (const node &b) const {
    return x < b.x;
  }
} s[N];
ll f[N], dp[N];
int ans[N], n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i].x);
    s[i].id = i;
  }
  sort(s + 1, s + n + 1);
  int id = 0;
  dp[1] = dp[2] = 1e18;
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[id] - s[id + 1].x + s[i].x, f[i] = id;
    if (dp[i - 2] - s[i - 1].x < dp[id] - s[id + 1].x)
      id = i - 2;
  }
  printf("%d ", dp[n]);
  id = n; int times = 0;
  while (id != 0) {
    int idd = f[id];
    times++;
    for (int i = id; i > idd; i--) ans[s[i].id] = times;
    id = idd;
  }
  printf("%d\n", times);
  for (int i = 1; i<= n; i++) {
    printf("%d ", ans[i]);
  }
  return putchar('\n') & 0;
}