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

const int max_n = 202222, inf = 1111111111;
const int max_lev = 20;

int n, res, all, a[max_n], ans[max_n], h[max_n], b[max_n];
int p[max_lev][max_n];
long long sum[max_lev][max_n];
vector<int> g[max_n], d[max_n];

void dfs(int v) {
    for (int i = 0; i < g[v].size(); ++i) {
        p[0][g[v][i]] = v;
        sum[0][g[v][i]] = d[v][i];
        h[g[v][i]] = h[v] + 1;
        dfs(g[v][i]);
    }
}

void get_all() {
    p[0][1] = 0;
    for (int lev = 1; lev < max_lev; ++lev) {
        for (int i = 1; i <= n; ++i) {
            p[lev][i] = p[lev - 1][p[lev - 1][i]];
            sum[lev][i] = sum[lev - 1][i] + sum[lev - 1][p[lev - 1][i]];
        }
    }
}

int get(int v) {
    long long q = 0, mx = a[v];
    for (int i = max_lev - 1; i >= 0; --i) {
        if (sum[i][v] + q <= mx) {
            q += sum[i][v];
            v = p[i][v];
        }
    }
    return max(v, 1);
}

int dfs2(int v) {
    int res = b[v];
    for (int i = 0; i < g[v].size(); ++i) {
        res += dfs2(g[v][i]);
    }
    ans[v] = res - b[v];
    return res;

}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 2; i <= n; ++i) {
        int p, dist;
        scanf("%d%d", &p, &dist);
        g[p].push_back(i);
        d[p].push_back(dist);
    }
    dfs(1);
    get_all();
    for (int i = 1; i <= n; ++i) {
        --b[get(i)];
        ++b[i];
    }
    dfs2(1);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}