#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
static const int MAXN = 102;
static const int MAXG = 503;

int n, m;
int g[MAXN][MAXN];
std::vector<std::pair<bool, int>> ans;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%d", (n > m ? &g[j][i] : &g[i][j]));
    bool flipped = false;
    if (n > m) {
        std::swap(n, m);
        flipped = true;
    }

    for (int i = 0; i < n; ++i) {
        int min = MAXG;
        for (int j = 0; j < m; ++j) min = std::min(min, g[i][j]);
        for (int j = 0; j < min; ++j) ans.push_back(std::make_pair(true, i));
        for (int j = 0; j < m; ++j) g[i][j] -= min;
    }
    for (int i = 0; i < m; ++i) {
        int min = MAXG;
        for (int j = 0; j < n; ++j) min = std::min(min, g[j][i]);
        for (int j = 0; j < min; ++j) ans.push_back(std::make_pair(false, i));
        for (int j = 0; j < n; ++j) g[j][i] -= min;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (g[i][j] != 0) { puts("-1"); return 0; }
    printf("%lu\n", ans.size());
    for (auto s : ans) printf("%s %d\n", (s.first ^ flipped) ? "row" : "col", s.second + 1);

    return 0;
}