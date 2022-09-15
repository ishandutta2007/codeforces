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

template<typename num_t>
struct node_t {
    node_t *l, *r;
    int h, size, rev;
    num_t key, lz;
    node_t(num_t key, node_t* l = 0, node_t* r = 0, int h = rand()) : key(key), l(0), r(0), h(h) {
        size = (l ? l->size : 0) + 1 + (r ? r->size : 0);
        rev = lz = 0;
    }
};

template<typename num_t>
int size(node_t<num_t>* x) {
    return x ? x->size : 0;
}
template<typename num_t>
void pull(node_t<num_t>* x) {
    x->size = size(x->l) + 1 + size(x->r);
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
        if (u) u->key ^= x->lz, u->lz ^= x->lz;
        if (v) v->key ^= x->lz, v->lz ^= x->lz;
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
    y->lz ^= val;
    y->key ^= val;
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
void insert(node_t<num_t>*& x, num_t key) {
    node_t<num_t>* y;
    split<num_t>(x, x, y, [&] (node_t<num_t>* x) {
            return x->key < key;
            }
            );
    x = join(x, join(new node_t<num_t>(key), y));
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
void free(node_t<num_t>*& x) {
    if (!x) return;
    free(x->l);
    free(x->r);
    delete x;
    x = 0;
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
    cerr << "(" << x->key << ") ";
    trace(x->r, 0);
    if (isrt) {
        cerr << "\n";
    }
}

template<typename num_t> int query(node_t<num_t>*& rt, int k) {
    node_t<num_t> *x, *y, *z;
    split(rt, x, y, z, k, k);
    int res = y->key;
    rt = join(x, join(y, z));
    return res;
}

void chemthan() {
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        string sa, sb;
        cin >> sa >> sb;
        vi a(n), b(n);
        FOR(i, 0, n) a[i] = sa[i] - '0', b[i] = sb[i] - '0';
        node_t<int>* rt = 0;
        FOR(i, 0, n) {
            rt = join(rt, new node_t<int>(a[i]));
        }
        vi res;
        FORd(i, n, 0) {
            int x = query(rt, 0);
            int y = query(rt, i);
            if (y != b[i]) {
                if (x == y) {
                    res.pb(i + 1);
                    reverse(rt, 0, i);
                    upd(rt, 0, i, 1);
                }
                else {
                    res.pb(1);
                    upd(rt, 0, 0, 1);
                    res.pb(i + 1);
                    reverse(rt, 0, i);
                    upd(rt, 0, i, 1);
                }
            }
        }
        cout << sz(res);
        FOR(i, 0, sz(res)) cout << " " << res[i];
        cout << "\n";
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