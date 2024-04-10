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
inline int mrand() {return abs((int) mt());}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

struct node_t {
    vi vals;
    vi revs;
    int nz;
    vi difa;
    vi difb;
    int totala;
    int totalb;
    int z, w;
    node_t() {
        vals.resize(26);
        revs.resize(26);
        nz = 0;
        difa.resize(26);
        difb.resize(26);
        totala = totalb = 0;
        z = 0, w = 1;
    }
};

node_t join(node_t a, node_t b) {
    node_t c;
    FOR(i, 0, 26) {
        c.vals[i] = max(a.vals[i], b.vals[i]);
        if (a.vals[i] < b.vals[i]) {
            c.totala += b.vals[i] - a.vals[i];
            c.difa[i] = b.vals[i] - a.vals[i];
        }
        else {
            c.totalb += a.vals[i] - b.vals[i];
            c.difb[i] = a.vals[i] - b.vals[i];
        }
    }
    c.w = a.w & b.w;
    if (a.z < c.totala || b.z < c.totalb) {
        c.w = 0;
    }
    c.z = min(a.z - c.totala, b.z - c.totalb);
    return c;
}

void upd(node_t& c, node_t& a, node_t& b, int i) {
    c.vals[i] = max(a.vals[i], b.vals[i]);
    c.totala -= c.difa[i];
    c.totalb -= c.difb[i];
    if (a.vals[i] < b.vals[i]) {
        c.totala += b.vals[i] - a.vals[i];
        c.difa[i] = b.vals[i] - a.vals[i];
    }
    else {
        c.totalb += a.vals[i] - b.vals[i];
        c.difb[i] = a.vals[i] - b.vals[i];
    }
}
void upd(node_t& c, node_t& a, node_t& b) {
    c.w = a.w & b.w;
    if (a.z < c.totala || b.z < c.totalb) {
        c.w = 0;
    }
    c.z = min(a.z - c.totala, b.z - c.totalb);
}

void add(node_t& a, char c) {
    if (c == '?') {
        a.z++;
    }
    else {
        a.vals[c - 'a']++;
    }
}

void rem(node_t& a, char c) {
    if (c == '?') {
        a.z--;
    }
    else {
        a.vals[c - 'a']--;
    }
}

void chemthan() {
    int n, q; cin >> n >> q;
    vector<vi> adj(n);
    vi par(n);
    vector<char> c(n);
    FOR(i, 1, n) {
        cin >> par[i] >> c[i]; par[i]--;
        adj[par[i]].pb(i);
    }
    vi dj(n);
    FOR(u, 0, n) dj[u] = u;
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    FOR(u, 0, n) {
        if (sz(adj[u]) == 1) {
            int v = adj[u][0];
            if (sz(adj[v]) == 1) {
                dj[find(v)] = find(u);
            }
        }
    }
    vi lev(n);
    function<void(int)> dfs = [&] (int u) {
        for (int v : adj[u]) {
            lev[v] = lev[u] + 1;
            dfs(v);
        }
    };
    dfs(0);
    vi vals;
    FOR(u, 1, n) if (!sz(adj[u])) {
        vals.pb(lev[u]);
    }
    sort(all(vals)), uni(vals);
    if (sz(vals) ^ 1) {
        while (q--) {
            int u; char c; cin >> u >> c; u--;
            cout << "Fou\n";
        }
        return;
    }
    vector<node_t> f(n);
    function<void(int)> upd_dfs = [&] (int u) {
        int flag = 0;
        for (int v : adj[u]) {
            upd_dfs(v);
            if (!flag) {
                flag = 1;
                f[u] = f[v];
            }
            else {
                f[u] = join(f[u], f[v]);
            }
        }
        if (u) {
            add(f[u], c[u]);
        }
    };
    upd_dfs(0);
    vector<vi> adj_t(n);
    vi from(n);
    FOR(u, 0, n) {
        for (int v : adj[u]) {
            int uu = find(u);
            int vv = find(v);
            if (uu ^ vv) {
                adj_t[uu].pb(vv);
                from[vv] = uu;
            }
        }
    }
    FOR(u, 0, n) {
        sort(all(adj_t[u])), uni(adj_t[u]);
    }
    FOR(u, 1, n) {
        int v = find(u);
        if ('a' <= c[u] && c[u] <= 'z') {
            f[v].revs[c[u] - 'a']++;
        }
        else {
            f[v].nz++;
        }
    }
    while (q--) {
        int u; char x; cin >> u >> x; u--;
        char y = c[u];
        c[u] = x;
        if (x != y) {
            u = find(u);
            if ('a' <= x && x <= 'z') {
                f[u].revs[x - 'a']++;
            }
            else {
                f[u].nz++;
            }
            if ('a' <= y && y <= 'z') {
                f[u].revs[y - 'a']--;
            }
            else {
                f[u].nz--;
            }
            add(f[u], x);
            rem(f[u], y);
            while (u) {
                int nu = from[u];
                if (sz(adj_t[nu]) == 1) {
                    f[nu].w = f[u].w;
                    for (int ix : {x, y}) if ('a' <= ix && ix <= 'z') {
                        f[nu].vals[ix - 'a'] = f[u].vals[ix - 'a'] + f[nu].revs[ix - 'a'];
                    }
                    f[nu].z = f[u].z + f[nu].nz;
                }
                else {
                    int v = adj_t[nu][0];
                    int w = adj_t[nu][1];
                    for (int ix : {x, y}) if ('a' <= ix && ix <= 'z') {
                        upd(f[nu], f[v], f[w], ix - 'a');
                    }
                    upd(f[nu], f[v], f[w]);
                    for (int ix : {x, y}) if ('a' <= ix && ix <= 'z') {
                        f[nu].vals[ix - 'a'] += f[nu].revs[ix - 'a'];
                    }
                    f[nu].z += f[nu].nz;
                }
                u = nu;
            }
        }
        if (!f[0].w) {
            cout << "Fou\n";
        }
        else {
            long long res = 0;
            FOR(i, 0, 26) {
                res += (i + 1) * (f[0].vals[i] + f[0].z);
            }
            cout << "Shi " << res << "\n";
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