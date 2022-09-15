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

const int maxn = 1e5 + 5;
int n, q;
long long a[maxn];
long long st[4][maxn << 1];

void upd(long long st[], int p, long long val) {
    for (st[p += n] = val; p > 1; ) p >>= 1, st[p] = min(st[p << 1], st[p << 1 | 1]);
}
long long query(long long st[], int l, int r) {
    long long res = LINF;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) chkmin(res, st[l++]);
        if (r & 1) chkmin(res, st[--r]);
    }
    return res;
}

void upd(int pos) {
    FOR(i, 0, 2) FOR(j, 0, 2) {
        long long t = 0;
        if (pos) t -= abs(a[pos - 1]);
        if (pos < n - 1) t -= abs(a[pos]);
        if (pos) t += (i ? -1 : +1) * -a[pos - 1];
        if (pos < n - 1) t += (j ? -1 : +1) * a[pos];
        upd(st[i * 2 + j], pos, -t);
    }
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n - 1) a[i] = a[i + 1] - a[i];
    FOR(i, 0, n) {
        upd(i);
    }
    long long cost = 0;
    FOR(i, 0, n - 1) cost += abs(a[i]);
    cin >> q;
    while (q--) {
        int op, l, r, x; cin >> op >> l >> r >> x; l--, r--;
        if (op == 1) {
            long long res = -LINF;
            FOR(i, 0, 2) FOR(j, 0, 2) {
                long long tmp = cost;
                tmp += i ? x : -x;
                tmp += j ? x : -x;
                tmp -= query(st[i * 2 + j], l, r);
                chkmax(res, tmp);
            }
            cout << res << "\n";
        }
        else {
            if (l) {
                cost -= abs(a[l - 1]);
                a[l - 1] += x;
                cost += abs(a[l - 1]);
            }
            if (r < n - 1) {
                cost -= abs(a[r]);
                a[r] -= x;
                cost += abs(a[r]);
            }
            if (l) {
                upd(l - 1);
            }
            upd(l);
            upd(r);
            if (r < n - 1) {
                upd(r + 1);
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