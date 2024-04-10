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
//const int MOD = (int) 1e9 + 7;
const int MOD = 119 << 23 | 1;
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
        int n; cin >> n;
        vector<vi> a(n + n, vi(n));
        FOR(i, 0, n + n) FOR(j, 0, n) cin >> a[i][j], a[i][j]--;
        vi res;
        vi used(n + n);
        queue<int> que;
        vector<vi> f(n, vi(n));
        FOR(i, 0, n) {
            FOR(j, 0, n + n) f[i][a[j][i]]++;
            FOR(j, 0, n + n) {
                if (f[i][a[j][i]] == 1) {
                    if (!used[j]) {
                        que.push(j);
                        used[j] = 1;
                    }
                }
            }
        }
        while (sz(que)) {
            int u = que.front(); que.pop();
            res.pb(u);
            FOR(i, 0, n + n) if (!used[i]) {
                FOR(j, 0, n) if (a[u][j] == a[i][j]) {
                    used[i] = 1;
                    FOR(l, 0, n) {
                        if ((--f[l][a[i][l]]) == 1) {

                            FOR(x, 0, n + n) if (!used[x] && a[x][l] == a[i][l]) {
                                que.push(x);
                                used[x] = 1;
                            }

                        }
                    }
                    break;
                }
            }
            FOR(i, 0, n) {
                if ((--f[i][a[u][i]]) == 1) {
                    FOR(j, 0, n + n) if (!used[j] && a[j][i] == a[u][i]) {
                        que.push(j);
                        used[j] = 1;
                    }
                }
            }
        }
        vector<vi> g(n + n, vi(n + n));
        FOR(i, 0, n) {
            vector<vi> clu(n);
            FOR(j, 0, n + n) if (!used[j]) {
                clu[a[j][i]].pb(j);
            }
            FOR(j, 0, n) {
                for (int u : clu[j]) for (int v : clu[j]) if (u != v) {
                    g[u][v] = 1;
                }
            }
        }
        vi level(n + n);
        vi vis(n + n);
        int num = 0;
        FOR(u, 0, n + n) if (!used[u] && !vis[u]) {
            num++;
            queue<int> que;
            que.push(u);
            vis[u] = 1;
            while (sz(que)) {
                int v = que.front(); que.pop();
                FOR(w, 0, n + n) if (g[v][w]) {
                    if (!vis[w]) {
                        level[w] = level[v] ^ 1;
                        que.push(w);
                        vis[w] = 1;
                    }
                }
            }
        }
        FOR(i, 0, n + n) if (!used[i] && !level[i]) {
            res.pb(i);
        }
        assert(sz(res) == n);
        sort(all(res));
        cout << fpow(2, num) << "\n";
        FOR(i, 0, n) cout << res[i] + 1 << " \n"[i == n - 1];
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