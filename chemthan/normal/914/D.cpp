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

const int maxn = 5e5 + 5;
int n, q;
int a[maxn];

int st[maxn << 2];

void upd(int p, int i, int L, int R, int val) {
    if (i < L || i > R) return;
    if (L == R) {
        st[p] = val;
        return;
    }
    upd(p << 1, i, L, L + R >> 1, val);
    upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
    st[p] = gcd(st[p << 1], st[p << 1 | 1]);
}
int query(int p, int l, int r, int L, int R) {
    if (l > R || r < L) return 0;
    if (l <= L && r >= R) return st[p];
    return gcd(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}
vector<pair<int, pi> > segs;
void trace(int p, int l, int r, int L, int R, int x) {
    if (l > R || r < L) return;
    if (l <= L && r >= R) {
        segs.pb(mp(p, mp(L, R)));
        return;
    }
    trace(p << 1, l, r, L, L + R >> 1, x);
    trace(p << 1 | 1, l, r, (L + R >> 1) + 1, R, x);
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i], upd(1, i, 0, n - 1, a[i]);
    cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, x; cin >> l >> r >> x; l--, r--;
            segs.clear();
            trace(1, l, r, 0, n - 1, x);
            int pos = -1;
            for (auto it : segs) {
                int p = it.fi;
                int L = it.se.fi;
                int R = it.se.se;
                if (st[p] % x) {
                    while (L < R) {
                        if (st[p << 1] % x) {
                            p <<= 1;
                            R = L + R >> 1;
                        }
                        else {
                            p <<= 1;
                            p |= 1;
                            L = (L + R >> 1) + 1;
                        }
                    }
                    pos = L + R >> 1;
                    break;
                }
            }
            if (pos == -1) {
                cout << "YES\n";
            }
            else {
                if (query(1, pos + 1, r, 0, n - 1) % x == 0) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
        }
        else {
            int u, v; cin >> u >> v; u--;
            upd(1, u, 0, n - 1, v);
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