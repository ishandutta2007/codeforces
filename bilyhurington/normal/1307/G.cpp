/*
 * @Author: BilyHurington
 * @Date: 2020-08-07 10:33:57
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-08-07 11:16:05
 */
#include<bits/stdc++.h>
using namespace std;
int n,m,q;
namespace EK_Algorithm{
    struct edge{int to,nxt,flow,cost;}e[5010];int edge_tot;
    int S,T,MAXN_ID,bg[60],dis[60],lst[60];bool vis[60];
    void init(){memset(bg,-1,sizeof(bg));edge_tot=1;}
    void add_edge(int x,int y,int z,int w){
        e[++edge_tot]=(edge){y,bg[x],z,w};
        bg[x]=edge_tot;
    }
    void add(int x,int y,int z,int w){
        add_edge(x,y,z,w);
        add_edge(y,x,0,-w);
    }
    bool SPFA(){
        for(int i=0;i<=MAXN_ID;i++) dis[i]=2e9,vis[i]=0;
        queue<int> q;vis[S]=1;q.push(S);dis[S]=0;
        while(q.size()){
            int x=q.front();q.pop();vis[x]=0;
            for(int i=bg[x];i!=-1;i=e[i].nxt){
                if(!e[i].flow) continue;
                int to=e[i].to;
                if(dis[to]>dis[x]+e[i].cost){
                    dis[to]=dis[x]+e[i].cost;
                    lst[to]=i;
                    if(!vis[to]){
                        vis[to]=1;
                        q.push(to);
                    }
                }
            }
        }
        return dis[T]<1e9;
    }
    vector<pair<int,int> > EK(int s,int t,int id){
        S=s;T=t;MAXN_ID=id;
        vector<pair<int,int> > vec;
        int flow=0,cost=0;
        while(SPFA()){
            int t=2e9;
            for(int i=T;i!=S;i=e[lst[i]^1].to) t=min(t,e[lst[i]].flow);
            flow+=t;cost+=dis[T]*t;
            for(int i=T;i!=S;i=e[lst[i]^1].to) e[lst[i]].flow-=t,e[lst[i]^1].flow+=t;
            vec.push_back(make_pair(flow,cost));
        }
        return vec;
    }
}
int main(){
    scanf("%d %d",&n,&m);
    EK_Algorithm::init();
    for(int i=1,x,y,z;i<=m;i++){
        scanf("%d %d %d",&x,&y,&z);
        EK_Algorithm::add(x,y,1,z);
    }
    vector<pair<int,int> > vec=EK_Algorithm::EK(1,n,n);
    scanf("%d",&q);int x;
    while(q--){
        scanf("%d",&x);
        double ans=1e18;
        for(int i=0;i<vec.size();i++) ans=min(ans,1.0*(x+vec[i].second)/vec[i].first);
        printf("%.12lf\n",ans);
    }
    return 0;
}