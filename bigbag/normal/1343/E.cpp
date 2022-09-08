#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222;
const long long inf = 1000111222000111222LL;

int t, n, m, a, b, c, dist[3][max_n], cost[max_n];
vector<int> g[max_n];
long long sum[max_n];

void clr() {
    for (int i = 0; i <= m; ++i) {
        sum[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}

void bfs(int start, int dist[]) {
    for (int i = 0; i < n; ++i) {
        dist[i] = -1;
    }
    dist[start] = 0;
    queue<int> q;
    q.push(start);
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
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
        --a;
        --b;
        --c;
        for (int i = 0; i < m; ++i) {
            scanf("%d", &cost[i]);
        }
        sort(cost, cost + m);
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bfs(a, dist[0]);
        bfs(b, dist[1]);
        bfs(c, dist[2]);
        for (int i = 0; i < m; ++i) {
            sum[i + 1] += sum[i] + cost[i];
        }
        long long ans = inf;
        for (int i = 0; i < n; ++i) {
            int tot = dist[0][i] + dist[1][i] + dist[2][i];
            if (tot > m) {
                continue;
            }
            long long res = sum[tot] + sum[dist[1][i]];
            ans = min(ans, res);
        }
        printf("%I64d\n", ans);
        clr();
    }
    return 0;
}