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
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

void chemthan() {
    int test; cin >> test;
    while (test--) {
        int n, m, k; cin >> n >> m >> k;
        vector<vi> adj(n);
        FOR(i, 0, m) {
            int u, v; cin >> u >> v; u--, v--;
            adj[u].pb(v), adj[v].pb(u);
        }
        vi deg(n);
        FOR(i, 0, n) deg[i] = sz(adj[i]);
        priority_queue<pi> st;
        FOR(i, 0, n) st.push({-deg[i], i});
        vi rem(n);
        while (sz(st) && -st.top().fi < k - 1) {
            int u = st.top().se;
            st.pop();
            if (rem[u]) {
                continue;
            }
            rem[u] = 1;
            for (int v : adj[u]) if (!rem[v]) {
                deg[v]--;
                st.push({-deg[v], v});
            }
        }
        {
            auto tst = st;
            auto trem = rem;
            auto tdeg = deg;
            while (sz(st) && -st.top().fi < k) {
                int u = st.top().se;
                st.pop();
                if (rem[u]) {
                    continue;
                }
                rem[u] = 1;
                for (int v : adj[u]) if (!rem[v]) {
                    deg[v]--;
                    st.push({-deg[v], v});
                }
            }
            vi res;
            FOR(i, 0, n) if (!rem[i]) {
                res.pb(i);
            }
            if (sz(res)) {
                sort(all(res));
                cout << 1 << " " << sz(res) << "\n";
                FOR(i, 0, sz(res)) cout << res[i] + 1 << " \n"[i == sz(res) - 1];
                continue;
            }
            st = tst;
            rem = trem;
            deg = tdeg;
        }
        if (m < (long long) k * (k - 1) / 2) {
            cout << -1 << "\n";
            continue;
        }
        vector<vi> adj2(n);
        FOR(u, 0, n) if (!rem[u]) {
            for (int v : adj[u]) if (!rem[v]) {
                adj2[u].pb(v);
            }
            sort(all(adj2[u]));
        }
        auto solve = [&] () {
            vi flag(n);
            auto calc = [&] (int u) {
                vi res({u});
                for (int v : adj2[u]) {
                    if (!rem[v]) {
                        res.pb(v);
                    }
                }
                FOR(i, 0, sz(res)) FOR(j, i + 1, sz(res)) {
                    int u = res[i];
                    int v = res[j];
                    int k = lower_bound(all(adj2[u]), v) - adj2[u].begin();
                    if (k == sz(adj2[u]) || adj2[u][k] != v) {
                        return 0;
                    }
                }
                sort(all(res));
                cout << 2 << "\n";
                FOR(i, 0, k) cout << res[i] + 1 << " \n"[i == k - 1];
                return 1;
            };
            while (sz(st)) {
                int u = st.top().se;
                st.pop();
                if (rem[u]) continue;
                if (k - 1 <= deg[u]) {
                    assert(deg[u] == k - 1);
                    if (calc(u)) {
                        return;
                    }
                }
                for (int v : adj2[u]) if (!rem[v]) {
                    deg[v]--;
                    st.push({-deg[v], v});
                }
                rem[u] = 1;
            }
            cout << -1 << "\n";
        };
        solve();
    }
}

int32_t main(int32_t argc, char* argv[]) {
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