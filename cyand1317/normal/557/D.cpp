#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
static const int MAXN = 100003;
static const int ANS_UNKNOWN = 233;

// ans is t, and w will be calculated later.
int n, m, ans = ANS_UNKNOWN;
std::vector<int> e[MAXN];
unsigned char visited[MAXN] = {0};
int depth[MAXN];
std::set<int> components[MAXN];
int quad = 0;

void dfs(int root, int d, int parent, int component_num)
{
    components[component_num].insert(root);
    visited[root] = 1;
    depth[root] = d;
    for (int i: e[root]) if (i != parent) {
        if (visited[i]) {
            if (std::abs(d - depth[i]) % 2 == 0) { ans = 0; return; }
        } else {
            dfs(i, d + 1, parent, component_num);
            if (ans != ANS_UNKNOWN) return;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int component_num = 0;
    for (int i = 0; i < n; ++i)
        if (!visited[i]) dfs(i, 0, -1, component_num++);
    if (ans == 0) puts("0 1");
    else {
        // Check if ans = 1
        for (int i = 0; i < n; ++i) if (e[i].size() >= 2) { ans = 1; break; }
        if (ans == 1) {
            long long w = 0;
            for (int c = 0; c < component_num; ++c) {
                long long population[2] = {0};
                for (int node: components[c]) ++population[depth[node] % 2];
                w += population[1] * (population[1] - 1) / 2 +
                population[0] * (population[0] - 1) / 2;
            }
            printf("1 %I64d\n", w);
        } else {
            // Check if ans = 2
            for (int i = 0; i < n; ++i) if (e[i].size() > 0) { ans = 2; break; }
            if (ans == 2) {
                long long w = 0;
                for (int i = 0; i < n; ++i) if (e[i].size() > 0) w += n - 2;
                w /= 2;
                printf("2 %I64d\n", w);
            } else {
                long long w = (long long)n * (long long)(n - 1) * (long long)(n - 2) / 6;
                printf("3 %I64d\n", w);
            }
        }
    }
    
    return 0;
}