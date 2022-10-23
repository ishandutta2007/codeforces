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
const int MOD = (int) 1e9 + 7;
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

const int maxn = 1e5 + 5;
const int maxc = 26;
struct node_t {
  node_t* p;
  node_t* c[maxc];
  node_t *bf, *gf;
  int key;
  char val;
  int cost;
  node_t();
  void clear();
} pool[maxn], *ptr = pool;
node_t::node_t() {
  clear();
}
void node_t::clear() {
  p = 0;
  for (int i = 0; i < maxc; i++) c[i] = 0;
  bf = gf = 0, key = -1, val = 0, cost = 0;
}
void clear() {
  node_t* st = pool;
  while (st != ptr) {
    st->clear();
    st++;
  }
  ptr = pool;
}
node_t* insert(node_t* x, char* s, int key, int cost) {
  while (*s) {
    int k = *s - 'a';
    if (!x->c[k]) {
      x->c[k] = ptr++;
      x->c[k]->p = x;
      x->c[k]->val = k;
    }
    x = x->c[k];
    s++;
  }
  x->key = key;
  x->cost += cost;
  return x;
}
void pushlink(node_t* rt) {
  static node_t* q[maxn];
  int b = 0, e = 0;
  q[e++] = rt;
  while (b < e) {
    node_t* x = q[b++];
    for (int i = 0; i < maxc; i++) {
      if (x->c[i]) q[e++] = x->c[i];
    }
    if (x == rt || x->p == rt) {
      x->bf = rt;
      x->gf = 0;
    }
    else {
      x->bf = x->p->bf;
      while (x->bf != rt && !x->bf->c[x->val]) x->bf = x->bf->bf;
      if (x->bf->c[x->val]) x->bf = x->bf->c[x->val];
      if (x->bf->key != -1) x->gf = x->bf;
      else x->gf = x->bf->gf;
      x->cost += x->bf->cost;
    }
  }
}
void search(node_t* rt, char* s) {
  node_t* cur = rt;
  while (*s) {
    if (cur == rt && !cur->c[*s - 'a']) {
      s++;
      continue;
    }
    while (cur != rt && !cur->c[*s - 'a']) cur = cur->bf;
    cur = cur->c[*s - 'a'];
    if (!cur) {
      cur = rt;
      continue;
    }
    node_t* tmp = cur;
    if (tmp->key == -1) tmp = tmp->gf;
    while (tmp) {
      cout << tmp->key << " ";
      tmp = tmp->gf;
    }
    s++;
  }
  cout << "\n";
}

void chemthan() {
  int n; cin >> n;
  auto check = [&] (string s) -> string {
    vector<vi> adj(26);
    FOR(i, 0, sz(s) - 1) {
      int u = s[i] - 'a';
      int v = s[i + 1] - 'a';
      adj[u].pb(v);
      adj[v].pb(u);
    }
    FOR(i, 0, 26) sort(all(adj[i])), uni(adj[i]);
    vi v;
    FOR(i, 0, 26) {
      if (2 < sz(adj[i])) {
        return "";
      }
      if (sz(adj[i]) == 1) {
        v.pb(i);
      }
    }
    if (sz(v) != 2) return "";
    int t = v[0];
    int pt = -1;
    string res;
    res += char('a' + t);
    while (t != v[1]) {
      for (int nt : adj[t]) {
        if (nt != pt) {
          pt = t;
          t = nt;
          break;
        }
      }
      res += char('a' + t);
    }
    return res;
  };
  node_t* rt = ptr++;
  FOR(i, 0, n) {
    int c; string s;
    cin >> c >> s;
    auto t = check(s);
    if (t != "") {
      insert(rt, (char*) t.data(), i, c);
      reverse(all(t));
      insert(rt, (char*) t.data(), i, c);
    }
  }
  pushlink(rt);
  int tot = ptr - pool;
  vector<vi> dp(1 << 12, vi(tot, -1));
  vector<vi> nxt(tot, vi(26, -1));
  auto next_state = [&] (auto&& next_state, int state, int c) {
    int& res = nxt[state][c];
    if (~res) return res;
    node_t* cur = pool + state;
    while (cur != rt && !cur->c[c]) cur = cur->bf;
    cur = cur->c[c];
    if (!cur) cur = rt;
    return res = cur - pool;
  };
  auto calc = [&] (auto&& calc, int msk, int state) -> int {
    if (bitcount(msk) == 12) return 0;
    int& res = dp[msk][state];
    if (~res) return res;
    res = 0;
    FOR(c, 0, 12) if (!bit(msk, c)) {
      int nstate = next_state(next_state, state, c);
      chkmax(res, calc(calc, msk | (1 << c), nstate) + pool[nstate].cost);
    }
    return res;
  };
  int mx = calc(calc, 0, 0);
  int msk = 0, state = 0;
  string res;
  FOR(_, 0, 12) {
    FOR(c, 0, 12) if (!bit(msk, c)) {
      int nstate = next_state(next_state, state, c);
      if (calc(calc, msk | (1 << c), nstate) + pool[nstate].cost == mx) {
        mx -= pool[nstate].cost;
        msk |= 1 << c;
        state = nstate;
        res += char('a' + c);
        break;
      }
    }
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
  int test = 1;
  //cin >> test;
  FOR(it, 1, test + 1) {
    chemthan();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}