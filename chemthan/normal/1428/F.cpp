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
const ld EPS = 1e-15;
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

#define N 1000003
class SegmentTree {
  static const ll inf = 1e18;
  struct Node {
    Node *left, *right;
    ll max_v, smax_v, max_c;
    ll min_v, smin_v, min_c;
    ll sum;
    ll len, ladd, lval;

    Node() : left(0), right(0), ladd(0), lval(inf) {}

    void init(ll x) {
      max_v = min_v = sum = x;
      smax_v = -inf; smin_v = inf;
      max_c = min_c = 1;
    }

    void init_empty() {
      max_v = smax_v = -inf;
      min_v = smin_v = inf;
      max_c = min_c = 0;
    }

    void update_max(ll x) {
      sum += (x - max_v) * max_c;

      if(max_v == min_v) {
        max_v = min_v = x;
      } else if(max_v == smin_v) {
        max_v = smin_v = x;
      } else {
        max_v = x;
      }

      if(lval != inf && x < lval) {
        lval = x;
      }
    }

    void update_min(ll x) {
      sum += (x - min_v) * min_c;

      if(max_v == min_v) {
        max_v = min_v = x;
      } else if(max_v == smin_v) {
        min_v = smax_v = x;
      } else {
        min_v = x;
      }

      if(lval != inf && lval < x) {
        lval = x;
      }
    }

    void addall(ll x) {
      max_v += x;
      if(smax_v != -inf) smax_v += x;
      min_v += x;
      if(smin_v != inf) smin_v += x;

      sum += len * x;
      if(lval != inf) {
        lval += x;
      } else {
        ladd += x;
      }
    }

    void updateall(ll x) {
      max_v = min_v = x;
      smax_v = -inf; smin_v = inf;
      max_c = min_c = len;

      sum = len * x;
      lval = x; ladd = 0;
    }

    void push() {

      if(lval != inf) {
        left->updateall(lval);
        right->updateall(lval);
        lval = inf;
        return;
      }

      if(ladd != 0) {
        left->addall(ladd);
        right->addall(ladd);
        ladd = 0;
      }

      if(max_v < left->max_v) {
        left->update_max(max_v);
      }
      if(left->min_v < min_v) {
        left->update_min(min_v);
      }

      if(max_v < right->max_v) {
        right->update_max(max_v);
      }
      if(right->min_v < min_v) {
        right->update_min(min_v);
      }
    }

    void update() {
      sum = left->sum + right->sum;

      if(left->max_v < right->max_v) {
        max_v = right->max_v;
        max_c = right->max_c;
        smax_v = max(left->max_v, right->smax_v);
      } else if(left->max_v > right->max_v) {
        max_v = left->max_v;
        max_c = left->max_c;
        smax_v = max(left->smax_v, right->max_v);
      } else {
        max_v = left->max_v;
        max_c = left->max_c + right->max_c;
        smax_v = max(left->smax_v, right->smax_v);
      }

      if(left->min_v < right->min_v) {
        min_v = left->min_v;
        min_c = left->min_c;
        smin_v = min(left->smin_v, right->min_v);
      } else if(left->min_v > right->min_v) {
        min_v = right->min_v;
        min_c = right->min_c;
        smin_v = min(left->min_v, right->smin_v);
      } else {
        min_v = left->min_v;
        min_c = left->min_c + right->min_c;
        smin_v = min(left->smin_v, right->smin_v);
      }
    }
  };

  int n, n0;
  Node *root;

  void _update_min(ll x, int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a || nd->max_v <= x) {
      return;
    }
    if(a <= l && r <= b && nd->smax_v < x) {
      nd->update_max(x);
      return;
    }

    nd->push();
    _update_min(x, a, b, nd->left, l, (l+r)/2);
    _update_min(x, a, b, nd->right, (l+r)/2, r);
    nd->update();
  }

  void _update_max(ll x, int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a || x <= nd->min_v) {
      return;
    }
    if(a <= l && r <= b && x < nd->smin_v) {
      nd->update_min(x);
      return;
    }

    nd->push();
    _update_max(x, a, b, nd->left, l, (l+r)/2);
    _update_max(x, a, b, nd->right, (l+r)/2, r);
    nd->update();
  }

  void _add_val(ll x, int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return;
    }
    if(a <= l && r <= b) {
      nd->addall(x);
      return;
    }

    nd->push();
    _add_val(x, a, b, nd->left, l, (l+r)/2);
    _add_val(x, a, b, nd->right, (l+r)/2, r);
    nd->update();
  }

  void _update_val(ll x, int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return;
    }
    if(a <= l && r <= b) {
      nd->updateall(x);
      return;
    }

    nd->push();
    _update_val(x, a, b, nd->left, l, (l+r)/2);
    _update_val(x, a, b, nd->right, (l+r)/2, r);
    nd->update();
  }

  ll _query_max(int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return -inf;
    }
    if(a <= l && r <= b) {
      return nd->max_v;
    }
    nd->push();
    ll lv = _query_max(a, b, nd->left, l, (l+r)/2);
    ll rv = _query_max(a, b, nd->right, (l+r)/2, r);
    return max(lv, rv);
  }

  ll _query_min(int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return inf;
    }
    if(a <= l && r <= b) {
      return nd->min_v;
    }
    nd->push();
    ll lv = _query_min(a, b, nd->left, l, (l+r)/2);
    ll rv = _query_min(a, b, nd->right, (l+r)/2, r);
    return min(lv, rv);
  }

  ll _query_sum(int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return 0;
    }
    if(a <= l && r <= b) {
      return nd->sum;
    }
    nd->push();
    ll lv = _query_sum(a, b, nd->left, l, (l+r)/2);
    ll rv = _query_sum(a, b, nd->right, (l+r)/2, r);
    return lv + rv;
  }

public:
  SegmentTree(int n, ll *a) : n(n) {
    n0 = 1;
    while(n0 < n) n0 <<= 1;

    Node *nds = new Node[2*n0];
    root = nds;

    nds[0].len = n0;
    for(int i=0; i<n0-1; ++i) {
      nds[i].left = &nds[2*i+1];
      nds[i].right = &nds[2*i+2];
      nds[2*i+1].len = nds[2*i+2].len = (nds[i].len >> 1);
    }

    for(int i=0; i<n; ++i) nds[n0-1+i].init(a[i]);
    for(int i=n; i<n0; ++i) nds[n0-1+i].init_empty();
    for(int i=n0-2; i>=0; i--) nds[i].update();
  }

  void update_min(int a, int b, ll x) {
    _update_min(x, a, b, root, 0, n0);
  }

  void update_max(int a, int b, ll x) {
    _update_max(x, a, b, root, 0, n0);
  }

  void add_val(int a, int b, ll x) {
    _add_val(x, a, b, root, 0, n0);
  }

  void update_val(int a, int b, ll x) {
    _update_val(x, a, b, root, 0, n0);
  }

  ll query_max(int a, int b) {
    return _query_max(a, b, root, 0, n0);
  }

  ll query_min(int a, int b) {
    return _query_min(a, b, root, 0, n0);
  }

  ll query_sum(int a, int b) {
    return _query_sum(a, b, root, 0, n0);
  }
};
ll v[N];

void chemthan() {
    int n; cin >> n;
    string s; cin >> s;
    SegmentTree stb(n, v);
    int cnt = 0;
    long long res = 0;
    FOR(i, 0, sz(s)) {
        if (s[i] == '1') {
            cnt++;
        }
        else {
            FOR(j, i - cnt, i) {
                stb.update_max(j, j + 1, i - j);
            }
            cnt = 0;
        }
        stb.update_max(0, i - cnt + 1, cnt);
        res += stb.query_sum(0, i - cnt + 1);
        res += (long long) cnt * (cnt + 1) / 2;
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