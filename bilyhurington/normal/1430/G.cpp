/*
 * @Author: BilyHurington
 * @Date: 2020-10-19 13:54:19
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-10-20 14:08:13
 */
#include<bits/stdc++.h>
using namespace std;
namespace Dinic{
    struct edge{int to,nxt;long long flow;}e[100010];
    int S,T,ed_tot,bg[610],cur[610],dep[610];
    bool vis[610];queue<int> q;
    void init(){memset(bg,0,sizeof(bg));ed_tot=1;}
    void add_edge(int x,int y,long long z){
        e[++ed_tot]=(edge){y,bg[x],z};
        bg[x]=ed_tot;
    }
    void add(int x,int y,long long z){
        // printf("%d %d %lld\n",x,y,z);
        add_edge(x,y,z);
        add_edge(y,x,0);
    }
    long long dfs(int x,long long flow){
        if(x==T) return flow;
        long long ans=0;vis[x]=1;
        for(int &i=cur[x];i;i=e[i].nxt){
            if(vis[e[i].to]||dep[e[i].to]!=dep[x]+1||!e[i].flow) continue;
            long long p=dfs(e[i].to,min(flow-ans,e[i].flow));
            if(!p) continue;
            e[i].flow-=p;e[i^1].flow+=p;ans+=p;
            if(ans==flow) break;
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
            while(x=dfs(S,1e18)) flow+=x;
        }
        return flow;
    }
    void DFS(int x){
        vis[x]=1;
        for(int i=bg[x];i;i=e[i].nxt){
            if(vis[e[i].to]||!e[i].flow) continue;
            DFS(e[i].to);
        }
    }
}
int n,m,s,t,val[20];
int id(int x,int y){return (x-1)*(n+1)+y+1;}
int main(){
    Dinic::init();scanf("%d %d",&n,&m);
    s=0;t=id(n,n)+1;
    for(int i=1,x,y,z;i<=m;i++){
        scanf("%d %d %d",&x,&y,&z);
        val[x]-=z;val[y]+=z;
        for(int j=0;j<n;j++) Dinic::add(id(y,j),id(x,j+1),1e18);
    }
    for(int i=1;i<=n;i++){
        Dinic::add(s,id(i,0),1e18);
        Dinic::add(id(i,n),t,1e18);
        for(int j=1;j<=n;j++) Dinic::add(id(i,j-1),id(i,j),-val[i]*(j-1)+1e10);
    }
    Dinic::solve(s,t);Dinic::DFS(s);
    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=0;j<=n;j++) if(Dinic::vis[id(i,j)]) ans=j;
        printf("%d ",ans); 
    }
    return 0;
}