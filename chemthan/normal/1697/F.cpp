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

#define pos(v) ((v) << 1)
#define neg(v) (pos(v) ^ 1)
struct Twosat {
  static const int maxv = 3e6 + 5;
  int n;
  vector<int> forward[maxv], backward[maxv];
  bool used[maxv];
  int cnt, order[maxv], comp[maxv];
  void init(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) {
      forward[i].clear();
      backward[i].clear();
    }
  }
  void add(int u, int v) {
    forward[u].push_back(v);
    backward[v].push_back(u);
  }
  void dfs1(int u) {
    used[u] = true;
    for (int i = 0; i < forward[u].size(); i++) {
      int v = forward[u][i];
      if (!used[v]) dfs1(v);
    }
    order[cnt++] = u;
  }
  void dfs2(int u, int c) {
    comp[u] = c;
    for (int i = 0; i < backward[u].size(); i++) {
      int v = backward[u][i];
      if (comp[v] == -1) dfs2(v, c);
    }
  }
  int solve(vector<int>& res) {
    cnt = 0;
    fill_n(used, n, 0);
    for (int u = 0; u < n; u++) if (!used[u]) dfs1(u);
    fill_n(comp, n, -1);
    int c = 0;
    for (int i = n - 1; i >= 0; i--) {
      int u = order[i];
      if (comp[u] == -1) dfs2(u, c++);
    }
    for (int u = 0; u < n; u += 2)
      if (comp[u] == comp[u ^ 1]) return 0;
    res.clear();
    for (int u = 0; u < n; u += 2) {
      int choose = (comp[u] > comp[u ^ 1]) ? u : u ^ 1;
      res.push_back(choose);
    }
    return 1;
  }
} twosat;

void chemthan() {
  int test; cin >> test;
  while (test--) {
    int n, m, k; cin >> n >> m >> k;
    twosat.init(2 * n * (k + 1));
    auto id = [&] (int u, int v) {
      return u * (k + 1) + v;
    };
    FOR(i, 0, m) {
      int op; cin >> op;
      if (op == 1) {
        int u, v; cin >> u >> v; u--;
        twosat.add(pos(id(u, v)), pos(id(u, v - 1)));
        twosat.add(neg(id(u, v - 1)), neg(id(u, v)));
      }
      else if (op == 2) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        //a[u] + a[v] <= w
        FOR(i, 1, k + 1) {
          if (0 <= w - i && w - i <= k) {
            twosat.add(neg(id(u, i - 1)), pos(id(v, w - i)));
            twosat.add(neg(id(v, i - 1)), pos(id(u, w - i)));
          }
        }
        if (w - 1 <= k) {
          twosat.add(neg(id(u, w - 1)), pos(id(u, w - 1)));
          twosat.add(neg(id(v, w - 1)), pos(id(v, w - 1)));
        }
      }
      else {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        //w <= a[u] + a[v]
        FOR(i, 0, k + 1) {
          if (0 < w - i && w - i - 1 <= k) {
            twosat.add(pos(id(u, i)), neg(id(v, w - i - 1)));
            twosat.add(pos(id(v, i)), neg(id(u, w - i - 1)));
          }
        }
      }
    }
    FOR(i, 0, n) {
      twosat.add(pos(id(i, 0)), neg(id(i, 0)));
      twosat.add(neg(id(i, k)), pos(id(i, k)));
      FOR(j, 0, k + 1) {
        if (j + 1 < k) {
          twosat.add(pos(id(i, j)), pos(id(i, j + 1)));
          twosat.add(neg(id(i, j + 1)), neg(id(i, j)));
        }
        if (i + 1 < n) {
          twosat.add(pos(id(i + 1, j)), pos(id(i, j)));
          twosat.add(neg(id(i, j)), neg(id(i + 1, j)));
        }
      }
    }
    vi res;
    if (!twosat.solve(res)) {
      cout << -1 << "\n";
      continue;
    }
    vi f(2 * n * (k + 1));
    for (auto e : res) {
      f[e] = 1;
    }
    FOR(i, 0, n) {
      FOR(j, 1, k + 1) {
        if (f[pos(id(i, j))]) {
          cout << j << " \n"[i == n - 1];
          break;
        }
      }
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
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}