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

template<class T> struct RangeFenwick {
    static const int maxn = 5e5 + 5;
    int n;
    T fen0[maxn];
    long long fen1[maxn];
    RangeFenwick(int n) {
        this->n = n;
    }
    inline void upd(int p, T val) {
        p++;
        assert(p > 0);
        for (int pp = p; pp <= n; pp += pp & -pp) {
            fen0[pp] += val;
            fen1[pp] += val * p;
        }
    }
    void upd(int l, int r, T val) {
        upd(l, +val), upd(r + 1, -val);
    }
    inline long long query(int p) {
        p++;
        assert(p <= n);
        long long res = 0;
        for (int pp = p; pp > 0; pp -= pp & -pp) {
            res += (long long) fen0[pp] * (p + 1);
            res -= fen1[pp];
        }
        return res;
    }
};

const int maxn = 5e5 + 5;
int n;
vector<int> adj[maxn];
int size[maxn];
int lev[maxn];
int p[maxn];
int heavy[maxn];

int num[maxn];
int head[maxn];
int cnt;

RangeFenwick<int> fen(maxn);
long long ans[maxn];

inline void upd(int l, int r, int n, int val) {
    fen.upd(l, r, val);
}
inline long long query(int l, int r, int n) {
    return fen.query(r) - fen.query(l - 1);
}

void firstdfs(int u, int dad) {
    size[u] = 1, heavy[u] = -1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v != dad) {
            p[v] = u, lev[v] = lev[u] + 1;
            firstdfs(v, u);
            size[u] += size[v];
            if (heavy[u] == -1 || size[heavy[u]] < size[v]) {
                heavy[u] = v;
            }
        }
    }
}
void dfs(int u, int h, int p, long long sumsize = 0) {
    num[u] = cnt++, head[u] = h;
    sumsize += size[u];
    ans[u] = sumsize;
    if (~heavy[u]) {
        dfs(heavy[u], h, u, sumsize);
    }
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v != p && v != heavy[u]) {
            dfs(v, v, u, sumsize);
        }
    }
}
void upd(int u, int v, int val) {
    int hu = head[u], hv = head[v];
    while (hu != hv) {
        if (lev[hu] < lev[hv]) swap(u, v), swap(hu, hv);
        upd(num[hu], num[u], n, val);
        u = p[hu], hu = head[u];
    }
    if (lev[u] > lev[v]) swap(u, v);
    upd(num[u], num[v], n, val);
}
long long query(int u, int v) {
    long long res = 0;
    int hu = head[u], hv = head[v];
    while (hu != hv) {
        if (lev[hu] < lev[hv]) swap(u, v), swap(hu, hv);
        res += query(num[hu], num[u], n);
        u = p[hu], hu = head[u];
    }
    if (lev[u] > lev[v]) swap(u, v);
    res += query(num[u], num[v], n);
    return res;
}

void solve() {
    scanf("%d", &n);
    int rt = 0;
    FOR(i, 0, n) {
        int x; scanf("%d", &x);
        if (x) {
            x--;
            adj[x].pb(i);
        }
        else {
            rt = i;
        }
    }
    firstdfs(rt, -1), dfs(rt, rt, -1);
    vii v;
    FOR(i, 0, n) v.pb(mp(lev[i], i));
    sort(all(v), greater<pi>());
    int ptr = 0;
    FOR(i, 0, n) {
        while (ptr < n && v[ptr].fi > v[i].fi) {
            int u = v[ptr].se;
            upd(rt, u, -1);
            ptr++;
        }
        int u = v[i].se;
        ans[u] += query(rt, u) - lev[u] - 1;
    }
    FOR(i, 0, n) printf("%I64d%c", ans[i], " \n"[i == n - 1]);
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        //ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}