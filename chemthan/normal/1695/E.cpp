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

namespace Euler {
  vector<vi> find(const vector<pair<int, int>>& edges) {
    vector<vector<pair<int, int>>> adj;
    vector<int> dup;
    for (int i = 0; i < (int) edges.size(); i++) {
      int u = edges[i].first;
      int v = edges[i].second;
      if (u ^ v) {
        for (int j = 0; j < 2; j++) {
          while ((int) adj.size() <= u) {
            adj.push_back(vector<pair<int, int>>());
          }
          adj[u].push_back(make_pair(v, i));
          swap(u, v);
        }
      }
      else {
        while ((int) dup.size() <= u) {
          dup.push_back(0);
        }
        dup[u]++;
      }
    }
    vector<int> f(edges.size());
    vector<int> res, stk;
    vi vis(max(sz(adj), sz(dup)));
    function<void(int)> dfs = [&] (int u) {
      vis[u] = 1;
      stk.push_back(u);
      while (u < (int) adj.size() && !adj[u].empty()) {
        int v = adj[u].back().first;
        int e = adj[u].back().second;
        adj[u].pop_back();
        if (!f[e]) {
          f[e] = 1, dfs(v);
        }
      }
      int v = stk.back();
      stk.pop_back();
      res.push_back(v);
      while (v < (int) dup.size() && dup[v]) {
        res.push_back(v);
        dup[v]--;
      }
    };
    vector<vi> vres;
    FOR(u, 0, max(sz(adj), sz(dup))) if (!vis[u]) {
      res.clear();
      dfs(u);
      if (1 < sz(res)) {
        vres.pb(res);
      }
    }
    return vres;
  }
};

void chemthan() {
  int n; cin >> n;
  vii edges;
  FOR(i, 0, n) {
    int x, y; cin >> x >> y; x--, y--;
    edges.pb({x, y});
    edges.pb({y, x});
  }
  auto vres = Euler::find(edges);
  if (!sz(vres)) {
    cout << -1 << "\n";
    return;
  }
  vector<vi> a(2, vi(n));
  vector<string> x(2, string(n, 'a'));
  vector<string> y(2, string(n, 'a'));
  int ptr = 0;
  for (auto res : vres) {
    int k = sz(res) - 1;
    if (k < 4) {
      cout << -1 << "\n";
      return;
    }
    FOR(i, 0, k / 2) {
      int u = res[i];
      int v = res[i + 1];
      a[0][ptr + i] = u + 1;
      int go_r = i < k / 2 - 1;
      if (!(i & 1)) {
        x[0][ptr + i] = go_r ? 'L' : 'U';
        x[!go_r][ptr + i + go_r] = go_r ? 'R' : 'D';
      }
      else {
        y[0][ptr + i] = go_r ? 'L' : 'U';
        y[!go_r][ptr + i + go_r] = go_r ? 'R' : 'D';
      }
    }
    FOR(i, 0, k / 2) {
      int u = res[k / 2 + i];
      int v = res[k / 2 + i + 1];
      a[1][ptr + k / 2 - 1 - i] = u + 1;
      int go_l = i < k / 2 - 1;
      if (!(k / 2 + i & 1)) {
        x[1][ptr + k / 2 - 1 - i] = go_l ? 'R' : 'D';
        x[1 - !go_l][ptr + k / 2 - 1 - i - go_l] = go_l ? 'L' : 'U';
      }
      else {
        y[1][ptr + k / 2 - 1 - i] = go_l ? 'R' : 'D';
        y[1 - !go_l][ptr + k / 2 - 1 - i - go_l] = go_l ? 'L' : 'U';
      }
    }
    ptr += k / 2;
  }
  cout << 2 << " " << n << "\n\n";
  FOR(i, 0, 2) FOR(j, 0, n) cout << a[i][j] << " \n"[j == n - 1];
  cout << "\n";
  FOR(i, 0, 2) cout << x[i] << "\n";
  cout << "\n";
  FOR(i, 0, 2) cout << y[i] << "\n";
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