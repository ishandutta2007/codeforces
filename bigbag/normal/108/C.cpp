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

const int max_n = 1111, inf = 1111111111;

int n, m, ans, last, used[max_n];
vector<int> g[max_n], rg[max_n], d[max_n];
vector<pair<int, pair<int, int> > > q;

void dfs(int v) {
    last = v;
    for (int i = 0; i < g[v].size(); ++i) {
        ans = min(ans, d[v][i]);
        dfs(g[v][i]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b, dd;
        scanf("%d%d%d", &a, &b, &dd);
        g[a].push_back(b);
        rg[b].push_back(a);
        d[a].push_back(dd);
    }
    for (int i = 1; i <= n; ++i) {
        if (rg[i].size() == 0 && g[i].size()) {
            ans = inf;
            dfs(i);
            q.push_back(make_pair(i, make_pair(last, ans)));
        }
    }
    printf("%d\n", q.size());
    for (int i = 0; i < q.size(); ++i) {
        printf("%d %d %d\n", q[i].first, q[i].second.first, q[i].second.second);
    }
    return 0;
}