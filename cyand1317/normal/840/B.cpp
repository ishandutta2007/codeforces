#include <cstdio>
static const int MAXN = 3e5 + 4;
static const int MAXM = 6e5 + 3;

int n, m, w = 0;
int d[MAXN];
int head[MAXN], dest[MAXM], next[MAXM];

inline void add_edge(int u, int v)
{
    dest[w] = v; next[w] = head[u]; head[u] = w++;
}

int rt = -1;
bool vis[MAXN] = { false };
bool f[MAXN][2] = {{ false }};
bool sel[MAXM] = { false };

void dfs(int u)
{
    vis[u] = true;
    for (int w = head[u]; w != -1; w = next[w]) if (!vis[dest[w]]) {
        dfs(dest[w]);
        if (d[dest[w]] == 1) {
            sel[w] = sel[w ^ 1] = true;
            d[dest[w]] ^= 1;
            d[u] ^= 1;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
    for (int i = 0; i < n; ++i) head[i] = -1;
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v);
        add_edge(v, u);
    }

    rt = -1;
    for (int i = 0; i < n; ++i) if (d[i] == -1) { rt = i; break; }

    if (rt == -1) {
        dfs(0);
        if (d[0] == 1) { puts("-1"); return 0; }
    } else {
        for (int i = rt + 1; i < n; ++i) if (d[i] == -1) d[i] = 0;
        vis[rt] = true;
        for (int w = head[rt]; w != -1; w = next[w]) if (!vis[dest[w]]) {
            dfs(dest[w]);
            if (d[dest[w]] == 1) {
                sel[w] = sel[w ^ 1] = true;
            }
        }
    }

    int ct = 0;
    for (int i = 0; i < m; ++i) if (sel[i * 2]) ++ct;
    printf("%d\n", ct);
    for (int i = 0; i < m; ++i) if (sel[i * 2]) printf("%d\n", i + 1);

    return 0;
}