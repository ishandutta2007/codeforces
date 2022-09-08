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

int n, m, s1, t1, l1, s2, t2, l2, dist[5][max_n];
int ans = inf;
vector<int> g[max_n];
queue<int> q;

void get_dist(int s, int num) {
    for (int i = 1; i <= n; ++i) {
        dist[num][i] = inf;
    }
    dist[num][s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); ++i) {
            if (dist[num][g[v][i]] == inf) {
                dist[num][g[v][i]] = dist[num][v] + 1;
                q.push(g[v][i]);
            }
        }
    }
}

void proc() {
    get_dist(s1, 0);
    get_dist(s2, 1);
    get_dist(t1, 2);
    get_dist(t2, 3);
    if (dist[0][t1] <= l1 && dist[1][t2] <= l2) {
        ans = min(ans, dist[0][t1] + dist[1][t2]);
    }
    for (int a = 1; a <= n; ++a) {
        get_dist(a, 4);
        for (int b = 1; b <= n; ++b) {
            int sumlen = dist[4][b];
            int len1 = dist[4][b] + dist[0][a] + dist[2][b];
            int len2 = dist[4][b] + dist[1][a] + dist[3][b];
            if (len1 <= l1 && len2 <= l2) {
                //cout << a << " " << b << " - " << len1 + len2 - sumlen << endl;
                ans = min(ans, len1 + len2 - sumlen);
            }
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    int M = m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    proc();
    swap(s1, t1);
    proc();
    swap(s2, t2);
    proc();
    swap(s1, t1);
    proc();
    if (M - ans < 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << M - ans << endl;
    return 0;
}