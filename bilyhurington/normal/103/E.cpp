/*
 * @Author: BilyHurington
 * @Date: 2020-09-15 13:53:45
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-16 09:51:16
 */
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
namespace Dinic{
    struct edge{int to,nxt,flow;}e[1000010];
    int S,T,ed_tot,bg[610],cur[610],dep[610];
    bool vis[610];queue<int> q;
    void init(){ed_tot=1;}
    void add_edge(int x,int y,int z){
        e[++ed_tot]=(edge){y,bg[x],z};
        bg[x]=ed_tot;
    }
    void add(int x,int y,int z){
        add_edge(x,y,z);
        add_edge(y,x,0);
    }
    long long dfs(int x,long long flow){
        if(x==T) return flow;
        long long ans=0;vis[x]=1;
        for(int &i=cur[x];i;i=e[i].nxt){
            if(vis[e[i].to]||dep[e[i].to]!=dep[x]+1||!e[i].flow) continue;
            long long p=dfs(e[i].to,min(flow-ans,1ll*e[i].flow));
            if(!p) continue;
            e[i].flow-=p;e[i^1].flow+=p;ans+=p;
            if(ans==flow){i=e[i].nxt;break;}
        }
        vis[x]=0;return ans;
    }
    bool bfs(){
        memset(dep,0,sizeof(dep));
        q.push(S);dep[S]=1;
        while(q.size()){
            int x=q.front();q.pop();
            for(int i=bg[x];i;i=e[i].nxt){
                if(dep[e[i].to]||!e[i].flow) continue;
                dep[e[i].to]=dep[x]+1;
                q.push(e[i].to);
            }
        }
        return dep[T]>0;
    }
    long long solve(int s,int t){
        S=s;T=t;
        long long flow=0,x;
        while(bfs()){
            memcpy(cur,bg,sizeof(bg));
            while(x=dfs(S,2e9)) flow+=x;
        }
        return flow;
    }
}
int n;
int main(){
    scanf("%d",&n);Dinic::init();
    int s=0,t=2*n+1;
    for(int i=1;i<=n;i++) Dinic::add(i+n,t,INF);
    for(int i=1;i<=n;i++){
        int m;scanf("%d",&m);
        for(int j=1,x;j<=m;j++){
            scanf("%d",&x);
            Dinic::add(i,x+n,INF);
        }
    }
    long long sum=0;
    for(int i=1,x;i<=n;i++) scanf("%d",&x),Dinic::add(s,i,-x+INF),sum+=x;
    printf("%lld",sum+Dinic::solve(s,t)-1ll*INF*n);
}