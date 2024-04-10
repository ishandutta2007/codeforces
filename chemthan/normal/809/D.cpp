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

const int MAXN = 6e5 + 5;
int ptr;
struct Node {
    Node *l, *r, *p;
    int size, key;
    int rev, lz;
    Node();
    void clear();
} mem[MAXN], *nil = mem + MAXN - 1;
Node::Node() {
    clear();
}
void Node::clear() {
    l = r = p = nil;
    size = 1, key = rev = lz = 0;
}
inline Node* newNode(int key) {
    mem[ptr].clear();
    mem[ptr].key = key;
    return mem + (ptr++);
}
inline void init() {
    ptr = 1;
    nil->l = nil->r = nil->p = nil;
    nil->size = 0;
}
inline void normalize(Node*& x) {if (!x) x = nil;}
inline int isrt(Node* x) {
    normalize(x);
    return x->p == nil || (x->p->l != x && x->p->r != x);
}
inline void setchild(Node* p, Node* c, int l) {
    normalize(p), normalize(c);
    c->p = p; l ? p->l = c : p->r = c;
}
inline void updatelz(Node* x, int val) {
    normalize(x);
    if (x == nil) return;
    x->lz += val;
    x->key += val;
}
inline void pushdown(Node* x) {
    normalize(x);
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
inline void pushup(Node* x) {
    normalize(x);
    if (x == nil) return;
    x->size = x->l->size + x->r->size + 1;
}
inline void rotate(Node* x) {
    normalize(x);
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
inline void splay(Node* x) {
    normalize(x);
    pushdown(x);
    while (!isrt(x)) {
        pushdown(x->p->p); pushdown(x->p); pushdown(x);
        if (!isrt(x->p)) rotate((x->p->l == x) == (x->p->p->l == x->p) ? x->p : x);
        rotate(x);
    }
    pushup(x);
}
inline void insert(Node*& x, int key) {
    normalize(x);
    Node* p = nil;
    while (x != nil) {
        pushdown(x);
        p = x;
        if (x->key < key) x = x->r;
        else x = x->l;
    }
    x = newNode(key);
    x->p = p;
    if (p != nil) {
        if (p->key < x->key) p->r = x;
        else p->l = x;
    }
    splay(x);
}
inline Node* findkey(Node*& x, int key) {
    normalize(x);
    Node* p = nil;
    while (x != nil) {
        p = x;
        pushdown(x);
        if (x->key < key) x = x->r;
        else if (key < x->key) x = x->l;
        else {
            splay(x);
            return x;
        }
    }
    x = p, splay(x);
    return nil;
}
inline Node* findpos(Node*& x, int pos) {
    normalize(x);
    Node* p = nil;
    while (x != nil) {
        p = x;
        pushdown(x);
        int k = x->l ? x->l->size + 1 : 1;
        if (pos == k) {
            splay(x);
            return x;
        }
        else if (pos < k) x = x->l;
        else {x = x->r; pos -= k;}
    }
    x = p, splay(x);
    return nil;
}
inline Node* join(Node* x, Node* y) {
    normalize(x), normalize(y);
    x->p = y->p = nil;
    if (x == nil) return y;
    if (y == nil) return x;
    pushdown(y);
    while (1) {
        pushdown(x);
        if (x->r == nil) break;
        x = x->r;
    }
    splay(x);
    setchild(x, y, 0);
    pushup(x);
    return x;
}
inline void erase(Node*& x, int key) {
    normalize(x);
    Node* y = findkey(x, key);
    y->l->p = y->r->p = nil;
    x = join(y->l, y->r);
}
inline void split(Node* x, int pos, Node*& l, Node*& r) {
    normalize(x);
    if (!pos) {l = nil; r = x; return;}
    Node* y = findpos(x, pos);
    if ((r = y->r) != nil) r->p = nil;
    if ((l = y) != nil) {l->r = nil; pushup(l);}
}
inline void split(Node* x, int l, int r, Node*& y, Node*& z, Node*& t) {
    normalize(x);
    split(x, l - 1, y, z);
    split(z, r - l + 1, z, t);
}
inline void reverse(Node*& rt, int l, int r) {
    normalize(rt);
    Node *x, *y, *z, *t;
    split(rt, r, t, z);
    split(t, l - 1, x, y);
    if (y) {
        swap(y->l, y->r);
        y->rev ^= 1;
    }
    rt = join(join(x, y), z);
}
inline void upd(Node*& rt, int l, int r, int val) {
    normalize(rt);
    Node *x, *y, *z;
    split(rt, l, r, x, y, z);
    updatelz(y, val);
    rt = join(join(x, y), z);
}

int getpos(Node*& x, int key) {
    int res = 0;
    Node* p = nil;
    while (x != nil) {
        p = x;
        pushdown(x);
        if (x->key < key) {
            res += x->l->size + 1;
            x = x->r;
        }
        else {
            x = x->l;
        }
    }
    x = p, splay(x);
    return res;
}

void work(Node*& rt, int x, int y, int l) {
    Node *a, *b, *c;
    split(rt, x, y, a, b, c);
    updatelz(b, 1);
    if (c != nil) {
        Node *d, *e;
        split(c, 1, d, e);
        c = e;
    }
    rt = join(a, join(newNode(l), join(b, c)));
}

void solve() {
    init();
    int n; cin >> n;
    Node* rt = nil;
    insert(rt, 0); FOR(i, 0, n) insert(rt, INF + i + 1);
    FOR(i, 0, n) {
        int l, r; cin >> l >> r;
        int x = getpos(rt, l) + 1;
        int y = getpos(rt, r);
        if (x <= y) {
            work(rt, x, y, l);
        }
        else {
            findpos(rt, x);
            chkmin(rt->key, l);
        }
    }
    FOR(i, 2, n + 2) {
        if (findpos(rt, i)->key > INF) {
            cout << i - 2 << "\n";
            return;
        }
    }
    cout << n << "\n";
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