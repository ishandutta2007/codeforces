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

const int maxn = 1e3 + 5;
int n;
vi adj[maxn];
vii edges;
vector<vi> g[maxn];
int f[maxn][maxn];

int dj[maxn];
int ver;
void init() {
    FOR(i, 0, n) dj[i] = i;
    ver = n;
}
int find(int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
int join(int u, int v) {
    int p = find(u);
    int q = find(v);
    if (p != q) {
        adj[u].pb(v);
        adj[v].pb(u);
        ver--;
        dj[p] = q;
        return 1;
    }
    return 0;
}

void dfs(int u, int p, vi& ver) {
    ver.pb(u);
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (v != p) {
            dfs(v, u, ver);
        }
    }
}

void solve() {
    cin >> n;
    FOR(i, 0, n) {
        string s; cin >> s;
        FOR(j, 0, sz(s)) {
            if (s[j] == '-') {
                s[j] = ' ';
            }
        }
        stringstream ss(s);
        while (ss >> s) {
            FOR(j, 0, sz(s)) {
                if (!(s[j] >= '0' && s[j] <= '9')) {
                    s[j] = ' ';
                }
            }
            stringstream ss2(s);
            int u; ss2 >> u;
            vi tmp;
            while (ss2 >> u) {
                u--;
                tmp.pb(u);
            }
            sort(all(tmp));
            g[i].pb(tmp);
        }
        sort(all(g[i]));
    }
    
    FOR(u, 0, n) {
        FOR(v, 0, n) if (u != v) {
            f[u][v] = n;
        }
        FOR(i, 0, sz(g[u])) {
            vi v = g[u][i];
            FOR(j, 0, sz(v)) {
                int w = v[j];
                f[u][w] -= sz(v);
            }
        }
    }
    FOR(u, 0, n) FOR(v, u + 1, n) {
        if (f[u][v] + f[v][u] == n) {
            edges.pb(mp(u, v));
        }
    }
    init();
    vii res;
    FOR(i, 0, sz(edges)) {
        int u = edges[i].fi;
        int v = edges[i].se;
        if (join(u, v)) {
            res.pb(mp(u, v));
        }
    }
    if (ver != 1) {
        cout << -1 << "\n";
        return;
    }
    FOR(u, 0, n) {
        vector<vi> gg;
        FOR(i, 0, sz(adj[u])) {
            int v = adj[u][i];
            vi tmp;
            dfs(v, u, tmp);
            sort(all(tmp));
            gg.pb(tmp);
        }
        sort(all(gg));
        if (g[u] != gg) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << n - 1 << "\n";
    FOR(i, 0, sz(res)) {
        cout << res[i].fi + 1 << " " << res[i].se + 1 << "\n";
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