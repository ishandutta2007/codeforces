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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class const_node_iterator, class node_iterator, class cmp, class allocator> struct node_update {
    public:
        typedef typename node_iterator::value_type iterator;
        struct metadata_type {
            int mx;
            metadata_type() : mx(0) {}
        };
        int order_of_key(int key) {
            node_iterator it = node_begin();
            const_node_iterator end = node_end();
            int res = 0;
            while (it != end) {
                if (cmp()(**it, mp(key, -INF))) {
                    chkmax(res, (**it).se);
                    if (it.get_l_child() != end) {
                        chkmax(res, it.get_l_child().get_metadata().mx);
                    }
                    it = it.get_r_child();
                }
                else {
                    it = it.get_l_child();
                }
            }
            return res;
        }
        iterator find_by_order(int pos) {
            pos++;
            node_iterator it = node_begin();
            const_node_iterator it_end = node_end();
            while (it != it_end) {
                int sz = 1;
                if (it.get_l_child() != it_end) {
                    sz += it.get_l_child().get_metadata().size;
                }
                if (sz == pos) {
                    return *it;
                }
                else if (sz > pos) {
                    it = it.get_l_child();
                }
                else {
                    pos -= sz;
                    it = it.get_r_child();
                }
            }
            return end();
        }
    protected:
        inline void operator() (node_iterator it, const_node_iterator end) {
            metadata_type val;
            if (it.get_l_child() != end) {
                val.mx = it.get_l_child().get_metadata().mx;
            }
            val.mx = max(val.mx, (**it).se);
            if (it.get_r_child() != end) {
                val.mx = max(val.mx, it.get_r_child().get_metadata().mx);
            }
            (metadata_type&) it.get_metadata() = val;
        }
        virtual const_node_iterator node_begin() const = 0;
        virtual const_node_iterator node_end() const = 0;
        virtual iterator end() const = 0;
};

typedef tree<pi, null_type, less<pi>, rb_tree_tag, node_update> set_t;

const int maxn = 1e5 + 5;
int n, m;
vector<pair<int, pi> > edges;
set_t f[maxn];

void chemthan() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        edges.pb(mp(w, mp(u, v)));
    }
    int res = 0;
    for (auto it : edges) {
        int u = it.se.fi;
        int v = it.se.se;
        int w = it.fi;
        int k = f[u].order_of_key(w) + 1;
        f[v].insert(mp(w, k));
        chkmax(res, k);
    }
    cout << res << "\n";
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