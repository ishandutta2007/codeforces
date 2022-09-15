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
const int maxk = 1e7 + 5;
int sp[maxk];
int n;
vi adj[maxn];
int a[maxn];
int size[maxn];
int lev[maxn];
int p[maxn];
int heavy[maxn];

int num[maxn];
int head[maxn];
int cnt;

int fen[2][maxn];
void upd(int fen[], int p, int val) {
    p++;
    for (; p < maxn; p += p & -p) {
        fen[p] += val;
    }
}
int query(int fen[], int p) {
    p++;
    int res = 0;
    for (; p > 0; p -= p & -p) {
        res += fen[p];
    }
    return res;
}

int query(int l, int r, int n, int ix) {
    return query(fen[ix], r) - query(fen[ix], l - 1);
}

void firstdfs(int u, int dad) {
    size[u] = 1, heavy[u] = -1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v != dad) {
            p[v] = u, lev[v] = lev[u] + 1;
            firstdfs(v, u);
            size[u] += size[v];
            if (heavy[u] == -1 || size[heavy[u]] < size[v]) {
                heavy[u] = v;
            }
        }
    }
}
void dfs(int u, int h, int p) {
    num[u] = cnt++, head[u] = h;
    if (~heavy[u]) {
        dfs(heavy[u], h, u);
    }
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v != p && v != heavy[u]) {
            dfs(v, v, u);
        }
    }
}
int query(int u, int v, int ix) {
    int res = 0;
    int hu = head[u], hv = head[v];
    while (hu != hv) {
        if (lev[hu] < lev[hv]) swap(u, v), swap(hu, hv);
        res += query(num[hu], num[u], n, ix);
        u = p[hu], hu = head[u];
    }
    if (lev[u] > lev[v]) swap(u, v);
    res += query(num[u], num[v], n, ix);
    return res;
}

void chemthan() {
    FOR(i, 1, maxk) sp[i] = i;
    FOR(i, 2, maxk) if (sp[i] == i) {
        for (int j = i + i; j < maxk; j += i) {
            chkmin(sp[j], i);
        }
    }
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    FOR(i, 0, n) cin >> a[i];
    firstdfs(0, -1), dfs(0, 0, -1);
    static int res[maxn];
    static int u[maxn];
    static int v[maxn];
    static vii events[maxk];
    FOR(i, 0, n) {
        int t = a[i];
        map<int, int> hs;
        while (t > 1) {
            hs[sp[t]]++;
            t /= sp[t];
        }
        for (auto it : hs) {
            events[it.fi].pb(mp(it.se, -i - 1));
        }
    }
    int q; cin >> q;
    FOR(i, 0, q) {
        int x; cin >> u[i] >> v[i] >> x; u[i]--, v[i]--;
        int t = x;
        map<int, int> hs;
        while (t > 1) {
            hs[sp[t]]++;
            t /= sp[t];
        }
        for (auto it : hs) {
            events[it.fi].pb(mp(it.se, i));
        }
        res[i] = 1;
    }
    FOR(i, 1, maxk) if (sz(events[i])) {
        sort(all(events[i]));
        static int f[maxn];
        static int g[maxn];
        static int ver[maxn];
        int nver = 0;
        for (auto it : events[i]) {
            int ix = it.se;
            int k = it.fi;
            if (ix < 0) {
                ix = -ix - 1;
                upd(fen[0], num[ix], k);
                upd(fen[1], num[ix], 1);
            }
            else {
                if (!g[ix]) {
                    ver[nver++] = ix;
                    f[ix] = 0, g[ix] = 1;
                }
                f[ix] += query(u[ix], v[ix], 0);
                f[ix] -= query(u[ix], v[ix], 1) * k;
            }
        }
        for (auto it : events[i]) {
            int ix = it.se;
            int k = it.fi;
            if (ix >= 0) {
                f[ix] += query(u[ix], v[ix], 1) * k;
            }
        }
        for (auto it : events[i]) {
            int ix = it.se;
            int k = it.fi;
            if (ix < 0) {
                ix = -ix - 1;
                upd(fen[0], num[ix], -k);
                upd(fen[1], num[ix], -1);
            }
        }
        FOR(j, 0, nver) {
            int ix = ver[j];
            res[ix] = mult(res[ix], fpow(i, f[ix]));
            g[ix] = 0;
        }
    }
    FOR(i, 0, q) {
        cout << res[i] << "\n";
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