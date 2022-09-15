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

template<class T> struct SegmenTree {
    static const int MAXN = 1e5 + 5;
    T st[MAXN << 2];
    T lz[MAXN << 2];
    void pushdown(int node, int L, int R) {
        if (lz[node]) {
            st[node] += (R - L + 1) * lz[node];
            if (L < R) {
                lz[node << 1] += lz[node];
                lz[node << 1 | 1] += lz[node];
            }
            lz[node] = 0;
        }
    }
    void upd(int node, int l, int r, int L, int R, T val) {
        pushdown(node, L, R);
        if (l > R || r < L) return;
        if (l <= L && r >= R) {
            lz[node] = val;
            pushdown(node, L, R);
            return;
        }
        upd(node << 1, l, r, L, L + R >> 1, val);
        upd(node << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        st[node] = st[node << 1] + st[node << 1 | 1];
    }
    T query(int node, int l, int r, int L, int R) {
        pushdown(node, L, R);
        if (l > R || r < L) return 0;
        if (l <= L && r >= R) return st[node];
        return query(node << 1, l, r, L, L + R >> 1) + query(node << 1 | 1, l, r, (L + R >> 1) + 1, R);
    }
};
SegmenTree<long long> seg;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class const_node_iterator, class node_iterator, class cmp, class allocator> struct node_update {
    public:
        typedef typename node_iterator::value_type iterator;
        struct metadata_type {
            long long sum;
            metadata_type() : sum(0) {}
        };
        long long calc(int key) {
            node_iterator it = node_begin();
            const_node_iterator end = node_end();
            long long res = 0;
            while (it != end) {
                if (cmp()(**it, mp(key, INF))) {
                    res += (**it).se;
                    if (it.get_l_child() != end) {
                        res += it.get_l_child().get_metadata().sum;
                    }
                    it = it.get_r_child();
                }
                else {
                    it = it.get_l_child();
                }
            }
            return res;
        }
    protected:
        inline void operator() (node_iterator it, const_node_iterator end) {
            metadata_type val;
            val.sum = (**it).se;
            if (it.get_l_child() != end) {
                val.sum += it.get_l_child().get_metadata().sum;
            }
            if (it.get_r_child() != end) {
                val.sum += it.get_r_child().get_metadata().sum;
            }
            (metadata_type&) it.get_metadata() = val;
        }
        virtual const_node_iterator node_begin() const = 0;
        virtual const_node_iterator node_end() const = 0;
        virtual iterator end() const = 0;
};

typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, node_update> ordered_set;

const int maxn = 1e5 + 5;
int n, q;
int a[maxn];
set<int> g[maxn];

ordered_set fen[maxn];

void add(int p, int val) {
    int t = p;
    p++;
    for (; p < maxn; p += p & -p) {
        fen[p].insert(mp(val, val - t));
    }
}

void rem(int p, int val) {
    int t = p;
    p++;
    for (; p < maxn; p += p & -p) {
        fen[p].erase(mp(val, val - t));
    }
}

long long query(ordered_set& st, int l, int r) {
    return st.calc(r) - st.calc(l - 1);
}

long long query(int p, int l, int r) {
    p++;
    long long res = 0;
    for (; p > 0; p -= p & -p) {
        res += query(fen[p], l, r);
    }
    return res;
}

void rem(int pv, int cr, int nt) {
    if (~pv) {
        seg.upd(1, cr, cr, 0, n - 1, -(cr - pv));
        rem(pv, cr);
    }
    if (nt < n) {
        seg.upd(1, nt, nt, 0, n - 1, -(nt - cr));
        rem(cr, nt);
    }
    if (~pv && nt < n) {
        seg.upd(1, nt, nt, 0, n - 1, nt - pv);
        add(pv, nt);
    }
}

void add(int pv, int cr, int nt) {
    if (~pv && nt < n) {
        seg.upd(1, nt, nt, 0, n - 1, -(nt - pv));
        rem(pv, nt);
    }
    if (~pv) {
        seg.upd(1, cr, cr, 0, n - 1, cr - pv);
        add(pv, cr);
    }
    if (nt < n) {
        seg.upd(1, nt, nt, 0, n - 1, nt - cr);
        add(cr, nt);
    }
}

void solve() {
    cin >> n >> q;
    FOR(i, 0, n) {
        cin >> a[i];
        g[a[i]].insert(i);
    }
    FOR(i, 0, maxn) {
        int prv = -1;
        FORall(it, g[i]) {
            int cur = *it;
            if (~prv) {
                add(prv, cur);
                seg.upd(1, cur, cur, 0, n - 1, cur - prv);
            }
            prv = cur;
        }
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int u, v; cin >> u >> v; u--;
            set<int>::iterator it = g[a[u]].find(u);
            int pv = -1, nt = n;
            if (it != g[a[u]].begin()) {
                it--;
                pv = *it;
                it++;
            }
            if (++it != g[a[u]].end()) {
                nt = *it;
            }
            rem(pv, u, nt);
            g[a[u]].erase(u);
            a[u] = v;
            g[a[u]].insert(u);
            it = g[a[u]].find(u);
            pv = -1, nt = n;
            if (it != g[a[u]].begin()) {
                it--;
                pv = *it;
                it++;
            }
            if (++it != g[a[u]].end()) {
                nt = *it;
            }
            add(pv, u, nt);
        }
        else {
            int l, r; cin >> l >> r; l--, r--;
            cout << seg.query(1, l, r, 0, n - 1) - query(l - 1, l, r) << "\n";
        }
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