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

struct num_t {
    pair<long long, long long> e;
    long long p, q;
    num_t(pair<long long, long long> e = {0, 0}, long long p = 0, long long q = 0) : e(e), p(p), q(q) {}
};
int operator < (num_t a, num_t b) {
    long long x = a.p / a.q;
    while (a.p < x * a.q) x--;
    long long y = b.p / b.q;
    while (b.p < y * b.q) y--;
    if (x ^ y) return x < y;
    a.p %= a.q, b.p %= b.q;
    return a.p * b.q - b.p * a.q < 0;
}

void chemthan() {
    int n, m; cin >> n >> m;
    set<pair<long long, long long>> st;
    set<num_t> heap;
    auto add = [&] (pair<long long, long long> a, pair<long long, long long> b) {
        num_t e(b, a.se - b.se, b.fi - a.fi);
        heap.insert(e);
    };
    auto rem = [&] (pair<long long, long long> a, pair<long long, long long> b) {
        num_t e(b, a.se - b.se, b.fi - a.fi);
        heap.erase(e);
    };
    auto rems = [&] (pair<long long, long long> e) {
        auto it = st.find(e);
        pair<long long, long long> cr = *it, pv = {-1, -1}, nx = {-1, -1};
        if (it != st.begin()) {
            pv = *(--it);
            rem(pv, cr);
            it++;
        }
        if ((++it) != st.end()) {
            nx = *it;
            rem(cr, nx);
        }
        if (pv != mp(-1LL, -1LL) && nx != mp(-1LL, -1LL)) {
            add(pv, nx);
        }
        st.erase(e);
    };
    long long sum = n, offx = 0, offy = 0;
    st.insert({0, 0});
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int k; cin >> k;
            st.clear(), heap.clear();
            sum += k, offx = offy = 0;
            st.insert({0, 0});
        }
        else if (op == 2) {
            int k; cin >> k;
            if (sz(st)) {
                add(*st.rbegin(), {sum, -(offx * sum + offy)});
            }
            st.insert({sum, -(offx * sum + offy)});
            sum += k;
        }
        else {
            int b, s; cin >> b >> s;
            offx += s, offy += b;
        }
        while (sz(heap) && (heap.begin()->p <= 0 || (offx && (heap.begin()->p + offx - 1) / offx <= heap.begin()->q))) {
            rems(heap.begin()->e);
        }
        cout << st.rbegin()->fi + 1 << " " << st.rbegin()->fi * offx + st.rbegin()->se + offy << "\n";
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