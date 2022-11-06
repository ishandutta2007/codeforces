#include <bits/stdc++.h>

using namespace std;

const int N = 220;

int n, k;
int a[N];
int f[N][N];
vector < int > g[N];

int w[N][N];

void dfs(int u, int p) {
    if(p) g[u].erase(find(g[u].begin(), g[u].end(), p));
    for(int s : g[u]) {
        dfs(s, u);
    }
    f[u][0] = a[u];
    for(int s : g[u]) {
        f[u][0] += f[s][k];
    }
    memset(w, 0, sizeof w);
    for(int i = 0; i < g[u].size(); ++i) {
        int s = g[u][i];
        for(int j = 0; j <= n; ++j) {
            for(int x = 0; x <= n; ++x) {
                if(x + j + 1 <= k) continue;
                int nw = min(j + 1, x);
                w[i + 1][nw] = max(w[i + 1][nw], w[i][x] + f[s][j]);
            }
        }
    }
    for(int j = n + 1; j >= 0; --j) {
        if(j > 0) f[u][j] = w[g[u].size()][j];
        f[u][j] = max(f[u][j], f[u][j + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("1.inp" ,"r")) freopen("1.inp", "r", stdin);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    cout << f[1][0] << endl;

    return 0;
}