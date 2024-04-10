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

const int N = 510, M = N * N;

int n, m;
int a[N][N];
int u[M], v[M], w[M];

void mian() {
  n = rd(), m = rd();
  rep(i, 1, n) rep(j, 1, n) a[i][j] = i == j ? 0 : inf;
  rep(i, 1, m) {
    int x = rd(), y = rd();
    int z = rd();
    cmn(a[x][y], 1);
    cmn(a[y][x], 1);
    u[i] = x, v[i] = y, w[i] = z;
  }
  rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) cmn(a[i][j], a[i][k] + a[k][j]);
  int ans = inf;
  rep(i, 1, m) cmn(ans, (a[1][u[i]] + a[v[i]][n] + 1) * w[i]);
  rep(i, 1, m) cmn(ans, (a[1][v[i]] + a[u[i]][n] + 1) * w[i]);
  rep(i, 1, m) rep(x, 1, n) {
    cmn(ans, (min(a[u[i]][x], a[v[i]][x]) + 2 + a[1][x] + a[x][n]) * w[i]);
  }
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