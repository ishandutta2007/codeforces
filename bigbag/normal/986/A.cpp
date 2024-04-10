#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, max_k = 111, inf = 1000111222;

int n, m, k, s, dist[max_k][max_n], a[max_n], v[max_k];
vector<int> g[max_n];

void bfs(int dist[]) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &k, &s);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= k; ++i) {
        memset(dist[i], -1, sizeof(dist[i]));
        for (int j = 1; j <= n; ++j) {
            if (a[j] == i) {
                dist[i][j] = 0;
            }
        }
        bfs(dist[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            v[j - 1] = dist[j][i];
        }
        sort(v, v + k);
        int sum = 0;
        for (int j = 0; j < s; ++j) {
            sum += v[j];
        }
        printf("%d ", sum);
    }
    printf("\n");
    return 0;
}