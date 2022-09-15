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

template<class TF, class TC, TF Foo, TC Coo> struct MinCostMaximumFlow {
    static const int MAXV = 1e5 + 5;
    static const int MAXE = 1e6 + 5;
    int n, s, t, E;
    int adj[MAXE], nxt[MAXE], lst[MAXV], frm[MAXV], vis[MAXV];
    TF cap[MAXE], flw[MAXE], totalFlow;
    TC cst[MAXE], dst[MAXV], totalCost;
    void init(int n, int s, int t) {
        this->n = n, this->s = s, this->t = t;
        fill_n(lst, n, -1), E = 0;
    }
    void add(int u, int v, TF ca, TC co) {
        adj[E] = v, cap[E] = ca, flw[E] = 0, cst[E] = +co, nxt[E] = lst[u], lst[u] = E++;
        adj[E] = u, cap[E] =  0, flw[E] = 0, cst[E] = -co, nxt[E] = lst[v], lst[v] = E++;
    }
    int spfa() {
        fill_n(dst, n, Coo), dst[s] = 0;
        queue<int> que; que.push(s);
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int e = lst[u]; e != -1; e = nxt[e]) if (flw[e] < cap[e]) {
                int v = adj[e];
                if (dst[v] > dst[u] + cst[e]) {
                    dst[v] = dst[u] + cst[e];
                    frm[v] = e;
                    if (!vis[v]) {
                        vis[v] = 1;
                        que.push(v);
                    }
                }
            }
            vis[u] = 0;
        }
        return dst[t] < Coo;
    }
    TC mincost() {
        totalCost = 0, totalFlow = 0;
        while (1) {
            if (!spfa()) break;
            TF mn = Foo;
            for (int v = t, e = frm[v]; v != s; v = adj[e ^ 1], e = frm[v]) mn = min(mn, cap[e] - flw[e]);
            for (int v = t, e = frm[v]; v != s; v = adj[e ^ 1], e = frm[v]) {
                flw[e] += mn;
                flw[e ^ 1] -= mn;
            }
            totalFlow += mn;
            totalCost += mn * dst[t];
        }
        return totalCost;
    }
};
MinCostMaximumFlow<int, int, (int) 1e9, (int) 1e9> mcmf;

const int maxn = 50 + 5;
int n, q;
int l[maxn];
int r[maxn];
int a[maxn][maxn];

void solve() {
    cin >> n >> q;
    FOR(i, 0, n) l[i] = 0, r[i] = n - 1;
    FOR(i, 0, q) {
        int op, L, R, v; cin >> op >> L >> R >> v; L--, R--, v--;
        if (op == 1) {
            FOR(j, L, R + 1) {
                chkmax(l[j], v);
            }
        }
        else {
            FOR(j, L, R + 1) {
                chkmin(r[j], v);
            }
        }
    }
    FOR(i, 0, n) {
        FOR(j, l[i], r[i] + 1) {
            a[i][j] = 1;
        }
    }
    int tot = n + n, s = tot++, t = tot++;
    mcmf.init(tot, s, t);
    FOR(i, 0, n) {
        mcmf.add(s, i, 1, 0);
        FOR(j, 0, n) {
            mcmf.add(n + i, t, 1, 2 * j + 1);
        }
        FOR(j, 0, n) if (a[i][j]) {
            mcmf.add(i, n + j, INF, 0);
        }
    }
    int res = mcmf.mincost();
    if (mcmf.totalFlow < n) {
        cout << -1 << "\n";
        return;
    }
    cout << res << "\n";
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