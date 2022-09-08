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

int n, m, t[max_n], x[max_n], y[max_n], p[max_n], f[max_n], used[max_n];
int time, tin[max_n], tout[max_n], ans[max_n];
vector<int> g[max_n], q[max_n];

int find_set(int v) {
    if (v == p[v]) {
        return v;
    }
    return p[v] = find_set(p[v]);
}

void union_set(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (v1 != v2) {
        p[v1] = v2;
    }
}

void dfs(int v) {
    used[v] = 1;
    ++time;
    tin[v] = time;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i]);
        }
    }
    ++time;
    tout[v] = time;
}

bool is_ancestor(int v1, int v2) {
    return tin[v1] <= tin[v2] && tout[v1] >= tout[v2];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &t[i]);
        if (t[i] == 1) {
            scanf("%d%d", &x[i], &y[i]);
            g[y[i]].push_back(x[i]);
            f[x[i]] = 1;
        }
        if (t[i] == 2) {
            scanf("%d", &x[i]);
        }
        if (t[i] == 3) {
            scanf("%d%d", &x[i], &y[i]);
            q[y[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] + f[i] == 0) {
            dfs(i);
        }
    }
    int num = 0;
    for (int i = 0; i < m; ++i) {
        if (t[i] == 1) {
            union_set(x[i], y[i]);
        }
        if (t[i] == 2) {
            ++num;
            for (int j = 0; j < q[num].size(); ++j) {
                int v = x[q[num][j]];
                if (find_set(v) == find_set(x[i]) && is_ancestor(v, x[i])) {
                    ans[q[num][j]] = 1;
                } else {
                    ans[q[num][j]] = 0;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (t[i] == 3) {
            if (ans[i]) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}