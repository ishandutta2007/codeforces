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

const int N = 1005;
int s[N], sum[N], d[N];
int n, m, jump;

int l[N], r[N];

int main() {
  scanf("%d%d%d", &n, &m, &jump);
  int x = 0;
  for (int i = 1; i <= m; i++) {
    x += jump; int _x; scanf("%d", &_x);
    s[i] = _x; sum[i] = sum[i - 1] + s[i];
    x += _x - 1;
  }  
  if (x + jump <= n) {
    puts("NO");
    exit(0);
  }
  
  int lst = n + 1;
  for (int i = m; i >= 1; i--) {
    if (sum[i] + jump < lst) {
      for (int j = lst - jump; j >= lst - jump - s[i] + 1; j--)
        d[j] = i;
      r[i] = lst - jump, l[i] = lst - jump - s[i] + 1; 
      lst = lst - jump - s[i] + 1;
    }
    else {
      int di = lst - sum[i];
      for (int j = lst - di; j >= lst - di - s[i] + 1; j--)
        d[j] = i;
      r[i] = lst - di, l[i] = lst - di - s[i] + 1;
      lst = sum[i - 1];
    }
  }
  
  puts("YES");
  for (int i = 1; i <= n; i++)
    printf("%d ", d[i]);
  putchar('\n');
}