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

int sgn(int x) { return x == 0 ? 0 : x < 0 ? -1 : 1; }
int sq(int x) { return x * x; }

struct point {
  int x, y, i;
  point(int x = 0, int y = 0, int i = 0) : x(x), y(y), i(i) {}
  bool operator==(point v) const { return sgn(x - v.x) == 0 && sgn(y - v.y) == 0; }
  bool operator!=(point v) const { return sgn(x - v.x) || sgn(y - v.y); }
  point operator+(point v) const { return point(x + v.x, y + v.y); }
  point operator-(point v) const { return point(x - v.x, y - v.y); }
  point operator-() const { return point(-x, -y); }
  point operator*(int v) const { return point(x * v, y * v); }
  friend point operator*(int u, point v) { return point(u * v.x, u * v.y); }
  int operator~() const { return sq(x) + sq(y); }
  int operator*(point v) const { return x * v.x + y * v.y; }
  friend bool perp(point u, point v) { return sgn(u * v) == 0; }
  int operator%(point v) const { return x * v.y - y * v.x; }
  friend int clock(point u, point v) { return sgn(u % v); }
  friend bool operator<(point u, point v) {
    auto up = [&](point u) { return sgn(u.y) > 0 || sgn(u.y) == 0 && sgn(u.x) > 0; };
    bool U = up(u), V = up(v);
    return U == V ? clock(u, v) > 0 : U;
  }
};

struct line {
  point p, v; int i, j;
  line() {}
  line(point p, point v, int i = 0, int j = 0) : p(p), v(v), i(i), j(j) {}
  int side(point u) const { return clock(v, u - p); }
  friend bool para(line l1, line l2) { return clock(l1.v, l2.v) == 0; }
  friend bool coin(line l1, line l2) { return para(l1, l2) && l1.side(l2.p) == 0; }
  friend bool operator==(line l1, line l2) { return coin(l1, l2) && sgn(l1.v * l2.v) > 0; }
};

struct segment {
  point a, b;
  segment() {}
  segment(point a, point b) : a(a), b(b) {}
  operator line() const { return line(a, b - a); }
  bool operator==(segment l2) const { return a == l2.a && b == l2.b || a == l2.b && b == l2.a; }
  bool operator!=(segment l2) const { return !(*this == l2); }
  friend bool para(segment l1, segment l2) { return para(line(l1), line(l2)); }
  bool on(point u) const {
    if(a == b) return a == u;
    return line(*this).side(u) == 0 &&
       sgn(min(a.x, b.x) - u.x) <= 0 && sgn(u.x - max(a.x, b.x)) <= 0 &&
       sgn(min(a.y, b.y) - u.y) <= 0 && sgn(u.y - max(a.y, b.y)) <= 0;
  }
  friend bool inter(segment l1, segment l2) {
    if(l1.a == l1.b) return l2.on(l1.a);
    if(l2.a == l2.b) return l1.on(l2.a);
    line L1(l1.a, l1.b - l1.a), L2(l2.b, l2.b - l2.a);
    if(para(L1, L2)) {
      if(!coin(L1, L2)) return false;
      int l = max(min(l1.a.x, l1.b.x), min(l2.a.x, l2.b.x)), r = min(max(l1.a.x, l1.b.x), max(l2.a.x, l2.b.x));
      int d = max(min(l1.a.x, l1.b.x), min(l2.a.x, l2.b.x)), u = min(max(l1.a.x, l1.b.x), max(l2.a.x, l2.b.x));
      return sgn(l - r) <= 0 && sgn(d - u) <= 0;
    } else {
      return L1.side(l2.a) != L1.side(l2.b) && L2.side(l1.a) != L2.side(l1.b);
    }
  }
};

constexpr int N = 2010;

int n, S, m;
point a[N];
line b[N * N / 2];
int which[N][N];
int pos[N];

void mian() {
  n = read(), S = 2 * read();
  REP(i, 1, n) a[i].x = read(), a[i].y = read(), a[i].i = i;
  REP(i, 1, n) REP(j, i + 1, n) {
    point v = a[j] - a[i];
    if(v.y > 0 || v.y == 0 && v.x > 0) b[++m] = line(a[i], v, i, j);
    else b[++m] = line(a[j], -v, j, i);
    which[i][j] = which[j][i] = m;
  }
  sort(a + 1, a + n + 1, [&](point x, point y) {
    line &l = b[which[x.i][y.i]];
    return l.i == x.i;
  });
  sort(b + 1, b + m + 1, [&](line x, line y) {
    return x.v < y.v;
    if(clock(x.v, y.v)) return clock(x.v, y.v) == 1;
    if(x.side(y.p)) return x.side(y.p) == 1;
    if(x.p != y.p) return segment(x.p - y.p, x.v).on(point());
    return segment((x.p + x.v) - (y.p + y.v), x.v).on(point());
  });
  REP(i, 1, n) pos[a[i].i] = i;
  auto area = [&](const line &l, const point &p) {
    return abs(l.v % (p - l.p));
  };
  REP(i, 1, m) {
    int far = 0;
    PER(j, 12, 0) if(far + (1 << j) <= n && b[i].side(a[far + (1 << j)]) == -1) far += 1 << j;
    int fd = far + 1;
    PER(j, 12, 0) if(fd > 1 << j && area(b[i], a[fd - (1 << j)]) <= S) fd -= 1 << j;
    if(fd <= far && area(b[i], a[fd]) == S) {
      puts("Yes");
      prt(b[i].p.x), pc(' '), prt(b[i].p.y), pc('\n');
      prt((b[i].p + b[i].v).x), pc(' '), prt((b[i].p + b[i].v).y), pc('\n');
      prt(a[fd].x), pc(' '), prt(a[fd].y), pc('\n');
      return;
    }
    fd = far;
    PER(j, 12, 0) if(fd + (1 << j) <= n && area(b[i], a[fd + (1 << j)]) <= S) fd += 1 << j;
    if(fd > far && area(b[i], a[fd]) == S) {
      puts("Yes");
      prt(b[i].p.x), pc(' '), prt(b[i].p.y), pc('\n');
      prt((b[i].p + b[i].v).x), pc(' '), prt((b[i].p + b[i].v).y), pc('\n');
      prt(a[fd].x), pc(' '), prt(a[fd].y), pc('\n');
      return;
    }
    swap(a[pos[b[i].i]], a[pos[b[i].j]]);
    swap(pos[b[i].i], pos[b[i].j]);
  }
  puts("No");
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