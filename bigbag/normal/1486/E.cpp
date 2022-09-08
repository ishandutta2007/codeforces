/**
 *  created: 18/02/2021, 17:08:20
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111;
const long long inf = 1000111222000111222LL;
const int max_x = 51;

int n, m;
vector<pair<int, int>> g[max_n];
long long dist[max_n][max_x];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        --u;
        --v;
        g[u].push_back({v, d});
        g[v].push_back({u, d});
    }
    for (int i = 0; i < n; ++i) {
        for (int x = 0; x < max_x; ++x) {
            dist[i][x] = inf;
        }
    }
    dist[0][0] = 0;
    priority_queue<pair<long long, pair<int, int>>> q;
    q.push({0, {0, 0}});
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int v = p.second.first, last = p.second.second;
        if (-p.first != dist[v][last]) {
            continue;
        }
        for (const auto &e : g[v]) {
            long long nd = dist[v][last] + e.second * e.second;
            int nlast = 0;
            if (!last) {
                nlast = e.second;
            } else {
                nd += 2 * last * e.second;
            }
            if (dist[e.first][nlast] > nd) {
                dist[e.first][nlast] = nd;
                q.push({-nd, {e.first, nlast}});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dist[i][0] == inf) {
            printf("-1 ");
        } else {
            printf("%lld ", dist[i][0]);
        }
    }
    puts("");
    return 0;
}