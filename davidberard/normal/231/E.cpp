#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;
const int LG = 18;

int par[LG][N], f[N], g[N], vis[N], dep[N];
vector<int> adj[N];
int comp;

int n, m;

void dfs(int u, int p, int d=1) {
    //cerr << " dfs " << u << " " << p << " " << d << endl;
    vis[u] = 1;
    dep[u] = d;
    par[0][u] = p;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        if (f[v]) continue;
        if (vis[v]) {
            //cerr << "  ON trying " << v << endl;
            int x = u;
            int z = ++comp;
            f[v] = comp;
            while (x != v) {
                //cerr << "  (" << u << ") x = " << x << endl;
                f[x] = comp;
                x = par[0][x];
            }
        } else {
            dfs(v, u, d+1);
        }
    }
}

void dfs_g(int u, int p, int prev=0, int prefix=0) {
    vis[u] = 1;
    g[u] = prefix + (f[u] != 0 && f[u] != prev);
    for (auto& v : adj[u]) {
        if (vis[v]) continue;
        dfs_g(v, u, f[u], g[u]);
    }
}

void build() {
    for (int l=0; l<LG-1; ++l) {
        for (int i=1; i<=n; ++i) {
            par[l+1][i] = par[l][par[l][i]];
        }
    }
}

int jump_h(int u, int h) {
    for (int i=0; h; i++, h/=2) {
        if (h&1) {
            u = par[i][u];
        }
    }
    return u;
}

int get_lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    v = jump_h(v, dep[v]-dep[u]);

    for (int h=LG-1; h>=0; --h) {
        if (par[h][u] != par[h][v]) {
            u = par[h][u];
            v = par[h][v];
        }
    }

    if (u != v) {
        u = par[0][u];
        v = par[0][v];
        assert(u == v);
    }
    return u;
}

const int MOD = 1e9+7;
int tpow[N];
void setup() {
    tpow[0] = 1;
    for (int i=1; i<N; ++i) {
        tpow[i] = tpow[i-1]+tpow[i-1];
        if (tpow[i] >= MOD) tpow[i] -= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    memset(vis, 0, sizeof vis);
    dfs_g(1, 0);
    build();

    int k;
    cin >> k;
    for (int i=0; i<k; ++i) {
        int u, v;
        cin >> u >> v;
        int a = get_lca(u, v);
        int amt = g[u] + g[v] - 2*g[a] + (f[a] != 0);
        cout << tpow[amt] << "\n";
    }
    
    return 0;
}