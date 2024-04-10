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

const int MN = 4e5 + 5;
vector<int> nodes[MN];
vector<int> f[MN];

void fakeUpdate(int u, int v) {
    for(int x = u; x < MN; x += x & -x)
        nodes[x].push_back(v);
}

void fakeGet(int u, int v) {
    for(int x = u; x > 0; x -= x & -x)
        nodes[x].push_back(v);
}

void push() {
    FOR(x, 0, MN) {
        sort(all(nodes[x])), uni(nodes[x]);
        f[x].resize(nodes[x].size() + 1);
    }
}

void update(int u, int v) {
    for(int x = u; x < MN; x += x & -x)
        for(int y = lower_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin() + 1; y <= nodes[x].size(); y += y & -y)
            f[x][y]++;
}

int get(int u, int v) {
    int res = 0;
    for(int x = u; x > 0; x -= x & -x)
        for(int y = upper_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin(); y > 0; y -= y & -y)
            res += f[x][y];
    return res;
}

void chemthan() {
    int n, m; cin >> n >> m;
    vi p(n), s(n), b(n), inc(m), pref(m);
    FOR(i, 0, n) cin >> p[i];
    FOR(i, 0, n) cin >> s[i];
    FOR(i, 0, n) cin >> b[i];
    FOR(i, 0, m) cin >> inc[i];
    FOR(i, 0, m) cin >> pref[i];
    vi dc;
    FOR(i, 0, n) dc.pb(p[i] + b[i]), dc.pb(p[i] - b[i]);
    FOR(i, 0, m) dc.pb(inc[i] + pref[i]), dc.pb(inc[i] - pref[i]);
    sort(all(dc)), uni(dc);
    vi vn, vm;
    FOR(i, 0, n) vn.pb(i);
    FOR(i, 0, m) vm.pb(i);
    sort(all(vn), [&] (int i, int j) {
            return s[i] > s[j];
            }
        );
    sort(all(vm), [&] (int i, int j) {
            return inc[i] > inc[j];
            }
        );
    int ptr = 0;
    for (int e : vm) {
        while (ptr < n && inc[e] <= s[vn[ptr]]) {
            int t = vn[ptr];
            int u = lower_bound(all(dc), p[t] + b[t]) - dc.begin();
            int v = lower_bound(all(dc), p[t] - b[t]) - dc.begin();
            fakeUpdate(u, v);
            ptr++;
        }
        int u = lower_bound(all(dc), inc[e] + pref[e]) - dc.begin();
        int v = lower_bound(all(dc), inc[e] - pref[e]) - dc.begin();
        fakeGet(u, v);
    }
    push();
    ptr = 0;
    vi res(m);
    for (int e : vm) {
        while (ptr < n && inc[e] <= s[vn[ptr]]) {
            int t = vn[ptr];
            int u = lower_bound(all(dc), p[t] + b[t]) - dc.begin();
            int v = lower_bound(all(dc), p[t] - b[t]) - dc.begin();
            update(u, v);
            ptr++;
        }
        int u = lower_bound(all(dc), inc[e] + pref[e]) - dc.begin();
        int v = lower_bound(all(dc), inc[e] - pref[e]) - dc.begin();
        res[e] = get(u, v);
    }
    FOR(i, 0, m) {
        cout << res[i] << " \n"[i == m - 1];
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