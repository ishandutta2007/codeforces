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

const int maxc = 62;
struct node_t {
    node_t *p, *l, *r;
    int key, size;
    node_t* mx[maxc];
    node_t(int key) : p(0), l(0), r(0), key(key), size(1) {
        FOR(i, 0, maxc) mx[i] = 0;
        mx[key] = this;
    }
};

int size(node_t* x) {
    return x ? x->size : 0;
}

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
}

void pull(node_t* x) {
    x->size = size(x->l) + 1 + size(x->r);
    FOR(i, 0, maxc) {
        x->mx[i] = 0;
    }
    x->mx[x->key] = x;
    FOR(i, 0, maxc) {
        if (x->l) {
            chkmax(x->mx[i], x->l->mx[i]);
        }
        if (x->r) {
            chkmax(x->mx[i], x->r->mx[i]);
        }
    }
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

node_t* join(node_t* x, node_t* y) {
    if (!x) return y;
    while (x->r) push(x), x = x->r;
    push(x);
    setchild(y, x, 0);
    return splay(x);
}

void split(node_t* t, node_t*& x, node_t*& y, int pos) {
    if (pos < 0) {
    	x = 0, y = t;
        return;
    }
    if (pos == size(t) - 1) {
        x = t, y = 0;
        return;
    }
    while (size(t->l) != pos) {
        push(t);
        if (size(t->l) > pos) {
            t = t->l;
        }
        else {
            pos -= size(t->l) + 1;
            t = t->r;
        }
    }
    splay(t);
    x = t;
    y = x->r;
    x->r = y->p = 0;
    pull(x);
}

void split(node_t* t, node_t*& x, node_t*& y, node_t*& z, int l, int r) {
    split(t, x, y, l - 1), split(y, y, z, r - l);
}

map<char, int> hs;
char rb[maxc];

void trace(node_t* x) {
    if (!x) return;
    push(x);
    trace(x->l);
    cout << char(rb[x->key]);
    trace(x->r);
}

void solve() {
    int ptr = 0;
    FOR(i, 'a', 'z' + 1) hs[i] = ptr++, rb[ptr - 1] = i;
    FOR(i, 'A', 'Z' + 1) hs[i] = ptr++, rb[ptr - 1] = i;
    FOR(i, '0', '9' + 1) hs[i] = ptr++, rb[ptr - 1] = i;
    int n, m; cin >> n >> m;
    string s; cin >> s;
    node_t* rt = 0;
    FOR(i, 0, sz(s)) {
        int c = s[i];
        node_t* x = new node_t(hs[c]);
        rt = join(rt, x);
    }
    while (m--) {
        int l, r; char c; cin >> l >> r >> c; l--, r--;
        int ic = hs[c];
        node_t *x, *y, *z;
        split(rt, x, y, z, l, r);
        while (y && y->mx[ic]) {
            node_t* w = y->mx[ic];
            splay(w);
            if (w->l) w->l->p = 0;
            if (w->r) w->r->p = 0;
            y = join(w->l, w->r);
        }
        rt = join(x, join(y, z));
    }
    trace(rt);
    cout << "\n";
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