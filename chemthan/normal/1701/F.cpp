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

struct node_t {
  long long base_num, num;
  long long base_sum, sum;
  long long base_sqsum, sqsum;
  node_t() {
    base_num = 1, num = 0;
    base_sum = sum = 0;
    base_sqsum = sqsum = 0;
  }
};

node_t operator + (node_t a, long long k) {
  a.base_sqsum += 2LL * a.base_sum * k + (long long) a.base_num * k * k;
  a.base_sum += (long long) a.base_num * k;

  a.sqsum += 2LL * a.sum * k + (long long) a.num * k * k;
  a.sum += (long long) a.num * k;
  return a;
}

node_t merge(node_t a, node_t b) {
  node_t c;
  c.base_num = a.base_num + b.base_num;
  c.base_sum = a.base_sum + b.base_sum;
  c.base_sqsum = a.base_sqsum + b.base_sqsum;

  c.num = a.num + b.num;
  c.sum = a.sum + b.sum;
  c.sqsum = a.sqsum + b.sqsum;
  return c;
}

template<class num_t> struct SegmentTree {
  int n;
  vector<num_t> st;
  vector<long long> lz;
  void init(int n_) {
    n = n_;
    st.resize(n << 2);
    lz.resize(n << 2);
  }
  void pushdown(int p, int L, int R) {
    if (lz[p]) {
      st[p] = st[p] + lz[p];
      if (L < R) {
        lz[p << 1] += lz[p];
        lz[p << 1 | 1] += lz[p];
      }
      lz[p] = 0;
    }
  }
  void _upd(int p, int i, int L, int R, int val) {
    pushdown(p, L, R);
    if (i < L || R < i) return;
    if (L == R) {
      st[p].num += val;
      st[p].sum += st[p].base_sum * val;
      st[p].sqsum += st[p].base_sqsum * val;
      return;
    }
    _upd(p << 1, i, L, L + R >> 1, val);
    _upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
    st[p] = merge(st[p << 1], st[p << 1 | 1]);
  }
  void _upd(int p, int l, int r, int L, int R, int val) {
    pushdown(p, L, R);
    if (r < L || R < l) return;
    if (l <= L && R <= r) {
      lz[p] = val;
      pushdown(p, L, R);
      return;
    }
    _upd(p << 1, l, r, L, L + R >> 1, val);
    _upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = merge(st[p << 1], st[p << 1 | 1]);
  }
  void upd(int i, int val) {
    _upd(1, i, 0, n - 1, val);
  }
  void upd(int l, int r, int val) {
    _upd(1, l, r, 0, n - 1, val);
  }
};
SegmentTree<node_t> seg;
SegmentTree<node_t> seg2;

void chemthan() {
  int n, d; cin >> n >> d;
  seg.init(444444);
  seg2.init(444444);
  vi f(444444);
  vi cnt(444444);

  FOR(_, 0, n) {
    int x; cin >> x;
    if (!f[x]) {
      seg.upd(x, +1);
      seg.upd(max(0, x - d), x - 1, +1);
      seg2.upd(x, +1);
      seg2.upd(max(0, x - d), x - 1, 2 * cnt[x] + 1);
      cnt[x]++;
    }
    else {
      seg.upd(x, -1);
      seg.upd(max(0, x - d), x - 1, -1);
      seg2.upd(x, -1);
      seg2.upd(max(0, x - d), x - 1, 1 - 2 * cnt[x]);
      cnt[x]--;
    }
    f[x] ^= 1;
    auto t0 = seg.st[1].sqsum;
    auto t1 = seg2.st[1].sum;
    cout << (t0 - t1) / 2 << "\n";
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
  //cin >> test;
  while (test--)
    chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}