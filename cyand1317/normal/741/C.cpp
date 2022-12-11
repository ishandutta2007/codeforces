#include <cstdio>
static const int MAXN = 2e5 + 3;
static const int MAXM = MAXN * 2;

int n, a[MAXN], b[MAXN];

int head[MAXN], dest[MAXM], next[MAXM];
inline void add_edge(int u, int v) {
    static int w = 0;
    dest[w] = v; next[w] = head[u]; head[u] = w++;
}

bool vis[MAXN] = { false }, colour[MAXN];
void dfs_bipartite_colour(int u)
{
    vis[u] = true;
    for (int w = head[u]; w != -1; w = next[w]) if (!vis[dest[w]]) {
        colour[dest[w]] = !colour[u];
        dfs_bipartite_colour(dest[w]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n * 2; ++i) head[i] = -1;
    for (int i = 0; i < n; ++i) {
        add_edge(i * 2, i * 2 + 1);
        add_edge(i * 2 + 1, i * 2);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]); --a[i], --b[i];
        add_edge(a[i], b[i]);
        add_edge(b[i], a[i]);
    }

    for (int i = 0; i < n * 2; ++i) if (!vis[i]) {
        colour[i] = 0; dfs_bipartite_colour(i);
    }

    for (int i = 0; i < n; ++i)
        puts(colour[a[i]] ? "1 2" : "2 1");

    return 0;
}