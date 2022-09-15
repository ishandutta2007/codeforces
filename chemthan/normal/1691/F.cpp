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
  int n, k; cin >> n >> k;
  vi fac(n + 1, 1);
  FOR(i, 1, n + 1) fac[i] = mult(fac[i - 1], i);
  vi inv_fac(n + 1);
  FOR(i, 0, n + 1) inv_fac[i] = inv(fac[i]);
  auto binom = [&] (int n, int k) {
    if (n < k) return 0;
    return _mult(fac[n], inv_fac[k], inv_fac[n - k]);
  };
  vector<vi> adj(n);
  FOR(i, 0, n - 1) {
    int u, v; cin >> u >> v; u--, v--;
    adj[u].pb(v), adj[v].pb(u);
  }
  vi size(n);
  vi f(n);
  function<void(int, int)> dfs = [&] (int u, int p) {
    size[u] = 1;
    vi vals;
    for (int v : adj[u]) {
      if (v != p) {
        dfs(v, u);
        size[u] += size[v];
        addmod(f[u], f[v]);
        vals.pb(size[v]);
      }
    }
    int num = binom(size[u], k);
    for (int x : vals) {
      submod(num, binom(x, k));
    }
    addmod(f[u], mult(size[u], num));
  };
  dfs(0, -1);
  int res = 0;
  function<void(int, int, int)> dfs2 = [&] (int u, int p, int up_cnt) {
    addmod(res, up_cnt);
    vi vals;
    if (p != -1) {
      vals.pb(n - size[u]);
    }
    for (int v : adj[u]) {
      if (v != p) {
        addmod(up_cnt, f[v]);
        addmod(res, f[v]);
        vals.pb(size[v]);
      }
    }
    int tot = 0;
    for (int x : vals) {
      addmod(tot, binom(x, k));
    }
    for (int v : adj[u]) {
      if (v != p) {
        int n_up_cnt = up_cnt;
        submod(n_up_cnt, f[v]);

        int temp = binom(n - size[v], k);
        submod(temp, tot);
        addmod(temp, binom(size[v], k));
        addmod(n_up_cnt, mult(n - size[v], temp));

        dfs2(v, u, n_up_cnt);
      }
    }
    int num = binom(n, k);
    for (int x : vals) {
      submod(num, binom(x, k));
    }
    addmod(res, mult(n, num));
  };
  dfs2(0, -1, 0);
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
  int test = 1;
  //cin >> test;
  while (test--)
    chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}