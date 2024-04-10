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
 
void chemthan() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vi> g(n);
    FOR(i, 0, k) {
        int c; cin >> c;
        while (c--) {
            int u; cin >> u; u--;
            g[u].pb(i);
        }
    }
    vi dj(k + k + 1), sum(k + k + 1);
    FOR(i, 0, k + k + 1) dj[i] = i, sum[i] = i & 1;
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    auto join = [&] (int u, int v) {
        u = find(u);
        v = find(v);
        if (u ^ v) {
            dj[u] = v;
            sum[v] += sum[u];
        }
    };
    int cost = 0;
    auto func = [&] (int x, int y) {
        if (find(x) == find(y)) {
            return;
        }
        for (int z : {x, y}) {
            if (find(z) == find(k + k)) {
                cost -= sum[find(z ^ 1)];
            }
            else if (find(z ^ 1) == find(k + k)) {
                cost -= sum[find(z)];
            }
            else {
                cost -= min(sum[find(z)], sum[find(z ^ 1)]);
            }
        }
        join(x, y);
        join(x ^ 1, y ^ 1);
        if (find(x) == find(k + k)) {
            cost += sum[find(x ^ 1)];
        }
        else if (find(x ^ 1) == find(k + k)) {
            cost += sum[find(x)];
        }
        else {
            cost += min(sum[find(x)], sum[find(x ^ 1)]);
        }
    };
    FOR(u, 0, n) {
        if (sz(g[u]) == 2) {
            int x = g[u][0];
            int y = g[u][1];
            if (s[u] == '0') {
                func(x << 1, y << 1 | 1);
            }
            else if (s[u] == '1') {
                func(x << 1, y << 1);
            }
        }
        else if (s[u] == '0') {
            int x = g[u][0];
            if (find(x << 1) != find(k + k)) {
                cost -= min(sum[find(x << 1)], sum[find(x << 1 | 1)]);
                cost += sum[find(x << 1 | 1)];
                join(x << 1, k + k);
            }
        }
        else if (s[u] == '1') {
            if (sz(g[u]) == 1) {
                int x = g[u][0];
                if (find(x << 1 | 1) != find(k + k)) {
                    cost -= min(sum[find(x << 1)], sum[find(x << 1 | 1)]);
                    cost += sum[find(x << 1)];
                    join(x << 1 | 1, k + k);
                }
            }
        }
        cout << cost << "\n";
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