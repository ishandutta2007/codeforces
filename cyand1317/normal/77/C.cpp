#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
typedef long long int64;
static const int MAXN = 1e5 + 4;

int n, s;
int k[MAXN];
int head[MAXN], dest[MAXN * 2], next[MAXN * 2];

inline void add_edge(int u, int v) {
    static int w = 0;
    dest[w] = v; next[w] = head[u]; head[u] = w++;
}

int64 score[MAXN];
int remain[MAXN];

void dfs(int u, int p = -1)
{
    remain[u] = (p == -1 ? k[u] : k[u] - 1);
    score[u] = 0;
    for (int w = head[u]; w != -1; w = next[w])
        if (dest[w] != p) dfs(dest[w], u);
    static std::vector< std::pair<int64, int> > v;
    static int ch_remain_tot;
    v.clear(); ch_remain_tot = 0;
    for (int w = head[u]; w != -1; w = next[w])
        if (dest[w] != p) v.push_back(std::make_pair(score[dest[w]] + 2, dest[w]));
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());
    for (int i = 0; i < (int)v.size() && remain[u] > 0; ++i) {
        score[u] += v[i].first;
        --remain[u];
        ch_remain_tot += remain[v[i].second];
    }
    if (remain[u] > 0) {
        ch_remain_tot = std::min(ch_remain_tot, remain[u]);
        score[u] += ch_remain_tot * 2;
        remain[u] -= ch_remain_tot;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &k[i]);
    for (int i = 0; i < n; ++i) head[i] = -1;
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v);
        add_edge(v, u);
    }
    scanf("%d", &s); --s;
    dfs(s);
    printf("%I64d\n", score[s]);
    return 0;
}