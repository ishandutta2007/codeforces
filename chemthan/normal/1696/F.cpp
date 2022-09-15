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
  vector<vector<vi>> g(n, vector<vi>(n, vi(n)));
  FOR(i, 0, n - 1) {
    FOR(j, 1, n - i) {
      string s; cin >> s;
      FOR(k, 0, n) {
        if (s[k] == '1') {
          g[i][i + j][k] = g[i + j][i][k] = 1;
        }
      }
    }
  }
  vector<vi> d(n, vi(n, INF));
  FOR(u, 0, n) d[u][u] = 0;
  vi used(n);
  vii edges;
  auto rec = [&] (auto&& rec, int pos) {
    if (pos == n) {
      return;
    }
    vi f(n, INF);
    FOR(i, 0, n) if (!used[i]) {
      f[i] = 0;
      FOR(u, 0, n) FOR(v, u + 1, n) if (!used[u] && !used[v]) {
        f[i] += g[u][v][i];
      }
    }
    int ix = min_element(all(f)) - f.begin();
    used[ix] = 1;
    vi ver;
    FOR(u, 0, n) if (!used[u]) {
      ver.pb(u);
    }
    rec(rec, pos + 1);
    for (int u : ver) {
      for (int v : ver) {
        d[ix][v] = d[v][ix] = d[u][v] + 1;
      }
      int found = 0;
      for (int i1 : ver) if (!found) for (int i2 : ver) if (!found) {
        int ar[] = {i1, i2, ix};
        sort(ar, ar + 3);
        do {
          if ((d[ar[0]][ar[2]] == d[ar[1]][ar[2]]) != g[ar[0]][ar[1]][ar[2]] && ar[0] != ar[1]) {
            found = 1;
            break;
          }
        }
        while (next_permutation(ar, ar + 3));
      }
      if (!found) {
        edges.pb({ix, u});
        break;
      }
    }
  };
  rec(rec, 0);
  if (sz(edges) != n - 1) {
    cout << "No\n";
    return;
  }
  FOR(u, 0, n) FOR(v, u + 1, n) FOR(w, 0, n) {
    if ((d[u][w] == d[v][w]) != g[u][v][w]) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  for (auto [x, y] : edges) {
    cout << x + 1 << " " << y + 1 << "\n";
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
  cin >> test;
  while (test--)
    chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}