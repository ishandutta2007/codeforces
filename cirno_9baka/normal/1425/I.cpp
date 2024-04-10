#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define isNum(a) (a >= '0' && a <= '9')
#define SP putchar(' ')
#define EL putchar('\n')
#define File(a) freopen(a ".in", "r", stdin), freopen(a ".out", "w", stdout)

template <class T> void read(T &);
template <class T> void write(const T &);

typedef long long ll;
typedef unsigned long long ull;
typedef const long long &cll;
typedef const int &ci;
typedef std::pair<int, int> pii;
const int iinf = 2147483647;
const ll llinf = 9223372036854775807ll;
using std::abs;
using std::max;
using std::min;

const int N = 50005;
const int M = 50005;

void add(int u, int v);
void dfs(int u);

int hed[N], nxt[M], to[M], id;
int dep[N];
int dfn[N], tot, qwq[N];
int l[N], r[N];
int a[N];
int sum[N];
int dsum[N];
int tim[N];
int n, q;

int main() {
  read(n), read(q);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    if (a[i] == 1) {
      sum[i] = 1;
    }
  }
  for (int i = 2; i <= n; ++i) {
    int fa;
    read(fa);
    add(fa, i);
  }
  dfs(1);
  for (register int i = 1; i <= q; ++i) {
    int u;
    read(u);
    int ans1 = sum[u];
    int ans2 = dsum[u];
    for (register int j = l[u]; j <= r[u]; ++j) {
      int v = qwq[j];
      if (i >= tim[v]) {
        ++ans1;
        ans2 += dep[v];
        tim[v] = i + a[v];
      }
    }
    ans2 -= ans1 * dep[u];
    write(ans2), SP, write(ans1), EL;
  }
  return 0;
}

template <class T> inline void read(T &Re) {
  T k = 0;
  char ch = getchar();
  int flag = 1;
  while (!isNum(ch)) {
    if (ch == '-') {
      flag = -1;
    }
    ch = getchar();
  }
  while (isNum(ch)) {
    k = (k << 1) + (k << 3) + ch - '0';
    ch = getchar();
  }
  Re = flag * k;
}
template <class T> inline void write(const T &Wr) {
  if (Wr < 0) {
    putchar('-');
    write(-Wr);
  } else {
    if (Wr < 10) {
      putchar(Wr + '0');
    } else {
      write(Wr / 10);
      putchar((Wr % 10) + '0');
    }
  }
}

void add(int u, int v) {
  nxt[++id] = hed[u];
  hed[u] = id;
  to[id] = v;
}
void dfs(int u) {
  l[u] = tot + 1;
  if (sum[u] == 1) {
    dsum[u] = dep[u];
  } else {
    dfn[u] = ++tot;
    qwq[tot] = u;
  }
  for (int i = hed[u]; i; i = nxt[i]) {
    int v = to[i];
    dep[v] = dep[u] + 1;
    dfs(v);
    sum[u] += sum[v];
    dsum[u] += dsum[v];
  }
  r[u] = tot;
}