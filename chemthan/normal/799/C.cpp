#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

int n, c[2];
vii g[2];

int func1(int ix) {
    int ans = 0;
    multiset<int> st;
    FOR(i, 0, sz(g[ix])) st.insert(g[ix][i].se);
    int ptr = sz(g[ix]) - 1;
    FOR(i, 0, sz(g[ix])) {
        st.erase(st.find(g[ix][i].se));
        while (ptr >= 0 && g[ix][i].fi + g[ix][ptr].fi > c[ix]) {
            if (present(st, g[ix][ptr].se)) {
                st.erase(st.find(g[ix][ptr].se));
            }
            ptr--;
        }
        if (i >= ptr) break;
        chkmax(ans, g[ix][i].se + *st.rbegin());
    }
    return ans;
}

int func2() {
    int ans1 = 0, ans2 = 0;
    FOR(i, 0, sz(g[0])) {
        if (g[0][i].fi <= c[0]) {
            chkmax(ans1, g[0][i].se);
        }
    }
    FOR(i, 0, sz(g[1])) {
        if (g[1][i].fi <= c[1]) {
            chkmax(ans2, g[1][i].se);
        }
    }
    if (!ans1 || !ans2) {
        return 0;
    }
    return ans1 + ans2;
}

void solve() {
    cin >> n >> c[0] >> c[1];
    FOR(i, 0, n) {
        int a, b; string t; cin >> a >> b >> t;
        if (t == "C") {
            g[0].pb(mp(b, a));
        }
        else {
            g[1].pb(mp(b, a));
        }
    }
    sort(all(g[0])), sort(all(g[1]));
    int ans = 0;
    chkmax(ans, func1(0));
    chkmax(ans, func1(1));
    chkmax(ans, func2());
    cout << ans << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}