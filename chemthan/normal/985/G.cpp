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
const int magic = 50;
int n, m;
int a, b, c;
vi adj[maxn];
unsigned long long f[maxn];
unsigned long long g[maxn];
unsigned long long h[maxn];

void calc(unsigned long long f[]) {
    map<pi, int> hs;
    FOR(u, 0, n) for (int v : adj[u]) hs[mp(u, v)] = 1;
    unsigned long long sum = 0;
    FOR(u, 0, n) {
        f[u] = sum;
        vi ver;
        for (int v : adj[u]) if (v < u) {
            ver.pb(v);
            f[u] += u - 1;
            f[u] -= upper_bound(all(adj[v]), u - 1) - adj[v].begin();
        }
        f[u] -= (unsigned long long) sz(ver) * (sz(ver) - 1) / 2;
        if (sz(ver) < magic) {
            FOR(i, 0, sz(ver)) FOR(j, i + 1, sz(ver)) {
                if (hs[mp(ver[i], ver[j])]) {
                    f[u]++;
                }
            }
        }
        else {
            static int flag[maxn];
            for (int v : ver) {
                for (int w : adj[v]) {
                    if (w > v) break;
                    f[u] += flag[w];
                }
                flag[v] = 1;
            }
            for (int v : ver) {
                flag[v] = 0;
            }
        }
        sum += sz(ver);
        f[u] = (unsigned long long) u * (u - 1) / 2 - f[u];
    }
}

void chemthan() {
    cin >> n >> m >> a >> b >> c;
    FOR(i, 0, m) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        adj[v].pb(u);
        adj[u].pb(v);
    }
    FOR(u, 0, n) sort(all(adj[u]));
    calc(f);
    for (int u = 0; u + u <= n - 1; u++) {
        swap(adj[u], adj[n - u - 1]);
    }
    FOR(u, 0, n) {
        for (int& v : adj[u]) v = n - v - 1;
        reverse(all(adj[u]));
    }
    calc(g);
    for (int u = 0; u + u <= n - 1; u++) {
        swap(g[u], g[n - u - 1]);
        swap(adj[u], adj[n - u - 1]);
    }
    FOR(u, 0, n) {
        for (int& v : adj[u]) v = n - v - 1;
        reverse(all(adj[u]));
    }
    map<pi, int> hs;
    FOR(u, 0, n) for (int v : adj[u]) hs[mp(u, v)] = 1;
    FOR(u, 0, n) {
        h[u] = m - sz(adj[u]);
        vi ver;
        for (int v : adj[u]) {
            ver.pb(v);
            h[u] += n - 2;
            h[u] -= sz(adj[v]) - 1;
        }
        h[u] -= (unsigned long long) sz(ver) * (sz(ver) - 1) / 2;
        if (sz(ver) < magic) {
            FOR(i, 0, sz(ver)) FOR(j, i + 1, sz(ver)) {
                if (hs[mp(ver[i], ver[j])]) {
                    h[u]++;
                }
            }
        }
        else {
            static int flag[maxn];
            for (int v : ver) {
                for (int w : adj[v]) {
                    if (w > v) break;
                    h[u] += flag[w];
                }
                flag[v] = 1;
            }
            for (int v : ver) {
                flag[v] = 0;
            }
        }
        h[u] = (unsigned long long) (n - 1) * (n - 2) / 2 - h[u];
    }
    unsigned long long res = 0;
    FOR(u, 0, n) {
        res += c * f[u] * u;
        res += a * g[u] * u;
        res += b * (h[u] - f[u] - g[u]) * u;
    }
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