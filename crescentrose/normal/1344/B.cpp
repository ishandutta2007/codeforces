#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1010;
int ud[N][N], lr[N][N], mn[N][2], mx[N][2];
bool bz[N][N], bz1[N], bz2[N], bz3[N][N];
int du[N][N];
int n, m, sum;
char s[N][N];
vector<pair<int, int> > g[N][N];
void dfs(int x, int y) {
    if (bz3[x][y]) return ;
    bz3[x][y] = 1;
    for (auto u:g[x][y])
        dfs(u.first, u.second);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf(" %c", &s[i][j]), s[i][j] = (s[i][j] == '#');
    for (int i = 1; i <= n; i ++)
        for (int j = 2; j <= m; j ++)
            if ((s[i][j] ^ s[i][j - 1])) {
                if (s[i][j])
                    lr[i][1] ++, lr[i][j] --;
                else
                    lr[i][j] ++;
            }
    for (int i = 2; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if ((s[i][j] ^ s[i - 1][j]) ){
                if (s[i][j])
                    ud[1][j] ++, ud[i][j] --;
                else
                    ud[i][j] ++;
            }
    for (int i = 1; i <= max(m, n); i ++)
        mn[i][0] = mn[i][1] = 1e9;
    for (int i= 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            ud[i][j] += ud[i - 1][j], lr[i][j] += lr[i][j - 1];
            if (!ud[i][j] && !lr[i][j]) {
                bz[i][j] = 1, bz1[i] = bz2[j] = 1;
                mn[i][0] = min(mn[i][0], j);
                mx[i][0] = max(mx[i][0], j);
                mn[j][1] = min(mn[j][1], i);
                mx[j][1] = max(mx[j][1], i);
            }
        }
    bool sig = 1;
    for (int i = 1; i <= n; i ++)
        sig &= bz1[i];
    for (int i = 1; i <= m; i ++)
        sig &= bz2[i];
    if (!sig) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m;j ++)
            if (s[i][j]) {
                if (j > mn[i][0])
                    g[i][j].push_back({i, j - 1}), du[i][j - 1] ++;
                if (j < mx[i][0])
                    g[i][j].push_back({i, j + 1}), du[i][j + 1] ++;
                if (i > mn[j][1])
                    g[i][j].push_back({i - 1, j}), du[i - 1][j] ++;
                if (i < mx[j][1])
                    g[i][j].push_back({i + 1, j}), du[i + 1][j] ++;
            }
    for (int i= 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (!bz3[i][j] && s[i][j] && !du[i][j]) {
                sum ++;
                dfs(i, j);
            }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (!bz3[i][j] && s[i][j]) {
                ++sum;
                dfs(i, j);
            }
    printf("%d\n", sum);
    return 0;
}