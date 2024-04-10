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
const ld EPS = 1e-15;
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

vector<tuple<long long, char, long long>> res;
inline void add(long long x, vector<long long>& v) {
    vector<tuple<long long, char, long long>> tmp;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] & -v[i] & x) {
            tmp.pb({x, '^', v[i]});
            x ^= v[i];
        }
    }
    if (!x) return;
    for (auto e : tmp) res.pb(e);
    for (int i = 0; i < v.size(); i++) {
        if (x & -x & v[i]) {
            res.pb({v[i], '^', x});
            v[i] ^= x;
        }
    }
    v.push_back(x);
}

void chemthan() {
    auto solve = [&] (int x) {
        res.pb({x, '^', x});
        vector<long long> basic;
        basic.pb(x);
        while (sz(basic) < 40) {
            FOR(i, 0, sz(basic)) FOR(j, i, sz(basic)) {
                auto x = basic[i] + basic[j];
                res.pb({basic[i], '+', basic[j]});
                if (x < (1LL << 40)) {
                    int t1 = sz(basic);
                    add(x, basic);
                    int t2 = sz(basic);
                    if (t1 < t2) {
                        i = j = INF;
                        break;
                    }
                }
                FOR(k, 0, sz(basic)) {
                    auto x = basic[i] ^ basic[j];
                    auto y = x + basic[k];
                    res.pb({basic[i], '^', basic[j]});
                    res.pb({x, '+', basic[k]});
                    if (y < (1LL << 40)) {
                        int t1 = sz(basic);
                        add(y, basic);
                        int t2 = sz(basic);
                        if (t1 < t2) {
                            i = j = INF;
                            break;
                        }
                    }
                }
            }
        }
        map<long long, int> hs;
        FOR(msk, 0, 1 << 20) {
            long long x = 0;
            FOR(i, 0, 20) if (bit(msk, i)) {
                x ^= basic[i];
            }
            hs[x] = msk;
        }
        FOR(msk, 0, 1 << 20) {
            long long x = 0;
            FOR(i, 0, 20) if (bit(msk, i)) {
                x ^= basic[i + 20];
            }
            if (hs.count(x ^ 1)) {
                auto msk2 = hs[x ^ 1];
                long long t = 0;
                FOR(i, 0, 20) if (bit(msk, i)) {
                    res.pb({t, '^', basic[i + 20]});
                    t ^= basic[i];
                }
                t = 0;
                FOR(i, 0, 20) if (bit(msk2, i)) {
                    res.pb({t, '^', basic[i]});
                    t ^= basic[i];
                }
                res.pb({x, '^', x ^ 1});
                uni(res);
                cout << sz(res) << "\n";
                for (auto [x, c, y] : res) {
                    cout << x << " " << c << " " << y << "\n";
                }
                return;
            }
        }
    };
    int x; cin >> x;
    solve(x);
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