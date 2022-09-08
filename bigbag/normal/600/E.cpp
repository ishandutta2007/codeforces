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

int n, a[max_n], mx[max_n];
long long ans[max_n];
vector<int> g[max_n];

map<int, int> dfs(int v, int p) {
    map<int, int> res, to;
    res[a[v]] = 1;
    mx[v] = 1;
    ans[v] = a[v];
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        to = dfs(g[v][i], v);
        if (to.size() > res.size()) {
            res.swap(to);
            mx[v] = mx[g[v][i]];
            ans[v] = ans[g[v][i]];
        }
        for (map<int, int>::iterator it = to.begin(); it != to.end(); ++it) {
            pair<int, int> p = *it;
            int qq = (res[p.first] += p.second);
            if (qq > mx[v]) {
                mx[v] = qq;
                ans[v] = p.first;
            } else if (qq == mx[v]) {
                ans[v] += p.first;
            }
        }
    }
    to.clear();
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        printf("%I64d ", ans[i]);
    }
    return 0;
}