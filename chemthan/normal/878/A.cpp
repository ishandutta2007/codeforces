#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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

const int maxn = 5e5 + 5;
int n;
string op[maxn];
int a[maxn];

void solve() {
    string ar[] = {"|", "&", "^"};
    cin >> n;
    FOR(i, 0, n) {
        cin >> op[i] >> a[i];
    }
    static int f[10][2];
    FOR(k, 0, 10) {
        f[k][0] = 0, f[k][1] = 1;
        FOR(i, 0, n) {
            if (op[i] == "|") {
                f[k][0] |= bit(a[i], k);
                f[k][1] |= bit(a[i], k);
            }
            else if (op[i] == "&") {
                f[k][0] &= bit(a[i], k);
                f[k][1] &= bit(a[i], k);
            }
            else if (op[i] == "^") {
                f[k][0] ^= bit(a[i], k);
                f[k][1] ^= bit(a[i], k);
            }
        }
    }
    FOR(i0, 0, 3) FOR(i1, 0, 3) FOR(i2, 0, 3) FOR(i3, 0, 3) FOR(i4, 0, 3) {
        int zz[] = {i0, i1, i2, i3, i4};
        int g[1 << 5][2];
        FOR(msk, 0, 1 << 5) {
            g[msk][0] = 0, g[msk][1] = 1;
            FOR(i, 0, 5) {
                string t = ar[zz[i]];
                if (t == "|") {
                    g[msk][0] |= bit(msk, i);
                    g[msk][1] |= bit(msk, i);
                }
                else if (t == "&") {
                    g[msk][0] &= bit(msk, i);
                    g[msk][1] &= bit(msk, i);
                }
                else if (t == "^") {
                    g[msk][0] ^= bit(msk, i);
                    g[msk][1] ^= bit(msk, i);
                }
            }
        }
        vector<int> res(5);
        int ok = 1;
        FOR(i, 0, 10) {
            int found = 0;
            FOR(msk, 0, 1 << 5) {
                if (g[msk][0] == f[i][0] && g[msk][1] == f[i][1]) {
                    FOR(j, 0, 5) {
                        res[j] |= (1 << i) * bit(msk, j);
                    }
                    found = 1;
                    break;
                }
            }
            if (!found) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << 5 << "\n";
            FOR(i, 0, 5) {
                cout << ar[zz[i]] << " " << res[i] << "\n";
            }
            return;
        }
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int JUDGE_ONLINE = 1;
    if (argc > 1) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[2], "w", stdout));
    }
    solve();
    if (!JUDGE_ONLINE) {
        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}