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

const int max_n = 111111, inf = 111111111;

long long n, cost, cnt;
vector<long long> g[max_n], d[max_n];

long long dfs(int v, int p) {
    long long res = 0, k = cost;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            long long k1 = cost;
            cost += 2 * d[v][i];
            long long x = dfs(g[v][i], v);
            res = max(res, cost - k1 - d[v][i] - x);
        }
    }
    //cout << v << ' ' << k << ' ' << cost << ' ' << res << " - " << cost - k - res << endl;
    return cost - k - res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v, dist;
        cin >> u >> v >> dist;
        g[u].push_back(v);
        d[u].push_back(dist);
        g[v].push_back(u);
        d[v].push_back(dist);
    }
    cost = 0;
    if (cost != 0) {
        cout << "!!!";
    }
    cout << dfs(1, -1) << endl;
    return 0;
}