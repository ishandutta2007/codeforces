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

const int max_n = 1011111, inf = 1011111111;

int n, x, root, a[max_n], sum[max_n], dp[max_n];
vector<int> g[max_n];

void dfs(int v) {
    sum[v] = a[v];
    vector<int> q;
    for (int i = 0; i < g[v].size(); ++i) {
        dfs(g[v][i]);
        sum[v] += sum[g[v][i]];
        if (dp[g[v][i]] != -1) {
            q.push_back(dp[g[v][i]]);
            if (q.size() == 2) {
                printf("%d %d\n", q[0], q[1]);
                exit(0);
            }
        }
    }
    if (sum[v] == x) {
        dp[v] = v;
    }
    if (q.size()) {
        dp[v] = q[0];
    }
    if (sum[v] == 2 * x && q.size() && v != root) {
        printf("%d %d\n", v, q[0]);
        exit(0);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int num;
        scanf("%d%d", &num, &a[i]);
        if (num == 0) {
            root = i;
        } else {
            g[num].push_back(i);
        }
        x += a[i];
    }
    if (x % 3 != 0) {
        printf("-1\n");
        return 0;
    }
    x /= 3;
    memset(dp, -1, sizeof(dp));
    dfs(root);
    printf("-1\n");
    return 0;
}