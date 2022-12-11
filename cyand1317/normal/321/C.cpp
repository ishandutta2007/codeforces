#include <cstdio>
#include <vector>
static const int MAXN = 1e5 + 16;

int n;
int head[MAXN], dest[MAXN * 2], next[MAXN * 2];
bool marked[MAXN];
int sts[MAXN];
int rk[MAXN];

inline void add_edge(int u, int v) {
    static int w = 0;
    dest[w] = v; next[w] = head[u]; head[u] = w++;
}

void calc_sts(int u, int p = -1) {
    sts[u] = 1;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p && !marked[dest[w]]) {
        calc_sts(dest[w], u);
        sts[u] += sts[dest[w]];
    }
}
int cc_sz;
int calc_centroid(int u, int p = -1)
{
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p && !marked[dest[w]]) {
        if (sts[dest[w]] * 2 > cc_sz) return calc_centroid(dest[w], u);
    }
    return u;
}
void solve_subproblem(int u, int level = 0) {
    calc_sts(u);
    cc_sz = sts[u];
    int c = calc_centroid(u);
    marked[c] = true;
    rk[c] = level;
    for (int w = head[c]; w != -1; w = next[w]) if (!marked[dest[w]]) {
        solve_subproblem(dest[w], level + 1);
    }
    marked[c] = false;
}

int main()
{
    scanf("%d", &n);
    int u, v;
    for (int i = 0; i < n; ++i) head[i] = -1;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v);
        add_edge(v, u);
    }

    solve_subproblem(0);
    for (int i = 0; i < n; ++i) if (rk[i] >= 26) { puts("Impossible!"); return 0; }
    for (int i = 0; i < n; ++i) printf("%c%c", 'A' + rk[i], i == n - 1 ? '\n' : ' ');

    return 0;
}