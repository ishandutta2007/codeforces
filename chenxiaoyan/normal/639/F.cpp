#include <bits/stdc++.h>
using namespace std;
bool Mbe;

namespace temp {
// NORMAL
using ll = long long; // using i128 = __int128_t;
using uint = unsigned; using ull = unsigned long long; // using u128 = __uint128_t;
using db = double; using ld = long double; // using f128 = __float128;
// #define int ll
// #define db ld

using tii = tuple<int, int>; using ti3 = tuple<int, int, int>; using ti4 = tuple<int, int, int, int>;
#define mt(...) make_tuple(__VA_ARGS__)
#define X(x) get<0>(x)
#define Y(x) get<1>(x)
#define Z(x) get<2>(x)
#define W(x) get<3>(x)

using vi = vector<int>; using vii = vector<tii>; using vi3 = vector<ti3>; using vi4 = vector<ti4>;
using vvi = vector<vi>; using vvii = vector<vii>; using vvi3 = vector<vi3>; using vvi4 = vector<vi4>;
#define pf(...) emplace_front(__VA_ARGS__)
#define pb(...) emplace_back(__VA_ARGS__)

#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)
#define y0 kehaixing
#define y1 yigeiwoligiaogiao
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
int lowbit(int x) { return x & -x; }
template<class T, class U> void chkmx(T &x, U y) { if(y > x) x = y; }
template<class T, class U> void chkmn(T &x, U y) { if(y < x) x = y; }

// FASTIO
namespace fastio {
// #define fread_io
#ifdef fread_io
char buf[1 << 16], *st, *ed, wbuf[1 << 16], *wst = wbuf, *wed = wbuf + (1 << 16);
char gc() { return st == ed && (ed = (st = buf) + fread(buf, 1, 1 << 16, stdin), st == ed) ? -1 : *st++; }
__attribute__((destructor)) void flush() { fwrite(wbuf, 1, wst - wbuf, stdout), wst = wbuf; }
void pc(char x) { wst == wed && (flush(), 0), *wst++ = x; }
#else
char gc() { return getchar(); } void pc(char x) { putchar(x); }
#endif
#define notspace(x) (!isspace(x) && ~(x))
template<class T = int> T read() {
  T x = 0; char c = gc(); bool ne = false;
  while(!isdigit(c)) ne |= c == '-', c = gc();
  while(isdigit(c)) x = 10 * x + (c ^ 48), c = gc();
  return ne ? -x : x;
}
int reads(char *s) {
  int n = 0; char c = gc();
  while(!notspace(c)) c = gc();
  while(notspace(c)) s[n++] = c, c = gc();
  return s[n] = 0, n;
}
template<class T> void prt(T x) {
  x < 0 && (pc('-'), x = -x);
  x > 9 && (prt(x / 10), 0);
  pc(x % 10 ^ 48);
}
void prts(const char *s, int n = INT_MAX) { while(n-- && *s) pc(*s++); }
} using fastio::gc; using fastio::pc;
using fastio::read; using fastio::reads; using fastio::prt; using fastio::prts;

// MATH
constexpr int P = 0;
constexpr ll lnf = 0x3f3f3f3f3f3f3f3f;
#ifdef int
constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#else
constexpr int inf = 0x3f3f3f3f;
#endif

int gcd(int x, int y) { return __gcd(x, y); }
int exgcd(int a, int b, int &x, int &y) {
  if(!b) return x = 1, y = 0, a;
  int d = exgcd(b, a % b, y, x);
  return y -= a / b * x, d;
}
int qpow(int x, int y = P - 2, int p = P) {
  int res = 1;
  while(y) {
    if(y & 1) res = (ll)res * x % p;
    x = (ll)x * x % p;
    y >>= 1;
  } return res;
}
int inv(int a, int p = P) {
  int x, y, d = exgcd(a, p, x, y);
  if(d != 1) return -1;
  return x < 0 ? x + p : x;
}

namespace modint {
  void addto(int &x, int y) { x += y, x >= P && (x -= P), x < 0 && (x += P); }
  int add(int x, int y) { return x < 0 && (x += P), x += y, x >= P ? x - P : x < 0 ? x + P : x; }
  int add0(int x) { return x < 0 ? x + P : x; }
}
// using namespace modint;

template<int N, int p = P> struct fc_t {
  int iv[N], fc[N], ifc[N];
  fc_t() {
    iv[1] = 1; REP(i, 2, N - 1) iv[i] = (ll)iv[p % i] * (p - p / i) % p;
    fc[0] = ifc[0] = 1; REP(i, 1, N - 1) fc[i] = (ll)fc[i - 1] * i % p, ifc[i] = (ll)ifc[i - 1] * iv[i] % p;
  }
  int operator()(int n, int m) {
    if(m < 0 || m > n) return 0;
    return (ll)fc[n] * ifc[m] % p * ifc[n - m] % p;
  }
};
#define fc_init(...) fc_t<__VA_ARGS__> comb; int *iv = comb.iv, *fc = comb.fc, *ifc = comb.ifc
template<int N, int p = P> struct comb_t {
  int comb[N][N];
  comb_t() {
    comb[0][0] = 1;
    REP(i, 1, N - 1) REP(j, 0, i) comb[i][j] = ((j ? comb[i - 1][j - 1] : 0) + comb[i - 1][j]) % p;
  }
};
#define comb_init(...) comb_t<__VA_ARGS__> _comb; auto comb = _comb.comb
} using namespace temp;

constexpr int N = 3e5 + 10, LOG_N = 20;

int n, m, qu;
vi nei[N], rv[N];
vector<bool> brg[N];
namespace tarjan {
int dfn[N], low[N], nowdfn;
void tar(int x = 1, int fa = 0) {
  dfn[x] = low[x] = ++nowdfn;
  REP(i, 0, SZ(nei[x]) - 1) {
    int y = nei[x][i];
    if(y == fa) { fa = -1; continue; }
    if(!dfn[y]) {
      tar(y, x), chkmn(low[x], low[y]);
      if(dfn[x] < low[y]) brg[x][i] = brg[y][rv[x][i]] = true;
    } else chkmn(low[x], dfn[y]);
  }
}
} using tarjan::tar;

int cnt;
int cid[N];
void dfs(int x = 1) {
  cid[x] = cnt;
  REP(i, 0, SZ(nei[x]) - 1) if(!brg[x][i]) {
    int y = nei[x][i];
    if(!cid[y]) dfs(y);
  }
}
vector<int> cnei[N];

int R;
int rotate(int element)
{
   element=(element+R)%n;

   if (element==0) {
       element=n;
   }

   return element;
}

struct ufset {
  int fa[N];
  int root(int x) { return fa[x] ? fa[x] = root(fa[x]) : x; }
  void mrg(int x, int y) {
    x = root(x), y = root(y);
    if(x != y) fa[x] = y;
  }
} ufs;

int fa[N], dep[N], dfn[N], nowdfn, mng[N], mxdfn[N];
void dfs0(int x = 1) {
  dep[x] = dep[fa[x]] + 1;
  mng[dfn[x] = mxdfn[x] = ++nowdfn] = x;
  for(int y : cnei[x]) if(y != fa[x]) {
    fa[y] = x, dfs0(y);
    mxdfn[x] = mxdfn[y];
  }
}
struct stable {
  int mn[LOG_N][N], lg[N];
  static bool cmp(int x, int y) { return dep[x] < dep[y]; }
  void init() {
    REP(i, 2, cnt) lg[i] = lg[i >> 1] + 1;
    REP(i, 1, cnt) mn[0][i] = fa[mng[i]];
    REP(i, 1, LOG_N - 1) REP(j, 1, cnt - (1 << i) + 1) mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << i - 1)], cmp);
  }
  int lca(int x, int y) {
    if(x == y) return x;
    int l = dfn[x], r = dfn[y];
    if(l > r) swap(l, r); ++l;
    int lg0 = lg[r - l + 1];
    return min(mn[lg0][l], mn[lg0][r - (1 << lg0) + 1], cmp);
  }
} st;
int lca(int x, int y) {
  if(ufs.root(x) != ufs.root(y)) return 0;
  return st.lca(x, y);
}

int fafa[N];
vi son[N];
void virtree(vi &v) {
  dfn[0] = 0, mxdfn[0] = inf;
  auto cmp = [&](int x, int y) { return dfn[x] < dfn[y]; }; 
  sort(ALL(v), cmp), v.resize(unique(ALL(v)) - v.begin());;
  int tmp = SZ(v);
  REP(i, 0, tmp - 2) v.pb(lca(v[i], v[i + 1]));
  sort(ALL(v), cmp), v.resize(unique(ALL(v)) - v.begin());
  static int stk[N]; int top = 0;
  for(int x : v) {
    while(top && !(dfn[stk[top - 1]] <= dfn[x] && dfn[x] <= mxdfn[stk[top - 1]])) --top;
    if(top) son[stk[top - 1]].pb(x), fafa[x] = stk[top - 1];
    stk[top++] = x;
  }
}

struct ufsett {
  int fa[N];
  int root(int x) { return fa[x] ? fa[x] = root(fa[x]) : x; }
  void mrg(int x, int y) {
    x = root(x), y = root(y);
    if(x != y) fa[x] = y;
  }
} ufss;

namespace yet_another_tarjan {
vi nei[N];
void ae(int x, int y) {
  nei[x].pb(y), nei[y].pb(x);
}
int dfn[N], low[N], nowdfn;
void tar(int x = 1, int fa = 0) {
  dfn[x] = low[x] = ++nowdfn;
  REP(i, 0, SZ(nei[x]) - 1) {
    int y = nei[x][i];
    if(y == fa) { fa = -1; continue; }
    if(!dfn[y]) {
      tar(y, x), chkmn(low[x], low[y]);
      if(dfn[x] >= low[y]) ufss.mrg(x, y);
    } else chkmn(low[x], dfn[y]), ufss.mrg(x, y);
  }
}
void clear(vi &v) {
  for(int x : v) dfn[x] = low[x] = nowdfn = ufss.fa[x] = 0, nei[x].clear();
}
} using yet_another_tarjan::ae;

void mian() {
  n = read(), m = read(), qu = read();
  while(m--) {
    int x = read(), y = read();
    nei[x].pb(y), nei[y].pb(x);
    rv[x].pb(SZ(nei[y]) - 1), rv[y].pb(SZ(nei[x]) - 1);
    brg[x].pb(false), brg[y].pb(false);
  }
  REP(i, 1, n) if(!tarjan::dfn[i]) tar(i);
  REP(i, 1, n) if(!cid[i]) ++cnt, dfs(i);
  REP(i, 1, n) for(int x : nei[i]) {
    if(cid[i] != cid[x]) cnei[cid[i]].pb(cid[x]), ufs.mrg(cid[i], cid[x]);
  }
  REP(i, 1, n) if(!fa[i]) dfs0(i);
  st.init();
  REP(q, 1, qu) {
    int nn = read(), mm = read();
    vi v, key; vii eg;
    while(nn--) {
      int x = cid[rotate(read())];
      v.pb(x), key.pb(x);
    }
    while(mm--) {
      int x = cid[rotate(read())], y = cid[rotate(read())];
      v.pb(x), v.pb(y);
      eg.pb(x, y);
    }
    virtree(v);
    for(int x : v) if(fafa[x]) ae(x, fafa[x]);
    for(tii e : eg) ae(X(e), Y(e));
    for(int x : v) if(x && !yet_another_tarjan::dfn[x]) yet_another_tarjan::tar(x);
    REP(i, 0, SZ(key) - 2) if(ufss.root(key[i]) != ufss.root(key[i + 1])) {
      puts("NO"); goto edlp;
    }
    puts("YES"), R = (R + q) % n;
    edlp:;
    yet_another_tarjan::clear(v);
    for(int x : v) son[x].clear(), fafa[x] = 0;
  }
}

bool Med;
signed main() {
  fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
  // freopen("xxx.in", "r", stdin); freopen("xxx.out", "w", stdout);
  int t = 1;
  // t = read();
  while(t--) mian();
  fprintf(stderr, "(%.3lfs used)\n", (db)clock() / CLOCKS_PER_SEC);
  return 0;
}

/*
7 6 1
1 2
1 3
2 4
2 5
3 6
3 7
2 2
6 5
4 5
6 1
*/