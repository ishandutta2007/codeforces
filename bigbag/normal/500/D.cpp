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

int n, q, u[max_n], v[max_n], dist[max_n], f[max_n];
long long ans, sz[max_n];
vector<int> g[max_n], d[max_n], num[max_n];

void dfs(int v) {
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (sz[g[v][i]] == 0) {
            f[num[v][i]] = g[v][i];
            dfs(g[v][i]);
            sz[v] += sz[g[v][i]];
            //cout << v << "->" << g[v][i] << "  " << sz[g[v][i]] << " " << n - sz[g[v][i]] << "  " << d[v][i] << endl;
            ans += sz[g[v][i]] * (n - sz[g[v][i]]) * d[v][i];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d", &u[i], &v[i], &dist[i]);
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        d[u[i]].push_back(dist[i]);
        d[v[i]].push_back(dist[i]);
        num[u[i]].push_back(i);
        num[v[i]].push_back(i);
    }
    dfs(1);
    double a = 1LL * (n - 1) * n;
    scanf("%d", &q);
    //cout << "!" << ans << endl;
    while (q--) {
        int r, w;
        scanf("%d%d", &r, &w);
        long long x = sz[f[r]] * (n - sz[f[r]]) * (dist[r]);
        long long nx = sz[f[r]] * (n - sz[f[r]]) * (w);
        dist[r] = w;
        ans = ans - x + nx;
        //cout << x << " " << nx << endl;
        //cout << "!" << ans << endl;
        printf("%.10lf\n", 6 * ans / a);
    }
    return 0;
}