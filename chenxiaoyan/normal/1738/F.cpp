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

const int N = 1010;

int n, deg[N];

struct ufset {
  int fa[N], sz[N];
  void init() { rep(i, 1, n) fa[i] = 0, sz[i] = 1; }
  int root(int x) { return fa[x] ? fa[x] = root(fa[x]) : x; }
  void mrg(int x, int y) {
    x = root(x), y = root(y);
    if(x != y) fa[x] = y, sz[y] += sz[x];
  }
} ufs;

int get(int x) {
  cout << "? " << x << "\n";
  fflush(stdout);
  int res; cin >> res;
  return res;
}

void mian() {
  cin >> n; rep(i, 1, n) cin >> deg[i];
  ufs.init();
  vi v; rep(i, 1, n) v.pb(i);
  sort(v.begin(), v.end(), [&](int x, int y) { return deg[x] > deg[y]; });
  for(int x : v) if(deg[x] >= 2) {
    if(ufs.sz[ufs.root(x)] != 1) continue;
    rep(i, 1, deg[x]) {
      int y = get(x);
      int sz = ufs.sz[ufs.root(y)];
      ufs.mrg(x, y);
      if(sz != 1) break;
    }
  }
  static int vis[N];
  rep(i, 1, n) vis[i] = 0;
  cout << "! ";
  int now = 0;
  rep(i, 1, n) {
    int x = ufs.root(i);
    if(!vis[x]) vis[x] = ++now;
    cout << vis[x] << " ";
  }
  cout << "\n";
  fflush(stdout);
}

bool Med;
signed main() {
  fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
  int cases = 1;
  cin >> cases;
  while(cases--) mian();
  fprintf(stderr, "(%.3lfs used)\n", (double)clock() / CLOCKS_PER_SEC);
  return 0;
}

/*
g++ f.cpp -o f -O2 -std=c++14 -static -Wall -Wno-parentheses -Wextra -Wshadow -DLOCAL -Wl,--stack=1145141919

Author: chenxia25
Start coding at: 
Finish debugging at: 
*/