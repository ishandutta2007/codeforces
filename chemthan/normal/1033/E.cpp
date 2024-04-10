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
inline ull icbrt(ull k) {ull r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}

const int maxn = 600 + 5;
int n;
int f[maxn];
int g[maxn];
vi adj[maxn];
int vis[maxn];

int ask(vi ver) {
    static int num = 0;
    sort(all(ver)), uni(ver);
    if (sz(ver) <= 1) {
        return 0;
    }
    assert(num++ < 20000);
    cout << "? " << sz(ver) << "\n";
    FOR(i, 0, sz(ver)) cout << ver[i] + 1 << " \n"[i == sz(ver) - 1];
    cout.flush();
    int res; cin >> res;
    if (res == -1) {
        exit(0);
    }
    return res;
}

int from[maxn];
void dfs(int u, int p) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !vis[v]) {
            from[v] = u;
            dfs(v, u);
        }
    }
}

void chemthan() {
    srand(time(NULL));
    cin >> n;
    queue<int> que;
    f[0] = 1, que.push(0);
    while (sz(que)) {
        int u = que.front(); que.pop();
        while (1) {
            vi ver; FOR(i, 0, n) if (!f[i]) ver.pb(i);
            int x = ask(ver);
            ver.pb(u);
            int y = ask(ver);
            ver.pop_back();
            if (x == y) break;
            while (sz(ver) > 1) {
                vi ver1, ver2;
                FOR(i, 0, sz(ver)) {
                    if (i < sz(ver) / 2) {
                        ver1.pb(ver[i]);
                    }
                    else {
                        ver2.pb(ver[i]);
                    }
                }
                if (myrand() & 1) {
                    swap(ver1, ver2);
                }
                int x = ask(ver1);
                ver1.pb(u);
                int y = ask(ver1);
                ver1.pop_back();
                if (x < y) {
                    ver = ver1;
                }
                else {
                    ver = ver2;
                }
            }
            assert(sz(ver) == 1);
            int v = ver[0];
            if (!f[v]) {
                g[v] = g[u] ^ 1;
                adj[u].pb(v), adj[v].pb(u);
                f[v] = 1, que.push(v);
            }
        }
    }
    vi ver1, ver2;
    FOR(i, 0, n) {
        if (!g[i]) {
            ver1.pb(i);
        }
        else {
            ver2.pb(i);
        }
    }
    for (vi v : {ver1, ver2}) {
        if (ask(v)) {
            while (sz(v) > 2) {
                while (1) {
                    random_shuffle(all(v));
                    vi ver1, ver2;
                    FOR(i, 0, sz(v)) {
                        if (i < sz(v) / 2) {
                            ver1.pb(v[i]);
                        }
                        else {
                            ver2.pb(v[i]);
                        }
                    }
                    if (myrand() & 1) {
                        swap(ver1, ver2);
                    }
                    if (ask(ver1)) {
                        v = ver1;
                        break;
                    }
                    if (ask(ver2)) {
                        v = ver2;
                        break;
                    }
                }
            }
            assert(sz(v) == 2);
            int st = v[0];
            int ed = v[1];
            dfs(st, -1);
            assert(vis[ed]);
            vi cycle;
            while (ed != st) {
                cycle.pb(ed);
                ed = from[ed];
            }
            cycle.pb(ed);
            cout << "N " << sz(cycle) << "\n";
            FOR(i, 0, sz(cycle)) cout << cycle[i] + 1 << " \n"[i == sz(cycle) - 1];
            cout.flush();
            return;
        }
    }
    cout << "Y " << sz(ver1) << "\n";
    FOR(i, 0, sz(ver1)) cout << ver1[i] + 1 << " \n"[i == sz(ver1) - 1];
    cout.flush();
}

int main(int argc, char* argv[]) {
    //ios_base::sync_with_stdio(0), cin.tie(0);
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