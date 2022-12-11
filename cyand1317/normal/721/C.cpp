#include <cstdio>
#include <queue>
#include <vector>
static const int INF32 = 0x3fffffff;
static const int MAXN = 5004;
static const int MAXM = 5004;

int n, m, t;
int head[MAXN], in_deg[MAXN], dest[MAXM], next[MAXM], len[MAXM];
int f[MAXN][MAXN];
int pred[MAXN][MAXN];

inline void add_edge(int u, int v, int l)
{
    static int w = 0;
    dest[w] = v; next[w] = head[u]; len[w] = l; head[u] = w++;
    ++in_deg[v];
}

int main()
{
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; ++i) { head[i] = -1; in_deg[i] = 0; }
    int u, v, l;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &l); --u, --v;
        add_edge(u, v, l);
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j) {
            f[i][j] = INF32;
            pred[i][j] = -1;
        }
    f[0][1] = 0;
    pred[0][1] = -2;

    std::queue<int> q;
    for (int i = 0; i < n; ++i) if (in_deg[i] == 0) q.push(i);
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int w = head[u]; w != -1; w = next[w]) {
            for (int i = 0; i <= n - 1; ++i) if (f[u][i] != INF32) {
                if (f[dest[w]][i + 1] > f[u][i] + len[w]) {
                    f[dest[w]][i + 1] = f[u][i] + len[w];
                    pred[dest[w]][i + 1] = u;
                }
            }
            if (--in_deg[dest[w]] == 0) q.push(dest[w]);
        }
    }

    int ans = n;
    while (ans > 0 && f[n - 1][ans] > t) --ans;
    printf("%d\n", ans);
    if (ans != 0) {
        std::vector<int> route;
        u = n - 1;
        while (u != 0) {
            route.push_back(u);
            u = pred[u][ans];
            --ans;
        }
        printf("1");
        for (std::vector<int>::reverse_iterator i = route.rbegin(); i != route.rend(); ++i)
            printf(" %d", *i + 1);
        putchar('\n');
    }

    return 0;
}