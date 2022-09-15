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
const int MOD2 = 1007681537;
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
const int logn = 20;
int n;
vi adj[maxn];
int lev[maxn];
int p[logn][maxn];
int tin[maxn];
int tou[maxn];
int tms;

void dfs(int u) {
    tin[u] = tms++;
    FOR(i, 1, logn) p[i][u] = p[i - 1][p[i - 1][u]];
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        lev[v] = lev[u] + 1;
        p[0][v] = u;
        dfs(v);
    }
    tou[u] = tms - 1;
}

int lca(int u, int v) {
    if (lev[u] < lev[v]) swap(u, v);
    FORd(i, logn, 0) {
        if (lev[p[i][u]] >= lev[v]) {
            u = p[i][u];
        }
    }
    if (u == v) return u;
    FORd(i, logn, 0) {
        if (p[i][u] != p[i][v]) {
            u = p[i][u];
            v = p[i][v];
        }
    }
    return p[0][u];
}

int dist(int u, int v) {
    int a = lca(u, v);
    return lev[u] + lev[v] - lev[a] - lev[a];
}

int jump(int u, int d) {
    FORd(i, logn, 0) {
        if (d >= (1 << i)) {
            u = p[i][u];
            d -= 1 << i;
        }
    }
    return u;
}

int st[maxn << 2];
int lz[maxn << 2];

void pushdown(int p, int L, int R) {
    if (~lz[p]) {
        st[p] = lz[p];
        if (L < R) {
            lz[p << 1] = lz[p];
            lz[p << 1 | 1] = lz[p];
        }
        lz[p] = -1;
    }
}
void upd(int p, int l, int r, int L, int R, int val) {
    pushdown(p, L, R);
    if (l > R || r < L) return;
    if (l <= L && r >= R) {
        lz[p] = val;
        pushdown(p, L, R);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1, val);
    upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = st[p << 1] + st[p << 1 | 1];
}

void solve() {
    cin >> n;
    FOR(i, 1, n + 1) {
        int x; cin >> x; x--;
        adj[x].pb(i);
    }
    dfs(0);
    ms(lz, -1);
    upd(1, 0, 0, 0, n, 1);
    int x = 0, y = 0;
    FOR(u, 1, n + 1) {
        int cur = dist(x, y);
        pair<int, pi> best = mp(-INF, mp(-INF, -INF));
        chkmax(best, mp(dist(u, x), mp(u, x)));
        chkmax(best, mp(dist(u, y), mp(u, y)));
        int d = best.fi;
        if (d == cur) {
            upd(1, tin[u], tin[u], 0, n, 1);
        }
        else if (d > cur) {
            x = best.se.fi;
            y = best.se.se;
            if (lev[x] == lev[y]) {
                int w = jump(y, (d >> 1) - 1);
                upd(1, 0, tin[w] - 1, 0, n, 0);
                upd(1, tou[w] + 1, n, 0, n, 0);
            }
            else if (lev[x] > lev[y]) {
                int w = jump(x, d >> 1);
                upd(1, tin[w], tou[w], 0, n, 0);
            }
            else {
                int w = jump(y, d - (d >> 1) - 1);
                upd(1, 0, tin[w] - 1, 0, n, 0);
                upd(1, tou[w] + 1, n, 0, n, 0);
            }
            upd(1, tin[u], tin[u], 0, n, 1);
        }
        cout << st[1] << "\n";
    }
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}