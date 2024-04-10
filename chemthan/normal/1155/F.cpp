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
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(n, 0));
    FOR(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        a[u][v] = a[v][u] = 1;
    }
    vector<bitset<1 << 14>> cycle(1 << n);
    vector<vi> f(1 << n, vi(n));
    FOR(msk, 0, 1 << n) {
        vi b(n);
        FOR(i, 0, n) if (!bit(msk, i)) {
            FOR(j, 0, n) {
                if (bit(msk, j) && a[i][j]) {
                    b[i] = 1;
                    FOR(k, j + 1, n) if (bit(msk, k) && a[i][k]) {
                        cycle[msk][1 << i] = 1;
                    }
                    break;
                }
            }
        }
        if (!msk) {
            b[0] = 1;
        }
        queue<int> que;
        FOR(i, 0, n) if (b[i]) {
            f[1 << i][i] = 1, que.push(1 << i), que.push(i);
        }
        vii tmp;
        while (sz(que)) {
            int xmsk = que.front(); que.pop();
            int xlst = que.front(); que.pop();
            tmp.pb(mp(xmsk, xlst));
            if (b[xlst] && xmsk != (1 << xlst)) {
                cycle[msk][xmsk] = 1;
            }
            if (!msk) {
                if (a[xlst][0]) {
                    cycle[msk][xmsk] = 1;
                }
            }
            FOR(i, 0, n) if (!bit(msk, i) && !bit(xmsk, i) && a[xlst][i]) {
                int nxmsk = xmsk | (1 << i);
                int nxlst = i;
                if (!f[nxmsk][nxlst]) {
                    f[nxmsk][nxlst] = 1;
                    que.push(nxmsk);
                    que.push(nxlst);
                }
            }
        }
        for (auto e : tmp) {
            f[e.fi][e.se] = 0;
        }
    }
    vi dp(1 << n, -1), rb(1 << n);
    function<int(int)> calc = [&] (int msk) {
        if (msk == (1 << n) - 1) return 0;
        int& res = dp[msk];
        if (~res) return res;
        res = INF;
        int pmsk = msk ^ (1 << n) - 1;
        for (int sub = pmsk; sub; sub = sub - 1 & pmsk) {
            if (cycle[msk][sub] && chkmin(res, calc(msk | sub) + bitcount(sub) + !!msk)) {
                rb[msk] = sub;
            }
        }
        return res;
    };
    cout << calc(0) << "\n";
    int msk = 0;
    while (msk ^ (1 << n) - 1) {
        vector<vi> f(1 << n, vi(n));
        vector<vi> g(1 << n, vi(n));
        int sub = rb[msk];
        if (bitcount(sub) == 1) {
            int u = __lg(sub);
            vi vals;
            FOR(i, 0, n) if (bit(msk, i) && a[u][i]) {
                vals.pb(i);
            }
            assert(2 <= sz(vals));
            FOR(i, 0, 2) {
                cout << u + 1 << " " << vals[i] + 1 << "\n";
            }
            msk |= sub;
            continue;
        }
        vi b(n);
        FOR(i, 0, n) if (!bit(msk, i)) {
            FOR(j, 0, n) {
                if (bit(msk, j) && a[i][j]) {
                    b[i] = 1;
                    FOR(k, j + 1, n) if (bit(msk, k) && a[i][k]) {
                        cycle[msk][1 << i] = 1;
                    }
                    break;
                }
            }
        }
        if (!msk) {
            b[0] = 1;
        }
        queue<int> que;
        FOR(i, 0, n) if (b[i]) {
            f[1 << i][i] = 1, que.push(1 << i), que.push(i);
        }
        vii tmp;
        int lst = -1;
        while (sz(que)) {
            int xmsk = que.front(); que.pop();
            int xlst = que.front(); que.pop();
            tmp.pb(mp(xmsk, xlst));
            if (b[xlst] && xmsk != (1 << xlst)) {
                cycle[msk][xmsk] = 1;
                if (xmsk == sub) {
                    lst = xlst;
                    FOR(u, 0, n) if (bit(msk, u) && a[xlst][u]) {
                        cout << xlst + 1 << " " << u + 1 << "\n";
                        break;
                    }
                    break;
                }
            }
            if (!msk) {
                if (a[xlst][0]) {
                    if (xmsk == sub) {
                        lst = xlst;
                        cout << xlst + 1 << " " << 1 << "\n";
                        break;
                    }
                }
            }
            FOR(i, 0, n) if (!bit(msk, i) && !bit(xmsk, i) && a[xlst][i]) {
                int nxmsk = xmsk | (1 << i);
                int nxlst = i;
                if (!f[nxmsk][nxlst]) {
                    f[nxmsk][nxlst] = 1;
                    g[nxmsk][nxlst] = xlst;
                    que.push(nxmsk);
                    que.push(nxlst);
                }
            }
        }
        for (auto e : tmp) {
            f[e.fi][e.se] = 0;
        }
        assert(lst != -1);
        int xmsk = sub, xlst = lst;
        while (1 < bitcount(xmsk)) {
            int plst = g[xmsk][xlst];
            int pmsk = xmsk ^ (1 << xlst);
            cout << plst + 1 << " " << xlst + 1 << "\n";
            xmsk = pmsk, xlst = plst;
        }
        FOR(u, 0, msk) if (bit(msk, u) && a[xlst][u]) {
            cout << u + 1 << " " << xlst + 1 << "\n";
            break;
        }
        msk |= sub;
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
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}