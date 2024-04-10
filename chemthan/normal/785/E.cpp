#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << x << "\n";

const int MAXN = 2e7 + 5;
int ptr;
struct Node {
    Node *l, *r, *p;
    int size, key;
    Node();
    void clear();
} mem[MAXN], *nil = (mem + ptr++);

Node::Node() {
    clear();
}
void Node::clear() {
    l = r = p = nil;
    size = 1, key = 0;
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
inline void pushup(Node* x) {
    normalize(x);
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
    while (!isrt(x)) {
        if (!isrt(x->p)) rotate((x->p->l == x) == (x->p->p->l == x->p) ? x->p : x);
        rotate(x);
    }
    pushup(x);
}
inline void insert(Node*& x, int key) {
    normalize(x);
    Node* p = nil;
    while (x != nil) {
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
    while (x != nil) {
        if (x->key < key) x = x->r;
        else if (key < x->key) x = x->l;
        else {
            splay(x);
            return x;
        }
    }
    return nil;
}
inline Node* join(Node* x, Node* y) {
    normalize(x), normalize(y);
    x->p = y->p = nil;
    if (x == nil) return y;
    if (y == nil) return x;
    while (1) {
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
inline int query(Node*& x, int key) {
    normalize(x);
    insert(x, key);
    int res = x->r->size;
    x->l->p = x->r->p = nil;
    x = join(x->l, x->r);
    return res;
}

const int maxn = 2e5 + 5;
int n, q;
int a[maxn];

Node* fen[maxn];
void add(int p, int val) {
    p++;
    for (; p < maxn; p += p & -p) {
        insert(fen[p], val);
    }
}
void rem(int p, int val) {
    p++;
    for (; p < maxn; p += p & -p) {
        erase(fen[p], val);
    }
}
int query(int p, int val) {
    p++;
    int res = 0;
    for (; p > 0; p -= p & -p) {
        res += query(fen[p], val);
    }
    return res;
}

void solve() {
    init();
    cin >> n >> q;
    FOR(i, 0, n) {
        a[i] = i;
        add(i, a[i]);
    }
    long long ans = 0;
    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        if (u > v) swap(u, v);
        if (u < v) {
            rem(u, a[u]);
            rem(v, a[v]);
            int l = u + 1, r = v - 1;
            if (l <= r) {
                int x = query(r, a[u]) - query(l - 1, a[u]);
                int y = r - l + 1 - x;
                ans += x;
                ans -= y;
                x = query(r, a[v]) - query(l - 1, a[v]);
                y = r - l + 1 - x;
                ans -= x;
                ans += y;
            }
            if (a[u] < a[v]) {
                ans++;
            }
            else {
                ans--;
            }
            swap(a[u], a[v]);
            add(u, a[u]);
            add(v, a[v]);
        }
        cout << ans << "\n";
    }
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif
    solve();
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}