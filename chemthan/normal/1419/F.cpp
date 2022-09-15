#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int int64_t

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
    vii pts(n);
    vi dc;
    map<int, vii> gxx;
    map<int, vii> gyy;
    FOR(i, 0, n) {
        cin >> pts[i].fi >> pts[i].se;
        dc.pb(pts[i].fi);
        dc.pb(pts[i].se);
        gxx[pts[i].fi].pb({pts[i].se, i});
        gyy[pts[i].se].pb({pts[i].fi, i});
    }
    vii vv;
    FOR(i, 0, n) FOR(j, 0, n) {
        vv.pb({pts[i].fi, pts[j].se});
    }
    for (auto [x, g] : gxx) {
        sort(all(g));
        FOR(j, 1, sz(g)) {
            int u = g[j - 1].fi;
            int v = g[j].fi;
            int d = (u + v) / 2 - 5;
            while (d + d < u + v) d++;
            vv.pb({x, d});
        }
    }
    for (auto [y, g] : gyy) {
        sort(all(g));
        FOR(j, 1, sz(g)) {
            int u = g[j - 1].fi;
            int v = g[j].fi;
            int d = (u + v) / 2 - 5;
            while (d + d < u + v) d++;
            vv.pb({d, y});
        }
    }
    sort(all(vv)), uni(vv);
    for (auto e : vv) {
        dc.pb(e.fi);
        dc.pb(e.se);
    }
    sort(all(dc)), uni(dc);
    int d = sz(dc);
    vector<vii> adj(n);
    FOR(i, 0, n) {
        FOR(j, 0, n) if (i != j) {
            if (pts[i].fi == pts[j].fi) {
                adj[i].pb({abs(pts[i].se - pts[j].se), j});
            }
            if (pts[i].se == pts[j].se) {
                adj[i].pb({abs(pts[i].fi - pts[j].fi), j});
            }
        }
        sort(all(adj[i]));
    }
    vector<vii> gx(d);
    vector<vii> gy(d);
    FOR(i, 0, n) {
        int x = pts[i].fi, y = pts[i].se;
        x = lower_bound(all(dc), x) - dc.begin();
        y = lower_bound(all(dc), y) - dc.begin();
        assert(dc[x] == pts[i].fi);
        assert(dc[y] == pts[i].se);
        gx[x].pb({pts[i].se, i});
        gy[y].pb({pts[i].fi, i});
    }
    FOR(i, 0, d) {
        sort(all(gx[i]));
        sort(all(gy[i]));
    }
    int k = sz(vv);
    vector<vii> adj2(k);
    FOR(i, 0, k) {
        int x = vv[i].fi, y = vv[i].se;
        x = lower_bound(all(dc), x) - dc.begin();
        y = lower_bound(all(dc), y) - dc.begin();
        assert(dc[x] == vv[i].fi);
        assert(dc[y] == vv[i].se);
        {
            int t = lower_bound(all(gx[x]), mp(vv[i].se, -INF)) - gx[x].begin();
            if (t < sz(gx[x])) {
                adj2[i].pb({abs(vv[i].se - gx[x][t].fi), gx[x][t].se});
            }
            if (t) {
                t--;
                adj2[i].pb({abs(vv[i].se - gx[x][t].fi), gx[x][t].se});
            }
        }
        {
            int t = lower_bound(all(gy[y]), mp(vv[i].fi, -INF)) - gy[y].begin();
            if (t < sz(gy[y])) {
                adj2[i].pb({abs(vv[i].fi - gy[y][t].fi), gy[y][t].se});
            }
            if (t) {
                t--;
                adj2[i].pb({abs(vv[i].fi - gy[y][t].fi), gy[y][t].se});
            }
        }
    }
    vi vals;
    FOR(i, 0, n) {
        for (auto e : adj[i]) {
            vals.pb(e.fi);
        }
    }
    FOR(i, 0, k) {
        for (auto e : adj2[i]) {
            vals.pb(e.fi);
        }
    }
    sort(all(vals)), uni(vals);
    vi lo(k, 0);
    vi hi(k, sz(vals));
    vi mi(k);
    vector<tuple<int, int, int>> edges;
    FOR(i, 0, n) {
        for (auto [w, j] : adj[i]) {
            if (i < j) {
                edges.pb({w, i, j});
            }
        }
    }
    sort(all(edges));
    while (1) {
        int found = 0;
        vector<vi> g(sz(vals));
        FOR(i, 0, k) {
            if (lo[i] < hi[i]) {
                mi[i] = lo[i] + hi[i] >> 1;
                g[mi[i]].pb(i);
                found = 1;
            }
        }
        vi dj(n);
        FOR(u, 0, n) dj[u] = u;
        function<int(int)> find = [&] (int u) {
            return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
        };
        int ptr = 0;
        int num = n;
        FOR(i, 0, sz(vals)) {
            while (ptr < sz(edges) && get<0>(edges[ptr]) <= vals[i]) {
                int w, u, v; tie(w, u, v) = edges[ptr];
                u = find(u), v = find(v);
                if (u != v) {
                    dj[u] = v;
                    num--;
                }
                ptr++;
            }
            for (auto u : g[i]) {
                static int tmp[123456];
                int cc = 0;
                for (auto [w, j] : adj2[u]) {
                    if (w <= vals[i]) {
                        tmp[cc++] = find(j);
                    }
                }
                sort(tmp, tmp + cc);
                if (unique(tmp, tmp + cc) - tmp < num) {
                    lo[u] = mi[u] + 1;
                }
                else {
                    hi[u] = mi[u];
                }
            }
        }
        if (!found) {
            break;
        }
    }
    int res = INF + INF;
    FOR(i, 0, k) if (lo[i] < sz(vals)) {
        chkmin(res, vals[lo[i]]);
    }
    if (res == INF + INF) res = -1;
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