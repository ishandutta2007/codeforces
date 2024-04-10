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

const int max_n = 100011, inf = 1111111111;

struct dsu {
    int parent[2 * max_n];
    dsu() {
        for (int i = 0; i < 2 * max_n; ++i) {
            parent[i] = i;
        }
    }
    int find_set(int v) {
        if (v == inf) {
            return -1;
        }
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int v1, int v2) {
        v1 = find_set(v1);
        v2 = find_set(v2);
        parent[v1] = v2;
    }
};

int n, m, k, u[max_n], v[max_n], c[max_n], ans[max_n], sum[max_n];
dsu d;
vector<int> g[max_n];
vector<int>::iterator it;
pair<int, pair<int, int> > p[max_n];

int num(int v, int c) {
    it = lower_bound(g[v].begin(), g[v].end(), c);
    if (it == g[v].end()) {
        return inf;
    }
    return sum[v] + it - g[v].begin();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    dsu();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u[i], &v[i], &c[i]);
        g[u[i]].push_back(c[i]);
        g[v[i]].push_back(c[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
        cnt += g[i].size();
        sum[i + 1] = cnt;
    }
    for (int i = 0; i < m; ++i) {
        d.union_set(num(u[i], c[i]), num(v[i], c[i]));
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second.first);
        if (g[p[i].first].size() > g[p[i].second.first].size()) {
            swap(p[i].first, p[i].second.first);
        }
        p[i].second.second = i;
    }
    sort(p, p + k);
    for (int i = 0; i < k; ++i) {
        int res = 0;
        int u = p[i].first, v = p[i].second.first;
        for (int j = 0; j < g[u].size(); ++j) {
            int qqq = d.find_set(num(u, g[u][j]));
            if (qqq != -1 && qqq == d.find_set(num(v, g[u][j]))) {
                ++res;
            }
        }
        while (i + 1 < k && p[i + 1].first == u && p[i + 1].second.first == v) {
            ans[p[i].second.second] = res;
            ++i;
        }
        ans[p[i].second.second] = res;
    }
    for (int i = 0; i < k; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}