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
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;} inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

void chemthan() {
    auto ispr = [&] (int k) {
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                return 0;
            }
        }
        return 1;
    };
    int K = 1;
    vi prs;
    vi bases;
    FOR(it, 0, K) {
        int pr = INF - mrand(INF / 10);
        while (!ispr(pr)) pr++;
        prs.pb(pr);
        int base = 2311 + mrand(1992);
        bases.pb(base);
    }
    int n = 1e6 + 5;
    vector<vi> pp(K, vi(n, 1));
    vector<vi> ip(K, vi(n, 1));
    FOR(i, 0, K) {
        auto& pr = prs[i];
        auto& base = bases[i];
        int ibase = inv(base, pr);
        FOR(j, 1, n) {
            pp[i][j] = mult(pp[i][j - 1], base, pr);
            ip[i][j] = mult(ip[i][j - 1], ibase, pr);
        }
    }
    int test; cin >> test;
    while (test--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        reverse(all(s));
        for (char& c : s) {
            if (c == '0') {
                c = '1';
            }
            else {
                c = '0';
            }
        }
        vector<vi> f(K, vi(n));
        FOR(i, 0, K) {
            auto& pr = prs[i];
            int t = 0;
            FOR(j, 0, n) {
                addmod(t, mult(pp[i][j], s[j] - '0', pr), pr);
                f[i][j] = t;
            }
        }
        auto calc = [&] (int i, int l, int r) {
            auto& pr = prs[i];
            int res = f[i][r];
            if (l) submod(res, f[i][l - 1], pr);
            return mult(res, ip[i][l], pr);
        };
        vector<vi> vals;
        FOR(i, 0, n - k + 1) {
            vi v;
            FOR(j, 0, K) {
                v.pb(calc(j, i, i + k - 1));
            }
            vals.pb(v);
        }
        sort(all(vals)), uni(vals);
        auto find = [&] (vi& v) {
            int k = lower_bound(all(vals), v) - vals.begin();
            return k < sz(vals) && vals[k] == v;
        };
        static vi dp[1 << 20][21];
        auto ff = [&] (int msk, int k) {
            auto& res = dp[msk][k];
            if (sz(res)) return res;
            FOR(i, 0, K) {
                auto& pr = prs[i];
                int t = 0;
                FOR(j, 0, k) {
                    addmod(t, mult(bit(msk, j), pp[i][j], pr), pr);
                }
                res.pb(t);
            }
            return res;
        };
        string res;
        int d = min(20, __lg(n) + 1);
        FOR(msk, 0, 1 << d) {
            auto v = ff(msk, d);
            if (!find(v)) {
                string tmp;
                FORd(i, d, 0) {
                    tmp += char('0' + bit(msk, i));
                }
                reverse(all(tmp));
                while (sz(tmp) && tmp.back() == '0') tmp.pop_back();
                while (sz(tmp) < k) tmp.pb('0');
                reverse(all(tmp));
                if (sz(tmp) == k) {
                    res = tmp;
                    break;
                }
            }
        }
        if (!sz(res)) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            cout << res << "\n";
        }
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