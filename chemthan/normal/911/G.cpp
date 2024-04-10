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

const int maxn = 3e5 + 5;
const int maxx = 100 + 5;
const int magic = 1000;
int n, q;
int a[maxn];
vi* g[magic][maxx];

void merge(vi*& a, vi*& b) {
    if (sz(*a) < sz(*b)) {
        swap(a, b);
    }
    while (sz(*b)) {
        a->pb(b->back());
        b->pop_back();
    }
}

void upd(int id, int x, int y) {
    if (x != y) {
        merge(g[id][y], g[id][x]);
    }
}

void release(int id) {
    static int f[maxx];
    FOR(i, 0, maxx) {
        for (int x : *g[id][i]) {
            f[x] = i;
        }
        g[id][i]->clear();
        g[id][i]->pb(i);
    }
    FOR(i, id * magic, (id + 1) * magic) {
        if (i < maxn) {
            a[i] = f[a[i]];
        }
    }
}

void solve() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, magic) {
        FOR(j, 0, maxx) {
            g[i][j] = new vi();
            g[i][j]->pb(j);
        }
    }
    cin >> q;
    while (q--) {
        int l, r, x, y; cin >> l >> r >> x >> y; l--, r--;
        int il = (l + magic - 1) / magic;
        int ir = r / magic;
        if (l < il * magic) {
            release(il - 1);
            FOR(i, l, min(il * magic, r + 1)) {
                if (a[i] == x) {
                    a[i] = y;
                }
            }
        }
        if (il <= ir) {
            release(ir);
            FOR(i, max(ir * magic, l), r + 1) {
                if (a[i] == x) {
                    a[i] = y;
                }
            }
        }
        FOR(i, il, ir) {
            upd(i, x, y);
        }
    }
    FOR(i, 0, magic) {
        release(i);
    }
    FOR(i, 0, n) cout << a[i] << " \n"[i == n - 1];
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