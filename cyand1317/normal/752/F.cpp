#include <cstdio>
#include <utility>
static const int MAXN = 2e5 + 5;
static const int MAXM = 4e5 + 5;
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int n, k;
int head[MAXN], dest[MAXM], next[MAXM];
bool has_team[MAXN] = { false };

inline void add_edge(int u, int v) {
    static int w = 0;
    dest[w] = v; next[w] = head[u]; head[u] = w++;
}

int subt_teams[MAXN];
void dfs_count_teams(int u = 0, int p = -1) {
    subt_teams[u] = has_team[u];
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p) {
        dfs_count_teams(dest[w], u);
        subt_teams[u] += subt_teams[dest[w]];
    }
}

int teams_seq[MAXN], teams_top = 0;
void dfs_arrange_teams(int u = 0, int p = -1) {
    if (has_team[u]) teams_seq[teams_top++] = u;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p) {
        dfs_arrange_teams(dest[w], u);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) head[i] = -1;
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v); add_edge(v, u);
    }
    for (int i = 0; i < k + k; ++i) {
        scanf("%d", &u); --u; has_team[u] = true;
    }

    dfs_count_teams();
    int root = 0, parent = -1;
    while (true) {
        std::pair<int, int> p = std::make_pair(-1, -1);
        for (int w = head[root]; w != -1; w = next[w]) if (dest[w] != parent)
            p = max(p, std::make_pair(subt_teams[dest[w]], dest[w]));
        if (p.first <= k) break; else parent = root, root = p.second;
    }
    printf("1\n%d\n", root + 1);

    dfs_arrange_teams(root);
    for (int i = 0; i < k; ++i)
        printf("%d %d %d\n", teams_seq[i] + 1, teams_seq[i + k] + 1, root + 1);

    return 0;
}