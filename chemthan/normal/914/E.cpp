#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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

const int maxn = (1 << 20) + 5;
int n;
vi adj[maxn];
int a[maxn];
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

int rt;
int cnt[maxn];
long long f[maxn];
long long ans[maxn];
long long ans2[maxn];

void add(int u, int p, int val) {
    cnt[val]++;
    for (int v : adj[u]) {
        if (v != p && !del[v]) {
            add(v, u, val ^ a[v]);
        }
    }
}
void rem(int u, int p, int val) {
    cnt[val]--;
    for (int v : adj[u]) {
        if (v != p && !del[v]) {
            rem(v, u, val ^ a[v]);
        }
    }
}
void upd(int u, int p, int val) {
    f[u] = cnt[val ^ a[rt]];
    ans2[rt] += cnt[val ^ a[rt]];
    int d = val ^ a[rt];
    if (!d || bitcount(d) == 1) {
        ans2[rt]++;
    }
    FOR(i, 0, 20) {
        f[u] += cnt[val ^ (1 << i) ^ a[rt]];
        ans2[rt] += cnt[val ^ (1 << i) ^ a[rt]];
    }
    for (int v : adj[u]) {
        if (v != p && !del[v]) {
            upd(v, u, val ^ a[v]);
            f[u] += f[v];
        }
    }
    ans[u] += f[u];
}
void work(int u) {
    rt = u;
    cnt[0]++;
    ans[rt]++;
    for (int v : adj[u]) {
        if (!del[v]) {
            add(v, u, a[v]);
        }
    }
    for (int v : adj[u]) {
        if (!del[v]) {
            rem(v, u, a[v]);
            upd(v, u, a[v]);
            add(v, u, a[v]);
        }
    }
    cnt[0]--;
    for (int v : adj[u]) {
        if (!del[v]) {
            rem(v, u, a[v]);
        }
    }
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
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    string s; cin >> s;
    FOR(i, 0, n) a[i] = 1 << s[i] - 'a';
    divide(0);
    FOR(i, 0, n) cout << ans[i] + ans2[i] / 2 << " \n"[i == n - 1];
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