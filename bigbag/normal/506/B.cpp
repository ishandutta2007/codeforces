#include <map>
#include <set>
#include <bitset>
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

int n, m, used[max_n];
vector<int> g[max_n], rg[max_n], comp;

void dfs(int v) {
    used[v] = 1;
    comp.push_back(v);
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i]);
        }
    }
    for (int i = 0; i < rg[v].size(); ++i) {
        if (used[rg[v][i]] == 0) {
            dfs(rg[v][i]);
        }
    }
}

bool dfs2(int v) {
    used[v] = 2;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] < 2) {
            if (dfs2(g[v][i])) {
                return true;
            }
        } else if (used[g[v][i]] == 2) {
            return true;
        }
    }
    used[v] = 3;
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            comp.clear();
            dfs(i);
            ans += comp.size() - 1;
            for (int j = 0; j < comp.size(); ++j) {
                int v = comp[j];
                if (used[v] == 1) {
                    if (dfs2(v)) {
                        ++ans;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}