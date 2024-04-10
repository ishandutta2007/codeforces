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
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 1e5 + 5;
int n;
int a[maxn];
int used[maxn];

vi work1() {
    static int f[maxn];
    static int p[maxn];
    int t = 0;
    pi best;
    FOR(i, 0, n) {
        int k = lower_bound(f, f + t, a[i]) - f;
        chkmax(t, k + 1);
        f[k] = a[i];
        if (k) p[a[i]] = f[k - 1];
        chkmax(best, mp(k + 1, a[i]));
    }
    vi res;
    int st = best.se;
    FOR(i, 0, best.fi) {
        res.pb(st);
        st = p[st];
    }
    reverse(all(res));
    return res;
}

void work2(vector<vi>& res) {
    static int f[maxn];
    static int p[maxn];
    int t = 0;
    FOR(i, 0, n) {
        int k = lower_bound(f, f + t, a[i]) - f;
        chkmax(t, k + 1);
        f[k] = a[i];
        p[a[i]] = k;
    }
    int c = sz(res);
    res.resize(c + t);
    FOR(i, 0, n) {
        res[c + p[a[i]]].pb(a[i]);
    }
}

void chemthan() {
    int test; cin >> test;
    while (test--) {
        cin >> n;
        FOR(i, 0, n) cin >> a[i], a[i]--, used[i] = 1;
        vector<vi> res;
        while (n) {
            int k = 0;
            while (k * (k + 1) / 2 <= n) k++;
            vi r = work1();
            if (k * (k - 1) / 2 <= n - sz(r)) {
                break;
            }
            for (int x : r) {
                used[x] = 0;
            }
            res.pb(r);
            static int b[maxn];
            int nn = 0;
            FOR(i, 0, n) if (used[a[i]]) {
                b[nn++] = a[i];
            }
            n = nn;
            FOR(i, 0, n) a[i] = b[i];
        }
        work2(res);
        cout << sz(res) << "\n";
        for (auto it : res) {
            cout << sz(it) << " ";
            FOR(i, 0, sz(it)) cout << it[i] + 1 << " \n"[i == sz(it) - 1];
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