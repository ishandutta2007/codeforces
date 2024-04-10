#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 202222, max_k = 8, inf = 1011111111;

int n, k;
long long ans, dp[max_n][max_k], sum[max_n][max_k];
vector<int> g[max_n];

void write(int v) {
    cout << "$" << v << "  ";
    for (int i = 0; i < k; ++i) {
        cout << dp[v][i] << " ";
    }
    cout << "   ";
    for (int i = 0; i < k; ++i) {
        cout << sum[v][i] << " ";
    }
    cout << endl;
}

void dfs(int v, int p) {
    dp[v][0] = 1;
    sum[v][0] = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        dfs(g[v][i], v);
        //cout << v << " -> " << g[v][i] << endl;
        //write(v);
        for (int j = 0; j < k; ++j) {
            for (int q = 0; q < k; ++q) {
                long long pl = 0;
                ans += dp[v][j] * (sum[g[v][i]][q] + (q == 0) * dp[g[v][i]][q]) + dp[g[v][i]][q] * sum[v][j];
                if (j != 0 && q + 1 != k && j + q + 1 <= k) {
                    pl = -dp[v][j] * dp[g[v][i]][q];
                }
                ans += pl;
            }
        }
        for (int j = 0; j < k; ++j) {
            dp[v][(j + 1) % k] += dp[g[v][i]][j];
            sum[v][(j + 1) % k] += sum[g[v][i]][j] + (j == 0) * dp[g[v][i]][j];
        }
        //sum[v][0] += dp[g[v][i]][k - 1];
    }
    //write(v);
}

/*int res = 0;

void dfs2(int v, int p, int len) {
    res += len;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs2(g[v][i], v, len + 1);
        }
    }
}
int trivial() {

    for (int i = 1; i <= n; ++i) {
        dfs2(i, -1, 0);
    }
    return res / 2;
}*/

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    printf("%I64d\n", ans);
    //cout << trivial() << endl;
    return 0;
}