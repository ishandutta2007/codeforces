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

int n, sz[max_n], all_t[max_n], f[max_n];
vector<int> g[max_n], d[max_n];
vector<pair<double, int> > q;

double ans[max_n];

void dfs(int v, int p) {
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs(g[v][i], v);
            sz[v] += sz[g[v][i]];
            all_t[v] += all_t[g[v][i]] + 2 * d[v][i];
            all_t[g[v][i]] += 2 * d[v][i];
        }
    }
}

void get_ans(int v, int p) {
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            get_ans(g[v][i], v);
        }
    }
    q.clear();
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            f[g[v][i]] = d[v][i];
            q.push_back(make_pair((1.0 * all_t[g[v][i]]) / sz[g[v][i]], g[v][i]));
        }
    }
    sort(q.begin(), q.end());
    //reverse(q.begin(), q.end());
    int t = 0, n = sz[v];
    if (v == 1) {
        --n;
    }
    for (int i = 0; i < q.size(); ++i) {
        int v2 = q[i].second;
        //cout << q[i].first << " " << v2 << endl;
        ans[v] += ((1.0 * sz[v2]) / n) * (t + ans[v2] + f[v2]);
        t += all_t[v2];
    }
    //printf("%d %.5f        sz = %d\n", v, ans[v], sz[v]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        g[u].push_back(v);
        g[v].push_back(u);
        d[u].push_back(t);
        d[v].push_back(t);
    }
    dfs(1, -1);
    get_ans(1, -1);
    printf("%.10f\n", ans[1]);
    return 0;
}