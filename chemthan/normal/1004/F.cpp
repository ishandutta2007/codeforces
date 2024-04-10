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

const int maxn = 1e5 + 5;
int n, m, x;
int a[maxn];

struct node_t {
    int l, r;
    vii v1, v2;
    int sum;
    long long val;
    node_t() {
        l = r = -1;
    }
};

node_t join(node_t a, node_t b) {
    if (a.l == -1) return b;
    if (b.l == -1) return a;
    node_t res;
    res.l = a.l;
    res.r = b.r;
    res.sum = a.sum | b.sum;
    res.val = a.val + b.val;
    res.v1 = a.v1;
    for (pi p : b.v1) {
        int x = p.fi;
        if ((a.sum | x) != res.v1.back().fi) res.v1.pb(mp(a.sum | x, p.se));
    }
    res.v2 = b.v2;
    for (pi p : a.v2) {
        int x = p.fi;
        if ((b.sum | x) != res.v2.back().fi) res.v2.pb(mp(b.sum | x, p.se));
    }
    int j = 0;
    FORd(i, sz(b.v1), 0) {
        while (j < sz(a.v2) && (b.v1[i].fi | a.v2[j].fi) < x) j++;
        if (j < sz(a.v2)) {
            int u = (i < sz(b.v1) - 1 ? b.v1[i + 1].se : (b.r + 1)) - b.v1[i].se;
            int v = a.v2[j].se - (a.l - 1);
            res.val += (long long) u * v;
        }
    }
    return res;
}

node_t st[maxn << 2];

void build(int p, int L, int R) {
    if (L == R) {
        st[p].l = L, st[p].r = R;
        st[p].v1.pb(mp(a[L], L));
        st[p].v2.pb(mp(a[L], L));
        st[p].sum = a[L];
        st[p].val = a[L] >= x;
        return;
    }
    build(p << 1, L, L + R >> 1);
    build(p << 1 | 1, (L + R >> 1) + 1, R);
    st[p] = join(st[p << 1], st[p << 1 | 1]);
}

void upd(int p, int i, int L, int R, int val) {
    if (i < L || R < i) return;
    if (L == R) {
        st[p].v1[0].fi = val;
        st[p].v2[0].fi = val;
        st[p].sum = val;
        st[p].val = val >= x;
        return;
    }
    upd(p << 1, i, L, L + R >> 1, val);
    upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
    st[p] = join(st[p << 1], st[p << 1 | 1]);
}

node_t query(int p, int l, int r, int L, int R) {
    if (R < l || r < L) return node_t();
    if (l <= L && R <= r) return st[p];
    return join(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

void chemthan() {
    cin >> n >> m >> x;
    FOR(i, 0, n) cin >> a[i];
    build(1, 0, n - 1);
    FOR(i, 0, m) {
        int op, u, v; cin >> op >> u >> v;
        if (op == 1) {
            u--;
            upd(1, u, 0, n - 1, v);
        }
        else {
            u--, v--;
            node_t res = query(1, u, v, 0, n - 1);
            cout << res.val << "\n";
        }
    }
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