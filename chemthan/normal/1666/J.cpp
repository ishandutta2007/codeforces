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

void chemthan() {
  int n; cin >> n;
  vector<vi> a(n, vi(n));
  FOR(i, 0, n) FOR(j, 0, n) cin >> a[i][j];
  static long long sum1[222][222];
  FOR(i, 0, n) FOR(j, 0, n) {
    if (j) {
      sum1[i][j] += sum1[i][j - 1];
    }
    sum1[i][j] += a[i][j];
  }
  static long long sum2[222][222][222];
  FOR(l, 0, n) FOR(r, l, n) FOR(k, 0, n) {
    if (k) {
      sum2[l][r][k] += sum2[l][r][k - 1];
    }
    sum2[l][r][k] += sum1[k][r];
    if (l) sum2[l][r][k] -= sum1[k][l - 1];
  }
  auto calc = [&] (int l1, int r1, int l2, int r2) {
    long long res = sum2[l1][r1][r2];
    if (l2) res -= sum2[l1][r1][l2 - 1];
    return res;
  };
  static long long dp[222][222][222];
  static int rv[222][222][222];
  FOR(i, 0, 222) FOR(j, 0, 222) FOR(k, 0, 222) dp[i][j][k] = LINF;
  FOR(dep, 0, 1) FOR(diff, -1, n) FOR(l, 0, n + 1) {
    int r = l + diff;
    if (r < 0) continue;
    if (r < l) {
      dp[dep][l][r] = 0;
    }
    else if (l == r) {
      dp[dep][l][r] = calc(l, l, 0, n - 1);
      rv[dep][l][r] = l;
    }
    else {
      FOR(w, l, r + 1) {
        long long cost = (w ? dp[dep][l][w - 1] : 0) + dp[dep][w + 1][r];
        cost += calc(l, r, 0, n - 1);
        cost -= calc(l, r, l, r);
        if (chkmin(dp[dep][l][r], cost)) {
          rv[dep][l][r] = w;
        }
      }
    }
  }

  vi p(n, -1);
  queue<tuple<int, int, int>> que;
  que.push({0, 0, n - 1});
  while (sz(que)) {
    auto [dep, l, r] = que.front();
    que.pop();
    if (l < r) {
      int w = rv[dep][l][r];
      if (l < w) {
        p[rv[dep][l][w - 1]] = w;
        que.push({dep, l, w - 1});
      }
      if (w < r) {
        p[rv[dep][w + 1][r]] = w;
        que.push({dep, w + 1, r});
      }
    }
  }
  FOR(i, 0, n) cout << p[i] + 1 << " \n"[i == n - 1];
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