#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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

template<class T, T oo> struct Dinic {
    static const int MAXV = 1e6 + 5;
    static const int MAXE = 1e7 + 5;
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
        fill_n(lev, n, 0), lev[s] = 1;
        int qsize = 0;
        que[qsize++] = s;
        for (int i = 0; i < qsize; i++) {
            for (int u = que[i], e = lst[u]; ~e; e = nxt[e]) {
                int v = adj[e];
                if (flw[e] < cap[e] && !lev[v]) {
                    lev[v] = lev[u] + 1;
                    que[qsize++] = v;
                }
            }
        }
        return lev[t];
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
    T maxflow(int ss = -1, int tt = -1) {
        if (~ss) s = ss;
        if (~tt) t = tt;
        for (int e = 0; e < E; e++) {
            flw[e] = 0;
        }
        T total = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) ptr[i] = lst[i];
            for (T delta = dfs(s, oo); delta > 0; delta = dfs(s, oo)) total += delta;
        }
        return total;
    }
    void trace(int n) {
        FOR(i, 1, n + 1) {
            int st = i, last;
            while (st != t) {
                for (int e = lst[st]; ~e; e = nxt[e]) if (flw[e] > 0) {
                    last = st;
                    st = adj[e];
                    flw[e]--;
                    break;
                }
            }
            assert(last - n != i);
            assert(!(last - n & i));
            cout << last - n << " \n"[i == n];
        }
    }
    vector<pair<pair<int, int>, T> > gomory_hu() {
        vector<pair<pair<int, int>, T> > tree;
        vector<int> p(n);
        for (int u = 1; u < n; u++) {
            tree.push_back(make_pair(make_pair(p[u], u), maxflow(u, p[u])));
            for (int v = u + 1; v < n; ++v) {
                if (lev[v] && p[v] == p[u]) {
                    p[v] = u;
                }
            }
        }
        return tree;
    }
};
Dinic<int, (int) 1e9> dinic;

void case1(int n) {
    int k = __lg(n) + 1;
    int tmp = 1 << k;
    int tot = n + 1 + tmp, s = tot++, t = tot++;
    dinic.init(tot, s, t);
    FOR(i, 1, n + 1) dinic.add(s, i, 1, 0);
    FOR(i, 1, n + 1) {
        int msk = tmp - 1 ^ i;
        dinic.add(i, n + msk, 1, 0);
        FOR(j, 0, k) if (bit(msk, j)) {
            int nmsk = msk ^ (1 << j);
            dinic.add(n + msk, n + nmsk, n, 0);
        }
    }
    FOR(i, 1, n + 1) {
        dinic.add(n + i, t, 1, 0);
    }
    int r = dinic.maxflow();
    if (r != n) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        dinic.trace(n);
    }
}

void case2(int n) {
    int k = __lg(n);
    if (n <= 5 || n == (1 << k)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vi res;
    FOR(i, 0, n + 1) res.pb(i);
    static vi g[20];
    FOR(i, 1, n + 1) {
        if (i != 5) {
            g[__lg(i)].pb(i);
        }
        else {
            g[0].pb(i);
        }
    }
    FOR(i, 0, 20) {
        FOR(j, 0, sz(g[i])) {
            int k = (j + 1) % sz(g[i]);
            int x = g[i][j];
            int y = g[i][k];
            res[x] = y;
        }
    }
    FOR(i, 1, n + 1) {
        assert(res[i] != i);
        assert(res[i] & i);
        cout << res[i] << " \n"[i == n];
    }
}

void solve() {
    srand(time(NULL));
    int n; cin >> n;
    case1(n), case2(n);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}