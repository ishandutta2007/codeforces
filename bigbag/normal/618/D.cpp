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

const int max_n = 222222, inf = 1111111111;

int n, x, y, used[max_n], last;
vector<int> g[max_n];

int dfs(int v, int p) {
    int res = 0, k = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            res += dfs(g[v][i], v);
            if (used[g[v][i]] == 0) {
                ++k;
            }
        }
    }
    if (k >= 2) {
        k = 2;
        used[v] = 1;
    }
    res += k;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (x <= y) {
        long long kx = dfs(1, -1);
        long long ky = n - 1 - kx;
        long long ans = x * kx + y * ky;
        cout << ans << endl;
        return 0;
    }
    long long f = 0;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() + 1 == n) {
            f = 1;
            break;
        }
    }
    long long kx = f, ky = n - 1 - f;
    long long ans = x * kx + y * ky;
    cout << ans << endl;
    return 0;
}