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

constexpr int N = 110;

int n;
bitset<N> a[N][N];
vi nei[N];
bitset<N> ok[N][N];

vector<bitset<N>> vv[N];

int m;
tii eg[N * N];
struct ufset {
  int fa[N];
  void init() { memset(fa, 0, sizeof(fa)); }
  int root(int x) { return fa[x] ? fa[x] = root(fa[x]) : x; }
  bool mrg(int x, int y) {
    x = root(x), y = root(y);
    if(x == y) return false;
    return fa[x] = y, true;
  }
} ufs;
int dis[N][N];
void dfs(int x, int *d, int fa = 0) {
  for(int y : nei[x]) if(y != fa) {
    d[y] = d[x] + 1;
    dfs(y, d, x);
  }
}
bool valid() {
  REP(i, 1, n) sort(ALL(nei[i])), nei[i].resize(unique(ALL(nei[i])) - nei[i].begin());
  m = 0;
  REP(x, 1, n) for(int y : nei[x]) eg[++m] = mt(min(x, y), max(x, y));
  sort(eg + 1, eg + m + 1);
  m = unique(eg + 1, eg + m + 1) - 1 - eg;
  if(m != n - 1) return false;
  ufs.init();
  REP(i, 1, m) if(!ufs.mrg(X(eg[i]), Y(eg[i]))) return false;
  memset(dis, 0, sizeof(dis));
  REP(x, 1, n) dfs(x, dis[x]);
  REP(i, 1, n) REP(j, i + 1, n) REP(k, 1, n) if(a[i][j][k] != (dis[i][k] == dis[j][k])) return false;
  return true;
}

void mian() {
  n = read();
  REP(i, 1, n) nei[i].clear(), vv[i].clear();
  REP(i, 1, n) REP(j, i + 1, n) {
    static char aa[N];
    reads(aa + 1);
    a[i][j].reset();
    REP(k, 1, n) a[i][j][k] = aa[k] ^ 48;
    a[j][i] = a[i][j];
  }
  if(n == 2) {
    nei[1].pb(2), nei[2].pb(1);
    if(!valid()) return puts("NO"), void();
    puts("YES");
    REP(i, 1, n - 1) prt(X(eg[i])), pc(' '), prt(Y(eg[i])), pc('\n');
    return;
  }
  REP(x, 1, n) REP(y, 1, n) if(x != y) {
    ok[x][y].reset();
    ok[x][y].set(x), ok[x][y].set(y);
    REP(z, 1, n) if(z != x && z != y) ok[x][y][z] = a[x][y][z] && a[x][z][y] && a[y][z][x];
  }
  REP(x, 1, n) REP(y, x + 1, n) if(a[x][y].any()) {
    auto &b = ok[x][y];
    // if(x == 1 && y == 5) {
    //   REP(z, 1, n) if(b[z]) cout << z << " ";
    //   puts("?");
    // }
    bool flg = true;
    REP(z, 1, n) if(b[z] && z != x && z != y) {
      if(ok[x][z] != b || ok[y][z] != b) flg = false;
    }
    if(!flg) continue;
    bitset<N> inter; inter.set();
    int las = 0;
    REP(z, 1, n) if(b[z]) {
      if(las) inter = inter & a[las][z];
      las = z;
    }
    if(inter.count() != 1) continue;
    // REP(z, 1, n) if(inter[z]) {
    //   cout << z << ": ";
    //   REP(z, 1, n) if(b[z]) cout << z << " ";
    //   puts("");
    // }
    REP(z, 1, n) if(inter[z]) vv[z].pb(b);
  }
  tii mn(inf, 0);
  REP(x, 1, n) if(SZ(vv[x])) chkmn(mn, mt(SZ(vv[x]), x));
  int rt = Y(mn);
  if(!rt) return puts("NO"), void();
  for(auto base : vv[rt]) {
    REP(i, 1, n) nei[i].clear();
    static bool vis[N];
    memset(vis, 0, sizeof(vis));
    function<void(int, bitset<N>)> dfs = [&](int x, bitset<N> b) {
      if(vis[x]) return;
      vis[x] = true;
      REP(y, 1, n) if(b[y]) nei[x].pb(y), nei[y].pb(x);
      REP(y, 1, n) if(b[y]) {
        for(bitset<N> c : vv[y]) if(c[x]) dfs(y, c);
      }
    };
    dfs(rt, base);
    if(!valid()) continue;
    puts("YES");
    REP(i, 1, n - 1) prt(X(eg[i])), pc(' '), prt(Y(eg[i])), pc('\n');
    return;
  }
  puts("NO");
}

bool Med;
signed main() {
  fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
  // freopen("xxx.in", "r", stdin); freopen("xxx.out", "w", stdout);
  int t = 1;
  t = read();
  while(t--) mian();
  fprintf(stderr, "(%.3lfs used)\n", (db)clock() / CLOCKS_PER_SEC);
  return 0;
}