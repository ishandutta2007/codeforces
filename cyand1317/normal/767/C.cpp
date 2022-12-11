#include <cstdio>
#include <vector>
static const int MAXN = 1e6 + 5;

int n, t[MAXN], par[MAXN], root = -1;
std::vector<int> e[MAXN];

int all_sum = 0, sum[MAXN];
bool has_thirds[MAXN] = { false };
void dfs_calc_sum(int u)
{
    sum[u] = t[u];
    has_thirds[u] = false;
    for (int v : e[u]) {
        dfs_calc_sum(v);
        sum[u] += sum[v];
        has_thirds[u] |= has_thirds[v];
    }
    has_thirds[u] |= (sum[u] * 3 == all_sum);
}

int find_any_thirds(int u)
{
    for (int v : e[u]) if (has_thirds[v]) return find_any_thirds(v);
    if (sum[u] * 3 == sum[root]) return u; else return -1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &par[i], &t[i]); --par[i];
        if (par[i] == -1) root = i; else e[par[i]].push_back(i);
    }

    for (int i = 0; i < n; ++i) all_sum += t[i];
    dfs_calc_sum(root);

    // Case 1: two separated subtrees
    int fs, sc;
    for (int u = 0; u < n; ++u) {
        fs = sc = -1;
        for (int v : e[u]) if (has_thirds[v]) {
            if (fs == -1) fs = v;
            else {
                sc = v;
                fs = find_any_thirds(fs);
                sc = find_any_thirds(sc);
                printf("%d %d\n", fs + 1, sc + 1); return 0;
            }
        }
    }

    // Case 2: one subtree with 2/3 sum and its subtree with 1/3 sum
    for (int i = 0; i < n; ++i) if (i != root && sum[i] * 3 == sum[root] * 2 && has_thirds[i]) {
        fs = find_any_thirds(i);
        if (fs != i) {
            printf("%d %d\n", i + 1, fs + 1); return 0;
        }
    }

    puts("-1"); return 0;
}