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

int n, m, ans, used[max_n];
vector<int> g[max_n];

bool dfs(int v, int p) {
    used[v] = 1;
    bool res = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        if (used[g[v][i]] == 0) {
            res |= dfs(g[v][i], v);
        } else if (used[g[v][i]] == 1) {
            res = 1;
        }
    }
    used[v] = 2;
    return res;
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
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            ans += 1 - dfs(i, -1);
        }
    }
    printf("%d\n", ans);
    return 0;
}