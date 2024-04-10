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

const int max_n = 222222, inf = 1011111111;

int n, ans, a[max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    ans = max(ans, a[v]);
    int col = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        while (col == a[v] || col == a[p]) {
            ++col;
        }
        a[g[v][i]] = col;
        ++col;
        dfs(g[v][i], v);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    a[1] = 1;
    ans = 1;
    dfs(1, 0);
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}