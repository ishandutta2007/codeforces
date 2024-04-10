#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, dist[max_n];
int k, p[max_n];
vector<int> g[max_n], rg[max_n];

void bfs(int t) {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(t);
    dist[t] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : rg[v]) {
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
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &p[i]);
        --p[i];
    }
    bfs(p[k - 1]);
    int mn = 0, mx = 0;
    for (int i = 0; i + 1 < k; ++i) {
        for (int to : g[p[i]]) {
            if (to != p[i + 1] && dist[to] + 1 == dist[p[i]]) {
                ++mx;
                break;
            }
        }
        if (dist[p[i + 1]] + 1 != dist[p[i]]) {
            ++mn;
        }
    }
    printf("%d %d\n", mn, mx);
    return 0;
}