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

void chemthan() {
  int n, t; cin >> n >> t;
  vi g(n), c(n);
  vector<vii> segs(n);
  vi dc = {0, t};
  FOR(i, 0, n) {
    cin >> g[i] >> c[i];
  }
  vector<long long> d(n);
  FOR(i, 1, n) cin >> d[i], d[i] += d[i - 1];

  int c0 = c[0];
  FOR(i, 0, n) {
    c[i] = (c[i] - c0 + t) % t;
    int ed = (t - (c[i] + d[i]) % t) % t;
    int st = (ed + g[i]) % t;
    if (!ed) ed += t;
    if (st < ed) {
      dc.pb(st), dc.pb(ed);
      segs[i].pb({st, ed});
      dc.pb((st + t - 1) % t);
    }
    else {
      dc.pb(st), dc.pb(t);
      dc.pb(0), dc.pb(ed);
      dc.pb((st + t - 1) % t);
      segs[i].pb({st, t});
      segs[i].pb({0, ed});
    }
  }
  sort(all(dc)), uni(dc);
  int dim = sz(dc);
  vector<vi> st(dim << 2);
  auto add = [&] (auto&& add, int p, int l, int r, int L, int R, int v) {
    if (R <= l || r <= L) return;
    if (l <= L && R <= r) {
      st[p].pb(v);
      return;
    }
    int M = (L + R) / 2;
    add(add, p * 2, l, r, L, M, v);
    add(add, p * 2 + 1, l, r, M, R, v);
  };
  auto query = [&] (auto&& query, int p, int i, int L, int R, int v) -> int {
    if (R <= i || i + 1 <= L) return n;
    int k = lower_bound(all(st[p]), v) - st[p].begin();
    int res = k < sz(st[p]) ? st[p][k] : n;
    if (L + 1 < R) {
      int M = (L + R) / 2;
      chkmin(res, min(query(query, p * 2, i, L, M, v), query(query, p * 2 + 1, i, M, R, v)));
    }
    return res;
  };
  FOR(i, 0, n) {
    for (auto [l, r] : segs[i]) {
      l = lower_bound(all(dc), l) - dc.begin();
      r = lower_bound(all(dc), r) - dc.begin();
      add(add, 1, l, r, 0, dim, i);
    }
  }
  vector<long long> dp(n + 1);
  FORd(i, n, 0) {
    int sg = segs[i].back().se % t;
    int ix = lower_bound(all(dc), sg) - dc.begin();
    int nxt = query(query, 1, ix, 0, dim, i);
    if (nxt < n) {
      int e = segs[nxt].back().se;
      dp[i] = dp[nxt] + (e - sg + t) % t;
    }
  }
  long long res = LINF;
  FOR(i, 0, dim - 1) {
    int nxt = query(query, 1, i, 0, dim, 0);
    if (nxt < n) {
      int e = segs[nxt].back().se;
      chkmin(res, dp[nxt] + (e - dc[i] + t) % t);
    }
    else {
      res = 0;
    }
  }
  cout << res + d[n - 1] << "\n";
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