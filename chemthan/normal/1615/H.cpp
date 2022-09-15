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

template<class T, T oo> struct Dinic {
  static const int MAXV = 1e5 + 5;
  static const int MAXE = 1e6 + 5;
  int n, s, t, E;
  int adj[MAXE], nxt[MAXE], lst[MAXV], ptr[MAXV], lev[MAXV], que[MAXV];
  T flw[MAXE], cap[MAXE];
  void init(int n, int s, int t) {
    this->n = n, this->s = s, this->t = t, E = 0;
    fill_n(lst, n, -1);
  }
  void add(int u, int v, T c1, T c2) {
    adj[E] = v, flw[E] = 0, cap[E] = c1, nxt[E] = lst[u], lst[u] = E++;
    adj[E] = u, flw[E] = 0, cap[E] = c2, nxt[E] = lst[v], lst[v] = E++;
  }
  int bfs() {
    fill_n(lev, n, -1), lev[s] = 0;
    int qsize = 0;
    que[qsize++] = s;
    for (int i = 0; i < qsize; i++) {
      for (int u = que[i], e = lst[u]; ~e; e = nxt[e]) {
        int v = adj[e];
        if (flw[e] < cap[e] && !~lev[v]) {
          lev[v] = lev[u] + 1;
          que[qsize++] = v;
        }
      }
    }
    return lev[t] != -1;
  }
  T dfs(int u, T bot) {
    if (u == t) return bot;
    for (int& e = ptr[u]; ~e; e = nxt[e]) {
      int v = adj[e];
      T delta = 0;
      if (lev[v] == lev[u] + 1 && flw[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flw[e]))) > 0) {
        flw[e] += delta; flw[e ^ 1] -= delta;
        return delta;
      }
    }
    return 0;
  }
  T maxflow() {
    T total = 0;
    while (bfs()) {
      for (int i = 0; i < n; i++) ptr[i] = lst[i];
      for (T delta = dfs(s, oo); delta > 0; delta = dfs(s, oo)) total += delta;
    }
    return total;
  }
  pair<vi, vi> getmincut() {
    pair<vi, vi> res;
    static int vis[MAXV];
    fill_n(vis, n, 0);
    queue<int> que;
    vis[s] = 1, que.push(s);
    while (sz(que)) {
      int u = que.front(); que.pop();
      if (u != s) {
        res.fi.pb(u);
      }
      for (int e = lst[u]; ~e; e = nxt[e]) if (flw[e] < cap[e]) {
        int v = adj[e];
        if (!vis[v]) {
          vis[v] = 1, que.push(v);
        }
      }
    }
    FOR(u, 0, n) if (u != t && !vis[u]) {
      res.se.pb(u);
    }
    return res;
  }
};
Dinic<long long, (long long) 1e18> dinic;

const int maxn = 1e5 + 5;
int n, m;
vi adj[maxn];
int d[maxn];

inline int ff(int x, int d) {
  return abs(x - d) - abs(x - 1 - d);
}

long long divide(vi ver, int lo, int hi) {
  if (!sz(ver)) return 0;
  int x = (lo + hi + 1) / 2;
  if (lo == hi) {
    long long res = 0;
    FOR(i, 0, sz(ver)) {
      int u = ver[i];
      d[u] = x;
    }
    return res;
  }
  map<int, int> hs;
  FOR(i, 0, sz(ver)) {
    int u = ver[i];
    hs[u] = i;
  }
  int tot = sz(ver), s = tot++, t = tot++;
  dinic.init(tot, s, t);
  FOR(i, 0, sz(ver)) {
    int u = ver[i];
    int w = ff(x, d[u]);
    if (w < 0) {
      dinic.add(s, i, -w, 0);
    }
    else {
      dinic.add(i, t, +w, 0);
    }
    FOR(j, 0, sz(adj[u])) {
      int v = adj[u][j];
      if (hs.count(v)) {
        dinic.add(i, hs[v], INF, 0);
      }
    }
  }
  dinic.maxflow();
  pair<vi, vi> res = dinic.getmincut();
  vi v1, v2;
  FOR(i, 0, sz(res.fi)) {
    v2.pb(ver[res.fi[i]]);
  }
  FOR(i, 0, sz(res.se)) {
    v1.pb(ver[res.se[i]]);
  }
  return divide(v1, lo, x - 1) + divide(v2, x, hi);
}

void chemthan() {
  cin >> n >> m;
  FOR(i, 0, n) cin >> d[i];
  FOR(i, 0, m) {
    int u, v; cin >> u >> v; u--, v--;
    adj[u].pb(v);
  }
  vi ver;
  FOR(i, 0, n) ver.pb(i);
  divide(ver, -INF, +INF);
  FOR(i, 0, n) cout << d[i] << " \n"[i ==n - 1];
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