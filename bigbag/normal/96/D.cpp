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

const int max_n = 1011, inf = 1000111111;
const long long inf2 = 111111111111111111LL;

int n, m, st, fin, dist[max_n];
long long dist2[max_n];
vector<int> g[max_n], d[max_n], g2[max_n], d2[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &st, &fin);
    for (int i = 0; i < m; ++i) {
        int u, v, dd;
        scanf("%d%d%d", &u, &v, &dd);
        g[u].push_back(v);
        g[v].push_back(u);
        d[u].push_back(dd);
        d[v].push_back(dd);
    }
    for (int i = 1; i <= n; ++i) {
        int max_d, cost;
        scanf("%d%d", &max_d, &cost);
        set<pair<int, int> > s;
        dist[i] = 0;
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                dist[j] = inf;
            }
            s.insert(make_pair(dist[j], j));
        }
        while (!s.empty()) {
            pair<int, int> p = *s.begin();
            s.erase(p);
            int v = p.second, dd = p.first;
            if (dd > max_d) {
                break;
            }
            if (v != i) {
                g2[i].push_back(v);
                d2[i].push_back(cost);
            }
            for (int j = 0; j < g[v].size(); ++j) {
                if (dd + d[v][j] < dist[g[v][j]]) {
                    s.erase(make_pair(dist[g[v][j]], g[v][j]));
                    dist[g[v][j]] = dd + d[v][j];
                    s.insert(make_pair(dist[g[v][j]], g[v][j]));
                }
            }
        }
    }
    set<pair<long long, int> > s;
    dist2[st] = 0;
    for (int j = 1; j <= n; ++j) {
        if (st != j) {
            dist2[j] = inf2;
        }
        s.insert(make_pair(dist2[j], j));
    }
    while (!s.empty()) {
        pair<long long, int> p = *s.begin();
        s.erase(p);
        int v = p.second;
        long long dd = p.first;
        //cout << v << " " << dd << endl;
        for (int i = 0; i < g2[v].size(); ++i) {
            //cout << v << " -> " << g2[v][i] << "   " << dd << " " << d2[v][i] << "   ?< " << dist2[g2[v][i]] << endl;
            if (dd + d2[v][i] < dist2[g2[v][i]]) {
                //cout << v << " !!-> " << g2[v][i] << endl;
                s.erase(make_pair(dist2[g2[v][i]], g2[v][i]));
                dist2[g2[v][i]] = dd + d2[v][i];
                s.insert(make_pair(dist2[g2[v][i]], g2[v][i]));
            }
        }
    }
    if (dist2[fin] == inf2) {
        printf("-1\n");
    } else {
        printf("%I64d\n", dist2[fin]);
    }
    return 0;
}