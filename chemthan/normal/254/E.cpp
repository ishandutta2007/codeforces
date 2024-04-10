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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, t; cin >> n >> t;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    int m; cin >> m;
    vi l(m), r(m), f(m);
    vector<vi> g(123456);
    FOR(i, 0, m) {
        cin >> l[i] >> r[i] >> f[i], l[i]--, r[i]--;
        FOR(j, l[i], r[i] + 1) g[j].pb(i);
    }
    vector<vi> dp(n + 1, vi(444, -INF));
    vector<vi> rb(n + 1, vi(444));
    vector<vi> rr(n + 1, vi(444));
    dp[0][0] = 0;
    FOR(i, 0, n) {
        sort(all(g[i]), [&] (int u, int v) {
                return f[u] < f[v];
                }
            );
        FOR(u, 0, 444) {
            int nu = min(u + a[i] - t, a[i]);
            if (0 <= nu && chkmax(dp[i + 1][nu], dp[i][u])) {
                rb[i + 1][nu] = 0;
                rr[i + 1][nu] = u;
            }
            int sum = 0;
            FOR(j, 0, sz(g[i])) {
                sum += f[g[i][j]];
                if (sum + t <= u + a[i]) {
                    int nu = min(u + a[i] - sum - t, a[i]);
                    if (chkmax(dp[i + 1][nu], dp[i][u] + j + 1)) {
                        rb[i + 1][nu] = j + 1;
                        rr[i + 1][nu] = u;
                    }
                }
            }
        }
    }
    cout << *max_element(all(dp[n])) << "\n";
    int u = 0;
    FOR(i, 0, 444) {
        if (dp[n][u] < dp[n][i]) {
            u = i;
        }
    }
    vector<vi> res;
    FORd(i, n + 1, 1) {
        int x = rb[i][u];
        vi row;
        FOR(j, 0, x) {
            row.pb(g[i - 1][j]);
        }
        res.pb(row);
        u = rr[i][u];
    }
    reverse(all(res));
    for (auto row : res) {
        cout << sz(row) << " ";
        FOR(i, 0, sz(row)) cout << row[i] + 1 << " \n"[i == sz(row) - 1];
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