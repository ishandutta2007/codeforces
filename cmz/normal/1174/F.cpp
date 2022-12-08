#include <cstdio>
#include <vector>

const int N = 2e5 + 5, M = 4e5 + 5;

int n, tot, depx, lnk[N], ter[M], nxt[M], dep[N], siz[N], hvy[N];

int query(char opt, int v) {
    printf("%c %d\n", opt, v);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}
void addEdge(int u, int v) {
    ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot;
}
void dfs(int u, int p) {
    siz[u] = 1, hvy[u] = 0, dep[u] = dep[p] + 1;
    for (int i = lnk[u]; i; i = nxt[i]) {
        int v = ter[i];
        if (v == p) continue;
        dfs(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[hvy[u]]) hvy[u] = v;
    }
}
void getPath(int u, std::vector<int> &p) {
    p.emplace_back(u);
    if (hvy[u]) getPath(hvy[u], p);
}
int kkkkkk;
int solve(int u) {
    std::vector<int> p;
    getPath(u, p);
    int v = p.back();
    int depy = (depx + dep[v] - query('d', v)) >> 1, y = p[depy - dep[u]];
    return (depx == depy ? y : solve(query('s', y)));
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v), addEdge(v, u);
    }
    dfs(1, 0);
    depx = query('d', 1) + 1;
    printf("! %d\n", solve(1));
    fflush(stdout);
    return 0;
}