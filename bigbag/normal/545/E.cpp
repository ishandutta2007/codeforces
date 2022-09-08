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

const int max_n = 333333;
const long long inf = 1111111111111111111LL;

int n, m, st, p[max_n], dd[max_n];
long long ans, dist[max_n];
vector<int> g[max_n], d[max_n], a;
set<pair<long long, int> > q;
map<pair<int, int>, int> f;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d%d", &u, &v, &dd[i]);
        g[u].push_back(v);
        g[v].push_back(u);
        d[u].push_back(dd[i]);
        d[v].push_back(dd[i]);
        f[make_pair(u, v)] = i + 1;
        f[make_pair(v, u)] = i + 1;
    }
    scanf("%d", &st);
    for (int i = 1; i <= n; ++i) {
        dist[i] = inf;
        if (i == st) {
            dist[i] = 0;
        }
        q.insert(make_pair(dist[i], i));
    }
    while (!q.empty()) {
        pair<long long, int> P = *q.begin();
        q.erase(P);
        int v = P.second;
        if (p[v]) {
            int num = f[make_pair(v, p[v])];
            ans += dd[num - 1];
            a.push_back(num);
        }
        for (int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (dist[v] + d[v][i] <= dist[to]) {
                q.erase(make_pair(dist[to], to));
                dist[to] = dist[v] + d[v][i];
                p[to] = v;
                q.insert(make_pair(dist[to], to));
            }
        }
    }
    printf("%I64d\n", ans);
    for (int i = 0; i < a.size(); ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}