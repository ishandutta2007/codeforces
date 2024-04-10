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

struct node_t {
  node_t *l, *r;
  int lz;
  int mn;
  int mx;
  node_t() {
    l = r = 0;
    lz = mn = mx = 0;
  }
};

void push(node_t*& x, int L, int R) {
  if (L < R) {
    if (!x->l) {
      x->l = new node_t();
      x->l->mn = L;
      x->l->mx = L + R >> 1;
    }
    if (!x->r) {
      x->r = new node_t();
      x->r->mn = (L + R >> 1) + 1;
      x->r->mx = R;
    }
  }
  if (x->lz) {
    x->mn += x->lz;
    x->mx += x->lz;
    if (x->l) x->l->lz += x->lz;
    if (x->r) x->r->lz += x->lz;
    x->lz = 0;
  }
}

node_t* upd(node_t* x, int L, int R, int l, int r, int v) {
  if (!x) {
    x = new node_t();
    x->mn = L;
    x->mx = R;
  }
  push(x, L, R);
  if (R < l || r < L) return x;
  if (l <= L && R <= r) {
    x->lz += v;
    push(x, L, R);
    return x;
  }
  x->l = upd(x->l, L, L + R >> 1, l, r, v);
  x->r = upd(x->r, (L + R >> 1) + 1, R, l, r, v);
  x->mn = min(x->l->mn, x->r->mn);
  x->mx = max(x->l->mx, x->r->mx);
  return x;
}

int query(node_t*& x, int L, int R, int i) {
  if (!x) x = new node_t();
  push(x, L, R);
  if (i < L) return 0;
  if (R < i) return 0;
  if (L == R) {
    return x->mn;
  }
  return query(x->l, L, L + R >> 1, i) + query(x->r, (L + R >> 1) + 1, R, i);
}

int queryl(node_t*& x, int L, int R, int t) {
  if (!x) {
    x = new node_t();
    x->mn = L;
    x->mx = R;
  }
  push(x, L, R);
  if (L == R) {
    if (x->mn < t) {
      return L;
    }
    return -1;
  }
  push(x->r, (L + R >> 1) + 1, R);
  if (x->r->mn < t) {
    return queryl(x->r, (L + R >> 1) + 1, R, t);
  }
  return queryl(x->l, L, L + R >> 1, t);
}

int queryr(node_t*& x, int L, int R, int t) {
  if (!x) {
    x = new node_t();
    x->mn = L;
    x->mx = R;
  }
  push(x, L, R);
  if (L == R) {
    if (t < x->mx) {
      return L;
    }
    return INF;
  }
  push(x->l, L, L + R >> 1);
  if (t < x->l->mx) {
    return queryr(x->l, L, L + R >> 1, t);
  }
  return queryr(x->r, (L + R >> 1) + 1, R, t);
}

void chemthan() {
  int n; cin >> n;
  node_t* rt = 0;
  int last_ans = 0;
  FOR(i, 0, n) {
    int t; cin >> t;
    {
      int v = queryl(rt, 0, INF, t);
      if (0 <= v) {
        rt = upd(rt, 0, INF, 0, v, 1);
      }
    }
    {
      int v = queryr(rt, 0, INF, t);
      if (v < INF) {
        rt = upd(rt, 0, INF, v, INF - 1, -1);
      }
    }
    int k; cin >> k;
    while (k--) {
      int x; cin >> x;
      x = (x + last_ans) % ((int) 1e9 + 1);
      cout << (last_ans = query(rt, 0, INF, x)) << "\n";
    }
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
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}