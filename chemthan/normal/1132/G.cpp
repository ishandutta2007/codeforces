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

const int maxn = 1 << 20;
int n, k;
int a[maxn];

void chemthan() {
    cin >> n >> k;
    FOR(i, 0, n) cin >> a[i];
    RMQ<int, greater<int>> rmq;
    rmq.init(n);
    FOR(i, 0, n) rmq[i] = a[i];
    rmq.build();
    vector<vi> g(n);
    FOR(i, 0, n) {
        int lo = i, hi = n;
        while (lo < hi) {
            int mi = lo + hi >> 1;
            if (mi < i + 1 || rmq.query(i + 1, mi) <= a[i]) {
                lo = mi + 1;
            }
            else {
                hi = mi;
            }
        }
        int mi = lo + hi >> 1;
        if (mi < n) {
            g[mi].pb(i);
        }
    }
    vi dj(n), sum(n), f(n);
    FOR(u, 0, n) dj[u] = u;
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    auto join = [&] (set<pi>*& x, set<pi>*& y, int& sumx, int& sumy) {
        if (x->size() < y->size()) {
            swap(x, y);
            swap(sumx, sumy);
        }
        for (pi e : *y) {
            e.fi += sumy - sumx;
            x->insert(e);
            f[e.se] += sumy - sumx;
        }
        y->clear();
        delete y;
    };
    vector<set<pi>*> st(n);
    multiset<int> heap;
    vi rem(n);
    FOR(i, 0, n) {
        st[i] = new set<pi>();
        for (int j : g[i]) {
            if (st[j]->size()) {
                heap.erase(heap.find(st[j]->rbegin()->fi + sum[j]));
                dj[find(j)] = i;
                join(st[i], st[j], sum[i], sum[j]);
            }
        }
        sum[i]++;
        f[i] = 1 - sum[i], st[i]->insert(mp(f[i], i));
        heap.insert(st[i]->rbegin()->fi + sum[i]);
        if (k <= i) {
            int j = i - k;
            int u = find(j);
            heap.erase(heap.find(st[u]->rbegin()->fi + sum[u]));
            st[u]->erase(st[u]->find(mp(f[j], j)));
            if (st[u]->size()) {
                heap.insert(st[u]->rbegin()->fi + sum[u]);
            }
        }
        if (k - 1 <= i) {
            cout << *heap.rbegin() << " ";
        }
    }
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
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}