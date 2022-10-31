#include <bits/stdc++.h>
typedef long long LL;
 
const int MOD = 258280327;
const LL Inf = (LL)1e16;
const int N = 100000 + 5;
 
int n,m,s,t;
std::vector<std::pair<int,int>> edges[N],redges[N];
int W[N];
LL dis[N],rdis[N];
int ways[N],rways[N];
 
void dijkstra(LL *dis,int *ways,std::vector<std::pair<int,int>> *edges,int s,int t) {
    std::priority_queue<std::pair<LL,int>,std::vector<std::pair<LL,int>>,
        std::greater<std::pair<LL,int>>> que;
    std::fill(dis,dis + n,Inf);
    dis[s] = 0;
    ways[s] = 1;
    que.push({dis[s],s});
    while (!que.empty()) {
        int u = que.top().second;
        LL tmp = que.top().first;
        que.pop();
        if (tmp != dis[u]) continue;
        for (auto t : edges[u]) {
            int v = t.first;
            int w = W[t.second];
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                ways[v] = ways[u];
                que.push({dis[v],v});
            } else if (dis[u] + w == dis[v]) {
                ways[v] += ways[u];
                if (ways[v] >= MOD) {
                    ways[v] -= MOD;
                }
            }
        }
    }
}
 
LL answer[N];
 
void work() {
    dijkstra(dis,ways,edges,s,t);
    dijkstra(rdis,rways,redges,t,s);
    for (int u = 0; u < n; ++ u) {
        for (auto tt : edges[u]) {
            int v = tt.first;
            int w = W[tt.second];
            int id = tt.second;
            if (dis[u] + w + rdis[v] == dis[t]
                    && ways[u] * 1ll * rways[v] % MOD == ways[t]) {
                answer[id] = 0;
            } else if (dis[t] - dis[u] - rdis[v] - 1 > 0) {
                LL tmp = dis[t] - dis[u] - rdis[v] - 1;
                answer[id] = w - tmp;
            } else {
                answer[id] = -1;
            }
        }
    }
    for (int i = 0; i < m; ++ i) {
        if (answer[i] == 0) {
            puts("YES");
        } else if (answer[i] == -1) {
            puts("NO");
        } else {
            printf("CAN %I64d\n",answer[i]);
        }
    }
}
 
int main() {
    scanf("%d%d%d%d",&n,&m,&s,&t); s --; t --;
    for (int i = 0; i < m; ++ i) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c); a --; b --;
        W[i] = c;
        edges[a].push_back({b,i});
        redges[b].push_back({a,i});
    }
    work();
}