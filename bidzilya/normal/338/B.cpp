#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

int n, m, max_dist;
vector<vector<int> > g;
vector<int> dist, dang;
int ans = 0;

void build_dist(int v, int pr) {
    dist[v] = 0;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != pr) {
            build_dist(u, v);
            if (dang[u] || dist[u] > 0) {
                dist[v] = max(dist[v], dist[u] + 1);
            }
        }
    }
}

void build_ans(int v, int pr, int cur_dist) {
    if (dist[v] <= max_dist && (cur_dist == -1 || cur_dist <= max_dist))
        ++ans;
    int mx1 = -1, v1, mx2 = -1;
    if (dang[v]) {
        mx1 = 0;
        v1 = v;
    }
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != pr && (dang[u] || dist[u] > 0)) {
            if (mx1 == -1) {
                mx1 = dist[u] + 1;
                v1 = u;
            } else if (dist[u] + 1 > mx1) {
                mx2 = mx1;
                mx1 = dist[u] + 1;
                v1 = u;
            } else if (mx2 == -1 || dist[u] + 1 > mx2) {
                mx2 = dist[u] + 1;
            }
        }
    }
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != pr) {
            int new_cur_dist = -1;
            if (mx1 != -1 && v1 != u) {
                new_cur_dist = mx1;
            } else if (mx2 != -1) {
                new_cur_dist = mx2;
            }
            if (cur_dist != -1 && (new_cur_dist == -1 || cur_dist > new_cur_dist))
                new_cur_dist = cur_dist;
            if (new_cur_dist != -1)
                ++new_cur_dist;
            build_ans(u, v, new_cur_dist);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> max_dist;
    dang.resize(n);
    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;
        --v;
        dang[v] = 1;
    }
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1; --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dist.resize(n);
    build_dist(0, 0);
    build_ans(0, 0, -1);
    cout << ans << endl;
    return 0;
}