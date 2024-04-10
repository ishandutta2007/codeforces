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
const int MOD2 = 1007681537;
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
int n, R, C;
int x[maxn][2];
int y[maxn][2];
int l[maxn];
int r[maxn];
int u[maxn];
int d[maxn];
int cnt[4];

void solve() {
    cin >> n >> R >> C;
    vi vx[2], vy[2];
    FOR(i, 0, n) {
        FOR(j, 0, 2) cin >> x[i][j] >> y[i][j];
        sort(x[i], x[i] + 2);
        sort(y[i], y[i] + 2);
        FOR(j, 0, 2) {
            if (!j) {
                vx[j].pb(x[i][j]);
                vy[j].pb(y[i][j]);
            }
            else {
                vx[j].pb(-x[i][j]);
                vy[j].pb(-y[i][j]);
            }
        }
    }
    FOR(i, 0, 4) cin >> cnt[i];
    FOR(i, 0, 2) sort(all(vx[i])), sort(all(vy[i]));
    FOR(i, 0, n) {
        l[i] = lower_bound(all(vx[0]), x[i][1]) - vx[0].begin();
        l[i] -= x[i][0] < x[i][1];
        r[i] = lower_bound(all(vx[1]), -x[i][0]) - vx[1].begin();
        r[i] -= x[i][0] < x[i][1];
        u[i] = lower_bound(all(vy[0]), y[i][1]) - vy[0].begin();
        u[i] -= y[i][0] < y[i][1];
        d[i] = lower_bound(all(vy[1]), -y[i][0]) - vy[1].begin();
        d[i] -= y[i][0] < y[i][1];
        if (mp(mp(l[i], r[i]), mp(u[i], d[i])) == mp(mp(cnt[0], cnt[1]), mp(cnt[2], cnt[3]))) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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