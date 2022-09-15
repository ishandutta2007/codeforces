#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

#define pos(v) ((v) << 1)
#define neg(v) (pos(v) ^ 1)
struct Twosat {
    static const int MAXV = 4e3 + 5;
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
            if (!(choose & 1)) res.push_back(choose >> 1);
        }
        return 1;
    }
} twosat;

const int maxn = 4e3 + 5;
int n;
string a[maxn];
string b[maxn];
int ans[maxn << 1];

string ff(int d, int k) {
    if (!k) {
        return a[d].substr(0, 3);
    }
    return a[d].substr(0, 2) + b[d].substr(0, 1);
}

void solve() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i] >> b[i];
    twosat.init(n << 1);
    FOR(i, 0, n) FOR(j, i + 1, n) {
        FOR(u, 0, 2) FOR(v, 0, 2) {
            if (ff(i, u) == ff(j, v)) {
                twosat.add(pos(i) ^ u, pos(j) ^ v ^ 1);
                twosat.add(pos(j) ^ v, pos(i) ^ u ^ 1);
            }
        }
        if (ff(i, 0) == ff(j, 0)) {
            twosat.add(neg(i), neg(j));
            twosat.add(neg(j), neg(i));
        }
    }
    vi res;
    if (!twosat.solve(res)) {
        cout << "NO\n";
        return;
    }
    fill_n(ans, n, 1);
    FOR(i, 0, sz(res)) ans[res[i]] = 0;
    cout << "YES\n";
    FOR(i, 0, n) {
        cout << ff(i, ans[i]) << "\n";
    }
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif
    solve();
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}