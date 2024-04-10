#include <cstdio>
static const int MAXN = 3003;
template <typename T, typename K> inline T min(const T a, const K b) { return a < b ? a : b; }
template <typename T, typename K> inline T max(const T a, const K b) { return a > b ? a : b; }

int n, m = 0;
short head[MAXN], dest[MAXN * 2], next[MAXN * 2];
bool rev[MAXN * 2];
short f[MAXN], g[MAXN], h[MAXN];

void dfs(int u, int p = -1)
{
    bool is_leaf = true;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p) {
        is_leaf = false; dfs(dest[w], u);
    }
    f[u] = g[u] = h[u] = 0;
    if (is_leaf) return;
    short max_save_g = 0, max_save_h = 0;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p) {
        short inc = f[dest[w]] + (rev[w] ? 1 : 0);
        f[u] += inc;
        max_save_g = max(max_save_g, inc - (g[dest[w]] + (rev[w] ? 1 : 0)));
        max_save_g = max(max_save_g, inc - (h[dest[w]] + (rev[w] ? 1 : 0)));
        max_save_h = max(max_save_h, inc - (h[dest[w]] + (rev[w] ? 0 : 1)));
        if (rev[w]) max_save_h = max(max_save_h, 1);
    }
    g[u] = f[u] - max_save_g;
    h[u] = f[u] - max_save_h;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) head[i] = -1;
    int ui, vi;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &ui, &vi); --ui, --vi;
        dest[m] = vi; rev[m] = false; next[m] = head[ui]; head[ui] = m++;
        dest[m] = ui; rev[m] = true; next[m] = head[vi]; head[vi] = m++;
    }

    int ans = 0x7fffffff;
    for (int i = 0; i < n; ++i) {
        dfs(i);
        ans = min(ans, f[i]);
        ans = min(ans, g[i]);
        ans = min(ans, h[i]);
    }

    printf("%d\n", ans);
    return 0;
}