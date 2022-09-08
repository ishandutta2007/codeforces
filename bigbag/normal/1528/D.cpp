/**
 *  created: 24/05/2021, 18:27:32
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 606, inf = 1000111222;

int n, m, val[max_n][max_n];
int dist[max_n], used[max_n], c[max_n], closest[max_n];

void calc_dist(int start) {
    for (int i = 0; i < n; ++i) {
        dist[i] = inf;
        used[i] = 0;
    }
    dist[start] = 0;
    for (int it = 0; it < n; ++it) {
        int v = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && (v == -1 || dist[i] < dist[v])) {
                v = i;
            }
        }
        used[v] = 1;
        for (int to = 0; to < n; ++to) {
            c[(to + dist[v]) % n] = val[v][to];
        }
        int mn = inf;
        for (int to = 0; to < n; ++to) {
            mn = min(mn, c[to] - to);
            closest[to] = mn + to;
        }
        mn = inf;
        for (int to = n - 1; to >= 0; --to) {
            mn = min(mn, c[to] + n - to);
            closest[to] = min(closest[to], mn + to);
        }
        for (int to = 0; to < n; ++to) {
            if (dist[to] > dist[v] + closest[to]) {
                dist[to] = dist[v] + closest[to];
                //cout << v << " -> " << to << "   " << dist[v] << " " << dist[to] << endl;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            val[i][j] = inf;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        val[a][b] = c;
    }
    for (int i = 0; i < n; ++i) {
        calc_dist(i);
        for (int j = 0; j < n; ++j) {
            printf("%d ", dist[j]);
        }
        puts("");
    }
    return 0;
}