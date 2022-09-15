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
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

struct node_t {
    node_t *l, *r;
    int cnt;
    node_t(node_t* l = 0, node_t* r = 0, int cnt = 0) : l(l), r(r), cnt(cnt) {}
};

int cnt(node_t* p) {
    return p ? p->cnt : 0;
}

node_t* upd(node_t* p, int i, int L, int R, int val) {
    if (i < L || R < i) return p;
    if (L == R) {
        return new node_t(0, 0, cnt(p) + val);
    }
    node_t* res = new node_t(p ? p->l : 0, p ? p->r : 0);
    res->l = upd(res->l, i, L, L + R >> 1, val);
    res->r = upd(res->r, i, (L + R >> 1) + 1, R, val);
    res->cnt = cnt(res->l) + cnt(res->r);
    return res;
}

int query(node_t* p, node_t* q, int L, int R) {
    if (L == R) {
        return L;
    }
    if (cnt(p ? p->l : 0) > cnt(q ? q->l : 0)) {
        return query(p->l, q ? q->l : 0, L, L + R >> 1);
    }
    else {
        return query(p->r, q ? q->r : 0, (L + R >> 1) + 1, R);
    }
}

const int maxn = 1e5 + 5;
int n, m;
node_t* f[maxn];

void chemthan() {
    cin >> n >> m;
    vector<vi> a(n);
    FOR(i, 0, n) {
        int k; cin >> k;
        a[i].resize(k);
        for (int& x : a[i]) {
            cin >> x, x--;
            f[i] = upd(f[i], x, 0, m - 1, 1);
        }
    }
    set<pi> heap;
    FOR(i, 0, n) {
        heap.insert(mp(cnt(f[i]), i));
    }
    vector<pair<pi, int> > res;
    while (1) {
        int u = heap.begin()->se;
        int v = heap.rbegin()->se;
        if (cnt(f[u]) < cnt(f[v]) - 1) {
            heap.erase(mp(cnt(f[u]), u));
            heap.erase(mp(cnt(f[v]), v));
            int x = query(f[v], f[u], 0, m - 1);
            f[v] = upd(f[v], x, 0, m - 1, -1);
            f[u] = upd(f[u], x, 0, m - 1, +1);
            heap.insert(mp(cnt(f[u]), u));
            heap.insert(mp(cnt(f[v]), v));
            res.pb(mp(mp(v, u), x));
        }
        else {
            break;
        }
    }
    cout << sz(res) << "\n";
    for (auto e : res) {
        cout << e.fi.fi + 1 << " " << e.fi.se + 1 << " " << e.se + 1 << "\n";
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