#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define int long long

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
//const int MOD = (int) 1e9 + 7;
const int MOD = 119 << 23 | 1;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-12;
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
  int n, m; cin >> n >> m;
  int p, q; cin >> p >> q;
  vector<string> a(n);
  FOR(i, 0, n) cin >> a[i];
  auto ids = [&] (int r, int c) {
    return r * m + c;
  };
  vector<vii> adj(n * m);
  FOR(i, 0, n) FOR(j, 0, m) {
    if (j + 1 < m && a[i][j] == '.' && a[i][j + 1] == '.') {
      cout << 0 << "\n";
      return;
    }
    if (i + 1 < n && a[i][j] == '.' && a[i + 1][j] == '.') {
      cout << 0 << "\n";
      return;
    }
    if (a[i][j] == 'L' || a[i][j] == 'U') {
      int ii = i + (a[i][j] == 'U');
      int jj = j + (a[i][j] == 'L');
      int dx[] = {1, -1, 0, 0};
      int dy[] = {0, 0, 1, -1};
      FOR(d, 0, 4) {
        {
          int i2 = i + dx[d];
          int j2 = j + dy[d];
          if (0 <= i2 && i2 < n && 0 <= j2 && j2 < m && a[i2][j2] != '#' && mp(i2, j2) != mp(ii, jj)) {
            int cost = 0;
            if (a[i][j] == 'L') {
              if (dx[d]) {
                cost = p;
              }
              else {
                cost = q;
              }
            }
            else {
              if (dy[d]) {
                cost = p;
              }
              else {
                cost = q;
              }
            }
            int ix1 = ids(i2, j2);
            int ix2 = ids(ii, jj);
            adj[ix1].pb({ix2, cost});
          }
        }
        {
          int i2 = ii + dx[d];
          int j2 = jj + dy[d];
          if (0 <= i2 && i2 < n && 0 <= j2 && j2 < m && a[i2][j2] != '#' && mp(i2, j2) != mp(i, j)) {
            int cost = 0;
            if (a[i][j] == 'L') {
              if (dx[d]) {
                cost = p;
              }
              else {
                cost = q;
              }
            }
            else {
              if (dy[d]) {
                cost = p;
              }
              else {
                cost = q;
              }
            }
            int ix1 = ids(i2, j2);
            int ix2 = ids(i, j);
            adj[ix1].pb({ix2, cost});
          }
        }
      }
    }
  }
  vector<long long> dp(n * m, LINF);
  priority_queue<pair<long long, int>> heap;
  FOR(i, 0, n) FOR(j, 0, m) if (a[i][j] == '.') {
    int ix = ids(i, j);
    dp[ix] = 0;
    heap.push({-dp[ix], ix});
  }
  while (sz(heap)) {
    auto t = -heap.top().fi;
    int u = heap.top().se;
    heap.pop();
    if (dp[u] != t) continue;
    for (auto [v, w] : adj[u]) {
      if (chkmin(dp[v], dp[u] + w)) {
        heap.push({-dp[v], v});
      }
    }
  }
  long long res = LINF;
  FOR(i, 0, n) FOR(j, 0, m) {
    int dx[] = {0, 1};
    int dy[] = {1, 0};
    FOR(d, 0, 2) {
      int ii = i + dx[d];
      int jj = j + dy[d];
      if (0 <= ii && ii < n && 0 <= jj && jj < m) {
        if (a[i][j] != '#' && a[ii][jj] != '#') {
          int ix1 = ids(i, j);
          int ix2 = ids(ii, jj);
          chkmin(res, dp[ix1] + dp[ix2]);
        }
      }
    }
  }
  if (res == LINF) res = -1;
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
  int test = 1;
  //cin >> test;
  FOR(it, 1, test + 1) {
    chemthan();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}