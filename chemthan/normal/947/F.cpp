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

const int maxn = 1e4 + 5;
int n;
vi adj[maxn << 1];
bitset<maxn << 1> g[maxn << 1];
int f[maxn << 1];

int findmx(vi ver) {
    pi best;
    for (int u : ver) {
        chkmax(best, mp(sz(adj[u]), u));
    }
    return best.se;
}

void remove(vi& adj, int u) {
    FOR(i, 0, sz(adj)) {
        if (adj[i] == u) {
            swap(adj[i], adj.back());
            adj.pop_back();
            break;
        }
    }
}

void remove(int u) {
    for (int v : adj[u]) {
        remove(adj[v], u);
    }
}

void finish(vi ver1, vi ver2, int u) {
    int v = -1, w = -1;
    for (int x : ver1) {
        if (sz(adj[x]) == 1 && adj[x][0] != u) {
            v = adj[x][0], w = x;
            break;
        }
    }
    int uu = -1, vv = -1, ww = -1;
    for (int x : ver2) {
        if (sz(adj[x]) == 1) {
            uu = x, ww = adj[x][0];
            break;
        }
    }
    for (int x : ver2) {
        if (x != uu && x != ww && !g[x][ww]) {
            vv = x;
            break;
        }
    }
    f[u] = uu, f[uu] = u;
    f[v] = vv, f[vv] = v;
    f[w] = ww, f[ww] = w;
    for (int u : ver1) if (f[u] == -1) {
        for (int v : ver2) {
            if (f[v] == -1) {
                f[u] = v, f[v] = u;
                break;
            }
        }
    }
}

pi find(vi& ver) {
    int c = findmx(ver), u = -1;
    for (int v : ver) {
        if (sz(adj[v]) == 1 && g[v][c]) {
            u = v;
            break;
        }
    }
    if (u == -1) {
        for (int v : ver) {
            if (sz(adj[v]) == 1) {
                u = v, c = adj[v][0];
                break;
            }
        }
    }
    remove(u), remove(ver, u);
    int v = -1;
    for (int w : ver) {
        if (sz(adj[w]) == 1 && w != c && !g[w][c]) {
            v = w;
            break;
        }
    }
    remove(v), remove(ver, v);
    return mp(u, v);
}

void rec(vi& ver1, vi& ver2) {
    if (sz(ver1) <= 5) {
        sort(all(ver2));
        do {
            int found = 0;
            FOR(i, 0, sz(ver1)) FOR(j, i + 1, sz(ver1)) {
                int u = ver1[i];
                int v = ver1[j];
                int uu = ver2[i];
                int vv = ver2[j];
                if (g[u][v] && g[uu][vv]) {
                    found = 1;
                    i = j = sz(ver1);
                }
            }
            if (!found) {
                FOR(i, 0, sz(ver1)) {
                    int u = ver1[i];
                    int uu = ver2[i];
                    f[u] = uu, f[uu] = u;
                }
                return;
            }
        }
        while (next_permutation(all(ver2)));
    }
    int u = findmx(ver1);
    int v = findmx(ver2);
    if (sz(adj[u]) == sz(ver1) - 2) {
        finish(ver1, ver2, u);
        return;
    }
    if (sz(adj[v]) == sz(ver2) - 2) {
        finish(ver2, ver1, v);
        return;
    }
    pi p1 = find(ver1);
    pi p2 = find(ver2);
    rec(ver1, ver2);
    FOR(it, 0, 2) {
        int x = p1.fi, y = p1.se;
        int xx = p2.fi, yy = p2.se;
        if (f[adj[x][0]] != adj[xx][0] && f[adj[y][0]] != adj[yy][0]) {
            f[x] = xx, f[xx] = x;
            f[y] = yy, f[yy] = y;
            return;
        }
        swap(p1.fi, p1.se);
    }
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n - 1 << 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
        g[u][v] = g[v][u] = 1;
    }
    FOR(u, 0, n + n) {
        if (sz(adj[u]) == n - 1) {
            cout << "No\n";
            return;
        }
    }
    ms(f, -1);
    vi ver1, ver2;
    FOR(i, 0, n) ver1.pb(i), ver2.pb(n + i);
    rec(ver1, ver2);
    cout << "Yes\n";
    FOR(i, 0, n) cout << f[i] + 1 << " \n"[i == n - 1];
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