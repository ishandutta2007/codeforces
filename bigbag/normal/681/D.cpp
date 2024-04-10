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

int n, m, sz[max_n], res[max_n], p[max_n], ok[max_n], a[max_n];
vector<int> g[max_n], ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        p[y] = x;
        ++sz[x];
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        ok[a[i]] = 1;
        if (sz[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (ok[v]) {
            ans.push_back(v);
        }
        int x = -1;
        for (int i = 0; i < g[v].size(); ++i) {
            if (a[g[v][i]] != -1) {
                if (x == -1) {
                    x = a[g[v][i]];
                } else if (x != a[g[v][i]]) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
        if (x == v) {
            x = -1;
        }
        if (x == -1) {
            x = a[v];
        } else if (x != a[v]) {
            printf("-1\n");
            return 0;
        }
        if (x == v) {
            a[v] = -1;
        }
        --sz[p[v]];
        if (sz[p[v]] == 0) {
            q.push(p[v]);
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}