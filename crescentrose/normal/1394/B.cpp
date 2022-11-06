#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
bool ncan1[10][10], ncan2[10][10][10][10];
set<int> f[10][10];
int n, m, k;
vector<pair<int, int> > g[N];
int d[10];
int ans;
void dfs(int x) {
    if (x == k + 1) {
        ans ++;
        return;
    }
    for (int i = 1; i <= x; i ++)
        if (!ncan1[x][i]) {
            bool sig = 1;
            for (int j = 1; j < x; j ++)
                sig &= (!ncan2[x][i][j][d[j]]);
            if (sig) {
                d[x] = i;
                dfs(x + 1);
            }
        }
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i ++) {
        int x ,y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back({z, y});
    }
    for (int i= 1; i <= n; i ++) {
        sort(g[i].begin(),g[i].end());
        for (int j = 0; j < g[i].size(); j ++) {
            if (f[g[i].size()][j + 1].find(g[i][j].second) != f[g[i].size()][j + 1].end())
                ncan1[g[i].size()][j + 1] = 1;
            else {
                f[g[i].size()][j + 1].insert(g[i][j].second);
            }
        }
    }
    for (int i = 1; i <= 9; i ++)
        for (int j = 1; j <= i; j ++)
            if (!ncan1[i][j]) {
                for (auto u:f[i][j])
                    for (int k = 1; k <= 9; k++)
                        if (k != i)
                            for (int l = 1; l <= k; l++)
                                if (!ncan1[k][l] && !ncan2[i][j][k][l] && f[k][l].find(u) != f[k][l].end())
                                    ncan2[i][j][k][l] = 1;
            }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}