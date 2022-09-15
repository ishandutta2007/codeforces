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
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

template<typename num_t>
struct node_t {
    node_t *p, *l, *r;
    int size;
    num_t key;
    node_t(int key) : p(0), l(0), r(0), key(key), size(1) {}
};

template<typename num_t>
int size(node_t<num_t>* x) {
    return x ? x->size : 0;
}
template<typename num_t>
int isrt(node_t<num_t>* x) {
    return !(x->p) || (x->p->l != x && x->p->r != x);
}
template<typename num_t>
int left(node_t<num_t>* x) {
    return x->p->l == x;
}
template<typename num_t>
void setchild(node_t<num_t>* x, node_t<num_t>* p, int l) {
    (l ? p->l : p->r) = x;
    if (x) x->p = p;
}
template<typename num_t>
void push(node_t<num_t>* x) {
}
template<typename num_t>
void pull(node_t<num_t>* x) {
    x->size = size(x->l) + 1 + size(x->r);
}
template<typename num_t>
void rotate(node_t<num_t>* x) {
    node_t<num_t> *p = x->p, *g = p->p;
    int l = left(x);
    setchild(l ? x->r : x->l, p, l);
    if (!isrt(p)) setchild(x, g, left(p));
    else x->p = g;
    setchild(p, x, !l);
    pull(p);
}
template<typename num_t>
node_t<num_t>* splay(node_t<num_t>* x) {
    push(x);
    while (!isrt(x)) {
        node_t<num_t> *p = x->p, *g = p->p;
        if (g) push(g);
        push(p), push(x);
        if (!isrt(p)) rotate(left(x) != left(p) ? x : p);
        rotate(x);
    }
    pull(x);
    return x;
}
template<typename num_t>
node_t<num_t>* join(node_t<num_t>* x, node_t<num_t>* y) {
    if (!x) return y;
    while (x->r) push(x), x = x->r;
    push(x);
    setchild(y, x, 0);
    return splay(x);
}
template<typename num_t>
void split(node_t<num_t>* t, node_t<num_t>*& x, node_t<num_t>*& y, int pos) {
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
template<typename num_t>
void split(node_t<num_t>* t, node_t<num_t>*& x, node_t<num_t>*& y, node_t<num_t>*& z, int l, int r) {
    split(t, x, y, l - 1), split(y, y, z, r - l);
}
template<typename num_t>
void trace(node_t<num_t>* x, vector<int>& poly) {
    if (!x) return;
    push(x);
    trace(x->l, poly);
    poly.push_back(x->key);
    trace(x->r, poly);
}

int get_size(node_t<int>* x, node_t<int>*& rt) {
    splay(rt = x);
    return size(x->l) + 1;
}

void chemthan() {
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<tuple<int, int, int>> triples;
        vector<vi> adj(n);
        vi d(n);
        FOR(i, 0, n - 2) {
            int u, v, w; cin >> u >> v >> w; u--, v--, w--;
            triples.pb({u, v, w});
            d[u]++, d[v]++, d[w]++;
            adj[u].pb(i);
            adj[v].pb(i);
            adj[w].pb(i);
        }
        queue<int> que;
        vi used(n), used2(n);
        vi vals;
        FOR(i, 0, n) if (d[i] == 1) {
            que.push(i);
            used2[i] = 1;
        }
        while (sz(que)) {
            int uu = que.front(); que.pop();
            if (d[uu] != 1) continue;
            for (int ix : adj[uu]) {
                if (!used[ix]) {
                    used[ix] = 1;
                    vals.pb(ix);
                    if (get<0>(triples[ix]) == uu) {
                        swap(get<0>(triples[ix]), get<1>(triples[ix]));
                    }
                    if (get<2>(triples[ix]) == uu) {
                        swap(get<2>(triples[ix]), get<1>(triples[ix]));
                    }
                    int u, v, w; tie(u, v, w) = triples[ix];
                    d[u]--, d[v]--, d[w]--;
                    if (d[u] == 1 && !used2[u]) {
                        used2[u] = 1;
                        que.push(u);
                    }
                    if (d[w] == 1 && !used2[w]) {
                        used2[w] = 1;
                        que.push(w);
                    }
                    break;
                }
            }
        }
        node_t<int>* rt = 0;
        vector<node_t<int>*> f(n);
        for (int i = 0; i < n; i++) {
            f[i] = new node_t<int>(i);
        }
        reverse(all(vals));
        for (int& x : used) x = 0;
        for (int ix : vals) {
            int u, v, w; tie(u, v, w) = triples[ix];
            if (!rt) {
                rt = join(rt, f[u]);
                rt = join(rt, f[v]);
                rt = join(rt, f[w]);
                used[u] = used[v] = used[w] = 1;
            }
            else {
                for (int t : {u, v, w}) {
                    if (!used[t]) {
                        used[t] = 1;
                        vi x;
                        for (int tt : {u, v, w}) {
                            if (tt ^ t) {
                                x.pb(tt);
                            }
                        }
                        int uu = x[0], vv = x[1];
                        assert(used[uu] && used[vv]);
                        int k = get_size(f[uu], rt);
                        int l = get_size(f[vv], rt);
                        if (l < k) swap(k, l);
                        if (k + 1 == l) {
                            node_t<int> *l, *r;
                            split(rt, l, r, k - 1);
                            rt = join(l, join(f[t], r));
                        }
                        else {
                            rt = join(rt, f[t]);
                        }
                        break;
                    }
                }
            }
        }
        vector<int> poly;
        trace(rt, poly);
        FOR(i, 0, n) cout << poly[i] + 1 << " \n"[i == n - 1];
        reverse(all(vals));
        FOR(i, 0, n - 2) cout << vals[i] + 1 << " \n"[i == n - 3];
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