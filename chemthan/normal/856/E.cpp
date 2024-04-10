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

const int maxn = 5e5 + 5;
int n, d, k;
int op[maxn];
int x[maxn];
int y[maxn];
int z[maxn];
int l[maxn];
int r[maxn];
int a[maxn];
int b[maxn];

long long ff1(int i, int j) {
    int x1 = x[i] + d;
    int y1 = y[i] + 0;
    int x2 = x[j] + d;
    int y2 = y[j] + 0;
    return (long long) x1 * y2 - (long long) x2 * y1;
}

long long ff2(int i, int j) {
    int x1 = x[i] - d;
    int y1 = y[i] - 0;
    int x2 = x[j] - d;
    int y2 = y[j] - 0;
    return (long long) x1 * y2 - (long long) x2 * y1;
}

int cmp1(int i, int j) {
    long long cr = ff1(i, j);
    if (cr) return cr > 0;
    return i < j;
}

int cmp2(int i, int j) {
    long long cr = ff2(i, j);
    if (cr) return cr > 0;
    return i < j;
}

set<int> heap[maxn];
int st[maxn << 1];
void upd(int p, int n, int val) {
    for (st[p += n] = val; p > 1; ) p >>= 1, st[p] = min(st[p << 1], st[p << 1 | 1]);
}
int query(int l, int r, int n) {
    int res = INF;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) chkmin(res, st[l++]);
        if (r & 1) chkmin(res, st[--r]);
    }
    return res;
}

void upd(int u, int n) {
    int val = sz(heap[u]) ? *heap[u].begin() : INF;
    upd(u, n, val);
}

long long dot(pi a, pi b) {
    return (long long) a.fi * b.fi + (long long) a.se * b.se;
}

void solve() {
    cin >> d >> n;
    FOR(i, 0, n) {
        cin >> op[i];
        if (op[i] == 1) {
            cin >> x[k] >> y[k], k++;
        }
        else if (op[i] == 2) {
            cin >> z[i], z[i]--;
        }
        else {
            cin >> l[i] >> r[i], l[i]--, r[i]--;
        }
    }
    vi ver; FOR(i, 0, k) ver.pb(i);
    sort(all(ver), cmp1);
    int st1 = 0;
    FOR(i, 0, k) {
        if (i && ff1(ver[i - 1], ver[i])) st1++;
        a[ver[i]] = st1;
    }
    FOR(i, 0, k) a[i] = st1 - a[i];
    int st2 = 0;
    sort(all(ver), cmp2);
    FOR(i, 0, k) {
        if (i && ff2(ver[i - 1], ver[i])) st2++;
        b[ver[i]] = st2;
    }
    FOR(i, 0, k + k) st[i] = INF;
    k = 0;
    FOR(i, 0, n) {
        if (op[i] == 1) {
            heap[a[k]].insert(b[k]);
            upd(a[k], st1 + 1);
            k++;
        }
        else if (op[i] == 2) {
            int ix = z[i];
            heap[a[ix]].erase(b[ix]);
            upd(a[ix], st1 + 1);
        }
        else {
            int ix1 = l[i];
            int ix2 = r[i];
            int u = max(a[ix1], a[ix2]);
            int v = max(b[ix1], b[ix2]);
            pi p, q;
            if (a[ix1] > a[ix2]) {
                p = mp(x[ix1] + d, y[ix1]);
            }
            else {
                p = mp(x[ix2] + d, y[ix2]);
            }
            if (b[ix1] > b[ix2]) {
                q = mp(x[ix1] - d, y[ix1]);
            }
            else {
                q = mp(x[ix2] - d, y[ix2]);
            }
            heap[a[ix1]].erase(b[ix1]);
            upd(a[ix1], st1 + 1);
            heap[a[ix2]].erase(b[ix2]);
            upd(a[ix2], st1 + 1);
            if (dot(p, q) < 0 || query(0, u, st1 + 1) <= v) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
            heap[a[ix1]].insert(b[ix1]);
            upd(a[ix1], st1 + 1);
            heap[a[ix2]].insert(b[ix2]);
            upd(a[ix2], st1 + 1);
        }
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