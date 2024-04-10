#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

const int maxn = 5000 + 5;
int n, a, b, c, d;
int f[maxn];
int p[maxn];
vi adj[maxn];
int size[maxn];
int g[maxn];
bitset<maxn> can[maxn];

int dfs(int u) {
    int res = f[u] ? u + 1 : 0;
    size[u] = !sz(adj[u]);
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        chkmax(res, dfs(v));
        size[u] += size[v];
    }
    return res;
}

void upd(bitset<maxn>& bt, vi vsz) {
    FOR(i, 0, sz(vsz)) {
        bt |= bt << vsz[i];
    }
}

void solve() {
    cin >> n >> a >> b >> c >> d; a--, b--, c--, d--;
    f[a] = f[b] = f[c] = f[d] = 1;
    map<int, int> hs; hs[a] = 0, hs[b] = 1, hs[c] = 2, hs[d] = 3;
    FOR(i, 1, n) {
        cin >> p[i], p[i]--;
        adj[p[i]].pb(i);
    }
    int leaves = 0;
    FOR(i, 0, n) leaves += !sz(adj[i]);
    if (leaves & 1) {
        cout << "NO\n";
        return;
    }
    vi vsz;
    FOR(i, 0, sz(adj[0])) {
        int u = adj[0][i];
        int r = dfs(u);
        if (!r) {
            vsz.pb(size[u]);
        }
        else {
            g[hs[r - 1]] = size[u];
        }
    }
    int ar[] = {a, b, c, d};
    FOR(i, 0, 4) {
        int u = ar[i];
        can[i][0] = 1;
        while (p[u]) {
            int v = p[u];
            vi vsz;
            FOR(j, 0, sz(adj[v])) {
                int w = adj[v][j];
                if (w != u) {
                    vsz.pb(size[w]);
                }
            }
            upd(can[i], vsz);
            u = v;
        }
    }
    bitset<maxn> exbt;
    exbt[0] = 1, upd(exbt, vsz);
    int tot = 0, dif = leaves / 2 - 1;
    FOR(i, 0, maxn) FOR(j, 0, maxn) {
        if (can[0][i] && can[1][j] && i + j + g[2] <= dif && exbt[dif - i - j - g[2]]) {
            tot++;
            i = maxn - 1;
            break;
        }
    }
    FOR(i, 0, maxn) FOR(j, 0, maxn) {
        if (can[2][i] && can[3][j] && i + j + g[0] <= dif && exbt[dif - i - j - g[0]]) {
            tot++;
            i = maxn - 1;
            break;
        }
    }
    if (tot == 2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}