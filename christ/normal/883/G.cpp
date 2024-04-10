#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MN = 3e5+2;
vector<int> adj[MN];
int dist[MN];
char s[MN],s2[MN];
struct Edge {
    int t,a,b;
} edges[MN];
void dfs (int cur) {
    for (int i : adj[cur]) if (dist[i] == -1) {
        dist[i] = dist[cur] + 1;
        dfs(i);
    }
}
int main () {
    int n,m,st,ans=0,ans2=0;
    scanf ("%d %d %d",&n,&m,&st);
    for (int i = 1; i <= m; i++) {
        scanf ("%d %d %d",&edges[i].t,&edges[i].a,&edges[i].b);
        if (edges[i].t == 1) adj[edges[i].a].push_back(edges[i].b);
    }
    memset(dist,-1,sizeof dist); dist[st] = 0;
    dfs(st);
    for (int i = 1; i <= n; i++) if (dist[i] != -1) ++ans2;
    int ind = 0;
    for (int i = 1; i <= m; i++) if (edges[i].t == 2) {
        s2[ind++] = (dist[edges[i].a]==-1?'+':'-'); 
        adj[edges[i].a].push_back(edges[i].b);
        adj[edges[i].b].push_back(edges[i].a);
    }
    memset(dist,-1,sizeof dist); dist[st] = 0;
    dfs(st);
    for (int i = 1; i <= n; i++) if (dist[i] != -1) ++ans;
    ind = 0;
    for (int i = 1; i <= m; i++) if (edges[i].t == 2) s[ind++] = (dist[edges[i].a] < dist[edges[i].b] ? '+':'-');
    printf ("%d\n%s\n%d\n%s\n",ans,s,ans2,s2);
    return 0;
}