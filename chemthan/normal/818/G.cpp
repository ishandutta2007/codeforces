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
    static const int MAXV = 2e7 + 5;
    static const int MAXE = 2e7 + 5;
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

const int maxn = 3e3 + 5;
const int magic = 5;
int n;
int a[maxn];
int num[100005];

void solve() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    int tot = n + n, s = tot++, t = tot++, ss = tot++;
    mcmf.init(tot, ss, t);
    mcmf.add(ss, s, 4, 0);
    FOR(i, 0, n) {
        mcmf.add(s, i, 1, 0);
        mcmf.add(i + n, t, 1, 0);
        mcmf.add(i, i + n, 1, -1);
        static int* his[maxn];
        int nhis = 0;
        FOR(j, i + 1, n) if (abs(a[i] - a[j]) == 1) {
            his[nhis++] = &num[a[j]];
            if (num[a[j]]++ <= magic) {
                mcmf.add(i + n, j, 1, 0);
            }
        }
        FOR(j, 0, nhis) (*his[j])--;
    }
    vi lst[7];
    FORd(i, n, 0) {
        int r = a[i] % 7;
        FOR(j, 0, sz(lst[r])) {
            mcmf.add(i + n, lst[r][j], 1, 0);
        }
        while (sz(lst[r]) > magic) lst[r].erase(lst[r].begin());
        lst[r].pb(i);
    }
    cout << -mcmf.mincost() << "\n";
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