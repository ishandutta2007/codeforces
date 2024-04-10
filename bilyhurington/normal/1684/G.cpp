#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
namespace Dinic{
    struct edge{int to,nxt,flow;}e[10000010];
    int S,T,ed_tot,bg[2010],cur[2010],dep[2010];
    bool vis[2010];queue<int> q;
    void init(){ed_tot=1;memset(bg,0,sizeof(bg));}
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
            while(x=dfs(S,2e9)) flow+=x;
        }
        return flow;
    }
}
int n,m,a[1010];bool tag[1010];
vector<pair<int,int> > Ans;
int main(){
    scanf("%d %d",&n,&m);
    vector<int> v1,v2;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]*2ll+1>m){puts("-1");return 0;}
        if(a[i]*3ll>m){
            v2.push_back(a[i]);
        }else v1.push_back(a[i]);
    }Dinic::init();
    int S=0,T=v1.size()+v2.size()+1;
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            if(2ll*v2[j]+v1[i]<=m&&v2[j]%v1[i]==0){
                Dinic::add(i+1,v1.size()+j+1,1);
            }
        }
    }
    for(int i=0;i<v1.size();i++) Dinic::add(S,i+1,1);
    for(int i=0;i<v2.size();i++) Dinic::add(v1.size()+i+1,T,1);
    if(Dinic::solve(S,T)<v2.size()){puts("-1");return 0;}
    for(int i=0;i<v2.size();i++){
        int x=v1.size()+i+1;
        for(int j=Dinic::bg[x];j;j=Dinic::e[j].nxt){
            if(Dinic::e[j].flow==1){
                int t=Dinic::e[j].to-1;tag[t]=1;
                Ans.push_back(make_pair(v1[t]+v2[i],v1[t]+v2[i]*2));
            }
        }
    }
    for(int i=0;i<v1.size();i++){
        if(tag[i]) continue;
        Ans.push_back(make_pair(2*v1[i],3*v1[i]));
    }
    printf("%d\n",(int)Ans.size());
    for(auto pr:Ans) printf("%d %d\n",pr.first,pr.second);
    return 0;
}