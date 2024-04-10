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

const int max_n = 111111;
const long long inf = 1111111111111111111LL;

int n, ans, a[max_n], sz[max_n], f[max_n];
vector<int> g[max_n], d[max_n];

void dfs1(int v, long long dd, long long mx) {
    mx = min(mx, dd);
    if (a[v] < dd - mx) {
        f[v] = 1;
    }
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        dfs1(g[v][i], dd + d[v][i], mx);
        sz[v] += sz[g[v][i]];
    }
}

void dfs2(int v) {
    if (f[v]) {
        ans += sz[v];
        return;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        dfs2(g[v][i]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 2; i <= n; ++i) {
        int p, dd;
        scanf("%d%d", &p, &dd);
        g[p].push_back(i);
        d[p].push_back(dd);
    }
    dfs1(1, 0, inf);
    dfs2(1);
    printf("%d\n", ans);
    return 0;
}