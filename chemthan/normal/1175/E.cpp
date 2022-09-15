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
    int n, m; cin >> n >> m;
    vii vals(n);
    FOR(i, 0, n) cin >> vals[i].fi >> vals[i].se;
    vii fen(5e5 + 5, mp(-1, n));
    auto upd = [&] (int p, pi val) {
        p++;
        for (; p < sz(fen); p += p & -p) {
            chkmax(fen[p], val);
        }
    };
    auto query = [&] (int p) {
        p++;
        pi res = mp(-1, n);
        for (; 0 < p; p -= p & -p) {
            chkmax(res, fen[p]);
        }
        return res;
    };
    vector<vi> nxt(20, vi(n + 1, n));
    sort(all(vals));
    FORd(i, n, 0) {
        nxt[0][i] = query(vals[i].se).se;
        if (nxt[0][i] < n && vals[nxt[0][i]].se <= vals[i].se) {
            nxt[0][i] = n;
        }
        upd(vals[i].fi, mp(vals[i].se, i));
    }
    FOR(i, 1, 20) {
        FOR(u, 0, n) {
            nxt[i][u] = nxt[i - 1][nxt[i - 1][u]];
        }
    }
    vector<tuple<int, int, int>> que;
    FOR(i, 0, m) {
        int l, r; cin >> l >> r;
        que.pb(make_tuple(l, r, i));
    }
    sort(all(que));
    vi res(m);
    int ptr = 0;
    pi mx = mp(-1, n);
    FOR(i, 0, m) {
        while (ptr < n && vals[ptr].fi <= get<0>(que[i])) {
            chkmax(mx, mp(vals[ptr].se, ptr));
            ptr++;
        }
        int nx = mx.se;
        if (nx == n || mx.fi < get<0>(que[i])) {
            res[get<2>(que[i])] = -1;
        }
        else {
            int tmp = 1;
            FORd(j, 20, 0) {
                if (nxt[j][nx] < n && vals[nxt[j][nx]].se < get<1>(que[i])) {
                    tmp += 1 << j;
                    nx = nxt[j][nx];
                }
            }
            if (get<1>(que[i]) <= vals[nx].se) {
            }
            else if (nxt[0][nx] < n && get<1>(que[i]) <= vals[nxt[0][nx]].se) {
                tmp++;
            }
            else {
                tmp = -1;
            }
            res[get<2>(que[i])] = tmp;
        }
    }
    FOR(i, 0, m) cout << res[i] << "\n";
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