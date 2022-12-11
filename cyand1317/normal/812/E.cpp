#include <cstdio>
#include <map>
#include <vector>
typedef long long int64;
static const int MAXN = 1e5 + 4;

int n, a[MAXN], p[MAXN];
std::vector<int> e[MAXN];

bool level[MAXN];
std::map<int, int> count[2];
int tot[2] = { 0, 0 };
int oxo[2] = { 0, 0 };

inline void dfs_colour(int u)
{
    if (e[u].empty()) level[u] = false;
    else {
        for (int v : e[u]) dfs_colour(v);
        level[u] = level[e[u].front()] ^ 1;
    }
    count[level[u]][a[u]] += 1;
    tot[level[u]] += 1;
    oxo[level[u]] ^= a[u];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &p[i]); --p[i];
        e[p[i]].push_back(i);
    }

    dfs_colour(0);

    int64 ans = 0;
    if (oxo[0] == 0) {
        ans += (int64)tot[0] * (tot[0] - 1) / 2 + (int64)tot[1] * (tot[1] - 1) / 2;
        for (auto kv : count[0]) ans += (int64)kv.second * count[1][kv.first];
    } else {
        for (auto kv : count[0]) ans += (int64)kv.second * count[1][kv.first ^ oxo[0]];
    }

    printf("%I64d\n", ans);
    return 0;
}