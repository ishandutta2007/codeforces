#include <bits/stdc++.h>
using namespace std;
bool Mbe;

using ll = long long;
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

const int N = 2e5 + 10;

int n, m;
int a[N], b[N];
vi E[N];
int fa[N];

int dep[N];
bool vis[N];
void dfs(int x = 1) {
  dep[x] = dep[fa[x]] + 1;
  vis[x] = true;
  for(int y : E[x]) if(!vis[y]) {
    fa[y] = x;
    dfs(y);
  }
}
bool iseg[N];

void mian() {
  n = rd(), m = rd();
  rep(i, 1, n) E[i].clear(), vis[i] = fa[i] = 0;
  rep(i, 1, m) {
    a[i] = rd(), b[i] = rd();
    E[a[i]].pb(b[i]), E[b[i]].pb(a[i]);
  }
  dfs();
  rep(i, 1, m) iseg[i] = a[i] == fa[b[i]] || b[i] == fa[a[i]];
  set<int> st;
  rep(i, 1, m) if(!iseg[i]) st.insert(a[i]), st.insert(b[i]);
  if(m <= n + 1 || sz(st) != 3) {
    rep(i, 1, m) pc(iseg[i] ? '1' : '0');
    pc('\n'); return;
  }
  int x = 0;
  rep(i, 1, m) if(!iseg[i]) x = i;
  iseg[x] = true;
  x = dep[a[x]] > dep[b[x]] ? a[x] : b[x];
  rep(i, 1, m) if(mt(a[i], b[i]) == mt(x, fa[x]) || mt(b[i], a[i]) == mt(x, fa[x])) {
    iseg[i] = false; break;
  }
  rep(i, 1, m) pc(iseg[i] ? '1' : '0');
  pc('\n'); return;
}

bool Med;
signed main() {
  fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
  int cases = 1;
  cases = rd();
  while(cases--) mian();
  fprintf(stderr, "(%.3lfs used)\n", (double)clock() / CLOCKS_PER_SEC);
  return 0;
}

/*
g++ d.cpp -o d -O2 -std=c++14 -static -Wall -Wno-parentheses -Wextra -Wshadow -DLOCAL -Wl,--stack=1145141919

Author: chenxia25
Start coding at: 
Finish debugging at: 
*/