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

struct HopcroftKarp {
    static const int maxv = 3e3 + 5;
    static const int maxe = 2e6 + 5;
    int nx, ny, E, adj[maxe], nxt[maxe], lst[maxv], ptr[maxv], lev[maxv], que[maxv], matx[maxv], maty[maxv];
    void init(int nx, int ny) {
        this->nx = nx, this->ny = ny;
        E = 0, fill_n(lst, nx, -1);
        fill_n(matx, nx, -1), fill_n(maty, ny, -1);
    }
    void add(int x, int y) {
        adj[E] = y, nxt[E] = lst[x], lst[x] = E++;
    }
    int bfs() {
        int qsize = 0;
        for (int x = 0; x < nx; x++) if (matx[x] != -1) lev[x] = 0;
        else {
            lev[x] = 1;
            que[qsize++] = x;
        }
        int found = 0;
        for (int i = 0; i < qsize; i++) {
            for (int x = que[i], e = lst[x]; ~e; e = nxt[e]) {
                int y = adj[e];
                if (!~maty[y]) found = 1;
                else if (!lev[maty[y]]) {
                    lev[maty[y]] = lev[x] + 1;
                    que[qsize++] = maty[y];
                }
            }
        }
        return found;
    }
    int dfs(int x) {
        for (int& e = ptr[x]; ~e; e = nxt[e]) {
            int y = adj[e];
            if (!~maty[y] || (lev[maty[y]] == lev[x] + 1 && dfs(maty[y]))) {
                matx[x] = y;
                maty[y] = x;
                return 1;
            }
        }
        return 0;
    }
    int maxmat() {
        int res = 0;
        while (bfs()) {
            for (int x = 0; x < nx; x++) ptr[x] = lst[x];
            for (int x = 0; x < nx; x++) if (!~matx[x]) res += dfs(x);
        }
        return res;
    }
    int vis[2][maxv];
    void dfs(int u, int r) {
        vis[r][u] = 1;
        if (!r) {
            for (int e = lst[u]; ~e; e = nxt[e]) {
                int v = adj[e];
                if (matx[u] != v && !vis[!r][v]) {
                    dfs(v, !r);
                }
            }
        }
        else {
            int v = maty[u];
            if (~v && !vis[!r][v]) {
                dfs(v, !r);
            }
        }
    }
    pair<vi, vi> mincover() {
        FOR(u, 0, nx) if (!~matx[u] && !vis[0][u]) {
            dfs(u, 0);
        }
        pair<vi, vi> res;
        FOR(x, 0, nx) if (!vis[0][x]) res.fi.pb(x);
        FOR(y, 0, ny) if (vis[1][y]) res.se.pb(y);
        return res;
    }
} hopkarp;

const int maxn = 3000 + 5;
int n;
int x[maxn];
int y[maxn];
int f[maxn][maxn];
int idx[maxn][maxn];
int idy[maxn][maxn];
int gx[maxn];
int gy[maxn];

void chemthan() {
    cin >> n;
    vi dcx, dcy;
    FOR(i, 0, n) cin >> x[i] >> y[i], dcx.pb(x[i]), dcy.pb(y[i]);
    sort(all(dcx)), uni(dcx);
    sort(all(dcy)), uni(dcy);
    int cx = sz(dcx);
    int cy = sz(dcy);
    FOR(i, 0, n) {
        x[i] = lower_bound(all(dcx), x[i]) - dcx.begin();
        y[i] = lower_bound(all(dcy), y[i]) - dcy.begin();
        f[x[i]][y[i]] = 1;
    }
    int cidx = 0;
    FOR(i, 0, cx) {
        FOR(j, 0, cy) {
            if (!f[i][j]) {
                int nj = j;
                while (nj < cy && !f[i][nj]) {
                    idx[i][nj] = cidx;
                    nj++;
                }
                if (!j || nj == cy) {
                    gx[cidx] = 1;
                }
                j = nj - 1;
                cidx++;
            }
        }
    }
    int cidy = 0;
    FOR(j, 0, cy) {
        FOR(i, 0, cx) {
            if (!f[i][j]) {
                int ni = i;
                while (ni < cx && !f[ni][j]) {
                    idy[ni][j] = cidy;
                    ni++;
                }
                if (!i || ni == cx) {
                    gy[cidy] = 1;
                }
                i = ni - 1;
                cidy++;
            }
        }
    }
    assert(cidx < 3000 && cidy < 3000);
    hopkarp.init(cidx, cidy);
    FOR(i, 0, cx) FOR(j, 0, cy) {
        if (!f[i][j] && !gx[idx[i][j]] && !gy[idy[i][j]]) {
            hopkarp.add(idx[i][j], idy[i][j]);
        }
    }
    int res = hopkarp.maxmat();
    pair<vi, vi> cover = hopkarp.mincover();
    assert(res == sz(cover.fi) + sz(cover.se));
    for (int x : cover.fi) {
        gx[x] = 1;
    }
    for (int y : cover.se) {
        gy[y] = 1;
    }
    vector<pair<int, pi> > ver, hor;
    FOR(x, 0, cx) {
        FOR(y, 0, cy) {
            if (f[x][y]) {
                int ny = y;
                while (ny < cy && (f[x][ny] || !gx[idx[x][ny]])) ny++;
                ver.pb(mp(x, mp(y, ny - 1)));
                y = ny - 1;
            }
        }
    }
    FOR(y, 0, cy) {
        FOR(x, 0, cx) {
            if (f[x][y]) {
                int nx = x;
                while (nx < cx && (f[nx][y] || !gy[idy[nx][y]])) nx++;
                hor.pb(mp(y, mp(x, nx - 1)));
                x = nx - 1;
            }
        }
    }
    cout << sz(hor) << "\n";
    for (auto it : hor) {
        cout << dcx[it.se.fi] << " " << dcy[it.fi] << " " << dcx[it.se.se] << " " << dcy[it.fi] << "\n";
    }
    cout << sz(ver) << "\n";
    for (auto it : ver) {
        cout << dcx[it.fi] << " " << dcy[it.se.fi] << " " << dcx[it.fi] << " " << dcy[it.se.se] << "\n";
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