#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 3030;

vector<int> adj[N];
int lca[N][N];
int below[N][N];
int par[N];
int sz[N];
vector<int> sub[N];
int n;

void dfs(int u, int p) {
    par[u] = p;
    int q = p;

    sz[u] = 1;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        for (auto& x : sub[v]) {
            below[x][u] = v;
            below[u][x] = v;
            for (auto& y : sub[u]) {
                assert(lca[x][y] == 0);
                assert(lca[y][x] == 0);
                lca[x][y] = u;
                lca[y][x] = u;
            }
        }
        for (auto& x : sub[v]) {
            sub[u].push_back(x);
        }
    }
    for (auto& x : sub[u]) {
        assert(lca[x][u] == 0);
        assert(lca[u][x] == 0);
        lca[x][u] = u;
        lca[u][x] = u;
    }
    sub[u].push_back(u);
}

//ll dp[N][N];
const int M = N*(N+1)/2;
ll g[M];

ll solve(int u, int v) {
    if (u > v) swap(u, v);
    int ind = N*(N+1)/2 - (N-u+1)*(N-u)/2 +(v-u);
    if (g[ind] != -1) return g[ind];
    if (u == v) {
        return g[ind] = 0;
    }
    if (lca[u][v] == u) {
        ll a = solve(below[u][v], v);
        ll b = solve(u, par[v]);

        ll x = n - sz[below[u][v]];
        ll y = sz[v];

        g[ind] = max(a, b) + x*y;
    } else if (lca[u][v] == v) {
        ll a = solve(below[v][u], u);
        ll b = solve(v, par[u]);

        ll x = sz[u];
        ll y = n - sz[below[u][v]];

        g[ind] = max(a, b) + x*y;
    } else {
        ll a = solve(u, par[v]);
        ll b = solve(v, par[u]);

        ll x = sz[u];
        ll y = sz[v];

        g[ind] = max(a, b) + x*y;
    }

    return g[ind];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i=0; i<M; ++i) {
        g[i] = -1;
    }

    ll ans = 0;
    for (int i=1; i<=n; ++i) {
        for (int j=i; j<=n; ++j) {
            ans = max(ans, solve(i, j));
            //cerr << " dp " << i << " " << j << " = " << solve(i, j) << endl;
        }
    }


    cout << ans << endl;

    return 0;
}