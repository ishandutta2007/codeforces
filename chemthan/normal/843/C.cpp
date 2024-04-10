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

const int maxn = 2e5 + 5;
int n;
vi adj[maxn];
int del[maxn];
int size[maxn];

vector<pair<int, pi> > res;

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

int lst;

void dfs(int u, int p, int ac, int w) {
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (v != p) {
            dfs(v, u, ac, w);
            if (p != ac && u != w) {
                res.pb(mp(ac, mp(lst, v)));
                res.pb(mp(v, mp(u, w)));
                lst = v;
            }
        }
    }
}

void solve() {
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    int u = findcentroid(0);
    int w = -1;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (size[v] + size[v] == n) {
            w = v;
        }
    }
    if (w == -1) {
        FOR(i, 0, sz(adj[u])) {
            int v = adj[u][i];
            lst = v;
            dfs(v, u, u, v);
            if (lst != v) {
                res.pb(mp(u, mp(lst, v)));
            }
        }
    }
    else {
        FOR(it, 0, 2) {
            FOR(i, 0, sz(adj[u])) {
                int v = adj[u][i];
                if (v != w) {
                    lst = v;
                    dfs(v, u, u, v);
                    if (lst != v) {
                        res.pb(mp(u, mp(lst, v)));
                    }
                }
            }
            swap(u, w);
        }
    }
    cout << sz(res) << "\n";
    FOR(i, 0, sz(res)) {
        cout << res[i].fi + 1 << " " << res[i].se.fi + 1 << " " << res[i].se.se + 1 << "\n";
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