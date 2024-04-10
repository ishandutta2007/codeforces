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
//const int MOD = (int) 1e9 + 7;
const int MOD = 1007681537;
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

const int maxn = 2e5 + 5;
const int magic = 2000;
int n, q;
int a[maxn];
int op[maxn];
int x[maxn];
int y[maxn];

int cnt[maxn];
int fre[maxn];

void add(int u) {
    if (cnt[u] > 0) {
        fre[cnt[u]]--;
    }
    if (++cnt[u] > 0) {
        fre[cnt[u]]++;
    }
}
void rem(int u) {
    if (cnt[u] > 0) {
        fre[cnt[u]]--;
    }
    if (--cnt[u] > 0) {
        fre[cnt[u]]++;
    }
}

void chemthan() {
    cin >> n >> q;
    vi dc;
    FOR(i, 0, n) cin >> a[i], dc.pb(a[i]);
    FOR(i, 0, q) {
        cin >> op[i] >> x[i] >> y[i];
        if (op[i] == 1) {
            x[i]--, y[i]--;
        }
        else {
            x[i]--;
            dc.pb(y[i]);
        }
    }
    sort(all(dc)), uni(dc);
    FOR(i, 0, n) a[i] = lower_bound(all(dc), a[i]) - dc.begin();
    FOR(i, 0, q) if (op[i] == 2) {
        y[i] = lower_bound(all(dc), y[i]) - dc.begin();
    }
    static int res[maxn];
    for (int i = 0; i < q; i += magic) {
        vi ver; FOR(j, i, min(q, i + magic) ) if (op[j] == 1) ver.pb(j);
        sort(all(ver), [&] (int i, int j) {
                if (x[i] / magic != x[j] / magic) return x[i] / magic < x[j] / magic;
                if (y[i] != y[j]) return y[i] < y[j];
                return i < j;
                }
            );
        int u = 0, v = -1;
        fill_n(cnt, maxn, 0);
        fill_n(fre, maxn, 0);
        for (int ix : ver) {
            while (u > x[ix]) add(a[--u]);
            while (v < y[ix]) add(a[++v]);
            while (u < x[ix]) rem(a[u++]);
            while (v > y[ix]) rem(a[v--]);
            static pair<int, int> cache[maxn];
            int ncache = 0;
            FOR(j, i, ix) if (op[j] == 2) {
                if (x[ix] <= x[j] && x[j] <= y[ix]) {
                    add(y[j]);
                    rem(a[x[j]]);
                    cache[ncache++] = mp(j, a[x[j]]);
                    a[x[j]] = y[j];
                }
            }
            FOR(j, 1, maxn) if (!fre[j]) {
                res[ix] = j;
                break;
            }
            while (ncache-- > 0) {
                int j = cache[ncache].fi;
                int val = cache[ncache].se;
                add(val);
                rem(a[x[j]]);
                a[x[j]] = val;
            }
        }
        FOR(j, i, min(q, i + magic)) {
            if (op[j] == 2) {
                a[x[j]] = y[j];
            }
        }
    }
    FOR(i, 0, q) if (op[i] == 1) cout << res[i] << "\n";
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