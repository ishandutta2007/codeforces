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

#define double long double
const int maxn = 1e5 + 5;
int n, q;
int a[maxn];

double st[maxn << 2];
double lz[maxn << 2][2];

void push(int p, int L, int R) {
    if (lz[p][0] != 1.0) {
        st[p] *= lz[p][0];
        if (L < R) {
            int t = p << 1;
            FOR(i, 0, 2) {
                if (lz[t + i][1]) {
                    lz[t + i][1] *= lz[p][0];
                }
                lz[t + i][0] *= lz[p][0];
            }
        }
        lz[p][0] = 1.0;
    }
    if (lz[p][1] != 0.0) {
        st[p] += (R - L + 1) * lz[p][1];
        if (L < R) {
            int t = p << 1;
            FOR(i, 0, 2) {
                lz[t + i][1] += lz[p][1];
            }
        }
        lz[p][1] = 0.0;
    }
}
void pull(int p) {
    st[p] = st[p << 1] + st[p << 1 | 1];
}
void upd(int p, int l, int r, int L, int R, double mul, double add) {
    push(p, L, R);
    if (l > R || r < L) return;
    if (l <= L && r >= R) {
        lz[p][0] = mul, lz[p][1] = add;
        push(p, L, R);
        return;
    }
    upd(p << 1, l, r, L, L + R >> 1, mul, add);
    upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, mul, add);
    pull(p);
}
double query(int p, int l, int r, int L, int R) {
    push(p, L, R);
    if (l > R || r < L) return 0.0;
    if (l <= L && r >= R) return st[p];
    return query(p << 1, l, r, L, L + R >> 1) + query(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
}

void solve() {
    cin >> n >> q;
    FOR(i, 0, n << 2) lz[i][0] = 1.0, lz[i][1] = 0.0;
    FOR(i, 0, n) cin >> a[i], upd(1, i, i, 0, n - 1, 1, a[i]);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x[2], y[2];
            FOR(i, 0, 2) cin >> x[i] >> y[i], x[i]--, y[i]--;
            int len[2] = {y[0] - x[0] + 1, y[1] - x[1] + 1};
            double t[2];
            FOR(i, 0, 2) t[i] = query(1, x[i ^ 1], y[i ^ 1], 0, n - 1) / len[i ^ 1];
            FOR(i, 0, 2) {
                upd(1, x[i], y[i], 0, n - 1, 1.0 * (len[i] - 1) / len[i], 0);
                upd(1, x[i], y[i], 0, n - 1, 1.0, t[i] / len[i]);
            }
        }
        else {
            int x, y; cin >> x >> y, x--, y--;
            cout << prec(9) << query(1, x, y, 0, n - 1) << "\n";
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
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}