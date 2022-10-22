/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
int n, q, nxt[maxn];
set<int> rs[maxn];

int fin(int u) {
  if (nxt[u] == u)
    return u;
  return nxt[u] = fin(nxt[u]);
}

void uni(int u, int v) {
  u = fin(u), v = fin(v);
  if (u == v)
    return;
  nxt[u] = v;
  if (rs[u].size() < rs[v].size()) {
    for (auto i : rs[u])
      rs[v].insert(i);
    rs[u].clear();
  } else {
    for (auto i : rs[v])
      rs[u].insert(i);
    rs[v].clear();
    rs[v].swap(rs[u]);
  }
}

void query(int x) {
  if (nxt[x] != x) {
    puts("NO");
    return;
  }
  auto it = rs[x].lower_bound(x);
  if (it == rs[x].end()) {
    puts("N/A");
    return;
  }
  int rb = x == n ? n : fin(x + 1) - 1;
  if (*it <= rb) {
    puts("YES");
    return;
  }
  puts("N/A");
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n + 1; i++) {
    nxt[i] = i;
  }
  for (int i = 1; i <= q; i++) {
    int fl, l, r, x;
    scanf("%d", &fl);
    if (fl == 0) {
      scanf("%d%d%d", &l, &r, &x);
      if (!x) {
        for (int j = l; fin(j) <= r; j = fin(j)) {
          uni(j, fin(j) + 1);
        }
      } else {
        rs[fin(l)].insert(r);
      }
    } else {
      scanf("%d", &x);
      query(x);
    }
  }
  return 0;
}