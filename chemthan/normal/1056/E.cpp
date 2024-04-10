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

const int maxn = 1e6 + 5;
int pr;
int base = 257;
int p[maxn];
string s, t;
int f[maxn];

int ispr(int k) {
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            return 0;
        }
    }
    return 1;
}

int calc(int l, int r) {
    int res = f[r];
    if (l) submod(res, f[l - 1], pr);
    return mult(res, p[maxn - l - 1], pr);
}

void chemthan() {
    pr = INF - myrand() % INF / 10;
    while (!ispr(pr)) pr++;
    p[0] = 1; FOR(i, 1, maxn) p[i] = mult(p[i - 1], base, pr);
    cin >> s >> t;
    FOR(i, 0, sz(t)) {
        if (i) {
            f[i] = f[i - 1];
        }
        addmod(f[i], mult(t[i], p[i], pr), pr);
    }
    int a = 0, b = 0;
    for (char c : s) {
        if (c == '0') {
            a++;
        }
        else {
            b++;
        }
    }
    int res = 0;
    for (int x = 1; x * a < sz(t); x++) {
        int r = sz(t) - x * a;
        if (r % b == 0) {
            int y = r / b;
            vi pos0, pos1;
            int num = 0;
            FOR(i, 0, sz(s)) {
                if (s[i] == '0') {
                    pos0.pb(num);
                    num += x;
                }
                else {
                    pos1.pb(num);
                    num += y;
                }
            }
            int found = 0;
            FOR(i, 1, sz(pos0)) {
                int u = pos0[0];
                int v = pos0[i];
                if (calc(u, u + x - 1) != calc(v, v + x - 1)) {
                    found = 1;
                    break;
                }
            }
            FOR(i, 1, sz(pos1)) {
                int u = pos1[0];
                int v = pos1[i];
                if (calc(u, u + y - 1) != calc(v, v + y - 1)) {
                    found = 1;
                    break;
                }
            }
            int u = pos0[0];
            int v = pos1[0];
            if (calc(u, u + x - 1) == calc(v, v + y - 1)) {
                found = 1;
            }
            if (!found) res++;
        }
    }
    cout << res << "\n";
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