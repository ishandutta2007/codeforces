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
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

struct Node {
    int left, right;
    int num;
    int l[10], r[10];
    Node() : num(0) {}
};

const int maxn = 10 + 1;
const int maxm = 1e5 + 5;
const int logm = 20;
int n, m, q;
int a[maxn][maxm];
Node f[logm][maxm];
int dj[maxn * maxm];
vector<pair<int*, int> > rc;

inline int id(int u, int v) {
    return u * m + v;
}

void init() {
    FOR(i, 0, n) FOR(j, 0, m) dj[id(i, j)] = id(i, j);
}

int find(int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}

void change(int x, int v) {
    rc.pb(mp(&dj[x], dj[x]));
    dj[x] = v;
}

int join(int u, int v) {
    int p = find(u);
    int q = find(v);
    if (p != q) {
        change(p, q);
        return 1;
    }
    return 0;
}

void rollback() {
    while (sz(rc)) {
        *rc.back().fi = rc.back().se;
        rc.pop_back();
    }
}

Node join(Node x, Node y) {
    Node res;
    res.left = x.left, res.right = y.right;
    res.num = x.num + y.num;
    FOR(i, 0, n) {
        if (a[i][x.right] == a[i][y.left]) {
            if (join(x.r[i], y.l[i])) {
                res.num--;
            }
        }
    }
    FOR(i, 0, n) {
        res.l[i] = find(x.l[i]);
        res.r[i] = find(y.r[i]);
    }
    rollback();
    return res;
}

void solve() {
    cin >> n >> m >> q;
    FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];
    init();
    FOR(j, 0, m) {
        f[0][j].left = f[0][j].right = j;
        f[0][j].num = n;
        FOR(i, 0, n - 1) {
            if (a[i][j] == a[i + 1][j] && join(id(i, j), id(i + 1, j))) {
                f[0][j].num--;
            }
        }
        FOR(i, 0, n) {
            f[0][j].l[i] = f[0][j].r[i] = find(id(i, j));
        }
        rollback();
    }
    FOR(k, 1, logm) {
        FOR(i, 0, m) if (i + (1 << k) <= m) {
            int j = i + (1 << k - 1);
            f[k][i] = join(f[k - 1][i], f[k - 1][j]);
        }
    }
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        Node p;
        FORd(i, logm, 0) {
            if (l + (1 << i) <= r + 1) {
                if (!p.num) {
                    p = f[i][l];
                }
                else {
                    p = join(p, f[i][l]);
                }
                l += 1 << i;
            }
        }
        cout << p.num << "\n";
    }
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