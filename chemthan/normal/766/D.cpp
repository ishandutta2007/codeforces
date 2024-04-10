#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL_
    #define cout cerr
#endif
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

const int maxn = 100000 + 5;
int n, m, q;
string s[maxn];
map<string, int> hs;
int dj[maxn << 1];

void init() {
    FOR(i, 0, n << 1) dj[i] = i;
}
int find(int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v) {
    int p = find(u);
    int q = find(v);
    dj[p] = q;
}

inline int query(string s) {
    if (hs.count(s)) return hs[s];
    int res = sz(hs);
    return hs[s] = res;
}

void solve() {
    cin >> n >> m >> q;
    FOR(i, 0, n) cin >> s[i];
    init();
    FOR(i, 0, m) {
        int t; string x, y; cin >> t >> x >> y;
        int ix = query(x), iy = query(y);
        if (t == 1) {
            if (find(ix << 1) == find(iy << 1 | 1)) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
                join(ix << 1, iy << 1);
                join(ix << 1 | 1 , iy << 1 | 1);
            }
        }
        else {
            if (find(ix << 1) == find(iy << 1)) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
                join(ix << 1, iy << 1 | 1);
                join(ix << 1 | 1, iy << 1);
            }
        }
    }
    while (q--) {
        string x, y; cin >> x >> y;
        int ix = query(x), iy = query(y);
        if (find(ix << 1) == find(iy << 1)) {
            cout << 1 << "\n";
        }
        else if (find(ix << 1) == find(iy << 1 | 1)) {
            cout << 2 << "\n";
        }
        else {
            cout << 3 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    printf("\nTime elapsed: %dms\n", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}