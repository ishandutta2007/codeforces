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

char gc() { return getchar(); } void pc(const char &x) { putchar(x); }
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
int fa[N];
vi E[N];
int a[N];
int shd[N];

int f[N][2];

void dfs0(int x = 1) {
  if(x > 1) shd[x] = shd[fa[x]] / sz(E[fa[x]]);
  for(int y : E[x]) dfs0(y);
}

void dfs(int x = 1) {
  for(int y : E[x]) dfs(y);
  f[x][0] = shd[x] * a[x], f[x][1] = (shd[x] + 1) * a[x];
  if(!sz(E[x])) return;
  int hav = shd[x] % sz(E[x]);
  int sum = 0;
  vi v;
  for(int y : E[x]) sum += f[y][0], v.pb(f[y][1] - f[y][0]);
  sort(v.begin(), v.end(), greater<int>());
  f[x][0] += sum, f[x][1] += sum;
  rep(i, 0, hav - 1) f[x][0] += v[i];
  rep(i, 0, hav) f[x][1] += v[i];
}

void mian() {
  n = rd(), m = rd();
  rep(i, 1, n) E[i].clear();
  shd[1] = m;
  rep(i, 2, n) fa[i] = rd(), E[fa[i]].pb(i);
  rep(i, 1, n) a[i] = rd();
  dfs0();
  dfs();
  int ans = f[1][0];
  prt(ans), pc('\n');
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