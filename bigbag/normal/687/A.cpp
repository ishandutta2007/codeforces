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

int n, m, ans[max_n];
vector<int> g[max_n], q[2];

bool dfs(int v, int col) {
    ans[v] = col;
    for (int i = 0; i < g[v].size(); ++i) {
        if (ans[g[v][i]] == -1) {
            if (dfs(g[v][i], col ^ 1) == false) {
                return false;
            }
        } else if (ans[g[v][i]] != (col ^ 1)) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == -1) {
            if (dfs(i, 0) == false) {
                printf("-1\n");
                return 0;
            }
        }
        q[ans[i]].push_back(i);
    }
    for (int i = 0; i < 2; ++i) {
        printf("%d\n", q[i].size());
        for (int j = 0; j < q[i].size(); ++j) {
            printf("%d ", q[i][j]);
        }
        printf("\n");
    }
    return 0;
}