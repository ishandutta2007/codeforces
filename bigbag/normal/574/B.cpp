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

const int max_n = 4111, inf = 1111111111;

int n, m, ans = inf, a[max_n][max_n];
vector<int> g[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        a[u][v] = 1;
        a[v][u] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            int v = g[i][j];
            for (int k = 0; k < g[v].size(); ++k) {
                int v2 = g[v][k];
                if (a[i][v2]) {
                    ans = min(ans, (int) (g[i].size() + g[v].size() + g[v2].size() - 6));
                }
            }
        }
    }
    if (ans == inf) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}