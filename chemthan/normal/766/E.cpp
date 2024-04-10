#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL_
    #define cout cerr
#endif
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

struct CentroidTree {
    struct Info {
        int d;
        Info() : d(0) {}
        Info(int d) : d(d) {}
        Info(const Info& rhs) : d(rhs.d) {}
    };
    
    static const int maxn = 100000 + 10;
    static const int logn = 20;
    int n, rt;
    int a[maxn];
    vector<int> adj[maxn];
    int size[maxn];
    int del[maxn];
    vector<int> tree[maxn];
    int lev[maxn];
    int p[logn][maxn];
    Info info[logn][maxn];
    
    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            tree[i].clear();
            del[i] = 0;
        }
    }
    void addedge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u, int p) {
        size[u] = 1;
        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i];
            if (v != p && !del[v]) {
                dfs(v, u);
                size[u] += size[v];
            }
        }
    }
    int findcentroid(int u) {
        dfs(u, -1);
        int p = -1, t = size[u];
        while (1) {
            pair<int, int> best;
            for (int i = 0; i < (int) adj[u].size(); i++) {
                int v = adj[u][i];
                if (v != p && !del[v]) {
                    best = max(best, make_pair(size[v], v));
                }
            }
            if (best.first + best.first <= t) {
                return u;
            }
            p = u, u = best.second;
        }
    }
    void upd(int u, int dep, int p) {
        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i];
            if (v != p && !del[v]) {
                info[dep][v].d = info[dep][u].d ^ a[v];
                upd(v, dep, u);
            }
        }
    }
    int divide(int u, int dep) {
        lev[u = findcentroid(u)] = dep;
        p[0][u] = u;
        info[dep][u] = Info(a[u]);
        upd(u, dep, -1);
        del[u] = 1;
        for (int i = 0; i < (int) adj[u].size(); i++) {
            int v = adj[u][i];
            if (!del[v]) {
                int w = divide(v, dep + 1);
                tree[u].push_back(w);
                p[0][w] = u;
            }
        }
        return u;
    }
    void build() {
        rt = divide(0, 0);
        
    }
    long long ans;
    int hs[2][20], tmp;
    void add(int u, int ix) {
        FOR(k, 0, 20) {
            hs[bit(info[ix][u].d, k)][k]++;
        }
        for (int i = 0; i < (int) tree[u].size(); i++) {
            int v = tree[u][i];
            add(v, ix);
        }
    }
    void rem(int u, int ix) {
        FOR(k, 0, 20) {
            hs[bit(info[ix][u].d, k)][k]--;
        }
        for (int i = 0; i < (int) tree[u].size(); i++) {
            int v = tree[u][i];
            rem(v, ix);
        }
    }
    void query(int u, int ix) {
        FOR(k, 0, 20) {
            if (bit(info[ix][u].d, k)) ans += 1 << k + 1;
            int x = bit((info[ix][u].d ^ tmp), k);
            ans += (long long) hs[1 - x][k] * (1 << k);
        }
        for (int i = 0; i < (int) tree[u].size(); i++) {
            int v = tree[u][i];
            query(v, ix);
        }
    }
    void work(int u) {
        ms(hs, 0), tmp = a[u];
        FOR(k, 0, 20) {
            ans += bit(a[u], k) * (1 << k + 1);
        }
        int ix = lev[u];
        for (int i = 0; i < (int) tree[u].size(); i++) {
            int v = tree[u][i];
            add(v, ix);
        }
        for (int i = 0; i < (int) tree[u].size(); i++) {
            int v = tree[u][i];
            rem(v, ix);
            query(v, ix);
            add(v, ix);
        }
        for (int i = 0; i < (int) tree[u].size(); i++) {
            int v = tree[u][i];
            work(v);
        }
    }
} ct;

int n;

void solve() {
    cin >> n;
    ct.init(n);
    FOR(i, 0, n) cin >> ct.a[i];
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        ct.addedge(u, v);
    }
    ct.build();
    ct.work(ct.rt);
    cout << ct.ans / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    printf("\nTime elapsed: %dms\n", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}