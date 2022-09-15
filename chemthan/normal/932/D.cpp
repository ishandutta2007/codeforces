#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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

const int maxn = 4e5 + 5;
const int logn = 20;
int n, q;
long long w[maxn];
int par[logn][maxn];
long long sum[logn][maxn];

void chemthan() {
    cin >> q;
    long long last = 0;
    int cnt = 1;
    FOR(i, 0, logn) par[i][0] = -1;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            long long p, q; cin >> p >> q;
            long long r = p ^ last; r--;
            w[cnt] = q ^ last;
            if (w[cnt] <= w[r]) {
                par[0][cnt] = r;
                sum[0][cnt] = w[cnt];
                FOR(i, 1, logn) {
                    if (par[i - 1][cnt] == -1) {
                        par[i][cnt] = -1;
                    }
                    else {
                        par[i][cnt] = par[i - 1][par[i - 1][cnt]];
                        sum[i][cnt] = sum[i - 1][cnt] + sum[i - 1][par[i - 1][cnt]];
                    }
                }
            }
            else {
                int ptr = par[0][r];
                while (~ptr && w[cnt] > w[ptr]) {
                    ptr = par[0][ptr];
                }
                if (~ptr && w[cnt] <= w[ptr]) {
                    par[0][cnt] = ptr;
                    sum[0][cnt] = w[cnt];
                    FOR(i, 1, logn) {
                        if (par[i - 1][cnt] == -1) {
                            par[i][cnt] = -1;
                        }
                        else {
                            par[i][cnt] = par[i - 1][par[i - 1][cnt]];
                            sum[i][cnt] = sum[i - 1][cnt] + sum[i - 1][par[i - 1][cnt]];
                        }
                    }
                }
                else {
                    FOR(i, 0, logn) par[i][cnt] = -1;
                }
            }
            cnt++;
        }
        else {
            long long p, q; cin >> p >> q;
            long long r = p ^ last; r--;
            long long x = q ^ last;
            if (w[r] > x) {
                cout << (last = 0) << "\n";
            }
            else {
                last = 0;
                FORd(i, logn, 0) {
                    if (par[i][r] != -1 && sum[i][r] <= x) {
                        x -= sum[i][r];
                        r = par[i][r];
                        last += 1 << i;
                    }
                }
                if (w[r] <= x) {
                    last++;
                }
                cout << last << "\n";
            }
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