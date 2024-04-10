/**
 *  created: 04/01/2021, 16:59:44
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, m, d[max_n], best[max_n];
vector<int> g[max_n];

void calc_d() {
    for (int i = 0; i < n; ++i) {
        d[i] = -1;
    }
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (d[to] == -1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
}

void clr() {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}

int p[max_n];

bool cmp(int u, int v) {
    return d[u] < d[v];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        while (m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            g[u].push_back(v);
        }
        calc_d();
        for (int i = 0; i < n; ++i) {
            best[i] = d[i];
            for (int to : g[i]) {
                if (d[i] >= d[to]) {
                    best[i] = min(best[i], d[to]);
                }
            }
            p[i] = i;
        }
        sort(p, p + n, cmp);
        for (int i = n - 1; i >= 0; --i) {
            const int v = p[i];
            for (int to : g[v]) {
                if (d[v] < d[to]) {
                    best[v] = min(best[v], best[to]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            printf("%d ", best[i]);
        }
        puts("");
        clr();
    }
    return 0;
}