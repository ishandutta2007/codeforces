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

string toString(long long k) {
    string res;
    while (k) {
        res += char('0' + k % 10);
        k /= 10;
    }
    reverse(all(res));
    return res;
}

void chemthan() {
    long long n; cin >> n;
    if (n == 1e10) {
        cout << "100^5\n";
        return;
    }
    auto ff = [&] (long long k) {
        int res = 0;
        while (k) res++, k /= 10;
        return res;
    };
    vector<pair<long long, pair<int, string> > > vals;
    pair<int, string> res = mp(ff(n), toString(n));
    for (int p = 2; (long long) p * p <= n; p++) {
        long long pp = p;
        int cnt = 1;
        while (pp <= n) {
            FOR(i, 0, 10) {
            if (n >= i && (n - i) % pp == 0) {
                long long k = (n - i) / pp;
                string express;
                express += toString(p);
                if (cnt > 1) {
                    express += "^" + toString(cnt);
                }
                if (k > 1) {
                    express += "*";
                    express += toString(k);
                }
                if (i) {
                    express += "+";
                    express += toString(i);
                }
                chkmin(res, mp(sz(express), express));
            }
            }
            for (int i = 1; pp <= n / i; i++) {
                string express;
                if (i > 1) {
                    express += toString(i) + "*";
                }
                express += toString(p);
                if (cnt > 1) {
                    express += "^" + toString(cnt);
                }
                long long t = n - i * pp;
                if (!t) {
                    chkmin(res, mp(sz(express), express));
                }
                else {
                    string ee = express + "+" + toString(t);
                    chkmin(res, mp(sz(ee), ee));
                }
                if (sz(express) > 6) break;
                vals.pb(mp(i * pp, mp(sz(express), express)));
            }
            if (pp > n / p) break;
            pp *= p, cnt++;
        }
    }
    FOR(a, 2, 10) FOR(b, 2, 10) FOR(c, 2, 10) FOR(d, 2, 10) {
        long long t = (long long) fpow(a, b) * fpow(c, d);
        if (t <= n) {
            long long m = n - t;
            string express;
            express += char('0' + a);
            express += "^";
            express += char('0' + b);
            express += "*";
            express += char('0' + c);
            express += "^";
            express += char('0' + d);
            if (m) {
                express += "+";
                express += toString(m);
            }
            chkmin(res, mp(sz(express), express));
        }

    }
    FOR(i, 1, 1e5) {
        string t = toString(i);
        vals.pb(mp(i, mp(sz(t), t)));
    }
    sort(all(vals));
    int k = lower_bound(all(vals), mp(n, mp(-INF, (string) ""))) - vals.begin();
    if (k < sz(vals) && vals[k].fi == n) {
        chkmin(res, vals[k].se);
    }
    for (auto it : vals) {
        long long need = n - it.fi;
        string express = it.se.se;
        if (need) {
            express += "+" + toString(need);
        }
        chkmin(res, mp(sz(express), express));
        int k = lower_bound(all(vals), mp(need, mp(-INF, (string) ""))) - vals.begin();
        if (k < sz(vals) && vals[k].fi == need) {
            string express = it.se.se + "+" + vals[k].se.se;
            chkmin(res, mp(sz(express), express));
        }
    }
    cout << res.se << "\n";
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