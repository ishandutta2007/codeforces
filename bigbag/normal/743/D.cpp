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
const long long inf = 1111111111111111111LL;

int n, a[max_n];
vector<int> g[max_n];
vector<long long> q;
long long sz[max_n], mx[max_n], dp[max_n];

void dfs(int v, int p) {
    sz[v] = a[v];
    dp[v] = -inf;
    mx[v] = -inf;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs(g[v][i], v);
            sz[v] += sz[g[v][i]];
            mx[v] = max(mx[v], mx[g[v][i]]);
            dp[v] = max(dp[v], dp[g[v][i]]);
        }
    }
    mx[v] = max(mx[v], sz[v]);
    q.clear();
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            q.push_back(mx[g[v][i]]);
        }
    }
    sort(q.begin(), q.end());
    if (q.size() >= 2) {
        dp[v] = max(dp[v], q[q.size() - 2] + q[q.size() - 1]);
    }
    //cout << v << " " << mx[v] << " " << dp[v] << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    if (dp[1] == -inf) {
        printf("Impossible\n");
    } else {
        printf("%I64d\n", dp[1]);
    }
    return 0;
}