#include <iostream>
#include <vector>
#define int long long
const int N = 205, P = 1000000007;
int T, n, k, x, y, num[N][N], f[N][N];
std::vector<int> g[N];
std::vector<int> a;
void dfs(int u, int fa) {
    num[u][0] = 1;
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
        for (int j = 1; j <= n; j++)
            num[u][j] += num[v][j-1];
    }
}
signed main() {
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        int ans = 0;
        for (int i = 1; i < n; i++)
            std::cin >> x >> y, g[x].push_back(y), g[y].push_back(x);
        if (k == 2) {
            std::cout << n * (n-1) / 2 << '\n';
            for (int i = 1; i <= n; i++) g[i].clear();
            continue;
        }
        for (int i = 1; i <= n; i++) {
            dfs(i, 0);
            for (int j = 1; j <= n; j++) {
                for (int l = 0; l < (int)g[i].size(); l++) 
                    a.push_back(num[g[i][l]][j-1]);
                f[0][0] = 1;
                for (int x = 1; x <= (int)a.size(); x++) {
                    f[x][0] = 1;
                    for (int y = 1; y <= x; y++)
                        f[x][y] = (f[x-1][y] + f[x-1][y-1]*a[x-1]%P) % P;
                }
                ans = (ans + f[a.size()][k]) % P;
                for (int x = 1; x <= (int)a.size(); x++)
                    for (int y = 1; y <= x; y++) f[x][y] = 0;
                a.clear();
            }
            for (int j = 1; j <= n; j++)
                for (int l = 0; l <= n; l++) num[j][l] = 0;
        }
        std::cout << ans << '\n';
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= n; j++) num[i][j] = 0;
    }
    return 0;
}