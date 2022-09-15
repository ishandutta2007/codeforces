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

struct Dinic {
    static const int maxv = 1e5 + 5;
    static const int maxe = 1e6 + 5;
    static const int oo = (int) 1e9;
    int n, s, t, E;
    int adj[maxe], nxt[maxe], lst[maxv];
    int cap[maxe], flw[maxe];
    int lev[maxv], frm[maxv], ptr[maxv];
    
    void init(int _n, int _s, int _t) {
        n = _n, s = _s, t = _t, E = 0;
        fill_n(lst, n, -1);
    }
    void add(int u, int v, int c1, int c2) {
        adj[E] = v, nxt[E] = lst[u], lst[u] = E;
        cap[E] = c1, flw[E] = 0, E++;
        swap(u, v), swap(c1, c2);
        adj[E] = v, nxt[E] = lst[u], lst[u] = E;
        cap[E] = c1, flw[E] = 0, E++;
    }
    int bfs() {
        fill_n(lev, n, 0);
        static int que[maxv];
        int qh = 0, qe = 0;
        lev[s] = 1, que[qe++] = s;
        while (qh < qe) {
            int u = que[qh++];
            for (int e = lst[u]; ~e; e = nxt[e]) if (flw[e] < cap[e]) {
                int v = adj[e];
                if (!lev[v]) {
                    lev[v] = lev[u] + 1;
                    que[qe++] = v;
                }
            }
        }
        return lev[t];
    }
    int dfs(int u, int f) {
        if (u == t) return f;
        for (int& e = ptr[u]; ~e; e = nxt[e]) if (flw[e] < cap[e]) {
            int res;
            int v = adj[e];
            if (lev[v] == lev[u] + 1 && (res = dfs(v, min(f, cap[e] - flw[e])))) {
                frm[v] = e;
                return res;
            }
        }
        return 0;
    }
    int maxflow() {
        int res = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) ptr[i] = lst[i];
            int ff;
            while (ff = dfs(s, oo)) {
                res += ff;
                int st = t;
                while (st != s) {
                    int ix = frm[st];
                    flw[ix] += ff, flw[ix ^ 1] -= ff;
                    st = adj[ix ^ 1];
                }
            }
        }
        return res;
    }
    vector<int> mincut() {
        static int vis[maxv];
        fill_n(vis, n, 0);
        static int que[maxv];
        int qh = 0, qe = 0;
        vis[s] = 1, que[qe++] = s;
        while (qh < qe) {
            int u = que[qh++];
            for (int e = lst[u]; ~e; e = nxt[e]) if (flw[e] < cap[e]) {
                int v = adj[e];
                if (!vis[v]) {
                    vis[v] = 1, que[qe++] = v;
                }
            }
        }
        vector<int> res;
        for (int u = 0; u < n; u++) if (vis[u]) {
            for (int e = lst[u]; ~e; e = nxt[e]) if (!(e & 1)) {
                int v = adj[e];
                if (!vis[v]) {
                    res.push_back(e >> 1);
                }
            }
        }
        return res;
    }
    int findpath(int u, int v) {
        static int vis[maxv];
        fill_n(vis, n, 0);
        static int que[maxv];
        int qh = 0, qe = 0;
        vis[u] = 1, que[qe++] = u;
        while (qh < qe) {
            int x = que[qh++];
            for (int e = lst[x]; ~e; e = nxt[e]) if (!(e & 1)) {
                int y = adj[e];
                if (!vis[y]) {
                    frm[y] = e;
                    vis[y] = 1, que[qe++] = y;
                }
            }
        }
        if (vis[v]) {
            int st = v;
            while (st != u) {
                int ix = frm[st];
                flw[ix]++;
                st = adj[ix ^ 1];
            }
            return 1;
        }
        return 0;
    }
    void makecircle() {
        for (int e = 0; e < E; e += 2) {
            int u = adj[e ^ 1];
            int v = adj[e];
            flw[e]++;
            if (!findpath(v, u)) {
                findpath(s, u);
                findpath(v, t);
            }
        }
    }
} dinic;

const int maxn = 1e2 + 5;
const int maxm = 1e3 + 5;
int n, m, s, t;
int u[maxm];
int v[maxm];
int g[maxm];
int f[maxm];
int c[maxm];

void solve() {
    cin >> n >> m >> s >> t, s--, t--;
    dinic.init(n, s, t);
    FOR(i, 0, m) {
        cin >> u[i] >> v[i] >> g[i], u[i]--, v[i]--;
        if (g[i]) {
            dinic.add(u[i], v[i], 1, Dinic::oo);
        }
        else {
            dinic.add(u[i], v[i], Dinic::oo, 0);
        }
    }
    int res = dinic.maxflow();
    vi mincut = dinic.mincut();
    dinic.init(n, s, t);
    FOR(i, 0, m) {
        if (g[i]) {
            dinic.add(u[i], v[i], 0, 0);
        }
    }
    dinic.makecircle();
    int ptr = 0;
    FOR(i, 0, m) {
        if (g[i]) {
            f[i] = dinic.flw[ptr + ptr];
            c[i] = f[i] + 1;
            ptr++;
        }
    }
    FOR(i, 0, sz(mincut)) {
        int ix = mincut[i];
        c[ix]--;
    }
    cout << res << "\n";
    FOR(i, 0, m) {
        if (!g[i]) {
            cout << 0 << " " << 1 << "\n";
        }
        else {
            cout << f[i] << " " << c[i] << "\n";
        }
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