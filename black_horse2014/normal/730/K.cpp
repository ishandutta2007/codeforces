#include <bits/stdc++.h>
using namespace std;

const int N = 440000;
const int M = 1100000;

int T;
int vis[N], par[N], d[N];
int x[M], y[M], chk[M];

vector<int> adj[N], con[M];
vector<int> E;

void dfs(int u, int pe) {
    vis[u] = ++T;
    for (int e : adj[u]) {
        if (e == pe) continue;
        int v = x[e] ^ y[e] ^ u;
        if (!vis[v]) {
            E.push_back(e);
            par[v] = e;
            d[v] = d[u] + 1;
            dfs(v, e);
            E.pop_back();
        } else if (vis[v] < vis[u]) {
            con[E[d[v]]].push_back(e);
        }
    }
}

int solve(int n, int m, int A, int B) {
    for (int i = 1; i <= n; i++) adj[i].clear(), vis[i] = 0;
    for (int i = 1; i <= m; i++) con[i].clear(), chk[i] = 0;
    for (int i = 1; i <= m; i++) {
        int u = x[i], v = y[i];
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    T = d[A] = 0;
    dfs(A, 0);
    queue<int> Q;
    for (int i = 1; i <= m; i++) chk[i] = 0;
    for (int u = B; u != A; ) {
        int e = par[u];
        if (d[x[e]] > d[y[e]]) swap(x[e], y[e]);
        Q.push(e);
        chk[e] = 1;
        u ^= x[e] ^ y[e];
    }
    while (!Q.empty()) {
        int t = Q.front(); Q.pop();
        for (int e : con[t]) {
            chk[e] = 1;
            int dir = 0;
            if (d[x[t]] < d[y[t]]) {
                dir = -1;
                if (d[x[e]] > d[y[e]]) swap(x[e], y[e]);
            } else {
                dir = 1;
                if (d[x[e]] < d[y[e]]) swap(x[e], y[e]);
            }
            int u = d[x[e]] < d[y[e]] ? y[e] : x[e];
            while (par[u] && !chk[par[u]]) {
                int f = par[u];
                int cur = (d[x[f]] < d[y[f]]) - (d[x[f]] > d[y[f]]);
                if (cur != dir) swap(x[f], y[f]);
                Q.push(f);
                chk[f] = 1;
                u ^= x[f] ^ y[f];
            }
        }
    }
    for (int i = 1; i <= m; i++) if (!chk[i]) return puts("No"), 0;
    puts("Yes");
    for (int i = 1; i <= m; i++) printf("%d %d\n", x[i], y[i]);
    return 0;
}

int main() {

    ios::sync_with_stdio(0);
    int ncase;
    for (cin >> ncase; ncase--; ) {
        int n, m, A, B; cin >> n >> m >> A >> B;
        for (int i = 1; i <= m; i++) cin >> x[i] >> y[i];
        solve(n, m, A, B);
    }
    return 0;
}