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
    int n, m, k; cin >> n >> m >> k;
    vector<vi> a(n, vi(m));
    FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j], a[i][j]--;
    vector<vector<vi>> ds(k, vector<vi>(n, vi(m, INF)));
    FOR(t, 0, k) {
        auto& d = ds[t];
        queue<int> que;
        vector<vii> gg(k);
        FOR(i, 0, n) FOR(j, 0, m) {
            if (a[i][j] == t) {
                d[i][j] = 0, que.push(i), que.push(j);
            }
            else {
                gg[a[i][j]].pb({i, j});
            }
        }
        while (sz(que)) {
            int u = que.front(); que.pop();
            int v = que.front(); que.pop();
            auto inside = [&] (int u, int v) {
                if (!(0 <= u && u < n)) return 0;
                if (!(0 <= v && v < m)) return 0;
                return 1;
            };
            int t = a[u][v];
            while (sz(gg[t])) {
                int uu = gg[t].back().fi;
                int vv = gg[t].back().se;
                gg[t].pop_back();
                if (chkmin(d[uu][vv], d[u][v] + 1)) {
                    que.push(uu), que.push(vv);
                }
            }
            FOR(i, -1, 1 + 1) FOR(j, -1, 1 + 1) if (abs(i) + abs(j) == 1) {
                int nu = u + i;
                int nv = v + j;
                if (inside(nu, nv)) {
                    if (chkmin(d[nu][nv], d[u][v] + 1)) {
                        que.push(nu), que.push(nv);
                    }
                }
            }
        }
    }
    int q; cin >> q;
    while (q--) {
        vi x(2), y(2);
        FOR(i, 0, 2) cin >> x[i] >> y[i], x[i]--, y[i]--;
        int res = abs(x[0] - x[1]) + abs(y[0] - y[1]);
        if (a[x[0]][y[0]] == a[x[1]][y[1]]) {
            chkmin(res, 1);
        }
        FOR(t, 0, k) {
            chkmin(res, ds[t][x[0]][y[0]] + ds[t][x[1]][y[1]] + 1);
        }
        cout << res << "\n";
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