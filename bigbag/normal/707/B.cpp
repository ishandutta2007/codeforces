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

const int max_n = 111111;
const long long inf = 1111111111111111111LL;

int n, m, k;
vector<int> g[max_n], d[max_n];
long long dist[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        int u, v, dd;
        scanf("%d%d%d", &u, &v, &dd);
        g[u].push_back(v);
        g[v].push_back(u);
        d[u].push_back(dd);
        d[v].push_back(dd);
    }
    for (int i = 1; i <= n; ++i) {
        dist[i] = inf;
    }
    while (k--) {
        int x;
        scanf("%d", &x);
        dist[x] = 0;
    }
    set<pair<long long, int> > q;
    for (int i = 1; i <= n; ++i) {
        q.insert(make_pair(dist[i], i));
    }
    while (!q.empty()) {
        pair<long long, int> p = *q.begin();
        if (p.first != 0) {
            if (p.first == inf) {
                p.first = -1;
            }
            printf("%I64d\n", p.first);
            return 0;
        }
        q.erase(p);
        int v = p.second;
        for (int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (dist[to] > dist[v] + d[v][i]) {
                q.erase(make_pair(dist[to], to));
                dist[to] = dist[v] + d[v][i];
                q.insert(make_pair(dist[to], to));
            }
        }
    }
    printf("-1\n");
    return 0;
}