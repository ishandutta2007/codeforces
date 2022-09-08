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

const int max_n = 111111, inf = 1111111111;

int n;
long double dp[max_n], dp2[max_n];
vector<int> g[max_n];

void dfs(int v) {
    dp2[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        dfs(g[v][i]);
        dp2[v] += dp2[g[v][i]];
    }
}

void dfs2(int v) {
    if (g[v].size() == 0) {
        return;
    }
    long double sum = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        sum += dp2[g[v][i]];
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v].size() > 1) {
            dp[g[v][i]] = (sum - dp2[g[v][i]]) / 2;
        }
        dp[g[v][i]] += (dp[v] + 1);
        dfs2(g[v][i]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        int p;
        scanf("%d", &p);
        g[p].push_back(i);
    }
    dfs(1);
    dp[1] = 1;
    dfs2(1);
    for (int i = 1; i <= n; ++i) {
        printf("%.10f ", (double) dp[i]);
    }
    printf("\n");
    return 0;
}