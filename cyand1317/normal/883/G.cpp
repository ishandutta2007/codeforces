#include <cstdio>
#include <algorithm>
#include <queue>
static const int MAXN = 3e5 + 4;
static const int MAXM = 3e5 + 5;

static int n, m, s;
static int ty[MAXM], u[MAXM], v[MAXM];
static int head[MAXN], dest[MAXM * 2], next[MAXM * 2];
static bool dir[MAXM * 2];

static bool vis[MAXN];
static int vis_ct;
static int tag[MAXM * 2];

inline void add_edge(int type, int u, int v)
{
    static int w = 0;
    dest[w] = v; next[w] = head[u]; head[u] = w++;
    if (type == 2) {
        dest[w] = u; next[w] = head[v]; head[v] = w++;
        dir[w - 1] = dir[w - 2] = false;
    } else {
        w++;
        dir[w - 1] = dir[w - 2] = true;
    }
}

inline void bfs(int s, int mode)
{
    std::fill(vis, vis + n, false);
    std::queue<int> q;
    q.push(s); vis[s] = true; vis_ct = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int w = head[u]; w != -1; w = next[w]) {
            if (mode == 1 && !dir[w]) continue;
            if (!vis[dest[w]]) {
                q.push(dest[w]); vis[dest[w]] = true; ++vis_ct;
                tag[w] = tag[w ^ 1] = u;
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &s); --s;
    std::fill(head, head + n, -1);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &ty[i], &u[i], &v[i]);
        add_edge(ty[i], --u[i], --v[i]);
    }

    std::fill(tag, tag + m * 2, -1);
    bfs(s, 0);
    printf("%d\n", vis_ct);
    for (int i = 0; i < m; ++i) if (ty[i] == 2) {
        if (tag[i * 2] == u[i]) putchar('+');
        else putchar('-');
    }
    putchar('\n');

    bfs(s, 1);
    printf("%d\n", vis_ct);
    for (int i = 0; i < m; ++i) if (ty[i] == 2) {
        if (vis[u[i]]) putchar('-');
        else putchar('+');
    }
    putchar('\n');

    return 0;
}