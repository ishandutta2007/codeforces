#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) (int) ((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int _mult(int x, int y) {return (long long) x * y % MOD;}
template<typename ...Y> int _mult(int x, Y... y) { return (long long) x * _mult(y...) % MOD; }
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
template<typename X> void debug(X x) { cerr << x << "] "; }
template<typename X, typename ...Y> void debug(X x, Y... y) { cerr << x << " "; debug(y...); }
#define db(...) cerr << "[" << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#define endln cerr << "\n";
#define LIKELY(x)   (__builtin_expect(!!(x), 1))
#define UNLIKELY(x) (__builtin_expect(!!(x), 0))

void chemthan() {
  int n, m; cin >> n >> m;
  vector<tuple<int, int, int>> v;
  FOR(i, 0, n) {
    int x, p; cin >> x >> p;
    v.pb({x, p, i});
  }
  sort(all(v));
  vi x, p;
  vi dc;
  vi order(n);
  int ptr = 0;
  for (auto [_x, _p, i] : v) {
    x.pb(_x);
    p.pb(_p);
    dc.pb(_x - _p);
    dc.pb(_x);
    dc.pb(_x + _p + 1);
    order[i] = ptr++;
  }
  sort(all(dc)), uni(dc);
  int dim = sz(dc);
  vector<vector<long long>> fen(2, vector<long long>(dim + 1));
  auto upd = [&] (vector<long long>& fen, int p, int v) {
    for (p++; p < sz(fen); p += p & -p) {
      fen[p] += v;
    }
  };
  auto query = [&] (vector<long long>& fen, int p) {
    long long res = 0;
    for (p++; 0 < p; p -= p & -p) {
      res += fen[p];
    }
    return res;
  };
  auto _query = [&] (int x) -> long long {
    if (x < dc[0] || dc.back() <= x) {
      return 0;
    }
    int d = lower_bound(all(dc), x) - dc.begin();
    long long s = query(fen[0], d);
    long long c = query(fen[1], d);
    return s + c * x;
  };
  auto _upd = [&] (int i, int sign) {
    int a = lower_bound(all(dc), x[i] - p[i]) - dc.begin();
    int b = lower_bound(all(dc), x[i]) - dc.begin();
    int c = lower_bound(all(dc), x[i]) - dc.begin();
    int d = lower_bound(all(dc), x[i] + p[i] + 1) - dc.begin();
    upd(fen[0], a, sign * (p[i] - x[i]));
    upd(fen[1], a, sign * 1);
    upd(fen[0], b, sign * -(p[i] - x[i]));
    upd(fen[1], b, sign * -1);

    upd(fen[0], c, sign * (p[i] + x[i]));
    upd(fen[1], c, sign * -1);
    upd(fen[0], d, sign * -(p[i] + x[i]));
    upd(fen[1], d, sign * 1);
  };
  FOR(i, 0, n) _upd(i, 1);
  vector<pair<long long, int>> f(n);
  FOR(i, 0, n) {
    f[i].fi = _query(x[i]);
    if (f[i].fi <= m) f[i].fi = -LINF;
    f[i].se = i;
  }
  auto g = f;
  FOR(i, 0, n) {
    f[i].fi -= x[i];
    f[i].se *= -1;
    if (i) {
      chkmax(f[i], f[i - 1]);
    }
  }
  FORd(i, n, 0) {
    g[i].fi += x[i];
    if (i + 1 < n) {
      chkmax(g[i], g[i + 1]);
    }
  }
  vi res(n, 1);
  FOR(i, 0, n) {
    _upd(i, -1);
    int ix1 = -f[i].se;
    int ix2 = g[i].se;
    for (int ix : {ix1, ix2}) {
      if (m < _query(x[ix])) {
        res[i] = 0;
      }
    }
    _upd(i, 1);
  }
  FOR(i, 0, n) cout << res[order[i]];
  cout << "\n";
}

int32_t main(int32_t argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  int test = 1;
  cin >> test;
  while (test--)
    chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}