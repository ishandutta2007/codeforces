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

const int maxn = 5e5 + 5;
int n, q;
vii adj[maxn];
int v[maxn];
int l[maxn];
int r[maxn];
long long d[maxn];
int tin[maxn];
int tou[maxn];
int tms;

vi ver;
void dfs(int u, int p) {
    ver.pb(u);
    tin[u] = tms++;
    for (pi e : adj[u]) {
        int v = e.fi;
        int w = e.se;
        if (v != p) {
            d[v] = d[u] + w;
            dfs(v, u);
            ver.pb(u);
        }
    }
    tou[u] = tms - 1;
}

int isanc(int u, int v) {
    return tin[u] <= tin[v] && tou[v] <= tou[u];
}

long long st[maxn << 2];
long long lz[maxn << 2];
void push(int p, int L, int R) {
    if (lz[p]) {
        st[p] += lz[p];
        if (L < R) {
            FOR(i, 0, 2) {
                lz[p << 1 | i] += lz[p];
            }
        }
        lz[p] = 0;
    }
}
void upd(int p, int l, int r, int L, int R, long long val) {
    push(p, L, R);
    if (R < l || r < L) return;
    if (l <= L && R <= r) {
        lz[p] = val;
        push(p, L, R);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1, val);
    upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[p] = min(st[p << 1], st[p << 1 | 1]);
}
long long query(int p, int l, int r, int L, int R) {
    push(p, L, R);
    if (R < l || r < L) return LINF;
    if (l <= L && R <= r) return st[p];
    return min(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

void chemthan() {
    cin >> n >> q;
    FOR(i, 1, n) {
        int p, w; cin >> p >> w; p--;
        adj[p].pb(mp(i, w));
        adj[i].pb(mp(p, w));
    }
    FOR(u, 0, n) sort(all(adj[u]));
    dfs(0, -1);
    static vi que[maxn];
    FOR(i, 0, q) {
        cin >> v[i] >> l[i] >> r[i]; v[i]--, l[i]--, r[i]--;
        que[v[i]].pb(i);
    }
    FOR(u, 0, n) {
        if (u && sz(adj[u]) == 1) {
            upd(1, u, u, 0, n - 1, d[u]);
        }
        else {
            upd(1, u, u, 0, n - 1, LINF);
        }
    }
    static long long res[maxn];
    FOR(i, 0, sz(ver)) {
        int u = ver[i];
        if (i) {
            int v = ver[i - 1];
            if (isanc(u, v)) {
                upd(1, tin[v], tou[v], 0, n - 1, 2 * (d[v] - d[u]));
            }
            else {
                upd(1, tin[u], tou[u], 0, n - 1, 2 * (d[v] - d[u]));
            }
        }
        while (sz(que[u])) {
            int ix = que[u].back();
            que[u].pop_back();
            res[ix] = query(1, l[ix], r[ix], 0, n - 1) + d[v[ix]];
        }
    }
    FOR(i, 0, q) {
        cout << res[i] << "\n";
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