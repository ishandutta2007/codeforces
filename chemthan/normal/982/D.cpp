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

const int maxn = 1e5 + 5;
int n;
int a[maxn];

int dj[maxn];
int size[maxn];
int find(int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}

int num;
int cnt;
int f[maxn];

void add(int u) {
    if (!(f[u]++)) num++;
    cnt++;
}
void rem(int u) {
    if (!(--f[u])) num--;
    cnt--;
}

void join(int u, int v) {
    int p = find(u);
    int q = find(v);
    if (p != q) {
        rem(size[p]);
        rem(size[q]);
        dj[p] = q;
        size[q] += size[p];
        add(size[q]);
    }
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) dj[i] = i, size[i] = 1;
    vii vals;
    FOR(i, 0, n) vals.pb(mp(a[i], i));
    sort(all(vals));
    int ptr = 0;
    pi best = mp(-INF, -INF);
    FOR(i, 0, sz(vals)) {
        while (ptr < sz(vals) && vals[ptr].fi <= vals[i].fi) {
            add(1);
            int p = vals[ptr].se;
            if (p && a[p - 1] <= vals[i].fi) {
                join(p, p - 1);
            }
            if (p < n - 1 && a[p + 1] <= vals[i].fi) {
                join(p, p + 1);
            }
            ptr++;
        }
        if (num == 1) {
            chkmax(best, mp(cnt, -vals[i].fi));
        }
    }
    cout << -best.se + 1 << "\n";
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