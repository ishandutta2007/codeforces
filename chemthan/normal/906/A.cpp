#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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

const int maxn = 1e5 + 5;
const int magic = 40;
int n, p, q;
int a[maxn];
map<int, int> hs;
int f[maxn][magic];

int func(int p) {
    if (hs.count(p)) return hs[p];
    int& res = hs[p];
    res = 1;
    map<int, int> dvs;
    for (int i = 2; i * i <= p; i++) {
        while (p % i == 0) dvs[i]++, p /= i;
    }
    if (p > 1) dvs[p]++;
    FORall(it, dvs) {
        res *= it->fi - 1;
        res *= fpow(it->fi, it->se - 1);
    }
    return res;
}

int mypow(int n, int k) {
    if (!k) return 1;
    if (k & 1) return min(100LL, (long long) n * mypow(n, k - 1));
    int t = mypow(n, k >> 1);
    return min(100LL, (long long) t * t);
}

int calc(int l, int r, int p) {
    if (l == r || p == 1) return a[l] % p;
    int np = func(p);
    int x = calc(l + 1, r, np);
    if (f[l + 1][r - l - 1] < 100) {
        return fpow(a[l], f[l + 1][r - l - 1], p);
    }
    else {
        if (x < 100) {
            x += (100 - x + np - 1) / np * np;
        }
        return fpow(a[l], x, p);
    }
}

void solve() {
    int n; cin >> n;
    int f[26] = {};
    int flag = 0;
    int res = 0;
    FOR(i, 0, n) {
        string op, s; cin >> op >> s;
        if (op == ".") {
            for (char c : s) {
                f[c - 'a'] = 1;
            }
        }
        else if (op == "!") {
            FOR(i, 0, 26) {
                int found = 0;
                for (char c : s) {
                    if (c - 'a' == i) {
                        found = 1;
                    }
                }
                if (!found) {
                    f[i] = 1;
                }
            }
            if (flag) {
                res++;
            }
        }
        else {
            for (char c : s) {
                f[c - 'a'] = 1;
            }
            if (flag) {
                res++;
            }
        }
        vi cans;
        FOR(i, 0, 26) {
            if (!f[i]) {
                cans.pb(i);
            }
        }
        if (sz(cans) == 1) {
            flag = 1;
        }
    }
    cout << max(0, res - 1) << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}