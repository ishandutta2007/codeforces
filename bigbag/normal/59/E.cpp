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

const int max_n = 3333, inf = 111111111;

struct state {
    int a, b, c;
    state() {
        a = b = c = 0;
    }
    state(int aa, int bb, int cc) {
        a = aa;
        b = bb;
        c = cc;
    }
    bool operator < (const state &s) const {
        return a < s.a || a == s.a && b < s.b || a == s.a && b == s.b && c < s.c;
    }
};

int n, m, k, dist[max_n][max_n];
vector<int> g[max_n];
map<state, int> f;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        f[state(a, b, c)] = 1;
    }
    queue<pair<int, int> > q;
    q.push(make_pair(0, 1));
    dist[0][1] = 1;
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        int vv = v.second;
        for (int i = 0; i < g[vv].size(); ++i) {
            if (!f.count(state(v.first, vv, g[vv][i])) && dist[vv][g[vv][i]] == 0) {
                dist[vv][g[vv][i]] = dist[v.first][vv] + 1;
                q.push(make_pair(vv, g[vv][i]));
            }
        }
    }
    int ans = inf, poz1, poz2 = n;
    for (int i = 1; i < n; ++i) {
        if (dist[i][n] != 0) {
            if (ans > dist[i][n]) {
                ans = dist[i][n];
                poz1 = i;
            }
        }
    }
    if (ans == inf) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans - 1 << endl;
    vector<int> p;
    p.clear();
    while (poz1 != 1) {
        p.push_back(poz2);
        //cout << poz1 << ' ' << poz2 << endl;
        for (int i = 0; i < g[poz1].size(); ++i) {
            if (!f.count(state(g[poz1][i], poz1, poz2)) && dist[poz1][poz2] == dist[g[poz1][i]][poz1] + 1) {
                poz2 = poz1;
                poz1 = g[poz1][i];
                break;
            }
        }
    }
    p.push_back(poz2);
    p.push_back(1);
    reverse(p.begin(), p.end());
    for (int i = 0; i < p.size(); ++i) {
        cout << p[i] << ' ';
    }
    return 0;
}