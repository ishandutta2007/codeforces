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

template<typename num_t>
struct RangeFenwick {
    int n;
    vector<num_t> fen[2];
    RangeFenwick(int n) {
        this->n = n;
        fen[0].resize(n + 1);
        fen[1].resize(n + 1);
    }
    void upd(int p, num_t val) {
        p++;
        assert(0 < p);
        for (int pp = p; pp <= n; pp += pp & -pp) {
            fen[0][pp] += val;
            fen[1][pp] += val * p;
        }
    }
    void upd(int l, int r, num_t val) {
        upd(l, +val), upd(r + 1, -val);
    }
    num_t query(int p) {
        p++;
        assert(p <= n);
        num_t res = 0;
        for (int pp = p; pp > 0; pp -= pp & -pp) {
            res += fen[0][pp] * (p + 1);
            res -= fen[1][pp];
        }
        return res;
    }
    num_t query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void chemthan() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vi l(n), r(n);
  FOR(i, 0, n) {
    cin >> l[i] >> r[i], l[i]--, r[i]--;
  }
  vi ver;
  vector<vi> par(20, vi(n));
  vi tin(n);
  vi tou(n);
  int timer = 0;
  string res;
  function<void(int)> dfs = [&] (int u) {
    tin[u] = timer++;
    FOR(i, 1, 20) par[i][u] = par[i - 1][par[i - 1][u]];
    if (~l[u]) {
      par[0][l[u]] = u;
      dfs(l[u]);
    }
    ver.pb(u);
    res += s[u];
    if (~r[u]) {
      par[0][r[u]] = u;
      dfs(r[u]);
    }
    tou[u] = timer - 1;
  };
  dfs(0);
  vi fen(n + 1);
  auto upd = [&] (int p, int v) {
    p++;
    for (; p < sz(fen); p += p & -p) {
      fen[p] += v;
    }
  };
  auto query = [&] (int p) {
    p++;
    int res = 0;
    for (; 0 < p; p -= p & -p) {
      res += fen[p];
    }
    return res;
  };
  auto calc = [&] (int u) {
    if (query(tin[u] - 1) != query(tou[u])) {
      return 0;
    }
    int res = 1;
    if (!u) return res;
    FORd(i, 20, 0) {
      if (par[i][u] && query(tin[par[i][u]] - 1) == query(tou[par[i][u]])) {
        u = par[i][u];
        res += 1 << i;
      }
    }
    if (query(tin[par[0][u]] - 1) == query(tou[par[0][u]])) {
      u = par[0][u];
      res += 1 << 0;
    }
    return res;
  };
  vi f(n);
  FORd(i, n - 1, 0) {
    int u = ver[i];
    int v = ver[i + 1];
    if (s[u] != s[v]) {
      f[i] = s[v];
    }
    else {
      f[i] = f[i + 1];
    }
  }
  string ss;
  RangeFenwick<int> rf(n);
  FOR(i, 0, n - 1) {
    int u = ver[i];
    ss += s[u];
    if (query(tin[u] - 1) != query(tou[u])) {
        ss += s[u];
    }
    else if (s[u] < f[i]) {
      if (rf.query(tin[u] - 1) == rf.query(tin[u])) {
        int x = calc(u);
        if (x <= k) {
          k -= x;
          ss += s[u];
          upd(tin[u], 1);
        }
      }
      else {
        rf.upd(tin[u], tou[u], 1);
      }
    }
    else {
      rf.upd(tin[u], tou[u], 1);
    }
  }
  int u = ver[n - 1];
  ss += s[u];
  if (query(tin[u] - 1) != query(tou[u])) {
    ss += s[u];
  }
  cout << ss << "\n";
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