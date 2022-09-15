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

const int maxn = 2e5 + 5;
int fac[maxn];
int ifac[maxn];
string a, b;
int c[2][2];
int d[2][2];
int e[2][2];

int binom(int a, int b) {
    if (a < 0 || b < 0) return 0;
    return mult(fac[a + b], mult(ifac[a], ifac[b]));
}

int solve(int n, int lst) {
    if (!lst) {
        swap(e[0][1], e[1][0]);
        swap(e[0][0], e[1][1]);
        lst = 1;
    }
    if (abs(e[1][0] - e[0][1]) > 1) {
        return 0;
    }
    if (e[1][0] < e[0][1]) {
        return 0;
    }
    int d0 = 0, d1 = 0;
    if (e[1][0] == e[0][1]) {
        d0 = e[0][1];
        d1 = e[1][0] + 1;
    }
    else {
        d0 = e[1][0];
        d1 = e[1][0];
    }
    int n0 = d0 + e[0][0];
    int n1 = d1 + e[1][1];
    if (d0 < 0 || d1 < 0) {
        return 0;
    }
    if (lst == 1 && !d1) {
        return 0;
    }
    if (!d0 && n0) {
        return 0;
    }
    if (!d1 && n1) {
        return 0;
    }
    if (lst != -1 && n0 + n1 != n) {
        return 0;
    }
    if (n0 + n1 > n) {
        return 0;
    }
    return mult(d0 ? binom(d0 - 1, n0 - d0) : 1, d1 ? binom(d1 - 1, n1 - d1) : 1);
}

int solve(string a) {
    int n = sz(a);
    ms(d, 0);
    int res = 0, lst = -1, nonzero = 0;
    FORd(i, n, 0) {
        if (a[i] == '1') {
            FOR(u, 0, 2) FOR(v, 0, 2) e[u][v] = d[u][v];
            if (nonzero) {
                if (lst == 0) {
                    d[0][1]++;

                    e[0][0]++;
                }
                if (lst == 1) {
                    d[1][1]++;

                    e[1][0]++;
                }
            }
            int ok = 1;
            FOR(u, 0, 2) FOR(v, 0, 2) {
                if (e[u][v] > c[u][v]) {
                    ok = 0;
                }
                e[u][v] = c[u][v] - e[u][v];
            }
            if (ok) {
                if (nonzero) {
                    addmod(res, solve(i + 1, 0));
                }
                else {
                    addmod(res, solve(i, -1));
                }
            }
            nonzero = 1;
        }
        else {
            if (nonzero) {
                if (lst == 0) {
                    d[0][0]++;
                }
                if (lst == 1) {
                    d[1][0]++;
                }
            }
        }
        lst = a[i] - '0';
    }
    return res;
}

void chemthan() {
    fac[0] = 1; FOR(i, 1, maxn) fac[i] = mult(fac[i - 1], i);
    FOR(i, 0, maxn) ifac[i] = inv(fac[i]);
    cin >> a >> b;
    FOR(i, 0, 2) FOR(j, 0, 2) cin >> c[i][j];
    reverse(all(a)), reverse(all(b));
    int res = solve(b);
    submod(res, solve(a));
    ms(d, 0);
    reverse(all(b));
    FOR(i, 0, sz(b) - 1) {
        d[b[i] - '0'][b[i + 1] - '0']++;
    }
    int ok = 1;
    FOR(u, 0, 2) FOR(v, 0, 2) {
        if (c[u][v] != d[u][v]) {
            ok = 0;
        }
    }
    addmod(res, ok);
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