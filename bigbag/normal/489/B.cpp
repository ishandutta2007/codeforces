#include <map>
#include <set>
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

const int max_n = 505, inf = 111111111;

int n, m, a[max_n], b[max_n], used[max_n];
int c[max_n][max_n], f[max_n][max_n];
vector<int> g[max_n];

bool dfs(int u, int v, int c) {
    if (u == v) {
        return true;
    }
    if (used[u] == 1) {
        return false;
    }
    used[u] = 1;
    for (int ii = 0; ii < g[u].size(); ++ii) {
        int i = g[u][ii];
        if (::c[u][i] - f[u][i] >= c && dfs(i, v, c)) {
            f[u][i] += c;
            f[i][u] -= c;
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int s = n + m, t = n + m + 1;
    for (int i = 0; i < n; ++i) {
        g[s].push_back(i);
        c[s][i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        g[n + i].push_back(t);
        c[n + i][t] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (abs(a[i] - b[j]) <= 1) {
                c[i][n + j] = 1;
                g[i].push_back(n + j);
                g[n + j].push_back(i);
            }
        }
    }
    int current = inf;
    long long result = 0;
    while (current != 0) {
        memset(used, 0, sizeof(used));
        while (dfs(s, t, current)) {
            result += current;
            memset(used, 0, sizeof(used));
        }
        current /= 2;
    }
    cout << result << endl;
    return 0;
}