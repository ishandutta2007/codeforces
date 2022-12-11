#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
static const int MAXN = 3e5 + 4;
static const int ALPHABET = 26;
static const int INF = 0x3fffffff;

int n;
int e[MAXN * 2][ALPHABET];

int sts[MAXN * 2];
std::vector<int> layer[MAXN];

void dfs(int u, int d)
{
    layer[d].push_back(u);
    sts[u] = 1;
    for (int i = 0; i < ALPHABET; ++i) if (e[u][i] != -1) {
        dfs(e[u][i], d + 1); sts[u] += sts[e[u][i]];
    }
}

int vct;

void merge_tree(int u, int v = MAXN)
{
    for (int i = 0; i < ALPHABET; ++i) if (e[u][i] != -1) {
        if (e[v][i] == -1) {
            e[v][i] = MAXN + vct;
            memset(e[MAXN + vct], -1, sizeof e[MAXN + vct]);
            ++vct;
        }
        merge_tree(e[u][i], e[v][i]);
    }
}

void dfs_nodep(int u)
{
    sts[u] = 1;
    for (int i = 0; i < ALPHABET; ++i) if (e[u][i] != -1) {
        dfs_nodep(e[u][i]); sts[u] += sts[e[u][i]];
    }
}

int check_tree(int u, int v = MAXN)
{
    if (u == -1) return sts[v];
    int ans = 0;
    for (int i = 0; i < ALPHABET; ++i) if (e[v][i] != -1) {
        ans += check_tree(e[u][i], e[v][i]);
    }
    return ans;
}

int main()
{
    memset(e, -1, sizeof e);
    scanf("%d", &n);
    int u, v; char ch;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d %c", &u, &v, &ch); --u, --v;
        e[u][ch - 'a'] = v;
    }

    dfs(0, 0);

    int prev_sz = 0;
    std::pair<int, int> ans(INF, -1);
    for (int i = 0; !layer[i].empty(); ++i) {
        int accum = 0;
        for (int u : layer[i]) {
            std::pair<int, int> pfc(-1, -1);
            for (int j = 0; j < ALPHABET; ++j) if (e[u][j] != -1) {
                pfc = std::max(pfc, std::make_pair(sts[e[u][j]], j));
            }
            if (pfc.second != -1) {
                memset(e[MAXN], -1, sizeof e[MAXN]);
                vct = 1;
                for (int j = 0; j < ALPHABET; ++j) if (e[u][j] != -1 && j != pfc.second) {
                    merge_tree(e[u][j]);
                }
                dfs_nodep(MAXN);
                accum += sts[e[u][pfc.second]];
                accum += check_tree(e[u][pfc.second]);
            } else {
                accum += 1;
            }
        }
        ans = std::min(ans, std::make_pair(accum + prev_sz, i));
        prev_sz += layer[i].size();
    }

    printf("%d\n%d\n", ans.first, ans.second + 1);

    return 0;
}