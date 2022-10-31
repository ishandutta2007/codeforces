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

char s[N];
int n;

struct Bit_tree {
  int c[N];
  #define lowbit(x) (x & -x)
  void add(int x, int id) {
    while (x <= n) {
      c[x] += id;
      x += lowbit(x);
    }
    return ;
  }
  int query(int x) {
    int res = 0;
    while (x > 0) {
      res += c[x];
      x -= lowbit(x);
    }
    return res;
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
} bit[26];

int main() {
  scanf("%s", s + 1); n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    s[i] -= 'a';
    bit[s[i]].add(i, 1);
  }
  int m; read(m);
  while (m--) {
    int opt; read(opt);
    if (opt == 1) {
      int pos; char c;
      scanf("%d %c", &pos, &c);
      c -= 'a';
      bit[s[pos]].add(pos, -1);
      bit[c].add(pos, 1);
      s[pos] = c;
    }
    else {
      int l, r; read(l, r);
      int ret = 0;
      for (int let = 0; let < 26; let++) {
        if (bit[let].query(l, r) > 0)
          ret++;
      }
      printf("%d\n", ret);
    }
  }
  return 0;
}