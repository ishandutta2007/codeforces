#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

typedef long long T;
const T oo = (T) 1e18;
struct func_t {
    T a, b;
    func_t(T a = 0, T b = oo) : a(a), b(b) {}
    T query(T x) {return a * x + b;}
};
struct node_t {
    node_t *l, *r;
    func_t f;
    node_t(node_t* l = 0, node_t* r = 0, func_t f = func_t()) : l(l), r(r), f(f) {}
    T query(T x) {return f.query(x);}
};
node_t* upd(node_t* p, int l, int r, int L, int R, func_t f) {
    if (l > R || r < L) return p;
    int M = L + (R - L >> 1);
    node_t* res = p ? new node_t(p->l, p->r, p->f) : new node_t();
    if (l <= L && r >= R) {
        int fl = f.query(L) >= (p ? p->query(L) : oo);
        int fm1 = f.query(M) >= (p ? p->query(M) : oo);
        int fm2 = f.query(M + 1) >= (p ? p->query(M + 1) : oo);
        int fr = f.query(R) >= (p ? p->query(R) : oo);
        if (fl && fr) return res;
        if (!fl && !fr) {
            res->f = f;
            return res;
        }
        if (fl && fm1) {
            res->r = upd(res->r, l, r, M + 1, R, f);
            return res;
        }
        if (!fl && !fm1) {
            res->r = upd(res->r, l, r, M + 1, R, res->f);
            res->f = f;
            return res;
        }
        if (fm2 && fr) {
            res->l = upd(res->l, l, r, L, M, f);
            return res;
        }
        if (!fm2 && !fr) {
            res->l = upd(res->l, l, r, L, M, res->f);
            res->f = f;
            return res;
        }
        assert(0);
    }
    res->l = upd(res->l, l, r, L, M, f);
    res->r = upd(res->r, l, r, M + 1, R, f);
    return res;
}
node_t* upd(node_t* p, int l, int r, int L, int R, T a, T b) {
    return upd(p, l, r, L, R, func_t(a, b));
}
T query(node_t* p, int i, int L, int R) {
    if (!p) return oo;
    if (i < L || i > R) return oo;
    T res = p->query(i);
    if (L < R) {
        res = min(res, query(p->l, i, L, L + R >> 1));
        res = min(res, query(p->r, i, (L + R >> 1) + 1, R));
    }
    return res;
}

const int maxn = 1e5 + 5;
int n;
int a[maxn];
int b[maxn];
vi adj[maxn];
node_t* f[maxn];
vi* g[maxn];
int size[maxn];
long long dp[maxn];

void dfs(int u, int p) {
    g[u] = new vi();
    size[u] = 1;
    pi best;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            size[u] += size[v];
            chkmax(best, mp(size[v], v));
        }
    }
    if (best.fi) {
        f[u] = f[best.se];
        g[u] = g[best.se];
        for (int v : adj[u]) {
            if (v != p && v != best.se) {
                while (sz(*g[v])) {
                    int w = g[v]->back(); g[v]->pop_back();
                    f[u] = upd(f[u], -1e5, +1e5, -1e5, +1e5, func_t(b[w], dp[w]));
                    g[u]->pb(w);
                }
            }
        }
        dp[u] = query(f[u], a[u], -1e5, +1e5);
    }
    f[u] = upd(f[u], -1e5, +1e5, -1e5, +1e5, func_t(b[u], dp[u]));
    g[u]->pb(u);
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) cin >> b[i];
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, -1);
    FOR(i, 0, n) cout << dp[i] << " \n"[i == n - 1];
}

int main(int argc, char* argv[]) {
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