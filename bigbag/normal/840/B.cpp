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

const int max_n = 300333, inf = 1011111111;

int n, m, a[max_n], used[max_n], pos, lb[max_n];
vector<int> g2[max_n], num2[max_n], g[max_n], num[max_n], k, ans;

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g2[v].size(); ++i) {
        if (used[g2[v][i]] == 0) {
            g[v].push_back(g2[v][i]);
            num[v].push_back(num2[v][i]);
            dfs(g2[v][i]);
        }
    }
}

void dfs2(int v) {
    for (int i = 0; i < g[v].size(); ++i) {
        dfs2(g[v][i]);
        lb[v] ^= lb[g[v][i]];
        if (lb[g[v][i]]) {
            ans.push_back(num[v][i]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    pos = -1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] == -1) {
            pos = i;
        }
        if (a[i] == 1) {
            k.push_back(i);
        }
    }
    if (pos == -1 && k.size() % 2 != 0) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g2[u].push_back(v);
        g2[v].push_back(u);
        num2[u].push_back(i);
        num2[v].push_back(i);
    }
    dfs(1);
    for (int i = 0; i + 1 < k.size(); i += 2) {
        lb[k[i]] = 1;
        lb[k[i + 1]] = 1;
    }
    if (k.size() % 2) {
        lb[pos] = 1;
        lb[k.back()] = 1;
    }
    dfs2(1);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d\n", ans[i] + 1);
    }
    return 0;
}