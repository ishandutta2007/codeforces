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

const int max_n = 222222, inf = 1111111111;

int n, m, dp[max_n], sz[max_n];
long long ans;
vector<int> g[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        ++sz[u];
        ++sz[v];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j] < i) {
                dp[i] = max(dp[i], dp[g[i][j]]);
            }
        }
        ++dp[i];
        ans = max(ans, 1LL * dp[i] * sz[i]);
        //cout << i << " " << dp[i] << " " << sz[i] << endl;
    }
    cout << ans << endl;
    return 0;
}