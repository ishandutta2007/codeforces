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

const int maxn = 1e5 + 5;
int n, m;
int a[maxn];
int b[maxn];
vi adj[maxn];

int ix;
int compare(int x, int y) {
    if (x > ix && y < ix) return 0;
    if (x < ix && y > ix) return 1;
    return x > y;
}
struct RegionTree {
    static const int maxn = 1e5 + 5;
    int n, cnt;
    vector<int> adj[maxn];
    vector<int> tree[maxn];
    
    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            tree[i].clear();
        }
    }
    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void build() {
        static map<pair<int, int>, int> hs;
        static vector<pair<int, int> > g[maxn];
        hs.clear();
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        cnt = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            ix = i;
            sort(adj[i].begin(), adj[i].end(), compare);
        }
        for (int u = n - 1; u >= 0; u--) {
            for (int i = 1; i < (int) adj[u].size(); i++) {
                int v = adj[u][i];
                int w = adj[u][i - 1];
                if (!hs.count(make_pair(u, v))) {
                    hs[make_pair(u, v)] = cnt;
                    g[cnt].push_back(make_pair(u, v));
                    cnt++;
                }
                int ix = hs[make_pair(u, v)];
                if (!hs.count(make_pair(w, u))) {
                    g[ix].push_back(make_pair(w, u));
                }
                hs[make_pair(w, u)] = ix;
            }
        }
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < (int) g[i].size(); j++) {
                pair<int, int> p = g[i][j];
                swap(p.first, p.second);
                if (hs.count(p)) {
                    tree[i].push_back(hs[p]);
                }
            }
        }
    }
} rt;

int ans[maxn];
int dfs(int u, int p = -1) {
    int res = 0;
    int cnt[30] = {}, mx = 0;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (v != p) {
            int r = dfs(v, u);
            res |= r;
            FOR(j, 0, 30) {
                if (bit(r, j)) {
                    cnt[j]++;
                }
                if (cnt[j] > 1) chkmax(mx, j + 1);
            }
        }
    }
    FOR(i, mx, 30) if (!bit(res, i)) {
        FOR(j, 0, i) res |= 1 << j, res ^= 1 << j;
        res |= 1 << i;
        ans[u] = i;
        break;
    }
    return res;
}

void solve() {
    cin >> n >> m;
    rt.init(n);
    FOR(i, 0, m) {
        cin >> a[i] >> b[i]; a[i]--, b[i]--;
        rt.add(a[i], b[i]);
    }
    rt.build();
    int cnt = rt.cnt;
    for (int i = 0; i < cnt; i++) {
        adj[i] = rt.tree[i];
    }
    dfs(0);
    int mx = 0;
    FOR(i, 0, cnt) chkmax(mx, ans[i]);
    FOR(i, 0, cnt) {
        cout << mx - ans[cnt - i - 1] + 1 << " \n"[i == cnt - 1];
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