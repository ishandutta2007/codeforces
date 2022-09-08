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

const int max_n = 101111, inf = 1111111111;

int n, m, ok, dist[max_n], bad[max_n], p[max_n], ff[max_n], nxt[max_n], prev[max_n];
vector<int> g[max_n], f[max_n];
set<pair<int, int> > s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, q;
        scanf("%d%d%d", &u, &v, &q);
        ok += q;
        q ^= 1;
        g[u].push_back(v);
        g[v].push_back(u);
        f[u].push_back(q);
        f[v].push_back(q);
    }
    for (int i = 1; i <= n; ++i) {
        bad[i] = dist[i] = inf;
    }
    queue<int> q;
    q.push(1);
    dist[1] = 1;
    bad[1] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); ++i) {
            if (dist[v] + 1 < dist[g[v][i]]) {
                q.push(g[v][i]);
                dist[g[v][i]] = dist[v] + 1;
                bad[g[v][i]] = bad[v] + f[v][i];
                p[g[v][i]] = v;
            } else if (dist[v] + 1 == dist[g[v][i]] && bad[v] + f[v][i] < bad[g[v][i]]) {
                bad[g[v][i]] = bad[v] + f[v][i];
                p[g[v][i]] = v;
            }
        }
    }
    /*for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " " << bad[i] << endl;
    }*/
    printf("%d\n", ok - dist[n] + 1 + 2 * bad[n]);
    int k = n;
    while (k != 1) {
        //cout << "!" << k << endl;
        nxt[p[k]] = k;
        prev[k] = p[k];
        k = p[k];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (nxt[i] != g[i][j] && prev[i] != g[i][j]) {
                if (f[i][j] == 0) {
                    int u1 = i, v1 = g[i][j];
                    if (u1 > v1) {
                        swap(u1, v1);
                    }
                    pair<int, int> pp = make_pair(u1, v1);
                    if (!s.count(pp)) {
                        printf("%d %d %d\n", i, g[i][j], 0);
                    }
                    s.insert(pp);
                }
            } else {
                if (f[i][j] == 1) {
                    int u1 = i, v1 = g[i][j];
                    if (u1 > v1) {
                        swap(u1, v1);
                    }
                    pair<int, int> pp = make_pair(u1, v1);
                    if (!s.count(pp)) {
                        printf("%d %d %d\n", i, g[i][j], 1);
                    }
                    s.insert(pp);
                }
            }
        }
    }
    return 0;
}