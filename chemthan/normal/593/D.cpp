#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18 + 10;
const ld PI = 2 * acos(0);

const int maxn = 200010;
const int maxe = 22;
int from[maxn];
int to[maxn];
int n, m;
ll d[maxn];
vector<pair<int, ll> > adj[maxn];
int nchain, nbase;
int hchain[maxn];
int ichain[maxn];
int size[maxn];
int pib[maxn];
int vis[maxn];
int lev[maxn];
int p[maxe][maxn];
int tms;
int tin[maxn];
int tou[maxn];
int RR[maxn];

ll get(ll a, ll b) {
    if (ld(a) * ld(b) >= LINF) return LINF;
    return min(LINF, a * b);
}

ll st[4 * maxn];
void build(int node, int L, int R) {
    if (L == R) {st[node] = 1; return;}
    build(node << 1, L, (L + R) >> 1);
    build((node << 1) + 1, ((L + R) >> 1) + 1, R);
    st[node] = get(st[node << 1], st[(node << 1) + 1]);
}
void update(int node, int i, int L, int R, ll val) {
    if (i < L || i > R) return;
    if (L == R) {st[node] = val; return;}
    update(node << 1, i, L, (L + R) >> 1, val);
    update((node << 1) + 1, i, ((L + R) >> 1) + 1, R, val);
    st[node] = get(st[node << 1], st[(node << 1) + 1]);
}
ll query(int node, int l, int r, int L, int R) {
    if (l > R || r < L) return 1;
    if (l <= L && r >= R) return st[node];
    return get(query(node << 1, l, r, L, (L + R) >> 1), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}
void init() {
    memset(vis, 0, sizeof(vis)); memset(p, 0, sizeof(p)); memset(lev, 0, sizeof(lev));
    memset(hchain, -1, sizeof(hchain)); memset(ichain, -1, sizeof(ichain)); memset(pib, -1, sizeof(pib));
    tms = nchain = nbase = 0;
}
void dfs(int u) {
    tin[u] = tms++;
    vis[u] = size[u] = 1;
    for (int i = 1; i < maxe; i++) p[i][u] = p[i - 1][p[i - 1][u]];
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        if (!vis[v]) {
            p[0][v] = u; lev[v] = lev[u] + 1; dfs(v);
            size[u] += size[v]; d[v] = adj[u][i].second;
        }
    }
    tou[u] = tms++;
}
int lca(int u, int v) {
    if (lev[u] < lev[v]) swap(u, v);
    if (tin[v] <= tin[u] && tou[v] >= tou[u]) return v;
    for (int i = maxe - 1; i >= 0; i--) if (lev[u] - (1 << i) >= lev[v]) u = p[i][u];
    for (int i = maxe - 1; i >= 0; i--) if (p[i][u] != p[i][v]) {u = p[i][u]; v = p[i][v];}
    return p[0][u];
}
void hld(int u) {
    if (hchain[nchain] == -1) hchain[nchain] = u;
    ichain[u] = nchain;
    pib[u] = nbase++;
    RR[pib[u]] = u;
    int tmp = -1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        if (v != p[0][u]) {if (tmp == -1 || size[v] > size[tmp]) tmp = v;}
    }
    if (tmp != -1) hld(tmp);
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        if (v != p[0][u] && v != tmp) {nchain++; hld(v);}
    }
}
ll query(int u, int a) {
    ll res = 1;
    int uchain = ichain[u], achain = ichain[a];
    while (1) {
        if (uchain == achain) {
            return get(res, query(1, pib[a] + 1, pib[u], 0, n - 1));
        }
        res = get(res, query(1, pib[hchain[uchain]], pib[u], 0, n - 1));
        u = p[0][hchain[uchain]];
        uchain = ichain[u];
    }
    return res;
}

void solve() {
    scanf("%d%d", &n, &m);
    FOR(i, 0, n - 1) {
        int u, v; ll w; scanf("%d%d%I64d", &u, &v, &w); u--; v--;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
        from[i] = u; to[i] = v;
    }
    init(); dfs(0); hld(0);
    build(1, 0, n - 1);
    FOR(i, 0, n) update(1, pib[i], 0, n - 1, d[i]);
    while (m--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int a, b; ll y; scanf("%d%d%I64d", &a, &b, &y); a--; b--;
            int u = lca(a, b);
            ll res = query(a, u);
            res = get(res, query(b, u));
            printf("%I64d\n", y / res);
        }
        else {
            int p; ll c; scanf("%d%I64d", &p, &c); p--;
            int u = from[p], v = to[p];
            if (tin[u] <= tin[v]) swap(u, v);
            d[u] = c; update(1, pib[u], 0, n - 1, d[u]);
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}