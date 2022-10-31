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

const int N = 300005;

struct node {
  int id;
  basic_string <int> d;
  bool operator < (const node &b) const {
    return d < b.d;
  }
} s[N];

int fa[N], n, m;

int main() {
  read(n, m);
  for (int i = 1; i <= n; i++) {
    s[i].id = i;
  }  
  for (int i = 1; i <= m; i++) {
    int x, y; read(x, y);
    s[x].d += y; s[y].d += x;
  }
  for (int i = 1; i <= n; i++) {
    sort(s[i].d.begin(), s[i].d.end());
  }
  sort(s + 1, s + n + 1);
  if (s[1].d.size() == 0) { //  
    puts("-1"); exit(0);
  }
  
  int cnt = 0;
  for (int i = 1, j = 0; i <= n; i = j + 1) {
    cnt++;
    while (j < n && s[j + 1].d == s[i].d) {
      fa[s[j + 1].id] = cnt;
      j++;
    }
  }
  
  if (cnt != 3) {
    puts("-1");
  }
  else {
    for (int i = 1; i <= n; i++) {
      printf("%d ", fa[i]);
    }
    putchar('\n');
  }
  return 0;
}