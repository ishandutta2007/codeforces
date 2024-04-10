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

const int max_n = 3033, inf = 1111111111;

int n, m, A[4], mx, dist[max_n][max_n];
queue<int> q;
vector<int> g[max_n];
vector<pair<int, int> > v1[max_n], v2[max_n];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a > b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        memset(dist[i], -1, sizeof(dist[i]));
        q.push(i);
        dist[i][i] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int j = 0; j < g[v].size(); ++j) {
                if (dist[i][g[v][j]] == -1) {
                    dist[i][g[v][j]] = dist[i][v] + 1;
                    q.push(g[v][j]);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j || dist[j][i] == -1) {
                continue;
            }
            v1[i].push_back(make_pair(dist[j][i], j));
            sort(v1[i].begin(), v1[i].end(), cmp);
            if (v1[i].size() > 3) {
                v1[i].pop_back();
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j || dist[i][j] == -1) {
                continue;
            }
            v2[i].push_back(make_pair(dist[i][j], j));
            sort(v2[i].begin(), v2[i].end(), cmp);
            if (v2[i].size() > 3) {
                v2[i].pop_back();
            }
        }
    }
    int mx = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == -1 || i == j) {
                continue;
            }
            for (int q = 0; q < v1[i].size(); ++q) {
                int a = v1[i][q].second;
                for (int w = 0; w < v2[j].size(); ++w) {
                    int b = v2[j][w].second;
                    if (mx < dist[a][i] + dist[i][j] + dist[j][b]) {
                        if (a != j && a != b && i != b) {
                            mx = dist[a][i] + dist[i][j] + dist[j][b];
                            A[0] = a;
                            A[1] = i;
                            A[2] = j;
                            A[3] = b;
                        }
                    }
                }
            }
        }
    }
    //cout << mx << endl;
    for (int i = 0; i < 4; ++i) {
        printf("%d ", A[i]);
    }
    return 0;
}