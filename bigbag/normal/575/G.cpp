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

const int max_n = 111111, inf = 1111111111;

int n, m, dist[2][max_n], f[max_n], p2[max_n];
pair<int, pair<int, int> > p[max_n];
vector<int> g[max_n], d[max_n], all[2], ans;
queue<int> q;

void bfs2(int num, int st) {
    for (int i = 0; i < n; ++i) {
        dist[num][i] = -1;
    }
    dist[num][st] = 0;
    q.push(st);
    while (!q.empty()) {
        int v = q.front();
        f[v] = 1;
        q.pop();
        for (int i = 0; i < g[v].size(); ++i) {
            if (dist[num][g[v][i]] == -1 && d[v][i] == 0) {
                dist[num][g[v][i]] = dist[num][v] + 1;
                p2[g[v][i]] = v;
                q.push(g[v][i]);
            }
        }
    }
}

void bfs(int num, int st) {
    for (int i = 0; i < n; ++i) {
        dist[num][i] = -1;
    }
    dist[num][st] = 0;
    q.push(st);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); ++i) {
            if (dist[num][g[v][i]] == -1) {
                dist[num][g[v][i]] = dist[num][v] + 1;
                q.push(g[v][i]);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < max_n; ++i) {
        p[i] = make_pair(inf, make_pair(-1, 0));
    }
    memset(p2, -1, sizeof(p2));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        g[u].push_back(v);
        g[v].push_back(u);
        d[u].push_back(len);
        d[v].push_back(len);
    }
    bfs(0, 0);
    bfs2(1, n - 1);
    int minlen = inf;
    for (int i = 0; i < n; ++i) {
        if (f[i]) {
            minlen = min(minlen, dist[0][i]);
        }
    }
    int q1 = 0, q2 = 1;
    for (int i = 0; i < n; ++i) {
        if (f[i] && minlen == dist[0][i]) {
            all[q1].push_back(i);
            p[i] = make_pair(dist[1][i], make_pair(-1, i));
        }
    }
    int www = minlen, fw = 0;
    while (www--) {
        all[q2].clear();
        int mind = 11;
        for (int i = 0; i < all[q1].size(); ++i) {
            int v = all[q1][i];
            for (int j = 0; j < g[v].size(); ++j) {
                if (dist[0][g[v][j]] + 1 == dist[0][v]) {
                    mind = min(mind, d[v][j]);
                }
            }
        }
        fw = 1;
        printf("%d", mind);
        for (int i = 0; i < all[q1].size(); ++i) {
            int v = all[q1][i];
            for (int j = 0; j < g[v].size(); ++j) {
                if (dist[0][g[v][j]] + 1 == dist[0][v] && mind == d[v][j]) {
                    all[q2].push_back(g[v][j]);
                    p[g[v][j]] = min(p[g[v][j]], make_pair(dist[1][p[v].second.second], make_pair(v, p[v].second.second)));
                }
            }
        }
        swap(q1, q2);
    }
    if (fw == 0) {
        printf("0");
    }
    printf("\n");
    int v = 0;
    while (p[v].second.first != -1) {
        ans.push_back(v);
        v = p[v].second.first;
    }
    ans.push_back(v);
    while (p2[v] != -1) {
        v = p2[v];
        ans.push_back(v);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}