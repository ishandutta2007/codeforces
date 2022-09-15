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
const int MOD2 = 1007681537;
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

struct Node {
    long long mx[2];
    long long res;
    Node() {
        mx[0] = mx[1] = res = -LINF;
    }
    Node(const Node& rhs) {
        FOR(i, 0, 2) mx[i] = rhs.mx[i];
        res = rhs.res;
    }
} nil;

Node join(Node a, Node b) {
    if (a.res == nil.res) return b;
    if (b.res == nil.res) return a;
    Node res;
    FOR(i, 0, 2) res.mx[i] = max(a.mx[i], b.mx[i]);
    res.res = max(a.res, b.res);
    chkmax(res.res, a.mx[0] + b.mx[1]);
    return res;
}

const int maxn = 1e6 + 5;
int n;
vii adj[maxn];
int vis[maxn];
int p[maxn];
int pw[maxn];
int ver = -1;
long long mx[maxn];
long long localmx[maxn];
long long ps[maxn];
Node st[maxn << 2];

void dfs(int u, int dad) {
    if (~ver) return;
    vis[u] = 1;
    FOR(i, 0, sz(adj[u])) {
        if (~ver) return;
        int v = adj[u][i].fi;
        int w = adj[u][i].se;
        if (!vis[v]) {
            p[v] = u;
            pw[v] = w;
            dfs(v, u);
        }
        else if (v != dad) {
            if (!~ver) {
                p[v] = u;
                pw[v] = w;
                ver = u;
                return;
            }
        }
    }
}

long long calc(int u, int pu) {
    vis[u] = 1;
    long long res = 0;
    vector<long long> heap;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        int w = adj[u][i].se;
        if (!vis[v]) {
            long long r = calc(v, pu);
            heap.pb(r + w);
            chkmax(res, w + r);
        }
    }
    sort(all(heap), greater<long long>());
    if (sz(heap) > 1) {
        chkmax(localmx[pu], heap[0] + heap[1]);
    }
    return res;
}

void upd(int p, int i, int L, int R, Node x) {
    if (i < L || i > R) return;
    if (L == R) {
        st[p] = x;
        return;
    }
    upd(p << 1, i, L, L + R >> 1, x);
    upd(p << 1 | 1, i, (L + R >> 1) + 1, R, x);
    st[p] = join(st[p << 1], st[p << 1 | 1]);
}
Node query(int p, int l, int r, int L, int R) {
    if (l > R || r < L) return nil;
    if (l <= L && r >= R)  return st[p];
    return join(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

void solve() {
    nil.res = -LINF;
    cin >> n;
    FOR(i, 0, n) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    dfs(0, -1);
    fill_n(vis, n, 0);
    vi circle; circle.pb(ver), vis[ver] = 1;
    int ptr = p[ver];
    while (ptr != ver) {
        circle.pb(ptr), vis[ptr] = 1;
        ptr = p[ptr];
    }
    int k = sz(circle);
    int kk = k + k;
    long long tmp = 0;
    FOR(i, 0, k) {
        int u = circle[i];
        mx[i] = calc(u, u);
        chkmax(tmp, localmx[u]);
    }
    long long cur = 0;
    FOR(i, 0, kk) {
        ps[i] = cur;
        Node x; x.mx[0] = mx[i % k] - ps[i], x.mx[1] = mx[i % k] + ps[i], x.res = mx[i % k];
        upd(1, i, 0, kk - 1, x);
        cur += pw[circle[i % k]];
    }
    long long res = LINF;
    FOR(i, 0, k) {
        chkmin(res, max(tmp, query(1, i, i + k - 1, 0, kk - 1).res));
    }
    cout << res << "\n";
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