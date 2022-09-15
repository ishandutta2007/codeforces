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

template<class T, T oo> struct Dinic {
    static const int MAXV = 1e5 + 5;
    static const int MAXE = 1e6 + 5;
    int n, s, t, E;
    int adj[MAXE], nxt[MAXE], lst[MAXV], ptr[MAXV], lev[MAXV], que[MAXV];
    T flw[MAXE], cap[MAXE];
    void init(int n, int s, int t) {
        this->n = n, this->s = s, this->t = t, E = 0;
        fill_n(lst, n, -1);
    }
    void add(int u, int v, T c1, T c2) {
        adj[E] = v, flw[E] = 0, cap[E] = c1, nxt[E] = lst[u], lst[u] = E++;
        adj[E] = u, flw[E] = 0, cap[E] = c2, nxt[E] = lst[v], lst[v] = E++;
    }
    int bfs() {
        fill_n(lev, n, -1), lev[s] = 0;
        int qsize = 0;
        que[qsize++] = s;
        for (int i = 0; i < qsize; i++) {
            for (int u = que[i], e = lst[u]; ~e; e = nxt[e]) {
                int v = adj[e];
                if (flw[e] < cap[e] && !~lev[v]) {
                    lev[v] = lev[u] + 1;
                    que[qsize++] = v;
                }
            }
        }
        return lev[t] != -1;
    }
    T dfs(int u, T bot) {
        if (u == t) return bot;
        for (int& e = ptr[u]; ~e; e = nxt[e]) {
            int v = adj[e];
            T delta = 0;
            if (lev[v] == lev[u] + 1 && flw[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flw[e]))) > 0) {
                flw[e] += delta; flw[e ^ 1] -= delta;
                return delta;
            }
        }
        return 0;
    }
    T maxflow() {
        T total = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) ptr[i] = lst[i];
            for (T delta = dfs(s, oo); delta > 0; delta = dfs(s, oo)) total += delta;
        }
        return total;
    }
};
Dinic<long long, (long long) 1e18> dinic;

const int maxn = 100 + 5;
int n, k;
int p[maxn];
int c[maxn];
int l[maxn];

int ispr(int k) {
    if (k <= 1) return 0;
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) return 0;
    }
    return 1;
}

int check(int m, int one) {
    int tot = n, s = tot++, t = tot++;
    dinic.init(tot, s, t);
    vi v1, v2;
    int sum = 0, mxone = 0;
    FOR(i, 0, n) if (l[i] <= m) {
        if (!(c[i] & 1)) {
            dinic.add(s, i, p[i], 0);
            v1.pb(i);
            sum += p[i];
        }
        else if (c[i] > 1) {
            dinic.add(i, t, p[i], 0);
            v2.pb(i);
            sum += p[i];
        }
        else {
            chkmax(mxone, p[i]);
        }
    }
    FOR(ii, 0, sz(v1)) FOR(jj, 0, sz(v2)) {
        int i = v1[ii];
        int j = v2[jj];
        if (ispr(c[i] + c[j])) {
            dinic.add(i, j, INF, 0);
        }
    }
    if (one) {
        FOR(ii, 0, sz(v1)) {
            int i = v1[ii];
            if (ispr(c[i] + 1)) {
                dinic.add(i, t, INF, 0);
            }
        }
        FOR(jj, 0, sz(v2)) {
            int j = v2[jj];
            if (ispr(c[j] + 1)) {
                dinic.add(s, j, INF, 0);
            }
        }
    }
    long long mxfl = dinic.maxflow();
    if (one) mxfl -= mxone;
    return sum - mxfl >= k;
}

void solve() {
    cin >> n >> k;
    FOR(i, 0, n) cin >> p[i] >> c[i] >> l[i];
    int lo = 1, hi = k + 1;
    while (lo < hi) {
        int mi = lo + hi >> 1;
        if (!check(mi, 0) && !check(mi, 1)) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }
    if (lo == k + 1) lo = -1;
    cout << lo << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    } else {
        //ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}