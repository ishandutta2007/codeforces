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

const int max_n = 200222, inf = 1011111111;

int n, a[max_n], ans[max_n];
vector<int> g[max_n], all1, all, f;

void get_all(int x, vector<int> &v) {
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            v.push_back(i);
            if (i * i < x) {
                v.push_back(x / i);
            }
        }
    }
}

void update(int x, int pl) {
    for (int i = 0; i < all.size(); ++i) {
        if (x % all[i] == 0) {
            f[i] += pl;
        }
    }
}

void dfs(int v, int len, int p) {
    update(a[v], 1);
    ans[v] = 1;
    //cout << v << " " << len << "-------------------------" << endl;
    for (int i = 0; i < all.size(); ++i) {
        //cout << "#" << all[i] << " " << f[i] << endl;
        if (f[i] + 1 >= len) {
            ans[v] = max(ans[v], all[i]);
        }
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs(g[v][i], len + 1, v);
        }
    }
    update(a[v], -1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans[1] = a[1];
    get_all(a[1], all1);
    for (int i = 0; i < g[1].size(); ++i) {
        int v = g[1][i];
        all = all1;
        get_all(a[v], all);
        f.clear();
        for (int i = 0; i < all.size(); ++i) {
            f.push_back(0);
        }
        update(a[1], 1);
        dfs(v, 2, 1);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}