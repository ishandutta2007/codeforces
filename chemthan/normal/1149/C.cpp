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
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

struct node_t {
    int ans;
    int mn, mx;
    int mx_pref, mx_suff;
    node_t() {
        ans = 0;
        mn = +INF;
        mx = mx_pref = mx_suff = -INF;
    }
};

node_t merge(node_t a, node_t b) {
    node_t c;
    c.ans = max(a.ans, b.ans);
    chkmax(c.ans, a.mx_pref + b.mx);
    chkmax(c.ans, a.mx + b.mx_suff);
    c.mn = min(a.mn, b.mn);
    c.mx = max(a.mx, b.mx);
    c.mx_pref = max(a.mx_pref, b.mx_pref);
    c.mx_suff = max(a.mx_suff, b.mx_suff);
    chkmax(c.mx_pref, a.mx - b.mn - b.mn);
    chkmax(c.mx_suff, b.mx - a.mn - a.mn);
    return c;
}

const int maxn = 3e5 + 5;
int n, q;
node_t st[maxn << 2];
int lz[maxn << 2];

void push(int p, int L, int R) {
    if (lz[p]) {
        st[p].mn += lz[p], st[p].mx += lz[p], st[p].mx_pref -= lz[p], st[p].mx_suff -= lz[p];
        if (L < R) {
            FOR(i, p << 1, p + 1 << 1) {
                lz[i] += lz[p];
            }
        }
        lz[p] = 0;
    }
}
void upd(int p, int l, int r, int L, int R, int val) {
    push(p, L, R);
    if (r < L || R < l) return;
    if (l <= L && R <= r) {
        lz[p] = val;
        push(p, L, R);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1, val);
    upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = merge(st[p << 1], st[p << 1 | 1]);
}

void build(int p, int L, int R, vi& a) {
    if (L == R) {
        st[p].mn = st[p].mx = a[L];
        st[p].mx_pref = st[p].mx_suff = -a[L];
        return;
    }
    build(p << 1, L, L + R >> 1, a);
    build(p << 1 | 1, (L + R >> 1) + 1, R, a);
    st[p] = merge(st[p << 1], st[p << 1 | 1]);
}

void chemthan() {
    cin >> n >> q, n = 2 * n - 2;
    string s; cin >> s;
    vi a(n);
    int sum = 0;
    FOR(i, 0, n) {
        sum += s[i] == '(' ? 1 : -1;
        a[i] = sum;
    }
    build(1, 0, n - 1, a);
    cout << st[1].ans << "\n";
    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        for (int e : {u, v}) {
            upd(1, e, n - 1, 0, n - 1, s[e] == '(' ? -1 : 1);
        }
        swap(s[u], s[v]);
        for (int e : {u, v}) {
            upd(1, e, n - 1, 0, n - 1, s[e] == '(' ? 1 : -1);
        }
        cout << st[1].ans << "\n";
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