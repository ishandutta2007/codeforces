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
  int n; cin >> n;
  vi a(n);
  FOR(i, 0, n) cin >> a[i], a[i]--;
  vi l1(n), l2(n);
  FOR(i, 0, n) l1[i] = l2[i] = i;
  FOR(i, 1, n) {
    {
      int ptr = i;
      while (ptr && a[ptr - 1] < a[i]) ptr = l1[ptr - 1];
      l1[i] = ptr;
    }
    {
      int ptr = i;
      while (ptr && a[i] < a[ptr - 1]) ptr = l2[ptr - 1];
      l2[i] = ptr;
    }
  }
  vi st1(n << 1, INF);
  vi st2(n << 1, INF);
  auto upd = [&] (vi& st, int p, int v) {
    for (st[p += n] = v; 1 < p; ) p >>= 1, st[p] = min(st[p << 1], st[p << 1 | 1]);
  };
  auto query = [&] (vi& st, int l, int r) {
    int res = INF;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) chkmin(res, st[l++]);
      if (r & 1) chkmin(res, st[--r]);
    }
    return res;
  };
  vii stk1;
  vii stk2;
  vi dp(n, INF);
  dp[0] = 0;
  FOR(i, 0, n) {
    while (sz(stk1) && a[i] < stk1.back().fi) {
      int ix = stk1.back().se;
      stk1.pop_back();
      upd(st1, ix, INF);
    }
    while (sz(stk2) && stk2.back().fi < a[i]) {
      int ix = stk2.back().se;
      stk2.pop_back();
      upd(st2, ix, INF);
    }
    stk1.pb({a[i], i});
    stk2.pb({a[i], i});
    chkmin(dp[i], query(st1, l1[i], n - 1) + 1);
    chkmin(dp[i], query(st2, l2[i], n - 1) + 1);
    upd(st1, i, dp[i]);
    upd(st2, i, dp[i]);
  }
  cout << dp[n - 1] << "\n";
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