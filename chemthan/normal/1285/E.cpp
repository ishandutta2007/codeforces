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

typedef vector<vector<int>> dsk;

#define N 300001

int root[N];
int find(int u) {
    if (root[u] != u) root[u] = find(root[u]);
    return root[u];
}

bool visited[N];
int active[N];
int par[N];
vector<int> stk;

void dfs(int u, const dsk &ke) {
    visited[u] = true;
    root[u] = u;
    stk.push_back(u);

    for (int v: ke[u]) if (visited[v]) {
        v = find(active[v]);
        while (stk.back() != v) {
            root[find(stk.back())] = v;
            stk.pop_back();
        }
    }

    for (int v: ke[u]) if (!visited[v]) {
        active[u] = v;
        par[v] = u;
        dfs(v, ke);
    }

    if (stk.back() == u) stk.pop_back();
}

void chemthan() {
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        vii vals(n);
        FOR(i, 0, n) cin >> vals[i].fi >> vals[i].se;
        sort(all(vals));
        set<pi> st;
        vector<vi> adj(n);
        FOR(i, 0, sz(vals)) {
            auto it = st.lower_bound(mp(vals[i].fi, -INF));
            if (it != st.end()) {
                adj[i].pb(it->se);
                adj[it->se].pb(i);
            }
            it = st.end();
            if (it != st.begin()) {
                it--;
                if (vals[i].fi <= it->fi) {
                    adj[i].pb(it->se);
                    adj[it->se].pb(i);
                }
            }
            st.insert(mp(vals[i].se, i));
        }
        FOR(u, 0, n) {
            sort(all(adj[u])), uni(adj[u]);
        }
        int tot = 0;
        FOR(u, 0, n) root[u] = u, visited[u] = active[u] = 0, par[u] = -1;
        FOR(u, 0, n) {
            if (!visited[u]) {
                dfs(u, adj);
                tot++;
            }
        }
        int res = -1;
        FOR(u, 0, n) {
            map<int, int> hs;
            for (int v : adj[u]) {
                int t = find(v);
                if (par[t] != -1) {
                    hs[par[t]] = 1;
                }
            }
            vi vals;
            for (int v : adj[u]) if (!hs[v]) {
                vals.pb(find(v));
            }
            sort(all(vals)), uni(vals);
            chkmax(res, sz(vals) - 1);
        }
        cout << tot + res << "\n";
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