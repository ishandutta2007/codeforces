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

const int maxn = 2e5 + 5;
const int logn = 20;
int n, m;
vii adj[maxn];
int w[maxn];
int lev[maxn];
int p[logn][maxn];
int val[logn][maxn];
vi events[maxn];
vector<pair<pi, int> > edges;
int dj[maxn];
int ans[maxn];
int size[maxn];
int heavy[maxn];

void init() {
    FOR(i, 0, n) dj[i] = i;
}
int find(int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
int join(int u, int v) {
    int p = find(u);
    int q = find(v);
    if (p != q) {
        dj[p] = q;
        return 1;
    }
    return 0;
}

void dfs(int u, int dad) {
    FOR(i, 1, logn) {
        p[i][u] = p[i - 1][p[i - 1][u]];
        val[i][u] = val[i - 1][u];
        chkmax(val[i][u], val[i - 1][p[i - 1][u]]);
    }
    size[u] = 1;
    heavy[u] = -1;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        int ix = adj[u][i].se;
        if (v != dad) {
            lev[v] = lev[u] + 1;
            p[0][v] = u;
            val[0][v] = w[ix];
            dfs(v, u);
            size[u] += size[v];
            if (heavy[u] == -1 || size[heavy[u]] < size[v]) {
                heavy[u] = v;
            }
        }
    }
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

int query(int u, int a) {
    int res = -INF;
    if (u == a) return res;
    FORd(i, logn, 0) {
        if (lev[p[i][u]] > lev[a]) {
            chkmax(res, val[i][u]);
            u = p[i][u];
        }
    }
    chkmax(res, val[0][u]);
    return res;
}

multiset<int>* upd(int u, int prv) {
    multiset<int>* res;
    if (!~heavy[u]) {
        res = new multiset<int>();
    }
    else {
        FOR(i, 0, sz(adj[u])) {
            int v = adj[u][i].fi;
            int ix = adj[u][i].se;
            if (v == heavy[u]) {
                res = upd(v, ix);
            }
        }
    }
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        int ix = adj[u][i].se;
        if (ix != prv && v != heavy[u]) {
            multiset<int>* r = upd(v, ix);
            FORall(it, *r) {
                res->insert(*it);
            }
        }
    }
    FOR(i, 0, sz(events[u])) {
        int ix = events[u][i];
        if (ix >= 0) {
            res->insert(w[ix]);
        }
        else {
            ix = -ix - 1;
            res->erase(res->find(w[ix]));
        }
    }
    if (~prv) {
        ans[prv] = sz(*res) ? *res->begin() - 1 : INF + INF;
    }
    return res;
}

void solve() {
    cin >> n >> m;
    priority_queue<pair<pi, pi> > pq;
    FOR(i, 0, m) {
        int u, v; cin >> u >> v >> w[i]; u--, v--;
        pq.push(mp(mp(-w[i], i), mp(u, v)));
    }
    init();
    while (sz(pq)) {
        int u = pq.top().se.fi;
        int v = pq.top().se.se;
        int ix = pq.top().fi.se;
        pq.pop();
        if (join(u, v)) {
            adj[u].pb(mp(v, ix));
            adj[v].pb(mp(u, ix));
        }
        else {
            edges.pb(mp(mp(u, v), ix));
        }
    }
    val[0][0] = -INF, dfs(0, -1);
    FOR(i, 0, sz(edges)) {
        int u = edges[i].fi.fi;
        int v = edges[i].fi.se;
        int ix = edges[i].se;
        int a = lca(u, v);
        events[u].pb(ix);
        events[v].pb(ix);
        events[a].pb(-ix - 1);
        events[a].pb(-ix - 1);
        ans[ix] = max(query(u, a), query(v, a)) - 1;
    }
    upd(0, -1);
    FOR(i, 0, m) if (ans[i] > INF + 10) ans[i] = -1;
    FOR(i, 0, m) cout << ans[i] << " \n"[i == m - 1];
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