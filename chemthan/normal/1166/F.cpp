#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
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

void chemthan() {
    int n, m, c, q; cin >> n >> m >> c >> q;
    vi dj(n);
    vector<set<int>*> st(n);
    FOR(i, 0, n) dj[i] = i, st[i] = new set<int>(), st[i]->insert(i);
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    auto merge = [&] (set<int>*& a, set<int>*& b) {
        if (a->size() < b->size()) {
            swap(a, b);
        }
        for (int x : *b) {
            a->insert(x);
        }
        b->clear();
        delete b;
    };
    auto join = [&] (int u, int v) {
        u = find(u), v = find(v);
        if (u ^ v) {
            dj[u] = v;
            merge(st[v], st[u]);
        }
    };
    map<pi, int> hs;
    vector<tuple<int, int, int>> edges;
    FOR(i, 0, m) {
        int x, y, z; cin >> x >> y >> z; x--, y--;
        st[x]->insert(y);
        st[y]->insert(x);
        edges.pb(make_tuple(x, y, z));
    }
    FOR(i, 0, m) {
        int x, y, z; tie(x, y, z) = edges[i];
        FOR(it, 0, 2) {
            if (!hs.count(mp(z, x))) {
                hs[mp(z, x)] = y;
            }
            else {
                join(y, hs[mp(z, x)]);
            }
            swap(x, y);
        }
    }
    while (q--) {
        string op; cin >> op;
        if (op == "+") {
            int x, y, z; cin >> x >> y >> z; x--, y--;
            FOR(it, 0, 2) {
                if (!hs.count(mp(z, x))) {
                    hs[mp(z, x)] = y;
                }
                else {
                    join(y, hs[mp(z, x)]);
                }
                st[find(x)]->insert(y);
                swap(x, y);
            }
        }
        else {
            int x, y; cin >> x >> y; x--, y--;
            x = find(x);
            if (present((*st[x]), y)) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
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