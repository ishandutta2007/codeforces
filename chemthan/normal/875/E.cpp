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

template<class T, class cmp = less<T> > struct RMQ {
    int n;
    vector<T> a;
    vector<vector<T> > f;
    
    T best(T a, T b) {
        if (cmp()(a, b)) return a;
        return b;
    }
    void init(int n) {
        this->n = n;
        int p = 1; while ((1 << p) < n) p++;
        a.resize(n), f.resize(p + 1);
        for (int i = 0; i < (int) f.size(); i++) {
            f[i].resize(n);
        }
    }
    void upd(int u, T x) {
        a[u] = x;
    }
    void build() {
        for (int i = 0; i < n; i++) f[0][i] = a[i];
        for (int l = 0, k; (k = 1 << l) < n; l++) {
            for (int i = 0; i + k < n; i++) {
                f[l + 1][i] = best(f[l][i], f[l][i + k]);
            }
        }
    }
    T query(int a, int b) {
        int l = a == b ? 0 : __lg(b - a);
        return best(f[l][a], f[l][b - (1 << l) + 1]);
    }
};
RMQ<int> rmq1;
RMQ<int, greater<int> > rmq2;

const int maxn = 2e5 + 5;
int n, s, t;
int a[maxn];
int st[maxn << 1];

void upd(int p, int val) {
    for (st[p += maxn] = val; p > 1; ) p >>= 1, st[p] = st[p << 1] | st[p << 1 | 1];
}
int query(int l, int r) {
    int res = 0;
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res |= st[l++];
        if (r & 1) res |= st[--r];
    }
    return res;
}

int ff(int s, int t, int mi) {
    vi vals;
    vals.pb(s), vals.pb(t);
    FOR(i, 0, n) vals.pb(a[i]);
    rmq1.init(n + 2);
    rmq2.init(n + 2);
    FOR(i, 0, n + 2) {
        rmq1.upd(i, vals[i]);
        rmq2.upd(i, vals[i]);
    }
    rmq1.build();
    rmq2.build();
    fill_n(st, maxn << 1, 0);
    static int dp[maxn];
    dp[n + 1] = 1;
    FORd(i, n + 1, 0) {
        upd(i + 1, dp[i + 1]);
        int l = i, r = n + 1;
        while (l < r) {
            int m = l + r + 1 >> 1;
            int x = rmq1.query(i, m);
            int y = rmq2.query(i, m);
            if (abs(vals[i]- x) <= mi && abs(vals[i] - y) <= mi) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        int m = l + r >> 1;
        dp[i] = query(i, m);
    }
    return dp[0];
}

void solve() {
    cin >> n >> s >> t;
    FOR(i, 0, n) cin >> a[i];
    int lo = abs(s - t), hi = INF;
    while (lo < hi) {
        int mi = lo + hi >> 1;
        if (!ff(s, t, mi) && !ff(t, s, mi)) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }
    cout << (lo + hi >> 1) << "\n";
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