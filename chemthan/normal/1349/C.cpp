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
const ld EPS = 1e-6;
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
    int n, m, t; cin >> n >> m >> t;
    vector<string> s(n);
    FOR(i, 0, n) cin >> s[i];
    vector<vi> a(n, vi(m));
    FOR(i, 0, n) FOR(j, 0, m) a[i][j] = s[i][j] - '0';
    vector<vi> f(n, vi(m, INF));
    auto check = [&] (int u, int v, int t) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        FOR(i, 0, 4) {
            int uu = u + dx[i];
            int vv = v + dy[i];
            if (0 <= uu && uu < n && 0 <= vv && vv < m) {
                int cc = a[uu][vv];
                if (f[uu][vv] != INF) {
                    cc ^= t + f[uu][vv] & 1;
                }
                if (a[u][v] == cc) {
                    return 1;
                }
            }
        }
        return 0;
    };
    queue<int> que;
    FOR(i, 0, n) FOR(j, 0, m) {
        if (check(i, j, 0)) {
            f[i][j] = 0;
            que.push(i), que.push(j);
        }
    }
    while (sz(que)) {
        int u = que.front(); que.pop();
        int v = que.front(); que.pop();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        FOR(i, 0, 4) {
            int uu = u + dx[i];
            int vv = v + dy[i];
            if (0 <= uu && uu < n && 0 <= vv && vv < m) {
                if (f[uu][vv] > f[u][v] + 1 && check(uu, vv, f[u][v] + 1)) {
                    f[uu][vv] = f[u][v] + 1;
                    que.push(uu), que.push(vv);
                }
                else if (f[uu][vv] > f[u][v] + 2 && check(uu, vv, f[u][v] + 2)) {
                    f[uu][vv] = f[u][v] + 2;
                    que.push(uu), que.push(vv);
                }
            }
        }
    }
    while (t--) {
        int u, v; cin >> u >> v; u--, v--;
        long long p; cin >> p;
        if (p < f[u][v] || f[u][v] == INF) {
            cout << a[u][v] << "\n";
        }
        else {
            cout << (a[u][v] ^ (p + f[u][v] & 1)) << "\n";
        }
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