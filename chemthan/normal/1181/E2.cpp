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
    int n; cin >> n;
    vi a(n), b(n), c(n), d(n);
    FOR(i, 0, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
    int ok = 1;
    function<void(set<pi>&, set<pi>&, set<pi>&, set<pi>&)> rec = [&] (set<pi>& sa, set<pi>& sb, set<pi>& sc, set<pi>& sd) {
        int k = sz(sa);
        if (k == 1) {
            return;
        }
        auto sa_b = sa.begin(); sa_b++;
        auto sc_b = sc.begin();
        auto sa_e = sa.end(); sa_e--;
        auto sc_e = sc.end(); sc_e--, sc_e--;
        auto sb_b = sb.begin(); sb_b++;
        auto sd_b = sd.begin();
        auto sb_e = sb.end(); sb_e--;
        auto sd_e = sd.end(); sd_e--, sd_e--;
        int t = -1, cc = -1;
        for (int i = 0; i + i < k - 1; i++) {
            if (sc_b->fi <= sa_b->fi) {
                t = 0, cc = i + 1;
                break;
            }
            if (sc_e->fi <= sa_e->fi) {
                t = 1, cc = i + 1;
                break;
            }
            if (sd_b->fi <= sb_b->fi) {
                t = 2, cc = i + 1;
                break;
            }
            if (sd_e->fi <= sb_e->fi) {
                t = 3, cc = i + 1;
                break;
            }
            if ((i + 1) + (i + 1) < k - 1) {
                sa_b++, sc_b++, sa_e--, sc_e--;
                sb_b++, sd_b++, sb_e--, sd_e--;
            }
        }
        if (t == -1) {
            ok = 0;
            return;
        }
        vi ver;
        if (t == 0) {
            auto it = sc.begin();
            FOR(i, 0, cc) {
                ver.pb(it->se);
                it++;
            }
        }
        if (t == 1) {
            auto it = sa.end(); it--;
            FOR(i, 0, cc) {
                ver.pb(it->se);
                it--;
            }
        }
        if (t == 2) {
            auto it = sd.begin();
            FOR(i, 0, cc) {
                ver.pb(it->se);
                it++;
            }
        }
        if (t == 3) {
            auto it = sb.end(); it--;
            FOR(i, 0, cc) {
                ver.pb(it->se);
                it--;
            }
        }
        set<pi> sa2, sb2, sc2, sd2;
        for (int ix : ver) {
            sa.erase(mp(a[ix], ix));
            sb.erase(mp(b[ix], ix));
            sc.erase(mp(c[ix], ix));
            sd.erase(mp(d[ix], ix));
            sa2.insert(mp(a[ix], ix));
            sb2.insert(mp(b[ix], ix));
            sc2.insert(mp(c[ix], ix));
            sd2.insert(mp(d[ix], ix));
        }
        rec(sa, sb, sc, sd);
        rec(sa2, sb2, sc2, sd2);
    };
    set<pi> sa, sb, sc, sd;
    FOR(i, 0, n) {
        sa.insert(mp(a[i], i));
        sb.insert(mp(b[i], i));
        sc.insert(mp(c[i], i));
        sd.insert(mp(d[i], i));
    }
    rec(sa, sb, sc, sd);
    if (ok) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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