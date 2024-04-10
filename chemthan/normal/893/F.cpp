#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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

template<class T, class cmp = less<T> > struct RMQ {
    int n;
    vector<T> a;
    vector<vector<T> > f;

    T best(T a, T b) {
        if (cmp()(a, b)) return a;
        return b;
    }
    void init(int n) {
        this->n = n;
        int p = 1; while ((1 << p) < n) p++;
        a.resize(n), f.resize(p + 1);
        FOR(i, 0, n) a[i] = INF + INF;
        for (int i = 0; i < (int) f.size(); i++) {
            f[i].resize(n);
        }
    }
    void upd(int u, T x) {
        chkmin(a[u], x);
    }
    void build() {
        for (int i = 0; i < n; i++) f[0][i] = a[i];
        for (int l = 0, k; (k = 1 << l) < n; l++) {
            for (int i = 0; i + k < n; i++) {
                f[l + 1][i] = best(f[l][i], f[l][i + k]);
            }
        }
    }
    T query(int a, int b) {
        if (a > b) return INF + INF;
        int l = a == b ? 0 : __lg(b - a);
        return best(f[l][a], f[l][b - (1 << l) + 1]);
    }
};

const int maxn = 1e5 + 5;
int n, r;
int a[maxn];
vi adj[maxn];
int lev[maxn];
int tin[maxn];
int tou[maxn];
int tms;

void dfs(int u, int p) {
    tin[u] = tms++;
    for (int v : adj[u]) {
        if (v != p) {
            lev[v] = lev[u] + 1;
            dfs(v, u);
        }
    }
    tou[u] = tms - 1;
}

int mn[maxn << 2];
int mx[maxn << 2];
RMQ<int> st[maxn << 2];
void upd1(int p, int i, int L, int R, int lev) {
    if (i < L || i > R) return;
    chkmin(mn[p], lev);
    chkmax(mx[p], lev);
    if (L < R) {
        upd1(p << 1, i, L, L + R >> 1, lev);
        upd1(p << 1 | 1, i, (L + R >> 1) + 1, R, lev);
    }
}
void build1(int p, int L, int R) {
    st[p].init(mx[p] - mn[p] + 1);
    if (L < R) {
        build1(p << 1, L, L + R >> 1);
        build1(p << 1 | 1, (L + R >> 1) + 1, R);
    }
}
void upd2(int p, int i, int L, int R, int lev, int val) {
    if (i < L || i > R) return;
    int ix = lev - mn[p];
    st[p].upd(ix, val);
    if (L < R) {
        upd2(p << 1, i, L, L + R >> 1, lev, val);
        upd2(p << 1 | 1, i, (L + R >> 1) + 1, R, lev, val);
    }
}
void build2(int p, int L, int R) {
    st[p].build();
    if (L < R) {
        build2(p << 1, L, L + R >> 1);
        build2(p << 1 | 1, (L + R >> 1) + 1, R);
    }
}
int query(int p, int l, int r, int L, int R, int k) {
    if (l > R || r < L) return INF + INF;
    if (l <= L && r >= R) return st[p].query(0, min(k, mx[p]) - mn[p]);
    return min(query(p << 1, l, r, L, L + R >> 1, k), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R, k));
}

void solve() {
    scanf("%d%d", &n, &r); r--;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n - 1) {
        int u, v; scanf("%d%d", &u, &v); u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(r, -1);
    FOR(i, 0, n << 2) mn[i] = +INF, mx[i] = -INF;
    FOR(i, 0, n) {
        upd1(1, tin[i], 0, n - 1, lev[i]);
    }
    build1(1, 0, n - 1);
    FOR(i, 0, n) {
        upd2(1, tin[i], 0, n - 1, lev[i], a[i]);
    }
    build2(1, 0, n - 1);
    int q; scanf("%d", &q);
    int lst = 0;
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        int u = (x + lst) % n;
        int v = (y + lst) % n;
        printf("%d\n", (lst = query(1, tin[u], tou[u], 0, n - 1, lev[u] + v)));
    }
}

int main(int argc, char* argv[]) {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}