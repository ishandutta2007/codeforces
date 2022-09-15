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

template<typename num_t>
struct node_t {
    node_t *l, *r;
    int h, size, rev;
    num_t key, lz;
    num_t s, ss, mn;
    node_t<num_t> *first_node, *last_node;
    node_t(num_t key, num_t s, node_t* l = 0, node_t* r = 0, int h = rand()) : key(key), s(s), ss(0), mn(0), l(0), r(0), h(h) {
        size = (l ? l->size : 0) + 1 + (r ? r->size : 0);
        rev = lz = 0;
        first_node = last_node = this;
    }
};

template<typename num_t>
int size(node_t<num_t>* x) {
    return x ? x->size : 0;
}
template<typename num_t>
void pull(node_t<num_t>* x) {
    x->size = size(x->l) + 1 + size(x->r);
    x->first_node = x->last_node = x;
    x->ss = 0;
    x->mn = 1e18;
    if (x->l) {
        x->first_node = x->l->first_node;
        x->ss += x->l->ss;
        x->ss += x->l->last_node->s * (x->key - x->l->last_node->key);
        chkmin(x->mn, x->l->mn);
    }
    chkmin(x->mn, x->ss);
    if (x->r) {
        x->last_node = x->r->last_node;
        x->ss += x->s * (x->r->first_node->key - x->key);
        chkmin(x->mn, x->ss + x->r->mn);
        x->ss += x->r->ss;
    }
}
template<typename num_t>
void push(node_t<num_t>* x) {
    node_t<num_t>* u = x->l;
    node_t<num_t>* v = x->r;
    if (x->rev) {
        if (u) swap(u->l, u->r), u->rev ^= 1;
        if (v) swap(v->l, v->r), v->rev ^= 1;
        x->rev = 0;
    }
    if (x->lz) {
        if (u) u->key += x->lz, u->lz += x->lz;
        if (v) v->key += x->lz, v->lz += x->lz;
        x->lz = 0;
    }
}
template<typename num_t>
node_t<num_t>* join(node_t<num_t>* x, node_t<num_t>* y) {
    if (!x) return y;
    if (!y) return x;
    if (x->h < y->h) {
        push(x);
        x->r = join(x->r, y);
        pull(x);
        return x;
    }
    push(y);
    y->l = join(x, y->l);
    pull(y);
    return y;
}
template<typename num_t>
void split(node_t<num_t>* x, node_t<num_t>*& l, node_t<num_t>*& r, int pos) {
    if (!x) {
        l = r = 0;
        return;
    }
    push(x);
    if (size(x->l) + 1 <= pos) {
        split(x->r, x->r, r, pos - size(x->l) - 1);
        pull(l = x);
    }
    else {
        split(x->l, l, x->l, pos);
        pull(r = x);
    }
}
template<typename num_t>
void split(node_t<num_t>* t, node_t<num_t>*& x, node_t<num_t>*& y, node_t<num_t>*& z, int l, int r) {
    split(t, x, y, l);
    split(y, y, z, r - l + 1);
}
template<typename num_t>
void reverse(node_t<num_t>*& x, int l, int r) {
    node_t<num_t> *y, *z;
    split(x, x, y, z, l, r);
    y->rev ^= 1;
    swap(y->l, y->r);
    x = join(x, join(y, z));
}
template<typename num_t>
void upd(node_t<num_t>*& x, int l, int r, num_t val) {
    node_t<num_t> *y, *z;
    split(x, x, y, z, l, r);
    y->lz += val;
    y->key += val;
    x = join(x, join(y, z));
}
template<typename num_t>
void split(node_t<num_t>* x, node_t<num_t>*& l, node_t<num_t>*& r, const function<bool(node_t<num_t>*)>& go_right) {
    if (!x) {
        l = r = 0;
        return;
    }
    push(x);
    if (go_right(x)) {
        split(x->r, x->r, r, go_right);
        pull(l = x);
    }
    else {
        split(x->l, l, x->l, go_right);
        pull(r = x);
    }
}
template<typename num_t>
void insert(node_t<num_t>*& x, num_t key, num_t s) {
    node_t<num_t>* y;
    split<num_t>(x, x, y, [&] (node_t<num_t>* x) {
            return x->key < key;
            }
            );
    x = join(x, join(new node_t<num_t>(key, s), y));
}
template<typename num_t>
node_t<num_t>* erase(node_t<num_t>*& x, num_t key) {
    node_t<num_t> *l, *r, *res;
    split<num_t>(x, l, res, [&] (node_t<num_t>* x) {
            return x->key < key;
            }
            );
    split<num_t>(res, res, r, [&] (node_t<num_t>* x) {
            return x->key <= key;
            }
            );
    x = join(l, r);
    return res;
}
template<typename num_t>
void free(node_t<num_t>* x) {
    if (!x) return;
    free(x->l);
    free(x->r);
    delete x;
}
template<typename num_t>
int depth(node_t<num_t>* x) {
    if (!x) return 0;
    push(x);
    return 1 + max(depth(x->l), depth(x->r));
}
template<typename num_t>
void trace(node_t<num_t>* x, int isrt = 1) {
    if (!x) return;
    push(x);
    trace(x->l, 0);
    cerr << "(" << x->key << ", " << x->s << ", " << x->ss << ") ";
    trace(x->r, 0);
    if (isrt) {
        cerr << "\n";
    }
}
template<typename num_t>
long double query(node_t<num_t>* x, num_t val, node_t<num_t>* prv) {
    node_t<num_t>* r = x->r;
    x->r = 0;
    pull(x);
    num_t ss = x->ss;
    x->r = r;
    pull(x);
    if (x->l && x->l->mn + val <= 0) {
        return query(x->l, val, prv);
    }
    if (ss + val <= 0) {
        if (x->l) prv = x->l->last_node;
        return x->key - (long double) (ss + val) / prv->s;
    }
    if (x->r) {
        return query(x->r, val + ss + x->s * (x->r->first_node->key - x->key), x);
    }
    return -1;
}

const int maxn = 1e5 + 5;
int q;

void chemthan() {
    node_t<long long>* rt = 0;
    cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            long long t, s; cin >> t >> s;
            insert(rt, t, s);
        }
        else if (op == 2) {
            long long t; cin >> t;
            assert(erase(rt, t));
        }
        else {
            long long l, r, v; cin >> l >> r >> v;
            if (!v) {
                cout << l << "\n";
                continue;
            }
            node_t<long long> *x, *y;
            split<long long>(rt, x, rt, [&] (node_t<long long>* t) {
                    return t->key < l;
                    }
                    );
            split<long long>(rt, rt, y, [&] (node_t<long long>* t) {
                    return t->key <= r;
                    }
                    );
            int fl = 0, fr = 0;
            if (!rt || l < rt->first_node->key) {
                insert<long long>(rt, l, 0);
                fl = 1;
            }
            if (!rt || rt->last_node->key < r) {
                insert<long long>(rt, r, 0);
                fr = 1;
            }
            long double res = query<long long>(rt, v, 0);
            if (fl) {
                erase(rt, l);
            }
            if (fr) {
                erase(rt, r);
            }
            if (res == -1) {
                cout << -1 << "\n";
            }
            else {
                cout << prec(9) << res << "\n";
            }
            rt = join(x, join(rt, y));
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