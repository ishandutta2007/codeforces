#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
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
//const int MOD = (int) 1e9 + 7;
const int MOD = 119 << 23 | 1;
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
  int n; cin >> n;
  vii pts(n);
  FOR(i, 0, n) cin >> pts[i].fi >> pts[i].se;
  vi dj(n);
  FOR(i, 0, n) dj[i] = i;
  function<int(int)> find = [&] (int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
  };
  auto join = [&] (int u, int v) {
    dj[find(u)] = find(v);
  };
  auto dist = [&] (int u, int v) {
    return abs(pts[u].fi - pts[v].fi) + abs(pts[u].se - pts[v].se);
  };
  FOR(i, 0, n) {
    int dmin = INF;
    FOR(j, 0, n) if (j != i) {
      chkmin(dmin, dist(i, j));
    }
    vi v = {i};
    FOR(j, 0, n) if (j != i) {
      if (dist(i, j) == dmin) {
        v.pb(j);
      }
    }
    sort(all(v));
    while (1) {
      vi nv = v;
      for (int j : v) {
        FOR(k, 0, n) {
          if (dist(j, k) <= dmin) {
            nv.pb(k);
          }
        }
      }
      sort(all(nv)), uni(nv);
      if (v == nv) {
        break;
      }
      v = nv;
    }
    if (sz(v) <= 4) {
      int flag = 0;
      FOR(i, 0, sz(v)) FOR(j, i + 1, sz(v)) {
        if (dist(v[i], v[j]) != dmin) {
          flag = 1;
          break;
        }
      }
      if (!flag) {
        for (auto j : v) {
          join(i, j);
        }
      }
    }
  }
  map<int, int> hs;
  FOR(i, 0, n) {
    hs[find(i)]++;
  }
  vi dp(n + 1);
  dp[0] = 1;
  for (auto [k, c] : hs) {
    vi ndp(n + 1);
    FOR(i, 0, n) {
      addmod(ndp[i + 1], dp[i]);
      if (1 < c && i + c <= n) {
        addmod(ndp[i + c], dp[i]);
      }
    }
    dp = ndp;
  }
  vi f(n + 1);
  f[n] = n;
  FORd(i, n, 1) f[i] = mult(f[i + 1], i);
  int res = 0;
  FOR(i, 1, n + 1) {
    addmod(res, mult(dp[i], f[n - i + 1]));
  }
  cout << res << "\n";
}

int32_t main(int32_t argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}