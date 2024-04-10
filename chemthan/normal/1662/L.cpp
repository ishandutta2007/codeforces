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

const int sx = 2e5 + 5;
vector<vector<int>> nodes(sx + 1);
vector<vector<int>> f(sx + 1);

void fake_update(int x, int y) {
  for (; x <= sx; x += x & -x)
    nodes[x].push_back(y);
}

void update(int u, int v, int val) {
  for(int x = u; x <= sx; x += x & -x)
    for(int y = lower_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin() + 1; y <= (int) nodes[x].size(); y += y & -y)
      chkmax(f[x][y], val);
}

int get(int u, int v) {
  int res = -INF;
  for(int x = u; x > 0; x -= x & -x)
    for(int y = upper_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin(); y > 0; y -= y & -y)
      chkmax(res, f[x][y]);
  return res;
}

void chemthan() {
  int n, v; cin >> n >> v;
  vector<long long> t(n);
  FOR(i, 0, n) cin >> t[i], t[i] *= v;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  vector<long long> dcx, dcy;
  FOR(i, 0, n) dcx.pb(t[i] + a[i]), dcy.pb(t[i] - a[i]);
  sort(all(dcx)), sort(all(dcy));
  uni(dcx), uni(dcy);
  for (int i = 0; i < n; i++) {
    int x = lower_bound(all(dcx), t[i] + a[i]) - dcx.begin() + 1;
    int y = lower_bound(all(dcy), t[i] - a[i]) - dcy.begin() + 1;
    fake_update(x, y);
  }
  FOR(i, 1, sx + 1) {
    nodes[i].push_back(INF);
    sort(all(nodes[i]));
    uni(nodes[i]);
    f[i].resize(nodes[i].size() + 1, -INF);
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x = lower_bound(all(dcx), t[i] + a[i]) - dcx.begin() + 1;
    int y = lower_bound(all(dcy), t[i] - a[i]) - dcy.begin() + 1;
    int mx = get(x, y) + 1;
    if (abs(a[i]) <= t[i]) {
      chkmax(mx, 1);
    }
    chkmax(res, mx);
    update(x, y, mx);
  }
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