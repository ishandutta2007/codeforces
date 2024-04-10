#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
vector<int> adj[MN];
int dist[MN], cnt[MN], out[MN];
bool vis[MN];
int main () {
    int n,m; scanf ("%d %d",&n,&m);
    while (m--) {
        int a,b; scanf ("%d %d",&a,&b);
        adj[b].push_back(a); ++out[a];
    }
    memset(dist,0x3f,sizeof dist);
    dist[n] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,n});
    while (!pq.empty()) {
        auto [d,cur] = pq.top(); pq.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        for (int i : adj[cur]) {
            ++cnt[i];
            if (dist[cur] + 1 + out[i] - cnt[i] < dist[i]) {
                dist[i] = dist[cur] + 1 + out[i] - cnt[i];
                pq.push({dist[i],i});
            }
        }
    }
    printf ("%d\n",dist[1]);
    return 0;
}