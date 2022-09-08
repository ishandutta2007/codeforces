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

int n, m, used[2][max_n], sum;
vector<int> g[max_n], c[max_n], all;

bool dfs(int v, int q, int col) {
    used[q][v] = col;
    sum += col;
    all.push_back(v);
    for (int i = 0; i < g[v].size(); ++i) {
        int ncol = col ^ c[v][i];
        if (used[q][g[v][i]] == -1) {
            if (!dfs(g[v][i], q, ncol)) {
                return false;
            }
        } else if (used[q][g[v][i]] != ncol) {
            return false;
        }
    }
    return true;
}

int solve(int q) {
    int res = 0;
    memset(used[q], -1, sizeof(used[q]));
    for (int i = 1; i <= n; ++i) {
        if (used[q][i] == -1) {
            sum = 0;
            all.clear();
            if (!dfs(i, q, 0)) {
                return inf;
            }
            if (sum > all.size() - sum) {
                for (int j = 0; j < all.size(); ++j) {
                    used[q][all[j]] ^= 1;
                }
                sum = all.size() - sum;
            }
            res += sum;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        char cc;
        scanf("%d%d%c%c", &u, &v, &cc, &cc);
        g[u].push_back(v);
        g[v].push_back(u);
        c[u].push_back(cc == 'R');
        c[v].push_back(cc == 'R');
    }
    pair<int, int> ans = make_pair(inf, -1);
    for (int i = 0; i < 2; ++i) {
        ans = min(ans, make_pair(solve(i), i));
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k < g[j].size(); ++k) {
                c[j][k] ^= 1;
            }
        }
    }
    if (ans.first == inf) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans.first);
    for (int i = 1; i <= n; ++i) {
        if (used[ans.second][i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}