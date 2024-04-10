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
RMQ<pi, greater<pi> > rmq;

const int maxn = 3000 + 5;
int n;
pi a[maxn];
int ans[maxn];

void solve() {
    cin >> n;
    FOR(i, 1, n + 1) cin >> a[i].fi, a[i].se = i;
    rmq.init(n + 1);
    sort(a + 1, a + n + 1);
    FOR(i, 1, n + 1) {
        rmq.upd(i, mp(a[i].fi - a[i - 1].fi, i));
    }
    rmq.build();
    pair<pi, int> best, pos;
    FOR(i, 1, n + 1) FOR(j, i + 1, n + 1) {
        int u = a[j].fi - a[j - 1].fi;
        int v = a[i].fi - a[i - 1].fi;
        int x = n - j + 1;
        int y = j - i;
        if (x > y) swap(x, y);
        if (x + x < y) continue;
        int lo = max(1, i - x - x);
        int hi = i - (y + 1) / 2;
        if (lo <= hi) {
            pi w = rmq.query(lo, hi);
            if (chkmax(best, mp(mp(u, v), w.fi))) {
                pos = mp(mp(j, i), w.se);
            }
        }
    }
    int u = pos.fi.fi;
    int v = pos.fi.se;
    int w = pos.se;
    FOR(i, 1, w) {
        ans[a[i].se] = -1;
    }
    FOR(i, w, v) {
        ans[a[i].se] = 3;
    }
    FOR(i, v, u) {
        ans[a[i].se] = 2;
    }
    FOR(i, u, n + 1) {
        ans[a[i].se] = 1;
    }
    FOR(i, 1, n + 1) cout << ans[i] << " \n"[i == n];
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