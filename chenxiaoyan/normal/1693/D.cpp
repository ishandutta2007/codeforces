#include <bits/stdc++.h>
using namespace std;
bool Mbe;

namespace temp {
// NORMAL
using ll = long long; // using i128 = __int128_t;
using uint = unsigned; using ull = unsigned long long; // using u128 = __uint128_t;
using db = double; using ld = long double; // using f128 = __float128;
#define int ll
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

constexpr int N = 2e5 + 10, LOG_N = 20;

int n;
int a[N];
int R[N];

struct trans {
  int l, r;
  #define LL (-inf - 1)
  #define RR (-inf - 2)
  trans(int l = LL, int r = RR) : l(l), r(r) {}
  friend trans operator*(trans f, trans g) {
    swap(f, g);
    trans h;
    h.l = g.l == LL ? f.l : g.l == RR ? f.r : g.l;
    h.r = g.r == LL ? f.l : g.r == RR ? f.r : g.r;
    return h;
  }
} ts[N];

struct segtree {
  struct node {
    trans ts;
    #define ls(p) (p << 1)
    #define rs(p) (p << 1 | 1)
    #define ts(p) nd[p].ts
  } nd[N << 2];
  void sprup(int p) { ts(p) = ts(rs(p)) * ts(ls(p)); }
  void bld(int l = 1, int r = n, int p = 1) {
    if(l == r) return ts(p) = ts[l], void();
    int mid = l + r >> 1;
    bld(l, mid, ls(p)), bld(mid + 1, r, rs(p));
    sprup(p);
  }
  void init() { bld(); }
  trans ask(int l, int r, int p = 1, int tl = 1, int tr = n) {
    if(l > r) return trans();
    if(l <= tl && r >= tr) return ts(p);
    int mid = tl + tr >> 1;
    trans res;
    if(l <= mid) res = ask(l, r, ls(p), tl, mid) * res;
    if(r > mid) res = ask(l, r, rs(p), mid + 1, tr) * res;
    return res;
  }
} sgt;

int rit[N];
int want[N];
struct query {
  int *pt, l, r;
  query() {}
  query(int *pt, int l, int r) : pt(pt), l(l), r(r) {}
}; vector<query> q[N];

void solve() {
  static int s1[N], t1, s2[N], t2;
  PER(i, n + 1, 1) {
    if(i <= n) {
      while(t1 && a[i] < a[s1[t1]]) --t1;
      s1[++t1] = i;
      while(t2 && a[i] > a[s2[t2]]) --t2;
      s2[++t2] = i;
    }
    for(auto qry : q[i]) {
      int &res = *qry.pt = i - 1, l = qry.l, r = qry.r;
      PER(o, 20, 0) if(res + (1 << o) <= n) {
        int x = res + (1 << o);
        int fd1 = t1 + 1, fd2 = t2 + 1, fd3 = t1 + 1, fd4 = t2 + 1;
        PER(j, 20, 0) if(fd1 > 1 << j && a[s1[fd1 - (1 << j)]] >= l) fd1 -= 1 << j;
        PER(j, 20, 0) if(fd2 > 1 << j && a[s2[fd2 - (1 << j)]] <= r) fd2 -= 1 << j;
        PER(j, 20, 0) if(fd3 > 1 << j && s1[fd3 - (1 << j)] <= x) fd3 -= 1 << j;
        PER(j, 20, 0) if(fd4 > 1 << j && s2[fd4 - (1 << j)] <= x) fd4 -= 1 << j;
        // assert(fd1 - fd3 + fd2 - fd4 <= x - i + 1);
        if(max(0ll, fd1 - fd3) + max(0ll, fd2 - fd4) == x - i + 1) res = x;
      }
    }
  }
}

struct stable {
  int mx[LOG_N][N], lg[N];
  void init(int n, int *a) {
    REP(i, 2, n) lg[i] = lg[i >> 1] + 1;
    REP(i, 1, n) mx[0][i] = a[i];
    REP(i, 1, LOG_N - 1) REP(j, 1, n - (1 << i) + 1) mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << i - 1)]);
  }
  int _mx(int l, int r) {
    if(l > r) return -inf;
    int lg0 = lg[r - l + 1];
    return max(mx[lg0][l], mx[lg0][r - (1 << lg0) + 1]);
  }
} st;

void mian() {
  n = read();
  REP(i, 1, n) a[i] = read();
  REP(i, 1, n) {
    if(a[i - 1] < a[i]) ts[i] = trans(a[i - 1], RR);
    else ts[i] = trans(LL, a[i - 1]);
  } 
  sgt.init();
  REP(i, 1, n - 1) {
    q[i + 2].pb(rit + i, min(a[i], a[i + 1]), max(a[i], a[i + 1]));
  }
  int now = 0;
  REP(i, 1, n) {
    while(now < n) {
      int x = now + 1;
      trans t = sgt.ask(i + 1, x) * trans(0, n + 1);
      // cout << t.l << " " << t.r << "??\n";
      if(t.l < a[x] && a[x] < t.r) ++now;
      else break;
    }
    R[i] = now;
    // cout << now << "??\n";
    if(now < n) {
      trans t = sgt.ask(i + 1, now) * trans(0, n + 1);
      if(a[now + 1] < t.l) q[now + 2].pb(want + i, a[now + 1], t.l);
      else q[now + 2].pb(want + i, t.r, a[now + 1]);
    }
  }
  solve();
  st.init(n, rit);
  int ans = 0;
  REP(i, 1, n) {
    int r = min(n, R[i] + 1);
    chkmx(r, want[i]);
    // cout << want[i] << "????\n";
    int mx = st._mx(i, R[i] - 1);
    chkmx(r, mx);
    // cout << r << "???\n";
    ans += r - i + 1;
  }
  prt(ans), pc('\n');
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