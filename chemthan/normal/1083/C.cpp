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

namespace LCA {
    const int maxn = 2e5 + 5;
    const int logn = 20;
    vector<int> events;
    int sta[maxn];
    int tin[maxn];
    int idx[maxn];
    int tms;
    int f[logn][maxn << 1];
    int lg[maxn << 1];

    void dfs(int u, int p, vector<int> adj[]) {
        idx[tin[u] = tms++] = u;
        sta[u] = events.size();
        events.push_back(tin[u]);
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (v != p) {
                dfs(v, u, adj);
                events.push_back(tin[u]);
            }
        }
    }
    int query(int u, int v) {
        int l = u == v ? 0 : lg[v - u];
        return min(f[l][u], f[l][v - (1 << l) + 1]);
    }
    int lca(int u, int v) {
        if (sta[u] > sta[v]) swap(u, v);
        return idx[query(sta[u], sta[v])];
    }
    void build(vector<int> adj[]) {
        events.clear();
        dfs(tms = 0, -1, adj);
        for (int i = 0; i < events.size(); i++) {
            f[0][i] = events[i];
        }
        for (int i = 1; i < logn; i++) {
            for (int j = 0; j + (1 << i - 1) < events.size(); j++) {
                f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
            }
        }
        for (int i = 1; i < (maxn << 1); i++) {
            lg[i] = __lg(i);
        }
    }
}

const int maxn = 2e5 + 5;
const int logn = 20;
int n, q;
int p[maxn];
vi adj[maxn];
int tin[maxn];
int tou[maxn];
int tms;

void dfs(int u, int p) {
    tin[u] = tms++;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tou[u] = tms - 1;
}

int isanc(int u, int v) {
    return tin[u] <= tin[v] && tou[v] <= tou[u];
}

int between(int u, int v, int w) {
    int a = LCA::lca(u, v);
    return isanc(a, w) && (isanc(w, u) || isanc(w, v));
}

pi st[maxn << 2];
pi join(pi a, pi b) {
    if (a == mp(-1, -1) || b == mp(-1, -1)) return mp(-1, -1);
    if (a == mp(INF, INF)) return b;
    if (b == mp(INF, INF)) return a;
    for (int u : {a.fi, a.se, b.fi, b.se}) {
        for (int v : {a.fi, a.se, b.fi, b.se}) if (u < v) {
            if (between(u, v, a.fi) && between(u, v, a.se)
                    && between(u, v, b.fi) && between(u, v, b.se)) {
                return mp(u, v);
            }
        }
    }
    return mp(-1, -1);
}
void upd(int p, int i, int L, int R, pi val) {
    if (i < L || R < i) return;
    if (L == R) {
        st[p] = val;
        return;
    }
    upd(p << 1, i, L, L + R >> 1, val);
    upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
    st[p] = join(st[p << 1], st[p << 1 | 1]);
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n) cin >> p[i];
    FOR(i, 1, n) {
        int p; cin >> p; p--;
        adj[p].pb(i), adj[i].pb(p);
    }
    dfs(0, -1);
    LCA::build(adj);
    FOR(i, 0, n) {
        upd(1, p[i], 0, n - 1, mp(i, i));
    }
    cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int u, v; cin >> u >> v; u--, v--;
            swap(p[u], p[v]);
            upd(1, p[u], 0, n - 1, mp(u, u));
            upd(1, p[v], 0, n - 1, mp(v, v));
        }
        else {
            pi r = mp(INF, INF);
            int p = 1, L = 0, R = n - 1;
            while (L < R) {
                int M = L + R >> 1;
                pi nr = join(r, st[p << 1]);
                if (nr != mp(-1, -1)) {
                    r = nr;
                    L = M + 1;
                    p = p << 1 | 1;
                }
                else {
                    R = M;
                    p = p << 1;
                }
            }
            if (join(r, st[p]) != mp(-1, -1)) {
                cout << L + 1 << "\n";
            }
            else {
                cout << L << "\n";
            }
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