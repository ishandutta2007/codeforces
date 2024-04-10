#include <cstdio>
static const int INF = 0x7fffffff;
static const int MAXN = 200006;

int n, c[MAXN];
struct edgelist {
    int w, head[MAXN], dest[MAXN * 2], next[MAXN * 2];
    edgelist() : w(0) { }
    inline void init(int n) {
        for (int i = 0; i < n; ++i) head[i] = -1;
    }
    inline void add_edge(int u, int v) {
        dest[w] = v; next[w] = head[u]; head[u] = w++;
    }
} orig, scc;

void dfs_unionscc(int u, int p = -1, int anc = 0) {
    if (p != -1 && c[u] != c[p]) {
        scc.add_edge(anc, u);
        scc.add_edge(u, anc);
        anc = u;
    }
    for (int w = orig.head[u]; w != -1; w = orig.next[w]) if (orig.dest[w] != p)
        dfs_unionscc(orig.dest[w], u, anc);
}

int d[MAXN];
void dfs_sccdiam(int u, int p = -1) {
    for (int w = scc.head[u]; w != -1; w = scc.next[w]) if (scc.dest[w] != p) {
        d[scc.dest[w]] = d[u] + 1;
        dfs_sccdiam(scc.dest[w], u);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    int u, v;
    orig.init(n);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        orig.add_edge(u, v); orig.add_edge(v, u);
    }

    scc.init(n);
    dfs_unionscc(0);

    for (int i = 0; i < n; ++i) d[i] = INF;
    d[0] = 0; dfs_sccdiam(0);
    int max = -1, max_id = -1;
    for (int i = 0; i < n; ++i)
        if (d[i] != INF && max < d[i]) { max = d[i]; max_id = i; }

    for (int i = 0; i < n; ++i) d[i] = INF;
    d[max_id] = 0; dfs_sccdiam(max_id);
    max = -1, max_id = -1;
    for (int i = 0; i < n; ++i)
        if (d[i] != INF && max < d[i]) { max = d[i]; max_id = i; }
    ++max;  // for counting vertices

    printf("%d\n", max / 2);
    return 0;
}