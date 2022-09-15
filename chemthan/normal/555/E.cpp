#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 200010;
int n, m, q;
vi adj1[maxn];
vi adj2[maxn];
int num[maxn];
int low[maxn];
int p[maxn];
int cnt;
map<pi, int> edge, mp;

int r[maxn];
void init() {
    FOR(i, 0, maxn) r[i] = i;
}
int find(int u) {
    return u == r[u] ? u : r[u] = find(r[u]);
}
void join(int u, int v) {
    r[find(u)] = find(v);
}

void dfs(int u) {
    num[u] = low[u] = ++cnt;
    FOR(i, 0, sz(adj1[u])) {
        int v = adj1[u][i];
        if (!num[v]) {p[v] = u; dfs(v); low[u] = min(low[u], low[v]);}
        else if (p[u] != v || edge[make_pair(u, v)] >= 2) low[u] = min(low[u], num[v]);
    }
}

const int maxe = 30;
int nchain, nbase;
int hchain[maxn];
int ichain[maxn];
int size[maxn];
int pib[maxn];
int vis[maxn];
int lev[maxn];
int par[maxe][maxn];
int root[maxn];
int tin[maxn];
int tou[maxn];
int tms = 0;

int st[2][4 * maxn];
void updateintervaltree(int node, int l, int r, int L, int R, bool val) {
    if (l > R || r < L) return;
    if (l <= L && r >= R) {
        st[val][node] = 1;
        if (st[0][node] & st[1][node]) {printf("No"); exit(0);}
        return;
    }
    updateintervaltree(node << 1, l, r, L, (L + R) >> 1, val);
    updateintervaltree((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, val);
}

void dfs2(int u, int r) {
    tin[u] = tms++;
    vis[u] = size[u] = 1;
    root[u] = r;
    FOR(i, 1, maxe) par[i][u] = par[i - 1][par[i - 1][u]];
    FOR(i, 0, sz(adj2[u])) {
        int v = adj2[u][i];
        if (!vis[v]) {
            par[0][v] = u; lev[v] = lev[u] + 1; dfs2(v, r);
            size[u] += size[v];
        }
    }
    tou[u] = tms++;
}

int lca(int u, int v) {
    if (lev[u] < lev[v]) swap(u, v);
    if (tin[v] <= tin[u] && tou[v] >= tou[u]) return v;
    FORd(i, maxe, 0) if (lev[u] - (1 << i) >= lev[v]) u = par[i][u];
    FORd(i, maxe, 0) if (par[i][u] != par[i][v]) {u = par[i][u]; v = par[i][v];}
    return par[0][u];
}

void hld(int u) {
    if (hchain[nchain] == -1) hchain[nchain] = u;
    ichain[u] = nchain;
    pib[u] = nbase++;
    int tmp = -1;
    FOR(i, 0, sz(adj2[u])) {
        int v = adj2[u][i];
        if (v != par[0][u]) {
            if (tmp == -1 || size[v] > size[tmp]) tmp = v;
        }
    }
    if (tmp != -1) hld(tmp);
    FOR(i, 0, sz(adj2[u])) {
        int v = adj2[u][i];
        if (v != par[0][u] && v != tmp) {
            nchain++;
            hld(v);
        }
    }
}

void update(int u, int a, bool val) {
    int uchain = ichain[u], achain = ichain[a];
    while (1) {
        if (uchain == achain) {
            updateintervaltree(1, pib[a] + 1, pib[u], 0, n - 1, val);
            return;
        }
        updateintervaltree(1, pib[hchain[uchain]], pib[u], 0, n - 1, val);
        u = par[0][hchain[uchain]];
        uchain = ichain[u];
    }
}

void solve() {
    scanf("%d%d%d", &n, &m, &q);
    FOR(i, 0, m) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        adj1[u].push_back(v); adj1[v].push_back(u);
        edge[make_pair(u, v)]++;
        edge[make_pair(v, u)]++;
    }
    ms(p, -1); ms(num, 0); ms(low, 0); cnt = 0;
    FOR(i, 0, n) if (!num[i]) dfs(i);
    init();
    FOR(i, 0, n) if (low[i] < num[i]) join(i, p[i]);
    FOR(i, 0, n) {
        FOR(j, 0, sz(adj1[i])) {
            int k = adj1[i][j];
            int u = find(i);
            int v = find(k);
            if (u == v) continue;
            if (!mp[make_pair(u, v)]) {
                adj2[u].push_back(v);
                adj2[v].push_back(u);
                mp[make_pair(u, v)] = mp[make_pair(v, u)] = 1;
            }
        }
    }
    ms(vis, 0); ms(par, 0); ms(lev, 0);
    int nroot = 0;
    FOR(i, 0, n) if (!vis[i]) dfs2(i, nroot++);
    ms(hchain, -1); ms(ichain, -1); ms(pib, -1); nchain = nbase = 0;
    FOR(i, 0, n) if (pib[i] == -1) {hld(i); nchain++;}
    ms(st, 0);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        x = find(x); y = find(y);
        if (x == y) continue;
        if (root[x] != root[y]) {printf("No"); exit(0);}
        int z = lca(x, y);
        update(x, z, 1);
        update(y, z, 0);
    }
    printf("Yes");
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}