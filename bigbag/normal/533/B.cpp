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

const int max_n = 222222;
const long long inf = 1000000000000000000LL;

int n, a[max_n];
long long dp[max_n][2];
vector<int> g[max_n];

void dfs(int v) {
    for (int i = 0; i < g[v].size(); ++i) {
        dfs(g[v][i]);
    }
    dp[v][0] = 0;
    dp[v][1] = -inf;
    long long q[2];
    for (int i = 0; i < g[v].size(); ++i) {
        q[0] = dp[v][0];
        q[1] = dp[v][1];
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                q[(j + k) % 2] = max(q[(j + k) % 2], dp[v][j] + dp[g[v][i]][k]);
            }
        }
        dp[v][0] = q[0];
        dp[v][1] = q[1];
    }
    //cout << v << " - " << dp[v][0] << " " << dp[v][1] << endl;
    dp[v][1] = max(dp[v][1], dp[v][0] + a[v]);
    //cout << v << " - " << dp[v][0] << " " << dp[v][1] << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int p;
        scanf("%d%d", &p, &a[i]);
        if (p == -1) {
            continue;
        }
        g[p].push_back(i);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}