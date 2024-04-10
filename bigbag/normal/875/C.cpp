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

const int max_n = 100111, inf = 1011111111;

int n, m, f[max_n], used[max_n], len[max_n];
vector<int> g[max_n], a[max_n], ans;

void dfs(int v) {
    ans.push_back(v);
    used[v] = 1;
    f[v] = 1;
    for (int to : g[v]) {
        if (used[to] == 0) {
            dfs(to);
        }
    }
}

bool cmp(int x, int y) {
    if (f[x] != f[y]) {
        return f[x] == 1;
    }
    return x < y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &len[i]);
        a[i].resize(len[i]);
        for (int j = 0; j < len[i]; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        int pos = 0;
        while (pos < len[i] && pos < len[i + 1] && a[i][pos] == a[i + 1][pos]) {
            ++pos;
        }
        if (pos == len[i]) {
            continue;
        }
        if (pos == len[i + 1]) {
            printf("No\n");
            return 0;
        }
        if (a[i][pos] < a[i + 1][pos]) {
            g[a[i + 1][pos]].push_back(a[i][pos]);
        } else {
            f[a[i][pos]] = 1;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (f[i] && used[i] == 0) {
            dfs(i);
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        int pos = 0;
        while (pos < len[i] && pos < len[i + 1] && a[i][pos] == a[i + 1][pos]) {
            ++pos;
        }
        if (pos == len[i]) {
            continue;
        }
        if (!cmp(a[i][pos], a[i + 1][pos])) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}