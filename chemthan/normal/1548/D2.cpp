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
    int n; cin >> n;
    vii pts;
    map<pi, vii> hs;
    map<pi, vi> hs2;
    FOR(i, 0, n) {
        int x, y; cin >> x >> y;
        hs[mp(x & 1, y & 1)].pb({x / 2, y / 2});
        hs2[mp(x & 3, y & 3)].pb(i);
        pts.pb({x, y});
    }
    auto solve = [&] (vii pts) {
        int n = sz(pts);
        vector<vi> f(n, vi(n));
        long long sum0 = 0;
        long long sum01 = 0;
        FOR(i, 0, n) FOR(j, i + 1, n) {
            f[i][j] = f[j][i] = __gcd(abs(pts[i].fi - pts[j].fi), abs(pts[i].se - pts[j].se)) & 1;
            if (!f[i][j]) {
                sum0 += n - 2;
            }
        }
        FOR(i, 0, n) {
            int num0 = 0, num1 = 0;
            FOR(j, 0, n) if (i ^ j) {
                if (!f[i][j]) {
                    num0++;
                }
                else {
                    num1++;
                }
            }
            sum01 += (long long) num0 * num1;
        }
        return (sum0 + sum01) / 3;
    };
    long long res = 0;
    for (auto e : hs) {
        res += solve(e.se);
    }
    vector<vi> f(n, vi(n));
    FOR(i, 0, n) FOR(j, i + 1, n) {
        f[i][j] = f[j][i] = __gcd(abs(pts[i].fi - pts[j].fi), abs(pts[i].se - pts[j].se)) & 3;
    }
    vii v;
    FOR(i, 0, 4) FOR(j, 0, 4) v.pb({i, j});
    for (auto e1 : v) {
        auto& p1 = hs2[e1];
        if (!sz(p1)) continue;
        for (auto e2 : v) if ((e1.fi + e2.fi & 1) || (e1.se + e2.se & 1)) {
            auto& p2 = hs2[e2];
            for (int u : p2) {
                vi c(4);
                for (int v : p1) {
                    c[f[u][v]]++;
                }
                FOR(x, 0, 4) {
                    if ((x + x) % 4 == 0) {
                        res += (long long) c[x] * (c[x] - 1) / 2;
                    }
                    FOR(y, x + 1, 4) {
                        if ((x + y) % 4 == 0) {
                            res += (long long) c[x] * c[y];
                        }
                    }
                }
            }
        }
    }
    for (auto e1 : v) for (auto e2 : v) if (!(e1.fi + e2.fi & 1) && !(e1.se + e2.se & 1)) {
        if (e1 == e2) break;
        auto& p1 = hs2[e1];
        auto& p2 = hs2[e2];
        for (auto e3 : v) if ((e1.fi + e3.fi & 1) || (e1.se + e3.se & 1)) {
            auto& p3 = hs2[e3];
            for (auto u : p3) {
                vi c1(4);
                vi c2(4);
                for (auto v : p1) {
                    c1[f[u][v]]++;
                }
                for (auto v : p2) {
                    c2[f[u][v]]++;
                }
                long long cross = (long long) (e2.fi - e1.fi) * (e3.se - e1.se) - (long long) (e2.se - e1.se) * (e3.fi - e1.fi);
                FOR(x, 0, 4) FOR(y, 0, 4) if ((x + y + 2 - cross) % 4 == 0) {
                    res += (long long) c1[x] * c2[y];
                }
            }
        }
    }
    cout << res << "\n";
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