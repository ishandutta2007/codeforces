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

const int max_n = 101111, inf = 1011111111;

int n, m, a[max_n], used[max_n];
vector<int> g[max_n], num[max_n], all, allv;

bool dfs(int v, int col) {
    //cout << v << " " << col << endl;
    all.push_back(v);
    used[v] = col;
    for (int i = 0; i < g[v].size(); ++i) {
        a[g[v][i]] ^= col;
        if (col) {
            allv.push_back(g[v][i]);
        }
    }
    for (int i = 0; i < g[v].size(); ++i) {
        int to = num[g[v][i]][0] ^ num[g[v][i]][1] ^ v;
        int ncol = a[g[v][i]] ^ 1;
        if (used[to] == -1) {
            if (!dfs(to, ncol)) {
                return false;
            }
        } else if (a[g[v][i]] != 1) {
            return false;
        }
    }
    return true;
}

bool clr() {
    for (int i = 0; i < all.size(); ++i) {
        used[all[i]] = -1;
    }
    for (int i = 0; i < allv.size(); ++i) {
        a[allv[i]] ^= 1;
    }
    all.clear();
    allv.clear();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        int cnt;
        scanf("%d", &cnt);
        while (cnt--) {
            int x;
            scanf("%d", &x);
            --x;
            g[i].push_back(x);
            num[x].push_back(i);
        }
    }
    memset(used, -1, sizeof(used));
    for (int i = 0; i < m; ++i) {
        if (used[i] == -1) {
            //printf("#%d\n", i);
            if (!dfs(i, 0)) {
                clr();
                if (!dfs(i, 1)) {
                    printf("NO\n");
                    return 0;
                }
                all.clear();
                allv.clear();
            } else {
                all.clear();
                allv.clear();
            }
        }
    }
    printf("YES\n");
    return 0;
}