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
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

void chemthan() {
    int num = 5;
    auto ispr = [&] (int k) {
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                return 0;
            }
        }
        return 1;
    };
    vi pr(num);
    FOR(i, 0, num) {
        pr[i] = INF - mrand() % (INF / 100);
        while (!ispr(pr[i])) pr[i]++;
    }
    vi base({2311, 1992});
    while (sz(base) < num) {
        base.pb(mrand() % 1234 + 111);
    }
    int n; cin >> n;
    string s; cin >> s;
    vector<vi> p(num);
    FOR(k, 0, num) {
        int t = 1;
        FOR(i, 0, n + 5) {
            p[k].pb(t);
            t = mult(t, base[k], pr[k]);
        }
    }
    vi f(n);
    FOR(i, 0, n) f[i] = s[i] - '0';
    FOR(i, 1, n) f[i] += f[i - 1];
    vi vals;
    FOR(i, 0, n) if (s[i] == '0') {
        vals.pb(i);
    }
    vector<vi> g(num, vi(n));
    FOR(k, 0, num) {
        FOR(i, 1, sz(vals)) {
            int x = f[vals[i]] - f[vals[i - 1]];
            x &= 1;
            g[k][i] = g[k][i - 1];
            addmod(g[k][i], mult(x, p[k][i - 1], pr[k]), pr[k]);
        }
    }
    auto calc = [&] (int k, int l, int r) {
        l = lower_bound(all(vals), l) - vals.begin();
        r = lower_bound(all(vals), r) - vals.begin();
        int res = g[k][r];
        submod(res, g[k][l], pr[k]);
        return mult(res, p[k][n - l], pr[k]);
    };
    auto ff = [&] (int l, int r) {
        return f[r] - (l ? f[l - 1] : 0);
    };
    auto find_next = [&] (int u) {
        int lo = u, hi = n - 1;
        while (lo < hi) {
            int mi = lo + hi >> 1;
            if (ff(u, mi) == mi - u + 1) {
                lo = mi + 1;
            }
            else {
                hi = mi;
            }
        }
        return lo + hi >> 1;
    };
    auto find_prev = [&] (int u) {
        int lo = 0, hi = u;
        while (lo < hi) {
            int mi = lo + hi + 1 >> 1;
            if (ff(mi, u) < u - mi + 1) {
                lo = mi;
            }
            else {
                hi = mi - 1;
            }
        }
        return lo + hi >> 1;
    };
    int q; cin >> q;
    while (q--) {
        int u, v, k; cin >> u >> v >> k; u--, v--;
        if (ff(u, u + k - 1) ^ ff(v, v + k - 1)) {
            cout << "No\n";
            continue;
        }
        if (ff(u, u + k - 1) == k) {
            cout << "Yes\n";
            continue;
        }
        int uu = u + k - 1;
        int vv = v + k - 1;
        int nu = find_next(u);
        int puu = find_prev(uu);
        int nv = find_next(v);
        int pvv = find_prev(vv);
        if (nu + u + nv + v & 1) {
            cout << "No\n";
            continue;
        }
        if (puu + uu + pvv + vv & 1) {
            cout << "No\n";
            continue;
        }
        int found = 0;
        FOR(i, 0, num) {
            if (calc(i, nu, puu) ^ calc(i, nv, pvv)) {
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
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