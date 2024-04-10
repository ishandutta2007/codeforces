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
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

struct node_t {
    node_t *p, *l, *r;
    int size, rev;
    int s, w;
    int key;
    int max;
    node_t(int key = 0) : p(0), l(0), r(0), size(1), rev(0), s(0), w(1), key(key), max(key) {}
};

int isrt(node_t* x) {
    return !(x->p) || (x->p->l != x && x->p->r != x);
}

int left(node_t* x) {
    return x->p->l == x;
}

void setchild(node_t* x, node_t* p, int l) {
    (l ? p->l : p->r) = x;
    if (x) x->p = p;
}

void push(node_t* x) {
    node_t* u = x->l;
    node_t* v = x->r;
    if (x->rev) {
        if (u) swap(u->l, u->r), u->rev ^= 1;
        if (v) swap(v->l, v->r), v->rev ^= 1;
        x->rev = 0;
    }
}

int size(node_t* x) {
    return x ? x->size : 0;
}

int sum(node_t* x) {
    return x ? x->s : 0;
}

int mx(node_t* x) {
    return x ? x->max : 0;
}

void pull(node_t* x) {
    x->size = size(x->l) + 1 + size(x->r);
    x->s = sum(x->l) + x->w + sum(x->r);
    x->max = max(mx(x->l), max(x->key, mx(x->r)));
}

void rotate(node_t* x) {
    node_t *p = x->p, *g = p->p;
    int l = left(x);
    setchild(l ? x->r : x->l, p, l);
    if (!isrt(p)) setchild(x, g, left(p));
    else x->p = g;
    setchild(p, x, !l);
    pull(p);
}

node_t* splay(node_t* x) {
    push(x);
    while (!isrt(x)) {
        node_t *p = x->p, *g = p->p;
        if (g) push(g);
        push(p), push(x);
        if (!isrt(p)) rotate(left(x) != left(p) ? x : p);
        rotate(x);
    }
    pull(x);
    return x;
}

node_t* access(node_t* x) {
    node_t* z = 0;
    for (node_t* y = x; y; y = y->p) {
        splay(y);
        y->w += sum(y->r);
        y->r = z;
        y->w -= sum(y->r);
        pull(z = y);
    }
    splay(x);
    return z;
}

void link(node_t* x, node_t* p) {
    access(x), access(p);
    x->p = p;
    p->w += sum(x);
    chkmax(p->max, x->max);
}

void cut(node_t* x) {
    access(x);
    x->l->p = 0, x->l = 0;
    pull(x);
}

void makeroot(node_t* x) {
    access(x);
    x->rev ^= 1;
    swap(x->l, x->r);
}

node_t* findroot(node_t* x) {
    access(x);
    while (x->l) push(x), x = x->l;
    push(x);
    return splay(x);
}

node_t* lca(node_t* x, node_t* y) {
    if (findroot(x) != findroot(y)) return 0;
    access(x);
    return access(y);
}

int connect(node_t* x, node_t* y) {
    if (x == y) return 1;
    access(x), access(y);
    return x->p != 0;
}

int treequery(node_t* x) {
    access(x);
    return x->w;
}

const int maxn = 2e6 + 5;
node_t pool[maxn];

void makeroot(int u) {
    makeroot(pool + u);
}

void link(int u, int v) {
    link(pool + u, pool + v);
}

void cut(int u) {
    cut(pool + u);
}

int findroot(int u) {
    return findroot(pool + u) - pool;
}

int lca(int u, int v) {
    node_t* a = lca(pool + u, pool + v);
    if (!a) return -1;
    return a - pool;
}

int connect(int u, int v) {
    return connect(pool + u, pool + v);
}

int treequery(int u) {
    return treequery(pool + u);
}

int pathquery(int x, int y) {
    makeroot(pool + x);
    access(pool + y);
    pull(pool + y);
    return pool[y].max;
}

void chemthan() {
    int n, m, q; cin >> n >> m >> q;
    vii edges;
    FOR(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        edges.pb({u, v});
    }
    FOR(i, 0, 2 * n + 2 * m) pool[i].key = pool[i].max = i;
    vi f(m);
    vi used(2 * m);
    FOR(i, 0, m) {
        int u, v; tie(u, v) = edges[i];
        if (findroot(2 * u) == findroot(2 * v)) {
            break;
        }
        f[i] = 1;
        FOR(it, 0, 2) {
            if (findroot(2 * u + 1) != findroot(2 * v)) {
                makeroot(2 * u + 1);
                makeroot(2 * v);
                link(2 * u + 1, 2 * n + 2 * i + it);
                link(2 * v, 2 * n + 2 * i + it);
                used[2 * i + it] = 1;
            }
            swap(u, v);
        }
    }
    int ptr = m - 1;
    FORd(i, m, 0) {
        if (f[i]) {
            while (i < ptr) {
                int u, v; tie(u, v) = edges[ptr];
                if (findroot(2 * u) == findroot(2 * v)) {
                    break;
                }
                FOR(it, 0, 2) {
                    if (findroot(2 * u + 1) != findroot(2 * v)) {
                        makeroot(2 * u + 1);
                        makeroot(2 * v);
                        pool[2 * n + 2 * ptr + it].key = pool[2 * n + 2 * ptr + it].max = 0;
                        link(2 * u + 1, 2 * n + 2 * ptr + it);
                        link(2 * v, 2 * n + 2 * ptr + it);
                    }
                    else {
                        int d = pathquery(2 * u + 1, 2 * v);
                        if (2 * n <= d && d < 2 * n + 2 * ptr) {
                            int x = d - 2 * n >> 1;
                            int r = d - 2 * n & 1;
                            int uu, vv; tie(uu, vv) = edges[x];
                            if (r) {
                                swap(uu, vv);
                            }
                            makeroot(d);
                            cut(2 * uu + 1);
                            cut(2 * vv);
                            used[d - 2 * n] = 0;
                            makeroot(2 * u + 1);
                            makeroot(2 * v);
                            pool[2 * n + 2 * ptr + it].key = pool[2 * n + 2 * ptr + it].max = 0;
                            link(2 * u + 1, 2 * n + 2 * ptr + it);
                            link(2 * v, 2 * n + 2 * ptr + it);
                        }
                    }
                    swap(u, v);
                }
                ptr--;
            }
            f[i] = ptr;
            int u, v; tie(u, v) = edges[i];
            FOR(it, 0, 2) {
                if (used[2 * i + it]) {
                    makeroot(2 * n + 2 * i + it);
                    cut(2 * u + 1);
                    cut(2 * v);
                }
                swap(u, v);
            }
        }
        else {
            f[i] = m;
        }
    }
    while (0 <= ptr) {
        int u, v; tie(u, v) = edges[ptr];
        if (findroot(2 * u) == findroot(2 * v)) {
            break;
        }
        FOR(it, 0, 2) {
            if (findroot(2 * u + 1) != findroot(2 * v)) {
                makeroot(2 * u + 1);
                makeroot(2 * v);
                link(2 * u + 1, 2 * n + 2 * ptr + it);
                link(2 * v, 2 * n + 2 * ptr + it);
            }
            else {
                int d = pathquery(2 * u + 1, 2 * v);
                if (2 * n <= d && d < 2 * n + 2 * ptr) {
                    int x = d - 2 * n >> 1;
                    int r = d - 2 * n & 1;
                    int uu, vv; tie(uu, vv) = edges[x];
                    if (r) {
                        swap(uu, vv);
                    }
                    makeroot(d);
                    cut(2 * uu + 1);
                    cut(2 * vv);
                    used[d - 2 * n] = 0;
                    makeroot(2 * u + 1);
                    makeroot(2 * v);
                    pool[2 * n + 2 * ptr + it].key = pool[2 * n + 2 * ptr + it].max = 0;
                    link(2 * u + 1, 2 * n + 2 * ptr + it);
                    link(2 * v, 2 * n + 2 * ptr + it);
                }
            }
            swap(u, v);
        }
        ptr--;
    }
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        if (r < (l ? f[l - 1] : ptr)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
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