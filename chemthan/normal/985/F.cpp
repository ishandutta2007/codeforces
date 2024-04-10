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

const int maxn = 2e5 + 5;
const int maxc = 26;
int pr;
int n, q;
string s;
int nxt[maxn][maxc];
int hs[maxc][maxn];
int pp[maxn];

int ispr(int k) {
    for (int i = 2; i * i <= k; i++) if (k % i == 0) {
        return 0;
    }
    return 1;
}

int myrand() {
    return abs(rand() * rand() + 2311 * rand() + 1992);
}

int calc(int l, int r, int c) {
    int res = hs[c][r];
    if (l) submod(res, hs[c][l - 1], pr);
    return mult(res, pp[maxn - r - 1], pr);
}

void chemthan() {
    srand(time(NULL));
    pr = INF + myrand() % (INF / 1000);
    while (!ispr(pr)) pr++;
    pp[0] = 1; FOR(i, 1, maxn) pp[i] = mult(pp[i - 1], 2311, pr);
    static int vals[maxn];
    FOR(i, 0, maxn) vals[i] = myrand() % pr;
    cin >> n >> q >> s;
    static int lst[maxc];
    static int fuck[maxc];
    fill_n(lst, maxc, INF);
    FOR(i, 0, n) {
        int c = s[i] - 'a';
        addmod(fuck[c], pp[i], pr);
        FOR(j, 0, maxc) hs[j][i] = fuck[j];
    }
    FORd(i, n, 0) {
        int c = s[i] - 'a';
        lst[c] = i;
        FOR(j, 0, maxc) nxt[i][j] = lst[j];
    }
    while (q--) {
        int x, y, k; cin >> x >> y >> k; x--, y--;
        static int f[maxc];
        static int g[maxc];
        int found = 0;
        ms(f, -1), ms(g, -1);
        FOR(i, 0, 26) {
            if (nxt[x][i] < x + k) {
                int t = nxt[x][i] - x + y;
                int j = s[t] - 'a';
                if (f[i] != -1 && f[i] != j) {
                    found = 1;
                }
                if (g[j] != -1 && g[j] != i) {
                    found = 1;
                }
                f[i] = j, g[j] = i;
            }
        }
        if (found) {
            cout << "NO\n";
            continue;
        }
        int hs1 = 0, hs2 = 0;
        FOR(i, 0, 26) {
            if (f[i] != -1) {
                addmod(hs1, mult(vals[f[i]], calc(x, x + k - 1, i), pr), pr);
            }
            addmod(hs2, mult(vals[i], calc(y, y + k - 1, i), pr), pr);
        }
        if (hs1 == hs2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
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