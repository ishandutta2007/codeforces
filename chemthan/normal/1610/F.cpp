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
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

namespace Euler {
  vector<vector<int>> find(const vector<pair<int, int>>& edges, int st) {
    vector<vector<pair<int, int>>> adj(st + 1);
    vector<int> vis(st + 1);
    vector<int> dup(st + 1);
    for (int i = 0; i < (int) edges.size(); i++) {
      int u = edges[i].first;
      int v = edges[i].second;
      if (u ^ v) {
        for (int j = 0; j < 2; j++) {
          while ((int) adj.size() <= u) {
            adj.push_back(vector<pair<int, int>>());
            vis.push_back(0);
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
    vector<int> stk;
    vector<vector<int>> res;
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
      res.back().push_back(v);
      while (v < (int) dup.size() && dup[v]) {
        res.back().push_back(v);
        dup[v]--;
      }
    };

    vector<int> vv;
    for (int u = 0; u < (int) adj.size(); u++) {
      vv.push_back(u);
    }
    sort(vv.begin(), vv.end(), [&] (int u, int v) {
        int su = adj[u].size() & 1;
        int sv = adj[v].size() & 1;
        if (su != sv) return su;
        return make_pair(u != st, u) < make_pair(v != st, v) ? 1 : 0;
        });
    for (int u : vv) if (!vis[u]) {
      res.push_back({});
      dfs(u);
    }
    return res;
  }
};

void chemthan() {
  int n, m; cin >> n >> m;
  vii edges1;
  vii edges2;
  vi s1(n);
  vi s2(n);
  map<pi, vi> pool1;
  map<pi, vi> pool2;
  FOR(i, 0, m) {
    int u, v, w; cin >> u >> v >> w; u--, v--;
    if (w == 1) {
      edges1.pb({u, v});
      pool1[mp(u, v)].pb(i);
      s1[u]++, s1[v]++;
    }
    else {
      edges2.pb({u, v});
      pool2[mp(u, v)].pb(i);
      s2[u]++, s2[v]++;
    }
  }

  auto get = [&] (map<pi, vi>& pool, int u, int v) {
    if (auto& vv = pool[mp(u, v)]; sz(vv)) {
      auto res = vv.back(); vv.pop_back();
      return mp(res, 0);
    }
    else if (auto& vv = pool[mp(v, u)]; sz(vv)) {
      auto res = vv.back(); vv.pop_back();
      return mp(res, 1);
    }
    return mp(-1, -1);
  };

  vi res(m, 1);
  {
    FOR(i, 0, n) {
      if (s2[i] & 1) {
        edges2.pb({n, i});
      }
    }
    auto paths = Euler::find(edges2, n);
    const auto& path = paths[0];
    vi cycles;
    FOR(i, 0, sz(path)) {
      int j = (i + 1) % sz(path);
      int u = path[i];
      int v = path[j];
      if (u == n && v < n) {
        cycles.pb(j);
      }
      else if (u < n && v == n) {
        cycles.pb(i);
      }
    }
    for (int i = 0; i + 1 < sz(cycles); i += 2) {
      int x = cycles[i];
      int y = cycles[i + 1];
      int u = path[x];
      int v = path[y];
      edges1.pb({u, v});
      s1[u]++, s1[v]++;
    }
    FOR(i, 1, sz(paths)) {
      const auto& path = paths[i];
      FOR(i, 0, sz(path)) {
        int j = (i + 1) % sz(path);
        int u = path[i];
        int v = path[j];
        auto [ix, dir] = get(pool2, u, v);
        res[ix] = 1 + dir;
      }
    }
  }

  vi f(n);
  map<pi, int> mem;
  {
    FOR(i, 0, n) {
      if (s1[i] & 1) {
        edges1.pb({n, i});
      }
    }
    auto paths = Euler::find(edges1, n);
    const auto& path = paths[0];
    FOR(i, 0, sz(path)) {
      int j = (i + 1) % sz(path);
      int u = path[i];
      int v = path[j];
      if (u < n && v < n) {
        f[u] += 1, f[v] -= 1;
        auto [ix, dir] = get(pool1, u, v);
        if (dir == 0) {
          res[ix] = 1;
        }
        else if (dir == 1) {
          res[ix] = 2;
        }
        else {
          f[u] += 1, f[v] -= 1;
          mem[mp(u, v)]++;
        }
      }
    }
    FOR(i, 1, sz(paths)) {
      const auto& path = paths[i];
      FOR(i, 0, sz(path) - 1) {
        int j = (i + 1) % sz(path);
        int u = path[i];
        int v = path[j];
        auto [ix, dir] = get(pool1, u, v);
        if (0 <= dir) {
          res[ix] = 1 + dir;
        }
        else {
          f[u] += 1, f[v] -= 1;
          mem[mp(u, v)]++;
        }
      }
    }
  }

  {
    auto paths = Euler::find(edges2, n);
    const auto& path = paths[0];
    vi cycles;
    FOR(i, 0, sz(path)) {
      int j = (i + 1) % sz(path);
      int u = path[i];
      int v = path[j];
      if (u == n && v < n) {
        cycles.pb(j);
      }
      else if (u < n && v == n) {
        cycles.pb(i);
      }
    }
    for (int i = 0; i + 1 < sz(cycles); i += 2) {
      int x = cycles[i];
      int y = cycles[i + 1];
      int u = path[x];
      int v = path[y];
      if (mem[mp(u, v)]) {
        mem[mp(u, v)]--;
        for (int i = x; i < y; i++) {
          int p = path[i];
          int q = path[i + 1];
          auto [ix, dir] = get(pool2, p, q);
          res[ix] = 1 + dir;
        }
      }
      else {
        assert(mem[mp(v, u)]);
        mem[mp(v, u)]--;
        for (int i = x; i < y; i++) {
          int p = path[i];
          int q = path[i + 1];
          auto [ix, dir] = get(pool2, p, q);
          res[ix] = 1 + (dir ^ 1);
        }
      }
    }
  }

  int num = 0;
  FOR(i, 0, n) {
    if (abs(f[i]) == 1) {
      num++;
    }
  }
  cout << num << "\n";
  FOR(i, 0, m) cout << res[i];
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
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}