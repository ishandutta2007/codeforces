#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111111;

int n;
vector<int> q, g[max_n];

void dfs(int v, int p, int d) {
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs(g[v][i], v, d + 1);
        }
    }
    if (g[v].size() == 1) {
        q.push_back(d);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int i = 0; i < g[1].size(); ++i) {
        q.clear();
        dfs(g[1][i], 1, 0);
        sort(q.begin(), q.end());
        int res = -1;
        for (int i = 0; i < q.size(); ++i) {
            //cout << q[i] << " ";
            res = max(res + 1, q[i]);
        }
        //cout << "  res = ";
        //cout << res << endl;
        ans = max(ans, res + 1);
    }
    printf("%d\n", ans);
    return 0;
}