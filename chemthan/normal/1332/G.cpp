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
const ld EPS = 1e-6;
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

template<class num_t, class cmp = less<num_t> >
struct RMQ {
    int n;
    vector<num_t> a;
    vector<vector<num_t> > f;

    inline num_t best(const num_t& a, const num_t& b) {
        if (cmp()(a, b)) return a;
        return b;
    }
    void init(int _n) {
        n = _n;
        int p = 1; while ((1 << p) < n) p++;
        a.resize(n), f.resize(p + 1);
        a.shrink_to_fit(), f.shrink_to_fit();
        for (int i = 0; i < (int) f.size(); i++) {
            f[i].resize(n);
        }
    }
    num_t& operator [] (int u) {
        assert(u < (int) a.size());
        return a[u];
    }
    void build() {
        for (int i = 0; i < n; i++) f[0][i] = a[i];
        for (int l = 0, k; (k = 1 << l) < n; l++) {
            for (int i = 0; i + k < n; i++) {
                f[l + 1][i] = best(f[l][i], f[l][i + k]);
            }
        }
    }
    num_t query(int a, int b) {
        assert(a <= b);
        int l = a == b ? 0 : __lg(b - a);
        return best(f[l][a], f[l][b - (1 << l) + 1]);
    }
};
RMQ<pi> min_rmq;
RMQ<pi, greater<pi>> max_rmq;

void chemthan() {
    int n, q; cin >> n >> q;
    vi a(n);
    min_rmq.init(n);
    max_rmq.init(n);
    FOR(i, 0, n) cin >> a[i], min_rmq[i] = max_rmq[i] = mp(a[i], i);
    min_rmq.build();
    max_rmq.build();
    vector<vii> que(n);
    FOR(i, 0, q) {
        int l, r; cin >> l >> r; l--, r--;
        que[r].pb({l, i});
    }
    auto find_min = [&] (int u, int s) {
        int lo = 0, hi = u;
        while (lo < hi) {
            int mi = lo + hi >> 1;
            if (min_rmq.query(mi, u - 1).fi + s <= a[u]) {
                lo = mi + 1;
            }
            else {
                hi = mi;
            }
        }
        return lo + hi >> 1;
    };
    auto find_max = [&] (int u, int s) {
        int lo = 0, hi = u;
        while (lo < hi) {
            int mi = lo + hi >> 1;
            if (a[u] + s <= max_rmq.query(mi, u - 1).fi) {
                lo = mi + 1;
            }
            else {
                hi = mi;
            }
        }
        return lo + hi >> 1;
    };
    vii st(n << 1);
    auto upd = [&] (int p, pi v) {
        for (st[p += n] = v; 1 < p; ) p >>= 1, st[p] = max(st[p << 1], st[p << 1 | 1]);
    };
    auto query = [&] (int l, int r) {
        pi res;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) chkmax(res, st[l++]);
            if (r & 1) chkmax(res, st[--r]);
        }
        return res;
    };
    vi f(n);
    set<int> mn_st, mx_st;
    set<int> mn_v, mx_v;
    set<int> all_v;
    vector<vi> g(n);
    vector<vi> res(q);
    FOR(i, 0, n) {
        int mn = find_min(i, 0);
        int mx = find_max(i, 0);
        while (sz(mn_st) && mn <= *mn_st.rbegin()) {
            int k = *mn_st.rbegin();
            if (++f[k] == 2) {
                all_v.insert(k);
            }
            mn_v.insert(k);
            mn_st.erase(k);
        }
        while (sz(mx_st) && mx <= *mx_st.rbegin()) {
            int k = *mx_st.rbegin();
            if (++f[k] == 2) {
                all_v.insert(k);
            }
            mx_v.insert(k);
            mx_st.erase(k);
        }
        mn_st.insert(i);
        mx_st.insert(i);
        int mn2 = find_min(i, 1);
        int mx2 = find_max(i, 1);
        while (sz(mn_v) && *mn_v.begin() < mn2) {
            int k = *mn_v.begin();
            mn_v.erase(k);
            int u = min_rmq.query(k, i).se;
            if (sz(g[k]) < 3) {
                g[k].clear();
                g[k] = {k, u, i};
                upd(k, mp(3, k));
            }
        }
        while (sz(mx_v) && *mx_v.begin() < mx2) {
            int k = *mx_v.begin();
            mx_v.erase(k);
            int v = max_rmq.query(k, i).se;
            if (sz(g[k]) < 3) {
                g[k].clear();
                g[k] = {k, v, i};
                upd(k, mp(3, k));
            }
        }
        while (sz(all_v) && *all_v.begin() < min(mn2, mx2)) {
            int k = *all_v.begin();
            all_v.erase(k);
            int u = min_rmq.query(k, i).se;
            int v = max_rmq.query(k, i).se;
            if (sz(g[k]) < 4) {
                g[k].clear();
                g[k] = {k, u, v, i};
                sort(all(g[k]));
                upd(k, mp(4, k));
            }
        }
        for (auto e : que[i]) {
            int l = e.fi;
            int ix = e.se;
            auto mx = query(l, i);
            if (mx.fi) {
                res[ix] = g[mx.se];
            }
        }
    }
    FOR(i, 0, q) {
        cout << sz(res[i]) << "\n";
        FOR(j, 0, sz(res[i])) cout << res[i][j] + 1 << " \n"[j == sz(res[i]) - 1];
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