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

const int max_n = 202222, inf = 1011111111;

int n, m, k, used[max_n];
vector<int> g[max_n], all;

void dfs(int v) {
    used[v] = 1;
    all.push_back(v);
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i]);
            all.push_back(v);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    if (all.size() + 1 != 2 * n) {
        exit(228);
    }
    int cnt = (2 * n + k - 1) / k, st = 0;
    for (int i = 0; i < k; ++i) {
        if (st < all.size()) {
            int q = 0;
            for (int j = st; j < st + cnt && j < all.size(); ++j) {
                ++q;
            }
            printf("%d ", q);
            for (int j = st; j < st + cnt && j < all.size(); ++j) {
                printf("%d ", all[j]);
            }
            printf("\n");
            st += cnt;
        } else {
            printf("1 1\n");
        }
    }
    return 0;
}