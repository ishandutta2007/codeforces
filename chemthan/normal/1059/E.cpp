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
inline ull icbrt(ull k) {ull r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}

const int maxn = 1e5 + 5;
int n, l;
long long s;
int w[maxn];
vi adj[maxn];
map<int, long long>* f[maxn];
int off0[maxn];
long long off1[maxn];
int res[maxn];

void join(map<int, long long>*& a, map<int, long long>*& b, int& offa0, long long& offa1, int& offb0, long long& offb1) {
    if (a->size() < b->size()) swap(a, b), swap(offa0, offb0), swap(offa1, offb1);
    for (auto it : *b) {
        if (!a->count(it.fi + offb0 - offa0)) {
            (*a)[it.fi + offb0 - offa0] = it.se + offb1 - offa1;
        }
        else {
            chkmin((*a)[it.fi + offb0 - offa0], it.se + offb1 - offb0);
        }
    }
    b->clear();
    delete b;
}

void inc(map<int, long long>* a, int w, int& off0, long long& off1) {
    while (a->size() && (a->rbegin()->fi + off0 + 1 > l || a->rbegin()->se + off1 + w > s)) {
        a->erase(a->rbegin()->fi);
    }
    off0++, off1 += w;
}

void dfs(int u, int p) {
    f[u] = new map<int, long long>();
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            join(f[u], f[v], off0[u], off1[u], off0[v], off1[v]);
            res[u] += res[v];
        }
    }
    inc(f[u], w[u], off0[u], off1[u]);
    if (!f[u]->size()) {
        (*f[u])[1] = w[u];
        off0[u] = 0;
        off1[u] = 0;
        res[u]++;
    }
}

void chemthan() {
    cin >> n >> l >> s;
    FOR(i, 0, n) cin >> w[i];
    FOR(i, 1, n) {
        int p; cin >> p; p--;
        adj[p].pb(i);
    }
    if (*max_element(w, w + n) > s) {
        cout << -1 << "\n";
        return;
    }
    dfs(0, -1);
    cout << res[0] << "\n";
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