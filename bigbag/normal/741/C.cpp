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

const int max_n = 2222222, inf = 1111111111;

int n, a[max_n], b[max_n], used[max_n];
vector<int> g[max_n];

void dfs(int v, int col) {
    used[v] = col;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i], ((col - 1) ^ 1) + 1);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i += 2) {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    for (int i = 1; i <= 2 * n; ++i) {
        if (used[i] == 0) {
            dfs(i, 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", used[a[i]], used[b[i]]);
    }
    return 0;
}