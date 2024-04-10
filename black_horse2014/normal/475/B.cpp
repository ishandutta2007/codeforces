#include <cstdio>
#include <vector>
using namespace std;

#define pb push_back
#define sz(x) int((x).size())
#define MX 1005
char H[MX], V[MX];
int N, n, m;
vector<int> adj[MX], r_adj[MX];
int q[MX], qn;
int vis[MX], C;

bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void DFS(int u) {
    int i, v;
    
    vis[u]++;
    for (i = 0; i < sz(adj[u]); i++) {
        v = adj[u][i];
        if (!vis[v]) DFS(v);
    }
    q[qn++] = u;
}

void r_DFS(int u) {
    int i, v;
    
    vis[u] = C;
    for (i = 0; i < sz(r_adj[u]); i++) {
        v = r_adj[u][i];
        if (!vis[v]) r_DFS(v);
    }
}

bool scc() {
    int i, u;
    
    for (u = 0; u < N; u++) vis[u] = 0;
    for (qn = u = 0; u < N; u++) {
        if (!vis[u]) DFS(u);
    }
    
    C = 0;
    for (u = 0; u < N; u++) vis[u] = 0;
    for (i = qn - 1; i >= 0; i--) {
        u = q[i];
        if (vis[u]) continue;
        C++;
        r_DFS(u);
    }
    return C == 1;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    
    int i, j, u, v, d;
    
    scanf("%d%d", &n, &m);
    scanf("%s%s", H, V);
    
    N = n * m;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            u = i * m + j;
            d = (H[i] == '>') ? 1 : -1;
            if (in(i, j + d)) {
                v = i * m + (j + d);
                adj[u].pb(v);
                r_adj[v].pb(u);
            }
            
            d = (V[j] == 'v') ? 1 : -1;
            if (in(i + d, j)) {
                v = (i + d) * m + j;
                adj[u].pb(v);
                r_adj[v].pb(u);
            }
        }
    }
    puts(scc() ? "YES" : "NO");
    return 0;
}