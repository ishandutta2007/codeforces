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
const int FFTMOD = 1007681537;
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
int n;
int a[maxn];
vector<int> adj[maxn];
int del[maxn];
int size[maxn];
void dfs(int u, int p) {
    size[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v != p && !del[v]) {
            dfs(v, u);
            size[u] += size[v];
        }
    }
}
int findcentroid(int u) {
    int p = -1; dfs(u, -1);
    int cap = size[u] >> 1;
    while (1) {
        bool found = false;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (v != p && !del[v] && size[v] > cap) {
                found = true;
                p = u; u = v;
                break;
            }
        }
        if (!found) return u;
    }
}

int sum[2];
int cnt[2];
int res;
void add(int u, int p, int lev, int t) {
    addmod(sum[lev & 1], t);
    addmod(cnt[lev & 1], 1);
    for (int v : adj[u]) {
        if (v != p && !del[v]) {
            int nt = t;
            if (lev & 1) {
                addmod(nt, a[v]);
            }
            else {
                submod(nt, a[v]);
            }
            add(v, u, lev + 1, nt);
        }
    }
}
void rem(int u, int p, int lev, int t) {
    submod(sum[lev & 1], t);
    submod(cnt[lev & 1], 1);
    for (int v : adj[u]) {
        if (v != p && !del[v]) {
            int nt = t;
            if (lev & 1) {
                addmod(nt, a[v]);
            }
            else {
                submod(nt, a[v]);
            }
            rem(v, u, lev + 1, nt);
        }
    }
}
int z;
void upd(int u, int p, int lev, int t) {
    int tt = t;
    submod(tt, a[z]);
    if (!(lev & 1)) {
        addmod(res, mult(tt, cnt[0]));
        addmod(res, sum[0]);
    }
    else {
        submod(res, mult(tt, cnt[1]));
        submod(res, sum[1]);
    }
    for (int v : adj[u]) {
        if (v != p && !del[v]) {
            int nt = t;
            if (lev & 1) {
                addmod(nt, a[v]);
            }
            else {
                submod(nt, a[v]);
            }
            upd(v, u, lev + 1, nt);
        }
    }
}
void work(int u) {
    z = u;
    addmod(res, a[u]);
    addmod(sum[0], a[u]);
    addmod(cnt[0], 1);
    for (int v : adj[u]) {
        if (!del[v]) {
            int t = (a[u] - a[v] + MOD) % MOD;
            upd(v, u, 1, t);
            add(v, u, 1, t);
        }
    }
    for (int v : adj[u]) {
        if (!del[v]) {
            int t = (a[u] - a[v] + MOD) % MOD;
            rem(v, u, 1, t);
        }
    }
    submod(sum[0], a[u]);
    submod(cnt[0], 1);
}
void divide(int u) {
    u = findcentroid(u);
    del[u] = 1, work(u);
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!del[v]) {
            divide(v);
        }
    }
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n) {
        cin >> a[i];
        a[i] = (a[i] % MOD + MOD) % MOD;
    }
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    divide(0);
    res = mult(res, 2);
    FOR(i, 0, n) submod(res, a[i]);
    cout << res << "\n";
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