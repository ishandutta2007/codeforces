/**
 *  created: 14/01/2021, 17:00:27
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222;
const long long inf = 1000111222000111222LL;

int n, m;
vector<pair<int, int>> g[max_n];
long long dist[max_n][2][2];

struct state {
    int v, f1, f2;
    long long d;

    bool operator < (const state &s) const {
        return d > s.d;
    }
};

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
        for (int a = 0; a < 2; ++a) {
            for (int b = 0; b < 2; ++b) {
                dist[i][a][b] = inf;
            }
        }
    }
    priority_queue<state> q;
    dist[0][0][0] = 0;
    q.push({0, 0, 0, 0});
    while (!q.empty()) {
        auto s = q.top();
        q.pop();
        if (s.d != dist[s.v][s.f1][s.f2]) {
            continue;
        }
        //cout << s.v << " " << s.f1 << " " << s.f2 << ": " << s.d << endl;
        for (auto e : g[s.v]) {
            const int to = e.first, d = e.second;
            for (int nf1 = s.f1; nf1 < 2; ++nf1) {
                for (int nf2 = s.f2; nf2 < 2; ++nf2) {
                    long long nd = s.d + d;
                    if (s.f1 != nf1) {
                        nd -= d;
                    }
                    if (s.f2 != nf2) {
                        nd += d;
                    }
                    if (dist[to][nf1][nf2] > nd) {
                        dist[to][nf1][nf2] = nd;
                        q.push({to, nf1, nf2, nd});
                    }
                }
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        printf("%lld ", dist[i][1][1]);
    }
    puts("");
    return 0;
}