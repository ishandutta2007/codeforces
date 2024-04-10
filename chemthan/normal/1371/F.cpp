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

template<class num_t> struct SegmentTree {
    struct node_t {
        num_t max[2];
        num_t pref[2];
        num_t suff[2];
        num_t pref2[2];
        num_t suff2[2];
        num_t lz;
        int size;
        node_t() {
            lz = 0;
            size = -1;
        }
    };
    int n;
    vector<node_t> st;
    void init(int n_) {
        n = n_;
        st.resize(n << 2);
    }
    node_t merge(node_t u, node_t v) {
        if (u.size == -1) return v;
        if (v.size == -1) return u;
        node_t c;
        FOR(i, 0, 2) {
            c.max[i] = max(u.max[i], v.max[i]);
            c.pref[i] = u.pref[i];
            c.suff[i] = v.suff[i];
            c.pref2[i] = u.pref2[i];
            c.suff2[i] = v.suff2[i];
        }
        FOR(i, 0, 2) {
            if (u.pref[i] == u.size) {
                c.pref[i] = u.pref[i] + v.pref[i];
            }
            if (v.suff[i] == v.size) {
                c.suff[i] = u.suff[i] + v.suff[i];
            }
            if (u.pref[i ^ 1] == u.size) {
                c.pref2[i] = u.pref[i ^ 1] + v.pref2[i];
            }
            if (v.suff[i ^ 1] == v.size) {
                c.suff2[i] = u.suff2[i] + v.suff[i ^ 1];
            }
            if (u.pref2[i] == u.size) {
                chkmax(c.pref2[i], u.pref2[i] + v.pref[i]);
            }
            if (v.suff2[i] == v.size) {
                chkmax(c.suff2[i], u.suff[i] + v.suff2[i]);
            }
        }
        FOR(i, 0, 2) {
            chkmax(c.pref2[i], c.pref[i]);
            chkmax(c.suff2[i], c.suff[i]);
        }
        FOR(i, 0, 2) {
            chkmax(c.max[i], c.pref[i]);
            chkmax(c.max[i], c.suff[i]);
            chkmax(c.max[i], c.pref2[i]);
            chkmax(c.max[i], c.suff2[i]);
            chkmax(c.max[i], u.suff[i] + v.pref2[i]);
            chkmax(c.max[i], u.suff2[i] + v.pref[i]);
        }
        c.size = u.size + v.size;
        return c;
    }
    void build(int p, int L, int R, vi& a) {
        if (L == R) {
            st[p].max[0] = st[p].max[1] = 1;
            FOR(i, 0, 2) {
                st[p].pref[i] = st[p].pref2[i] = (a[L] == i);
                st[p].suff[i] = st[p].suff2[i] = (a[R] != i);
            }
            st[p].size = 1;
            return;
        }
        build(p << 1, L, L + R >> 1, a);
        build(p << 1 | 1, (L + R >> 1) + 1, R, a);
        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }
    void push(int p, int L, int R) {
        if (st[p].lz) {
            swap(st[p].max[0], st[p].max[1]);
            swap(st[p].pref[0], st[p].pref[1]);
            swap(st[p].suff[0], st[p].suff[1]);
            swap(st[p].pref2[0], st[p].pref2[1]);
            swap(st[p].suff2[0], st[p].suff2[1]);
            if (L < R) {
                st[p << 1].lz ^= st[p].lz;
                st[p << 1 | 1].lz ^= st[p].lz;
            }
            st[p].lz = 0;
        }
    }
    void upd(int p, int l, int r, int L, int R, num_t val) {
        push(p, L, R);
        if (r < L || R < l) return;
        if (l <= L && R <= r) {
            st[p].lz = val;
            push(p, L, R);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }
    node_t query(int p, int l, int r, int L, int R) {
        push(p, L, R);
        if (r < L || R < l) return node_t();
        if (l <= L && R <= r) {
            return st[p];
        }
        return merge(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
    void upd(int l, int r, num_t val) {
        upd(1, l, r, 0, n - 1, val);
    }
    node_t query(int l, int r) {
        return query(1, l, r, 0, n - 1);
    }
};
SegmentTree<int> seg;

void chemthan() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vi a(n);
    FOR(i, 0, n) a[i] = s[i] == '>';
    seg.init(n);
    seg.build(1, 0, n - 1, a);
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        seg.upd(l, r, 1);
        cout << seg.query(l, r).max[0] << "\n";
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