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

void chemthan() {
    int test; cin >> test;
    while (test--) {
        int n, m; cin >> n >> m;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        sort(all(a));
        auto dc = a;
        vii seg;
        FOR(i, 0, m) {
            int l, r; cin >> l >> r;
            int k = lower_bound(all(a), l) - a.begin();
            if (k == n || r < a[k]) {
                seg.pb({l, r});
                dc.pb(l), dc.pb(r);
            }
        }
        sort(all(seg));
        m = sz(seg);
        sort(all(dc)), uni(dc);
        vector<long long> dp(sz(dc), LINF);
        vector<long long> dp2(sz(dc), LINF);
        vector<long long> dp3(sz(dc), LINF);
        vector<long long> dp1(sz(dc), LINF);
        long long res = LINF;
        int ptr = 0;
        FOR(i, 0, n) {
            int ix = lower_bound(all(dc), a[i]) - dc.begin();
            if (i) {
                while (ptr < m && seg[ptr].se < a[i - 1]) ptr++;
            }
            vii tmp;
            while (ptr < m && seg[ptr].se < a[i]) {
                tmp.pb(seg[ptr]);
                ptr++;
            }
            long long cost1 = LINF;
            long long cost2 = LINF;
            if (!i) {
                if (sz(tmp)) {
                    sort(all(tmp), [&] (pi a, pi b) {
                            return a.se < b.se;
                            }
                        );
                    int t = tmp[0].se;
                    int k = lower_bound(all(dc), t) - dc.begin();
                    dp1[k] = a[i] - t;
                    dp2[k] = (long long) a[i] - t - t;
                    chkmin(dp[ix], dp1[k]);
                    chkmin(cost1, dp1[k]);
                    chkmin(cost2, dp2[k]);
                }
                else {
                    int k = lower_bound(all(dc), a[i]) - dc.begin();
                    dp1[k] = 0;
                    dp2[k] = -a[i];
                    chkmin(dp[ix], dp1[k]);
                    chkmin(cost1, dp1[k]);
                    chkmin(cost2, dp2[k]);
                }
            }
            else {
                sort(all(tmp), [&] (pi a, pi b) {
                        return a.se < b.se;
                        }
                    );
                int p = lower_bound(all(dc), a[i - 1]) - dc.begin();
                long long cost = dp[p];
                int mx = -INF;
                for (auto [l, r] : tmp) {
                    int k = lower_bound(all(dc), r) - dc.begin();
                    chkmin(dp1[k], cost + a[i] - r);
                    chkmin(dp2[k], cost + a[i] - r - r);
                    chkmax(mx, l);
                    int h = lower_bound(all(dc), mx) - dc.begin();
                    cost = dp3[h];
                    chkmin(cost1, dp1[k]);
                    chkmin(cost2, dp2[k]);
                    chkmin(dp[ix], dp1[k]);
                }
                chkmin(dp[ix], cost);
                chkmin(dp1[ix], cost);
                chkmin(dp2[ix], cost - a[i]);
                chkmin(cost1, dp1[ix]);
                chkmin(cost2, dp2[ix]);
            }
            vii tmp2;
            int ptr2 = ptr;
            while (ptr2 < m && (i == n - 1 || seg[ptr2].se < a[i + 1])) {
                tmp2.pb(seg[ptr2]);
                ptr2++;
            }
            sort(all(tmp2));
            res = cost1;
            for (auto [l, r] : tmp2) {
                int k = lower_bound(all(dc), l) - dc.begin();
                chkmin(dp3[k], cost1 + 2LL * (l - a[i]));
                chkmin(dp3[k], cost2 + l);
                res = dp3[k];
            }
        }
        cout << res << "\n";
    }
}

int32_t main(int32_t argc, char* argv[]) {
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