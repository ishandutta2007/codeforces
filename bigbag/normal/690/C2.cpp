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

int n, m;
vector<int> g[max_n];

pair<int, int> dfs(int v, int p, int len) {
    pair<int, int> res = make_pair(len, v);
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            res = max(res, dfs(g[v][i], v, len + 1));
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pair<int, int> p = dfs(1, -1, 0);
    p = dfs(p.second, -1, 0);
    printf("%d\n", p.first);
    return 0;
}