#include <cstdio>

int n;
const int MAXN = 2e5 + 5;
int head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt;
inline void add(int u, int v) { nxt[++ cnt] = head[u]; head[u] = cnt; e[cnt] = v; }
inline void link(int u, int v) { add(u, v); add(v, u); }

int t[MAXN], tt[MAXN], fa[MAXN], sz[MAXN], son[MAXN], dep[MAXN];

void dfs1(int x, int pre) {
    dep[x] = dep[fa[x] = pre] + (sz[x] = 1);
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == pre) continue;
        dfs1(e[i], x); sz[x] += sz[e[i]];
        if(sz[e[i]] > sz[son[x]]) son[x] = e[i];
    }
}

void dfs2(int x, int tp) {
    t[tt[x] = tp] = x; if(son[x]) dfs2(son[x], tp);
    for (int i = head[x];i;i = nxt[i]) {
        if(e[i] == fa[x] || e[i] == son[x]) continue;
        dfs2(e[i], e[i]);
    }
}

int solve(int x, int d) {
    if(!d) return x;
    const int y = t[x];
    printf("d %d\n", y); fflush(stdout); int dis; scanf("%d", &dis);
    if(dep[y] - dep[x] == dis + d) {
        int u = y; while(dis --) u = fa[u];
        return u;
    }
    int res = (dis + d - (dep[y] - dep[x])) >> 1;
    dis -= res; int u = y; while(dis --) u = fa[u];
    printf("s %d\n", u); fflush(stdout); scanf("%d", &u);
    return solve(u, res - 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 2;i <= n;++ i) {
        int u, v; scanf("%d%d", &u, &v);
        link(u, v);
    }
    dfs1(1, 0); dfs2(1, 1);

    printf("d 1\n"); fflush(stdout); int d; scanf("%d", &d);
    printf("! %d\n", solve(1, d));
    fflush(stdout);
}