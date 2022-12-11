// ()
#include <cstdio>
static const int MAXN = 2e5 + 4;

int n;
int head[MAXN], dest[MAXN * 2], next[MAXN * 2];
inline void add_edge(int u, int v) {
    static int m = 0;
    dest[m] = v; next[m] = head[u]; head[u] = m++;
}

int max_colour = 0;
int colour[MAXN];
void dfs(int u, int p = -1)
{
    if (max_colour < colour[u]) max_colour = colour[u];
    int cur = 0;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p) {
        while (cur == colour[u] || (p != -1 && cur == colour[p])) ++cur;
        colour[dest[w]] = cur++; dfs(dest[w], u);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) head[i] = -1;
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v);
        add_edge(v, u);
    }

    colour[0] = 0; dfs(0);

    printf("%d\n", max_colour + 1);
    for (int i = 0; i < n; ++i)
        printf("%d%c", colour[i] + 1, i == n - 1 ? '\n' : ' ');

    return 0;
}