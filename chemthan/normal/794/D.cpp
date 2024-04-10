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

const int maxn = 3e5 + 5;
int n, m;
vi adj[maxn];
vi adj2[maxn];
map<vi, int> hs;
int f[maxn];
int ans[maxn];

int query(vi& v) {
    if (hs.count(v)) return hs[v];
    int res = sz(hs);
    return hs[v] = res;
}

void solve() {
    cin >> n >> m;
    vii edge;
    FOR(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
        edge.pb(mp(u, v));
    }
    FOR(i, 0, n) adj[i].pb(i);
    FOR(i, 0, n) {
        sort(all(adj[i])), uni(adj[i]);
    }
    FOR(i, 0, n) {
        f[i] = query(adj[i]);
    }
    FOR(i, 0, m) {
        int u = edge[i].fi;
        int v = edge[i].se;
        u = f[u];
        v = f[v];
        if (u != v) {
            adj2[u].pb(v);
            adj2[v].pb(u);
        }
    }
    int sumdeg = 0;
    FOR(i, 0, sz(hs)) {
        sort(all(adj2[i])), uni(adj2[i]);
        sumdeg += sz(adj2[i]);
        if (sz(adj2[i]) > 2) {
            cout << "NO\n";
            return;
        }
    }
    if (sumdeg != 2 * (sz(hs) - 1)) {
        cout << "NO\n";
        return;
    }
    FOR(i, 0, sz(hs)) {
        if (sz(adj2[i]) <= 1) {
            int u = i, p = -1, cnt = 1;
            ans[i] = cnt++;
            while (1) {
                int found = 0;
                FOR(j, 0, sz(adj2[u])) {
                    int v = adj2[u][j];
                    if (v != p) {
                        ans[v] = cnt++;
                        p = u, u = v;
                        found = 1;
                        break;
                    }
                }
                if (!found) break;
            }
            break;
        }
    }
    cout << "YES\n";
    FOR(i, 0, n) cout << ans[f[i]] << " \n"[i == n - 1];
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