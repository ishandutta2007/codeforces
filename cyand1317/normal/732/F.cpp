#include <cstdio>
static const int MAXN = 400003;
static const int MAXM = 800003 * 2;

int n, m;
int head[MAXN], dest[MAXM], tag[MAXM], next[MAXM];
bool is_bridge[MAXM] = { false }, dir[MAXM];
int dep[MAXN], low[MAXN];
bool vis[MAXN] = { false };

int w = 0;
inline void add_edge(int u, int v, int t = 0) {
    dest[w] = v; next[w] = head[u]; tag[w] = t; head[u] = w++;
}

void dfs_bridge(int u, int p = -1, int d = 0) {
    dep[u] = low[u] = d; vis[u] = true;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p) {
        if (!vis[dest[w]]) {
            dfs_bridge(dest[w], u, d + 1);
            if (low[dest[w]] >= d + 1) is_bridge[w] = is_bridge[w ^ 1] = true;
            dir[w] = true; dir[w ^ 1] = false;  // For traversing with bridges
        } else {
            // Will be overwritten by parent.
            dir[w] = false; dir[w ^ 1] = true;
        }
        if (low[u] > low[dest[w]]) low[u] = low[dest[w]];
    }
}

int cc_id[MAXN], cc_sz[MAXN] = { 0 }, cc_ct = 0;

void dfs_cc(int u) {
    ++cc_sz[cc_id[u] = cc_ct]; vis[u] = true;
    for (int w = head[u]; w != -1; w = next[w])
        if (!is_bridge[w] && !vis[dest[w]]) dfs_cc(dest[w]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) head[i] = -1;
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v); add_edge(v, u);
    }

    dfs_bridge(0);
    int ans = 0, ans_id = -1;
    for (int i = 0; i < n; ++i) vis[i] = false;
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        dfs_cc(i);
        if (ans < cc_sz[cc_ct]) { ans = cc_sz[cc_ct]; ans_id = cc_ct; }
        cc_ct++;
    }
    // Rebuild tree with bridges
    for (int i = 0; i < cc_ct; ++i) head[i] = -1;
    for (int i = 0; i < m * 2; ++i)
        if (is_bridge[i]) add_edge(cc_id[dest[i ^ 1]], cc_id[dest[i]], i);
    for (int i = 0; i < cc_ct; ++i) vis[i] = false;
    dfs_bridge(ans_id);
    for (int i = m * 2; i < ::w; ++i) dir[tag[i]] = dir[i] ^ 1;

    printf("%d\n", ans);
    for (int i = 0; i < m * 2; i += 2)
        printf("%d %d\n", dest[i ^ dir[i]] + 1, dest[i ^ dir[i] ^ 1] + 1);

    return 0;
}