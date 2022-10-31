#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MX 100005
using namespace std;

vector <int> adj[MX], radj[MX];
vector <int> con[MX];
int chk[MX], cnt, vis[MX];
int val[MX], size[MX];
int T; 
int N, M, g[MX];
int ans;
void DFS(int u) {
    chk[u] = 1;
    int i, v;
    for (i = 0; i < adj[u].size(); i++) {
        v = adj[u][i];
        if (!chk[v]) DFS(v);
    }
    g[++cnt] = u;
}

void rDFS(int u) {
    chk[u] = 1, vis[u] = T;
    int i, v;
    for (i = 0; i < radj[u].size(); i++) {
        v = radj[u][i];
        if (!chk[v]) rDFS(v);
    }
    cnt++;
    size[T]++;
}


int calc(int u) {
    int ret = 0, i, v;
    vis[u] = true;
    val[u] = size[u];
    for (i = 0; i < con[u].size(); i++) {
        v = con[u][i];
        if (!vis[v]) {
            ret += calc(v);
            val[u] += val[v];
        }
    }
    return ret + 1;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int i, j, u, v;
    scanf("%d%d", &N, &M);
    for (i = 0; i < M; i++) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) if (!chk[i]) DFS(i);
    T = 0;
    memset(chk, 0, sizeof chk);
    for (int i = N; i > 0; i--) if (!chk[g[i]]) {
        T++;
        rDFS(g[i]);
    }
    for (i = 1; i <= N; i++) {
        u = vis[i];
        for (j = 0; j < adj[i].size(); j++) {
            v = vis[adj[i][j]];
            if (v != u) {
                con[u].push_back(v);
                con[v].push_back(u);
            }
        }
    }
    memset(vis, 0, sizeof vis);
    for (i = 1; i <= T; i++) if (!vis[i]) {
        int m = calc(i);
        if (m == val[i]) ans += m - 1;
        else ans += val[i];
    }
    printf("%d\n", ans);
    return 0;
}