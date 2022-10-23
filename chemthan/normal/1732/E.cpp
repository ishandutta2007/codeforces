#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define int long long

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
const ld EPS = 1e-12;
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

struct fract_t {
  int p, q;
  fract_t(int p = 0, int q = 1) : p(p), q(q) {}
};

int operator < (const fract_t& a, const fract_t& b) {
  return (long long) a.p * b.q < (long long) b.p * a.q;
};

void chemthan() {
  static const int C = 5e4 + 5;
  vector<vi> dvs(C);
  FOR(i, 1, C) {
    for (int j = i; j < C; j += i) {
      dvs[j].pb(i);
    }
  }
  vi sp(C);
  vector<vi> prdvs(C);
  FOR(i, 1, C) sp[i] = i;
  FOR(i, 2, C) if (sp[i] == i) {
    for (int j = i; j < C; j += i) {
      chkmin(sp[j], i);
      prdvs[j / i].pb(i);
    }
  }
  int n, q; cin >> n >> q;
  vi a(n), b(n);
  FOR(i, 0, n) cin >> a[i];
  FOR(i, 0, n) cin >> b[i];
  static const int magic = 111;
  static fract_t g[C / magic + 5][C];
  FOR(i, 0, C / magic + 5) FOR(j, 0, C) g[i][j] = fract_t(INF, 1);
  FOR(i, 0, n) {
    for (int d : dvs[b[i]]) {
      chkmin(g[i / magic][d], fract_t(b[i] / d, d));
    }
  }
  FOR(i, 0, n / magic + 5) {
    auto& gi = g[i];
    FOR(j, 1, C) {
      for (int k : prdvs[j]) {
        chkmin(gi[j * k], gi[j]);
      }
    }
  }
  vector<long long> f(n / magic + 5, LINF);
  vi c(n / magic + 5, -1);
  FOR(i, 0, n) {
    int d = gcd(a[i], b[i]);
    chkmin(f[i / magic], (long long) (a[i] / d) * (b[i] / d));
  }
  auto bulk_upd = [&] (int bix, int x) {
    c[bix] = x;
    f[bix] = LINF;
    auto& mn = g[bix][x];
    if (mn.p < INF) {
      chkmin(f[bix], (long long) (x / mn.q) * mn.p);
    }
  };
  auto partial_upd = [&] (int bix, int l, int r, int x) {
    f[bix] = LINF;
    int st = bix * magic;
    int ed = min(n, (bix + 1) * magic);
    FOR(i, st, ed) {
      if (l <= i && i <= r) {
        a[i] = x;
      }
      else if (c[bix] != -1) {
        a[i] = c[bix];
      }
      int d = __gcd(a[i], b[i]);
      chkmin(f[bix], (long long) (a[i] / d) * (b[i] / d));
    }
    c[bix] = -1;
  };
  auto partial_query = [&] (int bix, int l, int r) {
    long long res = LINF;
    int st = bix * magic;
    int ed = min(n, (bix + 1) * magic);
    FOR(i, st, ed) {
      if (l <= i && i <= r) {
        int t = c[bix] == -1 ? a[i] : c[bix];
        int d = __gcd(t, b[i]);
        chkmin(res, (long long) (t / d) * (b[i] / d));
      }
    }
    return res;
  };
  FOR(_, 0, q) {
    int op; cin >> op;
    if (op == 1) {
      int l, r, x; cin >> l >> r >> x; l--, r--;
      int lix = l / magic;
      int rix = r / magic;
      partial_upd(lix, l, r, x);
      if (lix < rix) {
        FOR(bix, lix + 1, rix) {
          bulk_upd(bix, x);
        }
        partial_upd(rix, l, r, x);
      }
    }
    else {
      int l, r; cin >> l >> r; l--, r--;
      int lix = l / magic;
      int rix = r / magic;
      long long res = LINF;
      chkmin(res, partial_query(lix, l, r));
      if (lix < rix) {
        FOR(bix, lix + 1, rix) {
          chkmin(res, f[bix]);
        }
        chkmin(res, partial_query(rix, l, r));
      }
      cout << res << "\n";
    }
  }
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
  //cin >> test;
  FOR(it, 1, test + 1) {
    chemthan();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}