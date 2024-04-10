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
const int FFTMOD = 1007681537;
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
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

#define pos(v) ((v) << 1)
#define neg(v) (pos(v) ^ 1)
struct Twosat {
    static const int MAXV = 1e6 + 5;
    int n;
    vector<int> forward[MAXV], backward[MAXV];
    bool used[MAXV];
    int cnt, order[MAXV], comp[MAXV];
    void init(int _n) {
        n = _n;
        for (int i = 0; i < n; i++) {
            forward[i].clear();
            backward[i].clear();
        }
    }
    void add(int u, int v) {
        forward[u].push_back(v);
        backward[v].push_back(u);
    }
    void dfs1(int u) {
        used[u] = true;
        for (int i = 0; i < forward[u].size(); i++) {
            int v = forward[u][i];
            if (!used[v]) dfs1(v);
        }
        order[cnt++] = u;
    }
    void dfs2(int u, int c) {
        comp[u] = c;
        for (int i = 0; i < backward[u].size(); i++) {
            int v = backward[u][i];
            if (comp[v] == -1) dfs2(v, c);
        }
    }
    int solve(vector<int>& res) {
        cnt = 0;
        memset(used, 0, sizeof(used));
        for (int u = 0; u < n; u++) if (!used[u]) dfs1(u);
        memset(comp, -1, sizeof(comp));
        int c = 0;
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            if (comp[u] == -1) dfs2(u, c++);
        }
        for (int u = 0; u < n; u += 2)
            if (comp[u] == comp[u ^ 1]) return 0;
        res.clear();
        for (int u = 0; u < n; u += 2) {
            int choose = (comp[u] > comp[u ^ 1]) ? u : u ^ 1;
            if (choose & 1) res.push_back(choose >> 1);
        }
        return 1;
    }
} twosat;

const int maxn = 1e6 + 5;
int n, m;
int f[maxn];
vi g[maxn];

void solve() {
    cin >> n >> m;
    FOR(i, 0, n) {
        int k; cin >> k;
        g[i].resize(k);
        FOR(j, 0, k)  cin >> g[i][j], g[i][j]--;
    }
    twosat.init(m + m);
    FOR(i, 0, n - 1) {
        int k = min(sz(g[i]), sz(g[i + 1]));
        int found = -1;
        FOR(j, 0, k) {
            if (g[i][j] != g[i + 1][j]) {
                found = j;
                break;
            }
        }
        if (~found) {
            int u = found;
            int c = g[i][u];
            int d = g[i + 1][u];
            if (c > d) {
                twosat.add(pos(c), neg(c));
                twosat.add(neg(d), pos(d));
            }
            else {
                twosat.add(pos(c), pos(d));
                twosat.add(neg(d), neg(c));
            }
        }
        else {
            if (sz(g[i]) > sz(g[i + 1])) {
                cout << "No\n";
                return;
            }
        }
    }
    vi res;
    if (!twosat.solve(res)) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    cout << sz(res) << "\n";
    FOR(i, 0, sz(res)) cout << res[i] + 1 << " \n"[i == sz(res) - 1];
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int JUDGE_ONLINE = 1;
    if (argc > 1) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[2], "w", stdout));
    }
    solve();
    if (!JUDGE_ONLINE) {
        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}