#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void chemthan() {
  int test; cin >> test;
  while (test--) {
    int n, q; cin >> n >> q;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    vector<vi> adj(n);
    FOR(i, 1, n) {
      int p; cin >> p; p--;
      adj[p].pb(i);
    }
    vector<vector<tuple<int, int, int>>> qs(n);
    FOR(i, 0, q) {
      int v, l, k; cin >> v >> l >> k; v--;
      qs[v].pb({i, l, k});
    }
    vi f(n + 1);
    vi fen(n + 5);
    auto upd = [&] (int p, int v) {
      p++;
      for (; p < sz(fen); p += p & -p) {
        fen[p] += v;
      }
    };
    auto fquery = [&] (int p) {
      p++;
      int res = 0;
      for (; 0 < p; p -= p & -p) {
        res += fen[p];
      }
      return res;
    };
    auto search = [&] (int v) {
      int sum = 0, pos = 0;
      for (int i = 20; 0 <= i; i--) {
        if (pos + (1 << i) < sz(fen) && sum + fen[pos + (1 << i)] < v) {
          sum += fen[pos + (1 << i)];
          pos += 1 << i;
        }
      }
      return pos + 1;
    };
    auto salt = mrand();
    vector<unordered_set<int>> vst(n + 1);
    FOR(i, 1, n + 1) {
      upd(f[i], 1);
      vst[f[i]].insert(i ^ salt);
    }
    auto add = [&] (int x) {
      upd(f[x], -1);
      vst[f[x]].erase(x ^ salt);
      upd(++f[x], 1);
      vst[f[x]].insert(x ^ salt);
    };
    auto rem = [&] (int x) {
      upd(f[x], -1);
      vst[f[x]].erase(x ^ salt);
      upd(--f[x], 1);
      vst[f[x]].insert(x ^ salt);
    };
    auto query = [&] (int l, int k) {
      int d = fquery(l - 1);
      if (n - d < k) {
        return -1;
      }
      int t = search(d + k) - 1;
      return *vst[t].begin() ^ salt;
    };

    vi res(q);
    function<void(int, int)> dfs = [&] (int u, int p) {
      add(a[u]);
      for (auto [ix, l, k] : qs[u]) {
        res[ix] = query(l, k);
      }
      for (int v : adj[u]) {
        if (v ^ p) {
          dfs(v, u);
        }
      }
      rem(a[u]);
    };
    dfs(0, -1);
    FOR(i, 0, q) cout << res[i] << " \n"[i == q - 1];
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
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}