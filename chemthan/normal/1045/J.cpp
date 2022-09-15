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

struct KMP {
    string s;
    int n;
    vector<int> link;
    void build(char* str) {
        s = str, n = (int) s.size();
        link.resize(n);
        int cur = link[0] = -1;
        for (int i = 1; i < n; i++) {
            while (cur >= 0 && s[i] != s[cur + 1]) cur = link[cur];
            if (s[i] == s[cur + 1]) cur++;
            link[i] = cur;
        }
    }
    vector<int> query(char* t) {
        vector<int> res;
        int k = strlen(t);
        int cur = -1;
        for (int i = 0; i < k; i++) {
            while (cur >= 0 && t[i] != s[cur + 1]) cur = link[cur];
            if (t[i] == s[cur + 1]) cur++;
            if (cur == n - 1) {
                res.push_back(i - n + 1);
                cur = link[cur];
            }
        }
        return res;
    }
} kmp;

const int maxn = 1e5 + 5;
const int logn = 20;
int pr, base;
int pr2, base2;
int n, q;
vector<pair<int, char> > adj[maxn];
int u[maxn];
int v[maxn];
string s[maxn];
int lev[maxn];
int par[logn][maxn];
pi g[maxn];
pi gi[maxn];
vii vals;
int res[maxn];
vector<pair<int, pi> > que[maxn];

char from[maxn];
void dfs(int u, int dad) {
    FOR(i, 1, logn) par[i][u] = par[i - 1][par[i - 1][u]];
    for (auto e : adj[u]) {
        int v = e.fi;
        char c = e.se;
        if (v != dad) {
            lev[v] = lev[u] + 1;
            par[0][v] = u;
            from[v] = c;
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (lev[u] < lev[v]) swap(u, v);
    FORd(i, logn, 0) {
        if (lev[par[i][u]] >= lev[v]) {
            u = par[i][u];
        }
    }
    if (u == v) return u;
    FORd(i, logn, 0) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

int jump(int u, int k) {
    FORd(i, logn, 0) {
        if ((1 << i) <= k) {
            k -= 1 << i;
            u = par[i][u];
        }
    }
    return u;
}

int cnt[maxn * 2];
void upd_dfs(int u, int dad) {
    int w = u, rt = 0;
    pi hs = mp(0, 0);
    FOR(i, 0, min(100, lev[u])) {
        char c = from[w];
        hs.fi = mult(hs.fi, base, pr);
        addmod(hs.fi, c, pr);
        hs.se = mult(hs.se, base2, pr2);
        addmod(hs.se, c, pr2);
        int k = lower_bound(all(vals), hs) - vals.begin();
        if (k < sz(vals) && vals[k] == hs) {
            cnt[k]++;
        }
        w = par[0][w];
    }
    for (auto it : que[u]) {
        int ix = it.fi;
        int u = it.se.fi;
        int s = it.se.se;
        res[ix] += cnt[u] * s;
    }
    for (auto e : adj[u]) {
        int v = e.fi;
        if (v != dad) {
            upd_dfs(v, u);
        }
    }
    w = u, rt = 0;
    hs = mp(0, 0);
    FOR(i, 0, min(100, lev[u])) {
        char c = from[w];
        hs.fi = mult(hs.fi, base, pr);
        addmod(hs.fi, c, pr);
        hs.se = mult(hs.se, base2, pr2);
        addmod(hs.se, c, pr2);
        int k = lower_bound(all(vals), hs) - vals.begin();
        if (k < sz(vals) && vals[k] == hs) {
            cnt[k]--;
        }
        w = par[0][w];
    }
}

int ispr(int k) {
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            return 0;
        }
    }
    return 1;
}

void chemthan() {
    pr = INF + myrand() % (INF / 100);
    while (!ispr(pr)) pr++;
    base = 1234 + myrand() % 1234;
    pr2 = INF + myrand() % (INF / 100);
    while (!ispr(pr2)) pr2++;
    base2 = 1234 + myrand() % 1234;
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v; char c; cin >> u >> v >> c; u--, v--;
        adj[u].pb(mp(v, c));
        adj[v].pb(mp(u, c));
    }
    cin >> q;
    FOR(i, 0, q) {
        cin >> u[i] >> v[i] >> s[i], u[i]--, v[i]--;
        reverse(all(s[i]));
        for (char c : s[i]) {
            g[i].fi = mult(g[i].fi, base, pr);
            addmod(g[i].fi, c, pr);
            g[i].se = mult(g[i].se, base2, pr2);
            addmod(g[i].se, c, pr2);
        }
        reverse(all(s[i]));
        for (char c : s[i]) {
            gi[i].fi = mult(gi[i].fi, base, pr);
            addmod(gi[i].fi, c, pr);
            gi[i].se = mult(gi[i].se, base2, pr2);
            addmod(gi[i].se, c, pr2);
        }
        vals.pb(g[i]), vals.pb(gi[i]);
    }
    sort(all(vals)), uni(vals);
    static int h[maxn];
    static int hi[maxn];
    FOR(i, 0, q) h[i] = lower_bound(all(vals), g[i]) - vals.begin();
    FOR(i, 0, q) hi[i] = lower_bound(all(vals), gi[i]) - vals.begin();
    dfs(0, -1);
    FOR(i, 0, q) {
        if (u[i] == v[i]) {
            continue;
        }
        int w = lca(u[i], v[i]);
        int iter = 0;
        for (int t : {u[i], v[i]}) {
            if (lev[t] - lev[w] >= sz(s[i])) {
                int k = lev[t] - (lev[w] + sz(s[i]) - 1);
                int nt = jump(t, k);
                if (!iter) {
                    que[t].pb(mp(i, mp(hi[i], 1)));
                    que[nt].pb(mp(i, mp(hi[i], -1)));
                }
                else {
                    que[t].pb(mp(i, mp(h[i], 1)));
                    que[nt].pb(mp(i, mp(h[i], -1)));
                }
            }
            iter++;
        }
        if (w != u[i] && w != v[i]) {
            int du = lev[u[i]] - lev[w];
            int dv = lev[v[i]] - lev[w];
            int mu = min(du, sz(s[i]) - 1);
            int mv = min(dv, sz(s[i]) - 1);
            int su = jump(u[i], du - mu);
            int sv = jump(v[i], dv - mv);
            string tu;
            while (su != w) {
                char c = from[su];
                tu += c;
                su = par[0][su];
            }
            string tv;
            while (sv != w) {
                char c = from[sv];
                tv += c;
                sv = par[0][sv];
            }
            reverse(all(tv));
            string tt = tu + tv;
            kmp.build((char *) s[i].data());
            res[i] += sz(kmp.query((char *) tt.data()));
        }
    }
    upd_dfs(0, -1);
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
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}