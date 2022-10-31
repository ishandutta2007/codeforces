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

char get_ch() {
  for (;;) {
    char op = getchar();
    if (op >= 'a' && op <= 'z' || op >= 'A' && op <= 'Z')
      return op;
  }
}

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

#define IT set <node> :: iterator

struct node {
  int l, r;
  mutable bool v;
  node (int l = 0, int r = 0, int v = 0):
    l(l), r(r), v(v) {}
  bool operator < (const node &b) const {
    return l < b.l;
  }
};
set <node> s;
int sum = 0;

IT split(int pos) {
  IT it = s.lower_bound(node(pos));
  if (it != s.end() && it -> l == pos)
    return it;
  it--;
  
  int l = it -> l, r = it -> r, v = it -> v;
  s.erase(it); s.insert(node(l, pos - 1, v));
  return s.insert(node(pos, r, v)).first; 
}

void assign(int l, int r, int val) {
  IT itr = split(r + 1), itl = split(l);
  for (IT it = itl; it != itr; it++) {
    sum -= it -> v * (it -> r - it -> l + 1);
  } 
  s.erase(itl, itr);
  s.insert(node(l, r, val));
  sum += val * (r - l + 1);
  return ;
}

int n, m;

int main() {
  read(n, m);
  s.insert(node(1, n, 1));
  sum = n;
  while (m--) {
    int op, l, r;
    read(l, r, op);
    if (op == 1) {
      assign(l, r, 0);
    }
    else {
      assign(l, r, 1);
    }
    printf("%d\n", sum);
  }  
  return 0;
}