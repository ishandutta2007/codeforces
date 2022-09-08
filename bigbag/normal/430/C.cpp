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

int n, a[max_n], b[max_n], used[max_n];
vector<int> g[max_n], ans;

void dfs(int v, int cnt1, int cnt2, int lev) {
    if (lev % 2 == 0 && cnt1 % 2 == 1 || lev % 2 == 1 && cnt2 % 2 == 1) {
        a[v] = (a[v] + 1) % 2;
    }
    if (a[v] != b[v]) {
        ans.push_back(v);
        if (lev % 2 == 0) ++cnt1;
        else ++cnt2;
    }
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i], cnt1, cnt2, lev + 1);
        }
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
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    dfs(1, 0, 0, 0);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}