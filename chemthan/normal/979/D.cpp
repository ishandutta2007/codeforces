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

const int maxn = 1e5 + 5;
const int magic = 70;
const int logn = 17;
int q;
int f[maxn];

int ptr;
int nxt[maxn * 200][2];
int mn[maxn * 200];
int rts[magic];

void add(int rt, int k) {
    chkmin(mn[rt], k);
    FORd(i, logn, 0) {
        int b = bit(k, i);
        if (!nxt[rt][b]) {
            nxt[rt][b] = ++ptr;
            mn[ptr] = INF;
        }
        rt = nxt[rt][b];
        chkmin(mn[rt], k);
    }
}

int query(int rt, int k, int lim) {
    if (mn[rt] > lim) return -1;
    int res = 0;
    FORd(i, logn, 0) {
        int b = bit(k, i);
        res <<= 1;
        if (nxt[rt][b ^ 1] && mn[nxt[rt][b ^ 1]] <= lim) {
            rt = nxt[rt][b ^ 1];
            res |= 1;
        }
        else {
            rt = nxt[rt][b];
        }
    }
    return res;
}

void chemthan() {
    FOR(i, 0, magic) {
        rts[i] = ++ptr;
        mn[ptr] = INF;
    }
    cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int u; cin >> u;
            if (!f[u]) {
                f[u] = 1;
                FOR(i, 1, magic) if (u % i == 0) {
                    add(rts[i], u);
                }
            }
        }
        else {
            int x, k, s; cin >> x >> k >> s;
            if (x % k) {
                cout << -1 << "\n";
                continue;
            }
            if (k >= magic) {
                int res = -1;
                for (int i = k; i <= s - x; i += k) if (f[i]) {
                    chkmax(res, i ^ x);
                }
                if (res != -1) {
                    cout << (res ^ x) << "\n";
                }
                else {
                    cout << -1 << "\n";
                }
                continue;
            }
            int res = query(rts[k], x, s - x);
            if (res != -1) {
                cout << (res ^ x) << "\n";
            }
            else {
                cout << -1 << "\n";
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