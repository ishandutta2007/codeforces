#include <bits/stdc++.h>
using namespace std;

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

const int maxn = 100 + 5;
int n, D;
int a[maxn];
int x[maxn];
int y[maxn];
int d[maxn];

inline int dist(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

void solve() {
    cin >> n >> D;
    FOR(i, 1, n - 1) cin >> a[i];
    FOR(i, 0, n) cin >> x[i] >> y[i];
    fill_n(d, n, INF), d[n - 1] = 0;
    priority_queue<pi> pq; pq.push(mp(-d[n - 1], n - 1));
    while (sz(pq)) {
        int u = pq.top().se;
        int t = -pq.top().fi;
        pq.pop();
        if (d[u] != t) continue;
        FOR(i, 0, n - 1) if (i != u) {
            if (chkmin(d[i], max(0, d[u] + D * dist(i, u) - a[i]))) {
                pq.push(mp(-d[i], i));
            }
        }
    }
    cout << d[0] << "\n";
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif
    solve();
#ifdef _LOCAL_
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}