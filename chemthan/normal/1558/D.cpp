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
//const int MOD = (int) 1e9 + 7;
const int MOD = 119 << 23 | 1;
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void chemthan() {
    int C = 1e6 + 5;
    vi fac(C, 1);
    FOR(i, 1, C) fac[i] = mult(fac[i - 1], i);
    vi inv_fac(C);
    FOR(i, 0, C) inv_fac[i] = inv(fac[i]);
    auto binom = [&] (int n, int k) {
        return mult(fac[n], mult(inv_fac[k], inv_fac[n - k]));
    };
    ordered_set st;
    FOR(i, 0, 3e5) st.insert(i);
    vi fen(3e5);
    vi f(3e5);
    vi g(3e5);
    int test; cin >> test;
    while (test--) {
        int n, m; cin >> n >> m;
        vii v;
        FOR(i, 0, m) {
            int x, y; cin >> x >> y; x--, y--;
            v.pb({x, y});
        }
        auto upd = [&] (int p, int v) {
            p++;
            for (; p < sz(fen); p += p & -p) {
                fen[p] += v;
            }
        };
        auto query = [&] (int p) {
            p++;
            int res = 0;
            for (; 0 < p; p -= p & -p) {
                res += fen[p];
            }
            return res;
        };
        FORd(i, m, 0) {
            int x = v[i].fi;
            int y = v[i].se;
            f[x] = *st.find_by_order(y);
            st.erase(f[x]);
        }
        FOR(i, 0, m) {
            int x = v[i].fi;
            int y = v[i].se;
            st.insert(f[x]);
        }
        FOR(i, 0, m) {
            int x = v[i].fi;
            int y = v[i].se;
            st.erase(x);
        }
        vi dc;
        FOR(i, 0, m) {
            int x = v[i].fi;
            int y = v[i].se;
            dc.pb(f[x]);
        }
        sort(all(dc)), uni(dc);
        FOR(i, 0, m) {
            int x = v[i].fi;
            int y = v[i].se;
            g[x] = lower_bound(all(dc), f[x]) - dc.begin();
        }
        vi vv;
        set<pi> st2;
        FOR(i, 0, m) {
            int x = v[i].fi;
            int y = v[i].se;
            int num = query(f[x]);
            auto it = st2.upper_bound(mp(f[x], x));
            if (it != st2.end()) {
                int nx = it->se;
                if (f[nx] - g[nx] + query(f[nx] - 1) == y) {
                    vv.pb(nx);
                }
                else {
                    vv.pb(*st.find_by_order(y - num));
                }
            }
            else {
                vv.pb(*st.find_by_order(y - num));
            }
            upd(f[x], 1);
            st2.insert(mp(f[x], x));
        }
        FOR(i, 0, m) {
            int x = v[i].fi;
            int y = v[i].se;
            upd(f[x], -1);
        }
        FOR(i, 0, m) {
            int x = v[i].fi;
            int y = v[i].se;
            st.insert(x);
        }
        sort(all(vv)), uni(vv);
        int num = sz(vv);
        if (num <= n - 1) {
            cout << binom(n - num - 1 + n, n) << "\n";
        }
        else {
            cout << 0 << "\n";
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