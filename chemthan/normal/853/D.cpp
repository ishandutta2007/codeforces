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
const int MOD2 = 1007681537;
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

const int maxn = 1e6 + 5;
int n;
int a[maxn];
vi pos1;
vi pos2;

int mn[maxn << 1];
int sm[maxn << 1];

void upd(int p, int val) {
    p += 1 << 19;
    mn[p] = sm[p] = val;
    while (p > 1) {
        p >>= 1;
        sm[p] = sm[p << 1] + sm[p << 1 | 1];
        mn[p] = min(mn[p << 1], sm[p << 1] + mn[p << 1 | 1]);
    }
}

int check(int mi) {
    FOR(i, 0, n) {
        upd(i, -a[i]);
    }
    FOR(i, 0, sz(pos2)) {
        int ix = pos2[i];
        upd(ix, 200);
    }
    int ptr = sz(pos2) - 1;
    FOR(x, 0, sz(pos1) + 1) if (mi >= 1000 * x) {
        int y = min(sz(pos2), (mi - 1000 * x) / 2000);
        while (ptr >= y) {
            int ix = pos2[ptr];
            upd(ix, -2000);
            ptr--;
        }
        if (x) {
            int ix = pos1[x - 1];
            upd(ix, 100);
        }
        int rm = mi - 1000 * x - 2000 * y;
        if ((!x && a[0] == 1000) || (!y && a[0] == 2000)) {
            upd(0, rm - a[0]);
        }
        else {
            upd(0, rm + a[0] / 10);
        }
        if (mn[1] >= 0) {
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> n;
    FOR(i, 0, n) {
        cin >> a[i];
        if (a[i] == 1000) {
            pos1.pb(i);
        }
        else {
            pos2.pb(i);
        }
    }
    int lo = 0, hi = 600000000;
    while (lo < hi) {
        int mi = lo + hi >> 1;
        if (!check(mi)) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }
    cout << (lo + hi >> 1) << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}