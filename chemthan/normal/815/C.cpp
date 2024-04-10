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
const int MOD2 = (int) 1e8 + 7;
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

const int maxn = 5000 + 5;
int n, b;
int c[maxn];
int d[maxn];
vi adj[maxn];
vector<long long> dp[maxn];
vector<long long> dp2[maxn];
int ans;

vector<long long> combine(vector<long long> a, vector<long long> b) {
    int na = sz(a), nb = sz(b);
    vector<long long> c(na + nb - 1, LINF);
    FOR(i, 0, na) FOR(j, 0, nb) {
        chkmin(c[i + j], a[i] + b[j]);
    }
    return c;
}

void dfs(int u) {
    priority_queue<pair<int, vector<long long> > > heap, heap2;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        dfs(v);
        heap.push(mp(-sz(dp[v]), dp[v]));
        vector<long long> tmp;
        FOR(i, 0, sz(dp[v])) {
            tmp.pb(min(dp[v][i], dp2[v][i]));
        }
        heap2.push(mp(-sz(tmp), tmp));
    }
    while (sz(heap) > 1) {
        vector<long long> vx = heap.top().se; heap.pop();
        vector<long long> vy = heap.top().se; heap.pop();
        vector<long long> vz = combine(vx, vy);
        heap.push(mp(-sz(vz), vz));
    }
    while (sz(heap2) > 1) {
        vector<long long> vx = heap2.top().se; heap2.pop();
        vector<long long> vy = heap2.top().se; heap2.pop();
        vector<long long> vz = combine(vx, vy);
        heap2.push(mp(-sz(vz), vz));
    }
    dp[u].pb(0);
    dp[u].pb(c[u]);
    dp2[u].pb(LINF);
    dp2[u].pb(c[u] - d[u]);
    if (sz(heap)) {
        dp[u] = combine(dp[u], heap.top().se);
        vector<long long> cb;
        FOR(i, 0, sz(heap.top().se)) {
            cb.pb(min(heap.top().se[i], heap2.top().se[i]));
        }
        dp2[u] = combine(dp2[u], cb);
    }
    FOR(i, 0, sz(dp[u])) {
        if (dp[u][i] <= b) {
            chkmax(ans, i);
        }
    }
}

void solve() {
    cin >> n >> b;
    FOR(i, 0, n) {
        cin >> c[i] >> d[i];
        if (i) {
            int p; cin >> p; p--;
            adj[p].pb(i);
        }
    }
    dfs(0);
    FOR(i, 0, n + 1) {
        if (dp2[0][i] <= b) {
            chkmax(ans, i);
        }
    }
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