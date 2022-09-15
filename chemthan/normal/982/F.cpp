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

const int maxn = 2e5 + 5;
int n, m;
set<int> adj[maxn];
set<int> radj[maxn];
int use[maxn];
vi cycle;
int f[maxn];
int dp[maxn];

int calc(int u, int lim) {
    if (f[u] != -1) {
        if (f[u] <= lim) return f[u] + sz(cycle);
        return f[u];
    }
    int& res = dp[u];
    if (~res) return res;
    res = -INF;
    for (int v : adj[u]) {
        int x = calc(v, lim);
        if (x <= lim) x += sz(cycle);
        chkmax(res, x);
    }
    return res;
}

void chemthan() {
    cin >> n >> m;
    fill_n(use, n, 1);
    FOR(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].insert(v);
        radj[v].insert(u);
    }
    queue<int> que;
    FOR(u, 0, n) if (!sz(adj[u]) || !sz(radj[u])) {
        que.push(u);
    }
    while (sz(que)) {
        int u = que.front(); que.pop();
        use[u] = 0;
        for (int v : radj[u]) {
            if (present(adj[v], u)) {
                adj[v].erase(u);
            }
            if (!sz(adj[v]) && use[v]) {
                use[v] = 0, que.push(v);
            }
        }
        for (int v : adj[u]) {
            if (present(radj[v], u)) {
                radj[v].erase(u);
            }
            if (!sz(adj[v]) && use[v]) {
                use[v] = 0, que.push(v);
            }
        }
    }
    FOR(u, 0, n) if (use[u]) {
        static int from[maxn];
        static int vis[maxn];
        stack<int> stk;
        stk.push(u);
        while (sz(stk)) {
            int v = stk.top(); stk.pop();
            vis[v] = 1;
            for (int w : adj[v]) {
                if (w == u) {
                    int ptr = v;
                    while (ptr != u) {
                        cycle.pb(ptr);
                        ptr = from[ptr];
                    }
                    cycle.pb(ptr);
                    reverse(all(cycle));
                    while (sz(stk)) stk.pop();
                    break;
                }
                if (!vis[w]) {
                    stk.push(w);
                    from[w] = v;
                }
            }
        }
        break;
    }
    assert(1 < sz(cycle));
    fill_n(f, n, -1);
    FOR(i, 0, sz(cycle)) {
        f[cycle[i]] = i;
    }
    ms(dp, -1);
    static int cnt[maxn];
    FOR(i, 0, sz(cycle)) {
        int u = cycle[i];
        int ni = -INF;
        for (int v : adj[u]) {
            int w = cycle[(i + 1) % sz(cycle)];
            if (v != w) {
                int x = calc(v, i);
                if (x <= i) x += sz(cycle);
                chkmax(ni, x);
            }
        }
        if (0 <= ni) {
            cnt[i + 1]++, cnt[ni]--;
        }
    }
    partial_sum(cnt, cnt + maxn, cnt);
    int res = -1;
    FOR(i, 0, sz(cycle)) {
        if (!(cnt[i] + cnt[i + sz(cycle)])) {
            res = cycle[i];
        }
    }
    if (res == -1) {
        cout << -1 << "\n";
        return;
    }
    que.push(res);
    while (sz(que)) {
        int u = que.front(); que.pop();
        use[u] = 0;
        for (int v : radj[u]) {
            if (present(adj[v], u)) {
                adj[v].erase(u);
            }
            if (!sz(adj[v]) && use[v]) {
                use[v] = 0, que.push(v);
            }
        }
        for (int v : adj[u]) {
            if (present(radj[v], u)) {
                radj[v].erase(u);
            }
            if (!sz(adj[v]) && use[v]) {
                use[v] = 0, que.push(v);
            }
        }
    }
    if (accumulate(use, use + n, 0)) {
        cout << -1 << "\n";
        return;
    }
    cout << res + 1 << "\n";
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