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

struct SegTree {
    static const int maxn = 2e5 + 5;
    int sz[maxn << 2];
    int st[maxn << 2];
    int lz[maxn << 2];
    
    void push(int p, int L, int R) {
        if (lz[p]) {
            st[p] = sz[p] - st[p];
            if (L < R) {
                lz[p << 1] ^= 1;
                lz[p << 1 | 1] ^= 1;
            }
            lz[p] = 0;
        }
    }
    
    void pull(int p) {
        sz[p] = sz[p << 1] + sz[p << 1 | 1];
        st[p] = st[p << 1] + st[p << 1 | 1];
    }
    
    void build(int p, int L, int R) {
        if (L == R) {
            sz[p] = 1;
            return;
        }
        build(p << 1, L, L + R >> 1);
        build(p << 1 | 1, (L + R >> 1) + 1, R);
        pull(p);
    }
    
    void upd(int p, int l, int r, int L, int R, int val) {
        push(p, L, R);
        if (l > R || r < L) return;
        if (l <= L && r >= R) {
            lz[p] ^= val;
            push(p, L, R);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        pull(p);
    }
    int query(int p, int l, int r, int L, int R) {
        push(p, L, R);
        if (l > R || r < L) return 0;
        if (l <= L && r >= R) return st[p];
        return query(p << 1, l, r, L, L + R >> 1) + query(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
    }
} seg;

const int maxn = 2e5 + 5;
int n, q;
vi adj[maxn];
int tin[maxn];
int tou[maxn];
int tms;

void dfs(int u, int p) {
    tin[u] = tms++;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (v != p) {
            dfs(v, u);
        }
    }
    tou[u] = tms - 1;
}

void solve() {
    cin >> n;
    FOR(i, 1, n) {
        int p; cin >> p; p--;
        adj[p].pb(i);
    }
    dfs(0, -1);
    seg.build(1, 0, n - 1);
    FOR(i, 0, n) {
        int x; cin >> x;
        if (x) {
            seg.upd(1, tin[i], tin[i], 0, n - 1, 1);
        }
    }
    cin >> q;
    while (q--) {
        string op; cin >> op;
        if (op == "get") {
            int u; cin >> u; u--;
            cout << seg.query(1, tin[u], tou[u], 0, n - 1) << "\n";
        }
        else {
            int u; cin >> u; u--;
            seg.upd(1, tin[u], tou[u], 0, n - 1, 1);
        }
    }
    
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