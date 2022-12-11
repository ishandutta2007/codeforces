#include <cstdio>
#include <algorithm>
#include <set>
#include <unordered_map>
typedef long long int64;
static const int MAXN = 203;
static const int MAXM = 50004;
static const int64 INF = 1LL << 62;

int n, m, g_cost, s_cost;
struct edge { int u, v, g, s; } e[MAXM];
inline bool operator < (const edge &lhs, const edge &rhs) {
    return (lhs.g == rhs.g) ? (lhs.s < rhs.s) : (lhs.g < rhs.g);
}
int tree_e;
std::unordered_map<int, int> tree[MAXN];

inline int tree_bfs_find_most_s(int u, int v)
{
    static int pred[MAXN];
    static int q[MAXN], qhead, qtail;
    for (int i = 0; i < n; ++i) pred[i] = -1;
    pred[u] = -2, q[0] = u, qhead = 0, qtail = 1;
    while (qhead != qtail) {
        int r = q[qhead++];
        for (auto w : tree[r]) if (pred[w.first] == -1) {
            pred[w.first] = r; q[qtail++] = w.first;
        }
    }
    if (pred[v] == -1) return -1;
    int best = tree[v][pred[v]];
    for (v = pred[v]; v != u; v = pred[v]) {
        if (e[best].s < e[tree[v][pred[v]]].s)
            best = tree[v][pred[v]];
    }
    return best;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &g_cost, &s_cost);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].g, &e[i].s);
        --e[i].u, --e[i].v;
    }
    std::sort(e, e + m);

    tree_e = 0;
    int64 ans = INF;
    std::multiset<int> silvers;
    for (int i = 0; i < m; ++i) if (e[i].u != e[i].v) {
        //printf("Edge %d | %d-%d | G=%d S=%d\n", i, e[i].u + 1, e[i].v + 1, e[i].g, e[i].s); fflush(stdout);
        int most_s_idx = tree_bfs_find_most_s(e[i].u, e[i].v);
        if (most_s_idx != -1 && e[most_s_idx].s > e[i].s) {
            // Remove edge
            tree[e[most_s_idx].u].erase(e[most_s_idx].v);
            tree[e[most_s_idx].v].erase(e[most_s_idx].u);
            silvers.erase(silvers.find(e[most_s_idx].s));
            --tree_e;
        }
        if (most_s_idx == -1 || e[most_s_idx].s > e[i].s) {
            // Insert edge
            tree[e[i].u][e[i].v] = tree[e[i].v][e[i].u] = i;
            silvers.insert(e[i].s);
            ++tree_e;
        }
        if (tree_e == n - 1) {
            int64 cur_cost = (int64)g_cost * e[i].g + (int64)s_cost * (*silvers.rbegin());
            //printf("Cur. cost: G=%d S=%d Tot=%I64d\n", e[i].g, (*silvers.rbegin()), cur_cost);
            if (ans > cur_cost) ans = cur_cost;
        }
    }

    printf("%I64d\n", ans == INF ? -1LL : ans);
    return 0;
}