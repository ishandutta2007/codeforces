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

int n, m, ans, a[max_n];
vector<int> g[max_n];

void dfs(int v, int cnt, int p) {
    if (a[v] == 0) {
        cnt = 0;
    } else {
        ++cnt;
    }
    if (cnt > m) {
        return;
    }
    int qqq = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs(g[v][i], cnt, v);
            ++qqq;
        }
    }
    if (qqq == 0) {
        ++ans;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, -1);
    printf("%d\n", ans);
    return 0;
}