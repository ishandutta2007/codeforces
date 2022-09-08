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

const int max_n = 30111, inf = 1011111111;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, k, x[max_n], y[max_n], dist[max_n];
vector<int> g[max_n], cost[max_n];
map<pair<int, int>, int> q;

int row(int num) {
    return k + num;
}

int col(int num) {
    return k + n + num;
}

void add(int v1, int v2, int c) {
    g[v1].push_back(v2);
    cost[v1].push_back(c);
}

void write(int v) {
    if (v < k) {
        cout << "(" << x[v] << " " << y[v] << ")";
    } else if (v < k + n) {
        cout << "row " << v - k;
    } else {
        cout << "col " << v - k - n;
    }
}

const bool debug = false;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        --x[i];
        --y[i];
    }
    for (int i = 0; i < k; ++i) {
        q[make_pair(x[i], y[i])] = i;
    }
    for (int i = 0; i < k; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (0 <= x[i] + j && x[i] + j < n) {
                add(i, row(x[i] + j), 1);
                add(row(x[i] + j), i, 0);
            }
            if (0 <= y[i] + j && y[i] + j < m) {
                add(i, col(y[i] + j), 1);
                add(col(y[i] + j), i, 0);
            }
        }
        for (int j = 0; j < 4; ++j) {
            int nx = x[i] + dx[j], ny = y[i] + dy[j];
            if (q.count(make_pair(nx, ny))) {
                add(i, q[make_pair(nx, ny)], 0);
            }
        }
    }

    set<pair<int, int> > all;
    for (int i = 0; i < k + n + m; ++i) {
        dist[i] = inf;
        if (i < k && x[i] == 0 && y[i] == 0) {
            dist[i] = 0;
        }
        all.insert(make_pair(dist[i], i));
    }
    while (all.size()) {
        pair<int, int> p = *all.begin();
        all.erase(p);
        int v = p.second;
        //write(v);
        //cout << " " << dist[v] << endl;
        for (int i = 0; i < g[v].size(); ++i) {
            if (dist[g[v][i]] > dist[v] + cost[v][i]) {
                if (debug) {
                    write(v);
                    cout << " -> ";
                    write(g[v][i]);
                    cout << "     " << dist[g[v][i]] << "   " << dist[v] << " + " << cost[v][i] << endl;
                }
                all.erase(make_pair(dist[g[v][i]], g[v][i]));
                dist[g[v][i]] = dist[v] + cost[v][i];
                all.insert(make_pair(dist[g[v][i]], g[v][i]));
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < k; ++i) {
        if (x[i] == n - 1 && y[i] == m - 1) {
            ans = min(ans, dist[i]);
        }
        if (x[i] == n - 1 || y[i] == m - 1) {
            ans = min(ans, dist[i] + 1);
            //cout << "#" << i << " " << dist[i] << endl;
        }
    }
    ans = min(ans, dist[k + n - 1]);
    ans = min(ans, dist[k + n + m - 1]);
    if (ans == inf) {
        ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}