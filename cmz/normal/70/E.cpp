#include <cstdio>
#include <algorithm>

const int N = 205, M = 405;

int n, k, tot, d[N], e[N][N], lnk[N], ter[M], nxt[M];
int dis[N][N], f[N][N], p[N], ans[N];

void add(int u, int v) {
    ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot;
}
void Floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}
void dfs(int u, int fa) {
    for (int i = 1; i <= n; i++) {
        f[i][u] = d[dis[i][u]] + k;
    }
    for (int i = lnk[u]; i; i = nxt[i]) {
        int v = ter[i];
        if (v == fa) continue;
        dfs(v, u);
        for (int i = 1; i <= n; i++) {
            f[i][u] += std::min(f[p[v]][v], f[i][v] - k);
        }
    }
    p[u] = 1;
    for (int i = 1; i <= n; i++) {
        if (f[i][u] < f[p[u]][u]) p[u] = i;
    }
}
void getPath(int u, int fa, int pos) {
    for (int i = lnk[u]; i; i = nxt[i]) {
        int v = ter[i];
        if (v == fa) continue;
        ans[v] = (f[p[v]][v] > f[pos][v] - k ? pos : p[v]);
        getPath(v, u, ans[v]);
    }
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        scanf("%d", &d[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = (i == j ? 0 : 0x3f3f3f3f);
        }
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        dis[u][v] = dis[v][u] = 1;
        add(u, v), add(v, u);
    }
    Floyd();
    dfs(1, 0);
    printf("%d\n", f[p[1]][1]);
    ans[1] = p[1];
    getPath(1, 0, ans[1]);
    for (int i = 1; i <= n; i++) {
        printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}