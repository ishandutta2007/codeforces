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

struct node_t {
    node_t *l, *r;
    int val;
    node_t(node_t* l = 0, node_t* r = 0, int val = 0) : l(l), r(r), val(val) {}
};

node_t* upd1(node_t* p, int i, int L, int R, int val) {
    if (!p) p = new node_t();
    if (i < L || i > R) return p;
    if (L == R) {
        node_t* res = new node_t();
        res->val = val;
        return res;
    }
    node_t* res = new node_t();
    res->l = upd1(p->l, i, L, L + R >> 1, val);
    res->r = upd1(p->r, i, (L + R >> 1) + 1, R, val);
    res->val = res->l->val + res->r->val;
    return res;
}

node_t* upd2(node_t* p, int i, int L, int R, int val) {
    if (!p) p = new node_t();
    if (i < L || i > R) return p;
    if (L == R) {
        node_t* res = new node_t();
        res->val = p->val + val;
        return res;
    }
    node_t* res = new node_t();
    res->l = upd2(p->l, i, L, L + R >> 1, val);
    res->r = upd2(p->r, i, (L + R >> 1) + 1, R, val);
    res->val = res->l->val + res->r->val;
    return res;
}
int query(node_t* p, int l, int r, int L, int R) {
    if (!p) p = new node_t();
    if (l > R || r < L) return 0;
    if (l <= L && r >= R) return p->val;
    return query(p->l, l, r, L, L + R >> 1) + query(p->r, l, r, (L + R >> 1) + 1, R);
}

const int maxn = 1e5 + 5;
int q; 
map<string, int> hs;
node_t* f[maxn];
node_t* g[maxn];

int query(string s) {
    if (hs.count(s)) return hs[s];
    int res = sz(hs);
    return hs[s] = res;
}

void chemthan() {
    cin >> q;
    FOR(i, 1, q + 1) {
        string op; cin >> op;
        if (op == "set") {
            string a; int x; cin >> a >> x;
            int id = query(a);
            f[i] = upd1(f[i - 1], id, 0, maxn - 1, x);
            int px = query(f[i - 1], id, id, 0, maxn - 1);
            if (px) {
                g[i] = upd2(g[i - 1], px, 0, INF + 5, -1);
            }
            else {
                g[i] = g[i - 1];
            }
            g[i] = upd2(g[i], x, 0, INF + 5, 1);
        }
        else if (op == "remove") {
            string a; cin >> a;
            int id = query(a);
            f[i] = upd1(f[i - 1], id, 0, maxn - 1, 0);
            int px = query(f[i - 1], id, id, 0, maxn - 1);
            if (px) {
                g[i] = upd2(g[i - 1], px, 0, INF + 5, -1);
            }
            else {
                g[i] = g[i - 1];
            }
        }
        else if (op == "undo") {
            int d; cin >> d;
            f[i] = f[i - d - 1];
            g[i] = g[i - d - 1];
        }
        else if (op == "query") {
            string a; cin >> a;
            int id = query(a);
            int x = query(f[i] = f[i - 1], id, id, 0, maxn - 1);
            g[i] = g[i - 1];
            if (!x) {
                cout << -1 << "\n";
            }
            else {
                cout << query(g[i] = g[i - 1], 0, x - 1, 0, INF + 5) << "\n";
            }
            cout.flush();
        }
    }
}

int main(int argc, char* argv[]) {
    //ios_base::sync_with_stdio(0), cin.tie(0);
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