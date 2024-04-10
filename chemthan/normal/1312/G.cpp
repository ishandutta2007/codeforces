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
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

template<class num_t> struct SegmentTree {
    int n;
    vector<num_t> st;
    vector<num_t> lz;
    void init(int n_) {
        n = n_;
        st.resize(n << 2, +INF);
        lz.resize(n << 2, +INF);
    }
    void pushdown(int p, int L, int R) {
        if (lz[p] != +INF) {
            chkmin(st[p], lz[p]);
            if (L < R) {
                chkmin(lz[p << 1], lz[p]);
                chkmin(lz[p << 1 | 1], lz[p]);
            }
            lz[p] = +INF;
        }
    }
    void upd(int p, int l, int r, int L, int R, num_t val) {
        pushdown(p, L, R);
        if (r < L || R < l) return;
        if (l <= L && R <= r) {
            lz[p] = val;
            pushdown(p, L, R);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        st[p] = min(st[p << 1], st[p << 1 | 1]);
    }
    num_t query(int p, int l, int r, int L, int R) {
        pushdown(p, L, R);
        if (r < L || R < l) return INF;
        if (l <= L && R <= r) return st[p];
        return min(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
    void upd(int l, int r, num_t val) {
        upd(1, l, r, 0, n - 1, val);
    }
    num_t query(int l, int r) {
        return query(1, l, r, 0, n - 1);
    }
};
SegmentTree<int> seg;

void chemthan() {
    int ptr = 0;
    vector<vi> nxt(1234567, vi(26));
    auto add = [&] (int rt, int c) {
        if (!nxt[rt][c]) {
            nxt[rt][c] = ++ptr;
        }
        return nxt[rt][c];
    };
    int n; cin >> n;
    vi f(n + 1);
    FOR(i, 1, n + 1) {
        int p; char c; cin >> p >> c;
        f[i] = add(f[p], c - 'a');
    }
    int k; cin >> k;
    vi a(k);
    vi b(n + 1);
    FOR(i, 0, k) cin >> a[i], b[f[a[i]]] = 1;
    vi tin(n + 1), tou(n + 1);
    int timer = 0;
    function<void(int)> dfs = [&] (int u) {
        timer += b[u];
        tin[u] = timer;
        FOR(i, 0, 26) if (nxt[u][i]) {
            dfs(nxt[u][i]);
        }
        tou[u] = timer;
    };
    dfs(0);
    seg.init(n + 1);
    vi dp(n + 1, INF);
    dp[0] = 0;
    function<void(int, int)> upd_dfs = [&] (int u, int p) {
        if (p != -1) {
            chkmin(dp[u], dp[p] + 1);
        }
        if (b[u]) {
            chkmin(dp[u], seg.query(tin[u], tin[u]) + tin[u]);
        }
        seg.upd(tin[u], tou[u], dp[u] - tin[u] + b[u]);
        FOR(i, 0, 26) if (nxt[u][i]) {
            upd_dfs(nxt[u][i], u);
        }
    };
    upd_dfs(0, -1);
    FOR(i, 0, k) {
        cout << dp[f[a[i]]] << " \n"[i == k - 1];
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