#include <bits/stdc++.h>
using namespace std;
bool Mbe;

using ll = long long;
#define int ll
using tii = tuple<int, int>;
#define mt(arg...) make_tuple(arg)
#define X(x) get<0>(x)
#define Y(x) get<1>(x)
using vi = vector<int>; using vii = vector<tii>;
#define pb(arg...) emplace_back(arg)
#define sz(x) ((int)(x).size())
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define per(i, r, l) for(int i = (r); i >= (l); --i)
template<class T1, class T2> void cmx(T1 &x, const T2 &y) { if(y > x) x = y; }
template<class T1, class T2> void cmn(T1 &x, const T2 &y) { if(y < x) x = y; }
const int inf = sizeof(int) == 4 ? 0x3f3f3f3fll : 0x3f3f3f3f3f3f3f3fll;

char gc() { return getchar(); } void pc(char x) { putchar(x); }
template<class T = int> T rd() {
  T x = 0; char c = gc(); bool ne = false;
  while(!isdigit(c)) ne |= c == '-', c = gc();
  while(isdigit(c)) x = 10 * x + (c ^ 48), c = gc();
  return ne ? -x : x;
}
template<class T> void prt(T x) {
  x < 0 && (pc('-'), x = -x);
  x > 9 && (prt(x / 10), 0);
  pc(x % 10 ^ 48);
}

const int N = 1e5 + 10;

int n;
vii E[N];
int rt, dis[N];

void mian() {
  n = rd();
  rep(i, 1, n - 1) { int x = rd(), y = rd(), z = rd(); E[x].pb(y, z), E[y].pb(x, z); }
  {
    function<void(int, int*, int)> dfs = [&](int x, int *d, int fa) {
      for(tii e : E[x]) if(X(e) != fa) {
        d[X(e)] = d[x] + Y(e);
        dfs(X(e), d, x);
      }
    };
    static int d[N], du[N], dv[N];
    dfs(1, d, 0);
    int u = max_element(d + 1, d + n + 1) - d;
    dfs(u, du, 0);
    int v = max_element(du + 1, du + n + 1) - du;
    dfs(v, dv, 0);
    rep(i, 1, n) dis[i] = max(du[i], dv[i]);
    rt = min_element(dis + 1, dis + n + 1) - dis;
  }
  int qu = rd(); while(qu--) {
    int L = rd();
    static int stk[N], d[N], fa[N]; int top = 0;
    memset(d, 0, sizeof(d));
    function<void(int)> dfs = [&](int x) {
      stk[++top] = x;
      int fd = top;
      per(i, 32 - __builtin_clz(top), 0) if(fd > 1 << i && dis[stk[fd - (1 << i)]] >= dis[x] - L) fd -= 1 << i;
      ++d[x], --d[fa[stk[fd]]];
      for(tii e : E[x]) if(X(e) != fa[x]) fa[X(e)] = x, dfs(X(e));
      --top;
    };
    dfs(rt);
    int ans = 0;
    function<void(int)> dfs0 = [&](int x) {
      for(tii e : E[x]) if(X(e) != fa[x]) dfs0(X(e)), d[x] += d[X(e)];
      cmx(ans, d[x]);
    };
    dfs0(rt);
    cout << ans << "\n";
  }
}

bool Med;
signed main() {
  fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
  int cases = 1;
  // cases = rd();
  while(cases--) mian();
  fprintf(stderr, "(%.3lfs used)\n", (double)clock() / CLOCKS_PER_SEC);
  return 0;
}

/*
g++ qq.cpp -o qq -O2 -std=c++14 -static -Wall -Wno-parentheses -Wextra -Wshadow -DLOCAL -Wl,--stack=1145141919

Author: chenxia25
Start coding at: 10:45
Finish debugging at: 
*/