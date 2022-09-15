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
template<typename X> void debug(X x) { cerr << x << "] "; }
template<typename X, typename ...Y> void debug(X x, Y... y) { cerr << x << " "; debug(y...); }
#define db(...) cerr << "[" << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#define endln cerr << "\n";

template<class num_t, class cmp = less<num_t> >
struct RMQ {
  int n;
  vector<num_t> a;
  vector<vector<num_t> > f;
  vector<int> mlg;

  inline num_t best(const num_t& a, const num_t& b) {
    if (cmp()(a, b)) return a;
    return b;
  }
  void init(int _n) {
    n = _n;
    int p = 1; while ((1 << p) < n) p++;
    a.resize(n), f.resize(p + 1);
    a.shrink_to_fit(), f.shrink_to_fit();
    for (int i = 0; i < (int) f.size(); i++) {
      f[i].resize(n);
    }
    mlg.resize(n);
    for (int i = 0; i < n; i++) {
        mlg[i] = !i ? 0 : __lg(i);
    }
  }
  num_t& operator [] (int u) {
    assert(u < (int) a.size());
    return a[u];
  }
  void build() {
    for (int i = 0; i < n; i++) f[0][i] = a[i];
    for (int l = 0, k; (k = 1 << l) < n; l++) {
      for (int i = 0; i + k < n; i++) {
        f[l + 1][i] = best(f[l][i], f[l][i + k]);
      }
    }
  }
  num_t query(int a, int b) {
    int l = mlg[b - a];
    return best(f[l][a], f[l][b - (1 << l) + 1]);
  }
};
RMQ<long long> rmq;

void chemthan() {
  int n; cin >> n;
  vector<long long> a(n);
  FOR(i, 0, n) cin >> a[i];
  auto calc = [&] (int p, int q) {
    long long res = 0;
    vi l(n), r(n);
    FOR(i, 0, n) l[i] = r[i] = i;
    FOR(i, 1, n) {
      int ptr = i;
      while (ptr && a[ptr - 1] + p <= a[i]) ptr = l[ptr - 1];
      l[i] = ptr;
    }
    FORd(i, n - 1, 0) {
      int ptr = i;
      while (ptr + 1 < n && a[ptr + 1] + q <= a[i]) ptr = r[ptr + 1];
      r[i] = ptr;
    }
    rmq.init(n);
    FOR(i, 0, n) rmq[i] = a[i];
    rmq.build();
    vector<vector<pair<long long, int>>> cnts(100);
    vector<vii> cnt2s(100);
    auto add = [&] (pair<long long, int> v, int pos) {
      int k = bitcount(v.fi);
      auto& cnt = cnts[k];
      if (!sz(cnt)) {
        cnt.pb(v);
      }
      else {
        cnt.pb({v.fi, v.se + cnt.back().se});
      }
      auto& cnt2 = cnt2s[k];
      if (!sz(cnt2)) {
        cnt2.pb({pos, v.se});
      }
      else {
        cnt2.pb({pos, v.se + cnt2.back().se});
      }
    };
    auto rem = [&] (pair<long long, int> v) {
      int k = bitcount(v.fi);
      auto& cnt = cnts[k];
      cnt.pop_back();
      auto& cnt2 = cnt2s[k];
      cnt2.pop_back();
    };
    vector<pair<long long, int>> stk;
    auto query = [&] (int k, long long mn, int left) {
      int res = 0;
      auto& cnt = cnts[k];
      int d = upper_bound(all(cnt), mp(mn, INF)) - cnt.begin() - 1;
      if (0 <= d) {
        res += cnt[d].se;

        auto& cnt2 = cnt2s[k];
        int d2 = lower_bound(cnt2.begin(), cnt2.begin() + d + 1, mp(left, -INF)) - cnt2.begin();
        if (0 < d2) {
          res -= cnt2[d2 - 1].se;
        }
        if (d2 <= d) {
          int len = cnt2[d2].se - (d2 ? cnt2[d2 - 1].se : 0);
          int l = cnt2[d2].fi - len + 1;
          if (l < left) {
            res -= left - l;
          }
        }
      }
      return res;
    };
    FOR(i, 0, n) {
      int c = 1;
      while (sz(stk) && a[i] < stk.back().fi) {
        rem(stk.back());
        c += stk.back().se;
        stk.pop_back();
      }
      add({a[i], c}, i);
      stk.pb({a[i], c});
      if (r[i] - i + p <= i - l[i]) {
        long long mn = a[i];
        FOR(j, i, r[i] + 1) {
          chkmin(mn, a[j]);
          int lo = 0, hi = i + 1;
          while (lo < hi) {
            int mi = lo + hi >> 1;
            if (rmq.query(mi, i) <= mn) {
              lo = mi + 1;
            }
            else {
              hi = mi;
            }
          }
          int t = lo + hi >> 1;
          if (bitcount(a[i]) == bitcount(mn)) {
            res += i - max(l[i], t) + 1;
          }
          if (t) {
            res += query(bitcount(a[i]), mn, l[i]);
          }
        }
      }
    }
    return res;
  };
  long long res = 0;
  res += calc(0, 1);
  reverse(all(a));
  res += calc(1, 0);
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
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}