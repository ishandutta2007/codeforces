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
int n, k;
vii adj[maxn];
int from[maxn];
int fromw[maxn];

pi best;
void dfs(int u, int p, int d) {
    chkmax(best, mp(d, u));
    for (pi e : adj[u]) {
        int v = e.fi;
        int w = e.se;
        if (v != p) {
            dfs(v, u, d + w);
            from[v] = u;
            fromw[v] = w;
        }
    }
}

int center() {
    dfs(0, -1, 0);
    int st = best.se;
    best = mp(0, 0);
    dfs(st, -1, 0);
    int ed = best.se;
    int len = best.fi;
    int cur = 0;
    pi best = mp(len, ed);
    while (ed != st) {
        chkmin(best, mp(abs(cur + cur - len), ed));
        cur += fromw[ed];
        ed = from[ed];
    }
    chkmin(best, mp(abs(cur + cur - len), ed));
    return best.se;
}

int dep[maxn];
void dfs2(int u, int p) {
    for (pi e : adj[u]) {
        int v = e.fi;
        int w = e.se;
        if (v != p) {
            dfs2(v, u);
            chkmax(dep[u], dep[v] + w);
        }
    }
}

int f[maxn];
int ww[maxn];
int flag;

void u_dfs2(int u, int p, int mi) {
    int num = 0;
    for (pi e : adj[u]) {
        int v = e.fi;
        int w = e.se;
        if (v != p) {
            if (dep[v] + w > mi) {
                f[v] = 1;
                u_dfs2(v, u, mi);
                num++;
            }
        }
    }
    if (p != -1 && num > 1) flag = 0;
    if (num > 2) flag = 0;
}

void chemthan() {
    cin >> n >> k;
    FOR(i, 0, n - 1) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    int cen = center();
    for (pi e : adj[cen]) {
        int v = e.fi;
        int w = e.se;
        dfs(v, cen, w);
    }
    dfs2(cen, -1);
    int lo = 0, hi = INF;
    while (lo < hi) {
        int mi = lo + hi >> 1;
        ms(f, 0);
        f[cen] = 1;
        flag = 1;
        u_dfs2(cen, -1, mi);
        if (accumulate(f, f + n, 0) > k) {
            flag = 0;
        }
        if (!flag) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }
    cout << (lo + hi >> 1) << "\n";
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