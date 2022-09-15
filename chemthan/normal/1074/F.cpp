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

const int maxn = 2e5 + 5;
const int logn = 20;
int n, q;
vi adj[maxn];
int lev[maxn];
int par[logn][maxn];
int tin[maxn];
int tou[maxn];
int tms;

void dfs(int u, int p) {
    tin[u] = tms++;
    FOR(i, 1, logn) par[i][u] = par[i - 1][par[i - 1][u]];
    for (int v : adj[u]) {
        if (v != p) {
            par[0][v] = u;
            lev[v] = lev[u] + 1;
            dfs(v, u);
        }
    }
    tou[u] = tms - 1;
}

int isanc(int u, int v) {
    return tin[u] <= tin[v] && tou[u] >= tou[v];
}

int jump(int u, int k) {
    FORd(i, logn, 0) {
        if (k >= (1 << i)) {
            k -= 1 << i;
            u = par[i][u];
        }
    }
    return u;
}

int st[2][maxn << 2];
int lz[maxn << 2];

void build(int p, int L, int R) {
    if (L == R) {
        st[0][p] = 0, st[1][p] = 1;
        return;
    }
    build(p << 1, L, L + R >> 1);
    build(p << 1 | 1, (L + R >> 1) + 1, R);
    st[0][p] = st[0][p << 1], st[1][p] = st[1][p << 1];
    if (chkmax(st[0][p], st[0][p << 1 | 1])) {
        st[1][p] = st[1][p << 1 | 1];
    }
    else if (st[0][p] == st[0][p << 1 | 1]) {
        st[1][p] += st[1][p << 1 | 1];
    }
}
void push(int p, int L, int R) {
    if (lz[p]) {
        st[0][p] += lz[p];
        if (L < R) {
            FOR(i, 0, 2) lz[p << 1 | i] += lz[p];
        }
        lz[p] = 0;
    }
}
void upd(int p, int l, int r, int L, int R, int val) {
    push(p, L, R);
    if (R < l || r < L) return;
    if (l <= L && R <= r) {
        lz[p] += val;
        push(p, L, R);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1, val);
    upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    st[0][p] = st[0][p << 1], st[1][p] = st[1][p << 1];
    if (chkmax(st[0][p], st[0][p << 1 | 1])) {
        st[1][p] = st[1][p << 1 | 1];
    }
    else if (st[0][p] == st[0][p << 1 | 1]) {
        st[1][p] += st[1][p << 1 | 1];
    }
}

void chemthan() {
    cin >> n >> q;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v, u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, -1);
    map<pi, int> hs;
    build(1, 0, n - 1);
    int sum = 0;
    FOR(i, 0, q) {
        int u, v; cin >> u >> v, u--, v--;
        if (u > v) swap(u, v);
        int s = -1;
        if (!hs[mp(u, v)]) {
            s = 1;
        }
        hs[mp(u, v)] ^= 1;
        sum += s;
        if (isanc(v, u)) swap(u, v);
        if (isanc(u, v)) {
            int w = jump(v, lev[v] - lev[u] - 1);
            upd(1, tin[v], tou[v], 0, n - 1, s);
            upd(1, 0, tin[w] - 1, 0, n - 1, s);
            upd(1, tou[w] + 1, n - 1, 0, n - 1, s);
        }
        else {
            upd(1, tin[u], tou[u], 0, n - 1, s);
            upd(1, tin[v], tou[v], 0, n - 1, s);
        }
        if (st[0][1] < sum) {
            cout << 0 << "\n";
        }
        else {
            cout << st[1][1] << "\n";
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