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

const int max_n = 100011, max_k = 505, inf = 1111111111;

int n, m, k, c[max_n], num[max_n], used[max_n], dist[max_k][max_k];
vector<int> gn[max_n];

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < gn[v].size(); ++i) {
        if (used[gn[v][i]] == 0) {
            dfs(gn[v][i]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    int sum = 0;
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &c[i]);
        for (int j = sum + 1; j <= sum + c[i]; ++j) {
            num[j] = i;
        }
        sum += c[i];
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = inf;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        if (num[u] == num[v]) {
            if (x == 0) {
                gn[u].push_back(v);
                gn[v].push_back(u);
            }
        } else {
            if (x == 0) {
                gn[u].push_back(v);
                gn[v].push_back(u);
            }
            u = num[u], v = num[v];
            /*g[u].push_back(v);
            d[u].push_back(x);
            g[v].push_back(u);
            d[v].push_back(x);*/
            dist[u][v] = min(dist[u][v], x);
            dist[v][u] = min(dist[v][u], x);
        }
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i);
        while (i < n && num[i] == num[i + 1]) {
            if (used[i + 1] == 0) {
                printf("No\n");
                return 0;
            }
            ++i;
        }
    }
    for (int q = 1; q <= k; ++q) {
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (dist[i][q] != inf && dist[q][j] != inf) {
                    dist[i][j] = min(dist[i][j], dist[i][q] + dist[q][j]);
                }
            }
        }
    }
    printf("Yes\n");
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (dist[i][j] == inf) {
                printf("-1 ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}