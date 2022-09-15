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

struct Node {
    Node();
    Node *l, *r, *p;
    int size, key, cnt;
    int rev, lz;
};
Node* nil = new Node();
Node::Node() {
    l = r = p = nil;
    size = cnt = 1;
    key = rev = lz = 0;
}
void init() {
    nil->l = nil->r = nil->p = nil;
    nil->size = nil->cnt = 0;
}
int isrt(Node* x) {
    return x->p == nil || (x->p->l != x && x->p->r != x);
}
void setchild(Node* p, Node* c, int l) {
    c->p = p; l ? p->l = c : p->r = c;
}
void updatelz(Node* x, int val) {
    if (x == nil) return;
    x->lz += val;
    x->cnt += val;
}
void pushdown(Node* x) {
    if (x == nil) return;
    Node *u = x->l, *v = x->r;
    if (x->rev) {
        if (u != nil) {swap(u->l, u->r); u->rev ^= 1;}
        if (v != nil) {swap(v->l, v->r); v->rev ^= 1;}
        x->rev = 0;
    }
    if (x->lz) {
        if (u != nil) updatelz(u, x->lz);
        if (v != nil) updatelz(v, x->lz);
        x->lz = 0;
    }
}
void pushup(Node* x) {
    x->size = x->l->size + x->r->size + 1;
}
void rotate(Node* x) {
    Node* y = x->p;
    int l = x->p->l == x;
    if (!isrt(y)) {
        setchild(y->p, x, y->p->l == y);
    }
    else {
        x->p = y->p;
    }
    setchild(y, l ? x->r : x->l, l);
    setchild(x, y, !l);
    pushup(y);
}
void splay(Node* x) {
    pushdown(x);
    while (!isrt(x)) {
        pushdown(x->p->p); pushdown(x->p); pushdown(x);
        if (!isrt(x->p)) rotate((x->p->l == x) == (x->p->p->l == x->p) ? x->p : x);
        rotate(x);
    }
    pushup(x);
}
Node* access(Node* x) {
    Node* z = nil;
    for (Node* y = x; y != nil; y = y->p) {
        splay(y);
        y->r = z;
        pushup(z = y);
    }
    splay(x);
    return z;
}
void link(Node* x, Node* y) {
    access(y); access(x);
    y->cnt += x->cnt;
    updatelz(y->l, x->cnt);
    x->p = y;
    access(x);
}
void cut(Node* x) {
    access(x);
    x->l->p = nil;
    updatelz(x->l, -x->cnt);
    x->l = nil;
    pushup(x);
}
Node* findroot(Node* x) {
    access(x);
    while (x->l != nil) pushdown(x), x = x->l;
    splay(x);
    return x;
}
Node* lca(Node* x, Node* y) {
    if (findroot(x) != findroot(y)) return nil;
    access(x);
    return access(y);
}
void makeroot(Node* x) {
    access(x);
    swap(x->l, x->r);
    x->rev ^= 1;
}
int connected(Node* x, Node* y) {
    if (x == y) return 1;
    access(x); access(y);
    return x->p != nil;
}

const int maxn = 1e5 + 5;
const int logn = 20;
int n, q;
vi adj[maxn];
int lev[maxn];
int p[logn][maxn];
Node node[maxn];

void dfs(int u) {
    FOR(i, 1, logn) {
        p[i][u] = p[i - 1][p[i - 1][u]];
    }
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        lev[v] = lev[u] + 1;
        p[0][v] = u;
        dfs(v);
    }
}

int lca(int u, int v) {
    if (lev[u] < lev[v]) swap(u, v);
    FORd(i, logn, 0) {
        if (lev[p[i][u]] >= lev[v]) {
            u = p[i][u];
        }
    }
    if (u == v) return u;
    FORd(i, logn, 0) {
        if (p[i][u] != p[i][v]) {
            u = p[i][u];
            v = p[i][v];
        }
    }
    return p[0][u];
}

int dist(int u, int v) {
    int a = lca(u, v);
    return lev[u] + lev[v] - lev[a] - lev[a];
}

void solve() {
    init();
    cin >> n >> q;
    FOR(i, 1, n + 1) node[i].key = i;
    FOR(i, 1, n) {
        int p; cin >> p; p--;
        adj[p].pb(i);
        link(node + i + 1, node + p + 1);
    }
    dfs(0);
    while (q--) {
        int ar[3]; FOR(i, 0, 3) cin >> ar[i], ar[i]--;
        int res = 0;
        FOR(i, 0, 3) {
            swap(ar[0], ar[i]);
            makeroot(node + ar[0] + 1);
            int w = lca(node + ar[1] + 1, node + ar[2] + 1)->key - 1;
            chkmax(res, dist(ar[0], w) + 1);
        }
        cout << res << "\n";
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