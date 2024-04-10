#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 100;

int n, m;
vector<vector<int> > g;
int v1[max_n], v2[max_n], v3[max_n], c;
int used[max_n], tin[max_n], t;

void add_to_ans(int _v1, int _v2, int _v3) {
    v1[c] = _v1 + 1;
    v2[c] = _v2 + 1;
    v3[c] = _v3 + 1;
    ++c;
}

// 1,   
int dfs(int v, int pr) {
    tin[v] = t;
    ++t;
    used[v] = 1;
    int to_up = -1;
    int to_down = -1;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u == pr) continue;
        if (used[u]) {
            if (tin[u] > tin[v]) continue;
            if (to_up == -1) {
                to_up = u;
            } else {
                add_to_ans(to_up, v, u);
                to_up = -1;
            }
        } else {
            if (dfs(u, v)) {
                if (to_down == -1) {
                    to_down = u;
                } else {
                    add_to_ans(to_down, v, u);
                    to_down = -1;
                }
            }
        }
    }
    if (to_up != -1 && to_down != -1) {
        add_to_ans(to_up, v, to_down);
        return true;
    }
    if (to_up != -1) {
        add_to_ans(to_up, v, pr);
        return false;
    }
    if (to_down != -1) {
        add_to_ans(to_down, v, pr);
        return false;
    }
    return true;
}

int main() {
 //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    while (scanf("%d%d", &n, &m) != EOF) {
        g.clear();
        g.resize(n);
        for (int i = 0; i < m; ++i) {
            int v, u;
            scanf("%d%d", &v, &u);
            --v; --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        if ((m & 1) == 1) {
            printf("No solution\n");
            continue;
        }
        for (int i = 0; i < n; ++i)
            used[i] = 0;
        t = 0;
        c = 0;
        dfs(0, -1);
        for (int i = 0; i < c; ++i)
            printf("%d %d %d\n", v1[i], v2[i], v3[i]);
    }
    

    return 0;
}