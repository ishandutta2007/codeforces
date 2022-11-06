#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6;
int n, m, k;
int diss[N], dist[N], d[N];
vector<int>g[N];
vector<int>b;
void bfs(int x, int*dis) {
    for (int i= 1;i <= n; i ++)
        dis[i] = 1e9;
    dis[x] = 0;
    d[0] = 1;
    d[1] = x;
    for (int i = 1; i <= d[0]; i ++)
        for (auto u:g[d[i]])
            if (dis[u] == 1e9) {
                dis[d[++d[0]] = u] = dis[d[i]] + 1;
            }
}
int work(int x) {
    if (!x) return 0;
    int ans = 0;
    for (auto u:b) {
        int v = diss[n];
        v = min(v, min(diss[u] + 1 + dist[x], diss[x] + 1 +dist[u]));
        ans = max(ans, v);
    }
    return ans;
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    while (k --){
        int x;
        scanf("%d", &x);
        b.push_back(x);
    }
    for (int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1, diss);
    bfs(n, dist);
    sort(b.begin(), b.end(), [](int x, int y){return dist[x] > dist[y];});
    int mx = 0;
    int ans = 0;
    bool first = 1;
    for (auto u:b)
    {
        if (!first)
            ans = max(ans, min(diss[n], mx +  1 + dist[u]));
        first = 0;
        mx = max(mx, diss[u]);
    }
    printf("%d\n", ans);
    return 0;
}