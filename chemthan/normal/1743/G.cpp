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
  int n; cin >> n;
  vi pos;
  static bitset<3333333> bs;
  int k = 0;
  FOR(i, 0, n) {
    string s; cin >> s;
    FOR(j, 0, sz(s)) {
      bs[k++] = s[j] - '0';
    }
    pos.pb(sz(s));
  }

  int magic = 2;
  auto ispr = [&] (int k) {
    for (int i = 2; i * i <= k; i++) {
      if (k % i == 0) {
        return 0;
      }
    }
    return 1;
  };
  vi prs;
  vi bases;
  FOR(_, 0, magic) {
    int pr = INF - mrand(INF / 100);
    while (!ispr(pr)) pr++;
    int base = 2311 + mrand(1992);
    prs.pb(pr);
    bases.pb(base);
  }
  auto get = [&] (string s) {
    vi res;
    FOR(i, 0, sz(prs)) {
      auto& pr = prs[i];
      auto& base = bases[i];
      int h = 0;
      FOR(j, 0, sz(s)) {
        addmod(h, mult(fpow(base, j, pr), s[j] - '0', pr), pr);
      }
      res.pb(h);
    }
    return res;
  };
  int a = 1, b = 1;
  vector<vi> vh = {get("0"), get("1")};
  vi vl = {1, 1};
  while (1) {
    auto c = b + a;
    if (k < c) break;
    vi va = vh[sz(vh) - 2];
    vi vb = vh[sz(vh) - 1];
    vi vc(magic);
    FOR(i, 0, magic) {
      auto& pr = prs[i];
      auto& base = bases[i];
      vc[i] = va[i];
      addmod(vc[i], mult(vb[i], fpow(base, a, pr), pr), pr);
    }
    vh.pb(vc);
    vl.pb(c);
    a = b, b = c;
  }

  priority_queue<pi> que;
  vector<vi> hs(sz(vh), vi(magic));
  vector<vi> pps(sz(vh), vi(magic));
  FOR(j, 0, sz(vl)) {
    int& len = vl[j];
    auto& pp = pps[j];
    FOR(t, 0, magic) {
      auto& pr = prs[t];
      auto& base = bases[t];
      pp[t] = fpow(base, len, pr);
    }
  }
  FOR(j, 0, sz(vl)) {
    int found = 0;
    int& len = vl[j];
    FOR(t, 0, magic) {
      auto& pr = prs[t];
      auto& base = bases[t];
      auto& pp = pps[t];
      FOR(i, 0, len) {
        if (i < k) {
          hs[j][t] = mult(hs[j][t], base, pr);
          addmod(hs[j][t], (int) bs[i], pr);
        }
      }
      if (hs[j][t] != vh[j][t]) {
        found = 1;
      }
    }
    if (!found) {
      que.push({-len, 1});
    }
  }
  int sum = 1;
  int ptr = 0;
  int p = pos[ptr++];
  FOR(i, 1, k + 1) {
    int tmp = sum;
    while (sz(que) && que.top().fi == -i) {
      submod(tmp, que.top().se);
      que.pop();
    }
    if (i == p) {
      cout << tmp << "\n";
      if (ptr < n) {
        p += pos[ptr++];
      }
    }
    FOR(j, 0, sz(vl)) {
      int found = 0;
      int& len = vl[j];
      auto& pp = pps[j];
      FOR(t, 0, magic) {
        auto& pr = prs[t];
        auto& base = bases[t];
        auto& h = hs[j][t];
        h = mult(h, base, pr);
        submod(h, mult((int) bs[i - 1], pp[t], pr), pr);
        if (i + len - 1 < k) {
          addmod(h, (int) bs[i + len - 1], pr);
        }
        if (hs[j][t] != vh[j][t]) {
          found = 1;
        }
      }
      if (!found) {
        que.push({-(i + len), tmp});
      }
    }
    addmod(sum, tmp);
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
  FOR(it, 1, test + 1) {
    chemthan();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}