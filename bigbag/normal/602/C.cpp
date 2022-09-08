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

const int max_n = 444, inf = 1111111111;

int n, m, f[max_n][max_n], dist[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        f[u][v] = f[v][u] = 1;
    }
    if (f[1][n]) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] ^= 1;
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == -1 && f[v][i]) {
                dist[i] = dist[v] + 1;
                q.push(i);
            }
        }
    }
    printf("%d\n", dist[n]);
    return 0;
}