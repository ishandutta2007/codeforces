#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
struct dij{
    vector <pair<int,int>> v[200005];
    struct node{
        int x;
        long long dis;
        friend bool operator <(node a,node b){
            return a.dis>b.dis;
        }
    };
    long long dis[200005];
    int vis[200005];
    void add_edge(int x,int y,int w){
        v[x].push_back({y,w});
    }
    void solve(int st,int n){
        for(int i=1;i<=n;i++) dis[i]=LLONG_MAX/10;
        priority_queue <node> q;
        dis[st]=0,q.push({st,0});
        while(!q.empty()){
            auto temp=q.top();
            q.pop();
            if(vis[temp.x]) continue;
            vis[temp.x]=1;
            for(auto t:v[temp.x])
                if(!vis[t.first]&&temp.dis+t.second<dis[t.first])
                    dis[t.first]=temp.dis+t.second,q.push(node{t.first,dis[t.first]});
        }
    }
}G;
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n,m;
        cin>>n>>m;
        for(int i=1,x,y,w;i<=m;i++){
            scanf("%d%d%d",&x,&y,&w);
            G.add_edge(x,y,w),G.add_edge(y+n,x+n,w);
        }
        for(int i=1;i<=n;i++) G.add_edge(i,i+n,0);
        G.solve(1,n*2);
        for(int i=2;i<=n;i++){
            long long d=min(G.dis[i],G.dis[i+n]);
            if(d==LLONG_MAX/10) printf("-1");
            else printf("%lld",d);
            printf("%c",i==n?'\n':' ');
        }
    }
    return 0;
}