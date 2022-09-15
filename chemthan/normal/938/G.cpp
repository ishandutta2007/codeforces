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
    node_t *p, *l, *r;
    int size, rev;
    int w, mn;
    int val, sval;
    node_t() : p(0), l(0), r(0), size(1), rev(0), val(0), sval(0) {}
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

int mn(node_t* x) {
    return x ? x->mn : 1e9;
}

int sval(node_t* x) {
    return x ? x->sval : 0;
}

void pull(node_t* x) {
    x->size = size(x->l) + 1 + size(x->r);
    x->mn = min(x->w, min(mn(x->l), mn(x->r)));
    x->sval = x->val ^ sval(x->l) ^ sval(x->r);
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
        y->r = z;
        pull(z = y);
    }
    splay(x);
    return z;
}

void link(node_t* x, node_t* p) {
    access(x), access(p);
    x->p = p;
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

int connect(node_t* x, node_t* y) {
    if (x == y) return 1;
    access(x), access(y);
    return x->p != 0;
}

int query(node_t* x, node_t* y, int& val) {
    makeroot(x);
    access(y);
    val = sval(y);
    return mn(y);
}

struct Edge {
    int u, v, w;
    int l, r;
    int operator < (const Edge& rhs) const {
        return make_tuple(w, u, v, l, r) < make_tuple(rhs.w, rhs.u, rhs.v, rhs.l, rhs.r);
    }
};

const int maxn = 4e5 + 5;
node_t pool[maxn * 3];
int n, m, q;
Edge edges[maxn << 1];
vi que[maxn];
vii que2[maxn];
int res[maxn];

inline int ff(int x) {
    return 1 << __lg(x);
}
inline void add(int x, vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (ff(v[i]) & x) x ^= v[i];
    }
    if (!x) return;
    for (int i = 0; i < v.size(); i++) {
        if (ff(x) & v[i]) v[i] ^= x;
    }
    v.push_back(x);
}

int query(vi vals, int x) {
    sort(all(vals), greater<int>());
    for (int t : vals) {
        chkmin(x, x ^ t);
    }
    return x;
}

void divide(int l, int r, vector<pair<int, pi> > events, vi vals) {
    int m = l + r >> 1;
    vector<pair<int, pi> > Levents, Revents;
    for (auto it : events) {
        int x = it.fi;
        int u = it.se.fi;
        int v = it.se.se;
        if (u <= l && r <= v) {
            add(x, vals);
        }
        else {
            if (u <= m) {
                Levents.pb(it);
            }
            if (v >= m + 1) {
                Revents.pb(it);
            }
        }
    }
    if (l == r) {
        if (sz(que[l])) {
            int x = que[l][0];
            res[l] = query(vals, x);
        }
       return;
    }
    divide(l, m, Levents, vals);
    divide(m + 1, r, Revents, vals);
}

void chemthan() {
    cin >> n >> m;
    int cnt = 0;
    map<pi, int> hs;
    static vi add[maxn];
    static vi rem[maxn];
    FOR(i, 0, m) {
        cin >> edges[cnt].u >> edges[cnt].v >> edges[cnt].w; edges[cnt].u--, edges[cnt].v--;
        if (edges[cnt].u > edges[cnt].v) swap(edges[cnt].u, edges[cnt].v);
        edges[cnt].l = 0;
        hs[mp(edges[cnt].u, edges[cnt].v)] = cnt;
        add[0].pb(cnt);
        cnt++;
    }
    cin >> q;
    FOR(i, 0, m) {
        edges[i].r = q + i + 1;
    }
    FOR(i, 1, q + 1) {
        int op; cin >> op;
        if (op == 1) {
            cin >> edges[cnt].u >> edges[cnt].v >> edges[cnt].w; edges[cnt].u--, edges[cnt].v--;
            if (edges[cnt].u > edges[cnt].v) swap(edges[cnt].u, edges[cnt].v);
            edges[cnt].l = i;
            edges[cnt].r = q + cnt + 1;
            hs[mp(edges[cnt].u, edges[cnt].v)] = cnt;
            add[i].pb(cnt);
            cnt++;
        }
        else if (op == 2) {
            int u, v; cin >> u >> v; u--, v--;
            if (u > v) swap(u, v);
            int ix = hs[mp(u, v)];
            edges[ix].r = i;
            rem[i].pb(ix);
        }
        else {
            int u, v; cin >> u >> v; u--, v--;
            que2[i].pb(mp(u, v));
        }
    }
    FOR(i, 0, n) pool[i].w = pool[i].mn = INF;
    FOR(i, 0, cnt) {
        pool[n + i].w = pool[n + i].mn = edges[i].r;
        pool[n + i].val = edges[i].w;
    }
    static int del[maxn];
    fill_n(del, cnt, 1);
    vector<pair<int, pi> > events;
    FOR(i, 0, q + 1) {
        for (int ix : rem[i]) {
            if (!del[ix]) {
                makeroot(pool + n + ix);
                cut(pool + edges[ix].u);
                cut(pool + edges[ix].v);
                del[ix] = 1;
            }
        }
        for (int ix : add[i]) {
            int u = edges[ix].u;
            int v = edges[ix].v;
            if (connect(pool + u, pool + v)) {
                int val;
                int ix2 = query(pool + u, pool + v, val);
                events.pb(mp(val ^ edges[ix].w, mp(i, min(ix2, edges[ix].r))));
                if (ix2 > edges[ix].r) {
                    continue;
                }
                if (ix2 > q) {
                    ix2 -= q + 1;
                }
                else {
                    ix2 = rem[ix2][0];
                }
                makeroot(pool + n + ix2);
                cut(pool + edges[ix2].u);
                cut(pool + edges[ix2].v);
                del[ix2] = 1;
            }
            makeroot(pool + u);
            makeroot(pool + v);
            link(pool + u, pool + n + ix);
            link(pool + v, pool + n + ix);
            del[ix] = 0;
        }
        if (sz(que2[i])) {
            int u = que2[i][0].fi;
            int v = que2[i][0].se;
            int val;
            query(pool + u, pool + v, val);
            que[i].pb(val);
        }
    }
    divide(0, q, events, vi());
    FOR(i, 0, q + 1) if (sz(que[i])) {
        cout << res[i] << "\n";
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