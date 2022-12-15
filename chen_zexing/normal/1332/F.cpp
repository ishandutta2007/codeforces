#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
long long mod=998244353;
vector <int> v[300005];
long long dp[300005][2],f[300005];
void dfs(int x,int fa) {
    dp[x][0] = dp[x][1] = f[x] = 1;
    for (int i = 0; i < v[x].size(); i++) {
        if (v[x][i] != fa) {
            dfs(v[x][i], x);
            dp[x][0] *= dp[v[x][i]][1] + dp[v[x][i]][0] + dp[v[x][i]][1] - f[v[x][i]] + dp[v[x][i]][0];
            dp[x][1] *= dp[v[x][i]][0] + dp[v[x][i]][1] - f[v[x][i]] + dp[v[x][i]][0];
            f[x] *= dp[v[x][i]][1] - f[v[x][i]] + dp[v[x][i]][0];
            dp[x][0] %= mod, dp[x][1] %= mod, f[x] %= mod;
        }
    }
}
int main() {
    int n;
    cin >> n;
    int x, y;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    printf("%lld\n", ((dp[1][0] + dp[1][1] - f[1] - 1) % mod + mod) % mod);
    return 0;
}