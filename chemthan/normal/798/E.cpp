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

const int maxn = 5e5 + 5;
int n;
int a[maxn];
int b[maxn];
vi adj[maxn];
int ans[maxn];
int vis[maxn];
vi ver;

pi st[maxn << 1];
void upd(int p, int val) {
    int q = p;
    for (st[p += n] = mp(val, q); p > 1; ) p >>= 1, st[p] = max(st[p << 1], st[p << 1 | 1]);
}
pi query(int l, int r) {
    pi res = mp(-1, -1);
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) chkmax(res, st[l++]);
        if (r & 1) chkmax(res, st[--r]);
    }
    return res;
}

void dfs(int u) {
    vis[u] = 1;
    upd(u, -1);
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs(v);
        }
    }
    while (1) {
        if (a[u] == -1) a[u] = n;
        pi mx = query(0, a[u] - 1);
        if (mx.fi <= u) break;
        int v = mx.se;
        if (!vis[v]) {
            dfs(v);
        }
    }
    ver.pb(u);
}

void solve() {
    cin >> n;
    fill_n(b, n, n);
    FOR(i, 0, n) {
        cin >> a[i];
        if (a[i] > 0) {
            a[i]--;
            b[a[i]] = i;
            adj[a[i]].pb(i);
        }
    }
    FOR(i, 0, n) upd(i, b[i]);
    FOR(i, 0, n) if (!vis[i]) dfs(i);
    FOR(i, 0, sz(ver)) ans[ver[i]] = i;
    FOR(i, 0, n) cout << ans[i] + 1 << " \n"[i == n - 1];
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