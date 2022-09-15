#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
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

const int maxn = 1e5 + 5;
int n, q;
vector<int> adj[maxn];
int size[maxn];
int lev[maxn];
int p[maxn];
int heavy[maxn];

int num[maxn];
int out[maxn];
int pos[maxn];
int head[maxn];
int cnt;

int st[2][maxn << 2];
int lz[2][maxn << 2];

void push(int p, int L, int R) {
    if (lz[0][p] != -1) {
        st[1][p] = lz[0][p] - st[0][p];
        if (L < R) {
            FOR(i, 0, 2) {
                lz[0][p << 1 | i] = lz[0][p];
                lz[1][p << 1 | i] = 0;
            }
        }
        lz[0][p] = -1;
    }
    if (lz[1][p]) {
        st[1][p] += lz[1][p];
        if (L < R) {
            FOR(i, 0, 2) {
                if (lz[0][p << 1 | i] != -1) {
                    lz[0][p << 1 | i] += lz[1][p];
                }
                else {
                    lz[1][p << 1 | i] += lz[1][p];
                }
            }
        }
        lz[1][p] = 0;
    }
}
void build(int p, int L, int R) {
    if (L == R) {
        st[0][p] = lev[pos[L]];
        st[1][p] = -st[0][p];
        lz[0][p] = -1;
        return;
    }
    build(p << 1, L, L + R >> 1);
    build(p << 1 | 1, (L + R >> 1) + 1, R);
    st[0][p] = max(st[0][p << 1], st[0][p << 1 | 1]);
    st[1][p] = -st[0][p];
    lz[0][p] = -1;
}
void upd0(int p, int l, int r, int L, int R, int val0) {
    push(p, L, R);
    if (R < l || r < L) return;
    if (l <= L && R <= r) {
        lz[0][p] = val0;
        push(p, L, R);
        return;
    }
    upd0(p << 1, l, r, L, L + R >> 1, val0);
    upd0(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val0);
    st[1][p] = min(st[1][p << 1], st[1][p << 1 | 1]);
}
void upd1(int p, int l, int r, int L, int R, int val1) {
    push(p, L, R);
    if (R < l || r < L) return;
    if (l <= L && R <= r) {
        lz[1][p] = val1;
        push(p, L, R);
        return;
    }
    upd1(p << 1, l, r, L, L + R >> 1, val1);
    upd1(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val1);
    st[1][p] = min(st[1][p << 1], st[1][p << 1 | 1]);
}
int query(int p, int l, int r, int L, int R) {
    push(p, L, R);
    if (R < l || r < L) return INF;
    if (l <= L && R <= r) return st[1][p];
    return min(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
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
void dfs(int u, int h, int p) {
    pos[num[u] = cnt++] = u, head[u] = h;
    if (~heavy[u]) {
        dfs(heavy[u], h, u);
    }
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v != p && v != heavy[u]) {
            dfs(v, v, u);
        }
    }
    out[u] = cnt - 1;
}
int query(int u, int v) {
    int res = INF;
    int hu = head[u], hv = head[v];
    while (hu != hv) {
        if (lev[hu] < lev[hv]) swap(u, v), swap(hu, hv);
        chkmin(res, query(1, num[hu], num[u], 0, n - 1));
        u = p[hu], hu = head[u];
    }
    if (lev[u] > lev[v]) swap(u, v);
    chkmin(res, query(1, num[u], num[v], 0, n - 1));
    return res;
}

void chemthan() {
    cin >> n >> q;
    FOR(i, 1, n) {
        int u; cin >> u; u--;
        adj[u].pb(i);
        adj[i].pb(u);
    }
    firstdfs(0, -1), dfs(0, 0, -1);
    build(1, 0, n - 1);
    auto calc = [&] (int u) {
        int x = query(1, num[u], num[u], 0, n - 1) + lev[u];
        int y = u ? query(0, p[u]) : 1;
        return x - min(y, 1) - lev[u];
    };
    while (q--) {
        int op, u; cin >> op >> u; u--;
        if (op == 1) {
            upd1(1, num[u], out[u], 0, n - 1, 1);
        }
        else if (op == 2) {
            int val0 = u ? (query(1, num[p[u]], num[p[u]], 0, n - 1) + lev[p[u]]) : 0;
            if (u) {
                val0 -= max(0, calc(p[u]));
            }
            upd0(1, num[u], out[u], 0, n - 1, val0);
        }
        else if (op == 3) {
            if (calc(u) >= 0) {
                cout << "black\n";
            }
            else {
                cout << "white\n";
            }
        }
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}