#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

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
int n, m, q;
vii adj[maxn];
int w[maxn];
int ww[maxn];
long long pot[maxn];
int d[maxn];
int vis[maxn];

void dijktra() {
    fill_n(pot + 1, n - 1, LINF);
    priority_queue<pair<long long, int> > pq;
    pq.push(mp(-pot[0], 0));
    while (sz(pq)) {
        long long t = -pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (pot[u] != t) continue;
        FOR(i, 0, sz(adj[u])) {
            int v = adj[u][i].fi;
            int ix = adj[u][i].se;
            if (chkmin(pot[v], pot[u] + w[ix])) {
                pq.push(mp(-pot[v], v));
            }
        }
    }
}

void bfs(int k) {
    vector<queue<int> > que(k + 1);
    fill_n(d + 1, n - 1, INF);
    que[0].push(0);
    FOR(i, 0, k + 1) {
        while (sz(que[i])) {
            int u = que[i].front(); que[i].pop();
            if (d[u] != i) continue;
            FOR(j, 0, sz(adj[u])) {
                int v = adj[u][j].fi;
                int ix = adj[u][j].se;
                if (d[v] > d[u] + ww[ix] && d[u] + ww[ix] <= k) {
                    d[v] = d[u] + ww[ix];
                    que[d[v]].push(v);
                }
            }
        }
    }
}

void upd() {
    FOR(u, 0, n) if (pot[u] < LINF) pot[u] += d[u];
    FOR(u, 0, n) if (pot[u] < LINF) {
        FOR(i, 0, sz(adj[u])) {
            int v = adj[u][i].fi;
            int ix = adj[u][i].se;
            long long x = pot[u] + w[ix] - pot[v];
            ww[ix] = x > INF ? INF : x;
        }
    }
}

void solve() {
    scanf("%d%d%d", &n, &m, &q);
    FOR(i, 0, m) {
        int u, v; scanf("%d%d%d", &u, &v, w + i); u--, v--;
        adj[u].pb(mp(v, i));
    }
    dijktra(), upd();
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int u; scanf("%d", &u), u--;
            if (pot[u] == LINF) {
                puts("-1");
            }
            else {
                printf("%I64d\n", pot[u]);
            }
        }
        else {
            int k; scanf("%d", &k);
            FOR(i, 0, k) {
                int ix; scanf("%d", &ix); ix--;
                w[ix]++, ww[ix]++;
            }
            bfs(k), upd();
        }
    }
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