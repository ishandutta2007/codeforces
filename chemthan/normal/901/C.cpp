#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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

const int maxn = 3e5 + 5;
int n, m, q;
vi adj[maxn];
int vis[maxn];
int lev[maxn];
int from[maxn];
vii vals;

void dfs(int u, int p) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            from[v] = u;
            lev[v] = lev[u] + 1;
            dfs(v, u);
        }
        else if (v != p && lev[v] < lev[u]) {
            int mn = INF, mx = -INF;
            int ptr = u;
            while (ptr != v) {
                chkmin(mn, ptr);
                chkmax(mx, ptr);
                ptr = from[ptr];
            }
            chkmin(mn, ptr);
            chkmax(mx, ptr);
            vals.pb(mp(mn, mx));
        }
    }
}

long long fen[3][maxn];
void upd(long long fen[], int p, int val) {
    p++;
    for (; p < maxn; p += p & - p) {
        fen[p] += val;
    }
}
long long query(long long fen[], int p) {
    p++;
    long long res = 0;
    for (; p > 0; p -= p & -p) {
        res += fen[p];
    }
    return res;
}

void solve() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    FOR(i, 0, n) if (!vis[i]) dfs(i, -1);
    static int f[maxn];
    fill_n(f, n, n - 1);
    multiset<int> st;
    sort(all(vals));
    for (pi p : vals) {
        st.insert(p.se);
    }
    int ptr = 0;
    FOR(i, 0, n) {
        while (ptr < sz(vals) && vals[ptr].fi < i) {
            st.erase(st.find(vals[ptr].se));
            ptr++;
        }
        if (sz(st)) {
            f[i] = *st.begin() - 1;
        }
    }
    cin >> q;
    static vii que[maxn];
    FOR(i, 0, q) {
        int l, r; cin >> l >> r; l--, r--;
        que[l].pb(mp(r, i));
    }
    static long long res[maxn];
    FORd(i, n, 0) {
        upd(fen[0], f[i], f[i] - i + 1);
        upd(fen[1], f[i], 1);
        upd(fen[2], f[i], i);
        for (pi p : que[i]) {
            int r = p.fi;
            int ix = p.se;
            res[ix] += query(fen[0], r);
            long long cnt = (r - i + 1) - query(fen[1], r);
            long long sum = (long long) (i + r) * (r - i + 1) / 2 - query(fen[2], r);
            res[ix] += cnt * (r + 1) - sum;
        }
    }
    FOR(i, 0, q) cout << res[i] << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
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