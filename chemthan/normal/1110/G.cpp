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

const int maxn = 1e6 + 5;
int n;
vi adj[maxn];
string s;

pi mx;
vi vals;
void dfs(int u, int p, int lev) {
    chkmax(mx, mp(lev, u));
    if (s[u] == 'W') {
        vals.pb(lev);
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, lev + 1);
        }
    }
}

void diameter(int rt) {
    mx = mp(0, 0);
    dfs(rt, -1, 0);
    vals.clear();
    dfs(mx.se, -1, 0);
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

void solve() {
    cin >> n;
    FOR(i, 0, n) adj[i].clear();
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    cin >> s;
    if (n < 3) {
        cout << "Draw\n";
        return;
    }
    FOR(u, 0, n) {
        if (3 < sz(adj[u])) {
            cout << "White\n";
            return;
        }
        if (sz(adj[u]) == 3) {
            int num = 0;
            for (int v : adj[u]) {
                if (1 < sz(adj[v])) {
                    num++;
                }
            }
            if (1 < num) {
                cout << "White\n";
                return;
            }
        }
        if (s[u] == 'W' && 2 < sz(adj[u])) {
            cout << "White\n";
            return;
        }
        for (int v : adj[u]) {
            if (s[u] == 'W' && s[v] == 'W') {
                cout << "White\n";
                return;
            }
            if (s[u] == 'W' && 2 < sz(adj[v])) {
                cout << "White\n";
                return;
            }
            for (int w : adj[u]) if (v < w && s[v] == 'W' && s[w] == 'W') {
                cout << "White\n";
                return;
            }
        }
    }

    int ptr = n;
    FOR(u, 0, n) {
        vi leaves;
        FOR(i, 0, sz(adj[u])) {
            int v = adj[u][i];
            if (sz(adj[v]) == 1) {
                leaves.pb(v);
            }
        }
        while (1 < sz(leaves)) {
            int x = leaves.back();
            leaves.pop_back();
            int y = leaves.back();
            leaves.pop_back();
            remove(adj[u], x);
            remove(adj[u], y);
            remove(adj[x], u);
            remove(adj[y], u);
            adj[ptr].clear();
            adj[u].pb(ptr);
            adj[ptr].pb(u);
            s += "W";
            ptr++;
        }
    }

    diameter(ptr - 1);
    sort(all(vals));
    if (3 < mx.fi + 1) {
        for (int u : vals) {
            if (0 < u && u < mx.fi) {
                cout << "White\n";
                return;
            }
        }
    }
    FOR(i, 0, sz(vals) - 1) {
        if ((vals[i + 1] - vals[i] + 1) % 2 == 1) {
            cout << "White\n";
            return;
        }
    }
    cout << "Draw\n";
}

void chemthan() {
    int test; cin >> test;
    while (test--) {
        solve();
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