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

vi divide(vi a, vi b, int p) {
    int na = sz(a), nb = sz(b);
    vi res(max(0, na - nb + 1));
    int tmp = inv(b[nb - 1], p);
    FORd(i, na, nb - 1) {
        int coef = mult(a[i], tmp, p);
        addmod(res[i - nb + 1], coef, p);
        FOR(j, 0, nb) {
            submod(a[j + i - nb + 1], mult(coef, b[j], p), p);
        }
    }
    return res;
}

vi mod(vi a, vi b, int p) {
    int na = sz(a), nb = sz(b);
    int tmp = inv(b[nb - 1], p);
    FORd(i, na, nb - 1) {
        int coef = mult(a[i], tmp, p);
        FOR(j, 0, nb) {
            submod(a[j + i - nb + 1], mult(coef, b[j], p), p);
        }
    }
    while (sz(a) && !a.back()) a.pop_back();
    return a;
}

vi add(vi a, vi b, int p) {
    int na = sz(a), nb = sz(b);
    vi res(max(na, nb));
    FOR(i, 0, max(na, nb)) {
        if (i < na) {
            addmod(res[i], a[i], p);
        }
        if (i < nb) {
            addmod(res[i], b[i], p);
        }
    }
    return res;
}

vi mul(vi a, vi b, int p) {
    int na = sz(a), nb = sz(b);
    vi res(max(0, na + nb - 1));
    FOR(i, 0, na) FOR(j, 0, nb) {
        addmod(res[i + j], mult(a[i], b[j], p), p);
    }
    return res;
}

vi pow(vi a, vi b, long long k, int p) {
    if (!k) return vi(1, 1);
    if (k & 1) return mod(mul(a, pow(a, b, k - 1, p), p), b, p);
    vi r = pow(a, b, k >> 1, p);
    return mod(mul(r, r, p), b, p);
}

const int maxn = 1e5 + 5;
int n, m;
long long k;
int a[maxn];
int b[maxn];

void solve() {
    cin >> n >> m >> k;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, m) cin >> b[i];
    int mx = *max_element(b, b + m);
    vi d(mx + 1);
    d[mx] = 1;
    FOR(i, 0, m) submod(d[mx - b[i]], 1);
    vi res;
    vi tmp(2); tmp[1] = 1;
    FOR(i, 0, n) {
        res = add(res, pow(tmp, d, a[i], MOD), MOD);
    }
    res = pow(res, d, k, MOD);
    tmp.clear();
    tmp.resize(mx + 1), tmp[mx] = 1;
    res = mul(res, tmp, MOD);
    vi u = divide(res, d, MOD);
    cout << u[0] << "\n";
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