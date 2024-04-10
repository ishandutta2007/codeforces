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

const int maxn = 2e5 + 5;
int n;
vii adj[maxn];
int w[maxn];
int c[maxn];
int size[maxn];
int del[maxn];
int fen[2][maxn << 1];
int ans = 1;

void dfs(int u, int p) {
    size[u] = 1;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        int ix = adj[u][i].se;
        if (v != p && !del[v]) {
            dfs(v, u);
            size[u] += size[v];
        }
    }
}

int findcentroid(int u) {
    dfs(u, -1);
    int tot = size[u];
    int p = -1;
    while (1) {
        pi best;
        FOR(i, 0, sz(adj[u])) {
            int v = adj[u][i].fi;
            if (v != p && !del[v]) {
                chkmax(best, mp(size[v], v));
            }
        }
        if (best.fi + best.fi <= tot) {
            return u;
        }
        p = u, u = best.se;
    }
    assert(0);
}

void init(int fen1[], int fen2[]) {
    fill_n(fen1, maxn << 1, 1);
    fill_n(fen2, maxn << 1, 0);
}

void upd(int fen1[], int fen2[], int p, int val1, int val2) {
    p += maxn;
    for (; p > 0; p -= p & -p) {
        fen1[p] = mult(fen1[p], val1);
        fen2[p] += val2;
    }
}

pi query(int fen1[], int fen2[], int p) {
    p += maxn;
    pi res = mp(1, 0);
    for (; p < maxn + maxn; p += p & -p) {
        res.fi = mult(res.fi, fen1[p]);
        res.se += fen2[p];
    }
    return res;
}

void add(int u, int p, int dif, int prd) {
    upd(fen[0], fen[1], dif, prd, 1);
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        int ix = adj[u][i].se;
        if (v != p && !del[v]) {
            int ndif = dif, nprd = prd;
            if (!c[ix]) ndif++;
            else ndif -= 2;
            nprd = mult(prd, w[ix]);
            add(v, u, ndif, nprd);
        }
    }
}

void rem(int u, int p, int dif, int prd) {
    upd(fen[0], fen[1], dif, inv(prd), -1);
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        int ix = adj[u][i].se;
        if (v != p && !del[v]) {
            int ndif = dif, nprd = prd;
            if (!c[ix]) ndif++;
            else ndif -= 2;
            nprd = mult(prd, w[ix]);
            rem(v, u, ndif, nprd);
        }
    }
}

void upd(int u, int p, int dif, int prd) {
    pi r = query(fen[0], fen[1], -dif + 1);
    ans = mult(ans, r.fi);
    ans = mult(ans, fpow(prd, r.se));
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        int ix = adj[u][i].se;
        if (v != p && !del[v]) {
            int ndif = dif, nprd = prd;
            if (!c[ix]) ndif++;
            else ndif -= 2;
            nprd = mult(prd, w[ix]);
            upd(v, u, ndif, nprd);
        }
    }
}

void flip(int u, int p) {
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        int ix = adj[u][i].se;
        if (v != p && !del[v]) {
            c[ix] ^= 1;
            flip(v, u);
        }
    }
}

void work(int u) {
    upd(fen[0], fen[1], 0, 1, +1);
    FOR(it, 0, 2) {
        FOR(i, 0, sz(adj[u])) {
            int v = adj[u][i].fi;
            int ix = adj[u][i].se;
            if (!del[v]) {
                upd(v, u, !c[ix] ? 1 : -2, w[ix]);
                add(v, u, !c[ix] ? 1 : -2, w[ix]);
            }
        }
        FOR(i, 0, sz(adj[u])) {
            int v = adj[u][i].fi;
            int ix = adj[u][i].se;
            if (!del[v]) {
                rem(v, u, !c[ix] ? 1 : -2, w[ix]);
            }
        }
        flip(u, -1);
    }
    upd(fen[0], fen[1], 0, 1, -1);
}

void divide(int u) {
    u = findcentroid(u);
    del[u] = 1;
    work(u);
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        if (!del[v]) {
            divide(v);
        }
    }
}

void dfs2(int u, int p) {
    size[u] = 1;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        int ix = adj[u][i].se;
        if (v != p) {
            dfs2(v, u);
            size[u] += size[v];
            ans = mult(ans, fpow(w[ix], (long long) size[v] * (n - size[v])));
        }
    }
}

void solve() {
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v >> w[i] >> c[i]; u--, v--;
        adj[u].pb(mp(v, i)), adj[v].pb(mp(u, i));
    }
    init(fen[0], fen[1]);
    divide(0);
    ans = inv(ans);
    dfs2(0, -1);
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
        //ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}