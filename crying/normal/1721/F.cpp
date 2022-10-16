#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=4e5+10,MAXM=2e6+10,INF=1e9;
struct E{
    int u,v,c,f,idx;
}e[MAXM];
int fst[MAXN],nxt[MAXM],tot;
void adde(int u,int v,int c,int idx){
    e[++tot]=(E){u,v,c,0,idx};
    nxt[tot]=fst[u];fst[u]=tot;
}
void link(int u,int v,int c,int idx){
    adde(u,v,c,idx);
    adde(v,u,0,idx);
}
int L,R,m,q,S,T;
namespace Dinic{
    int dis[MAXN],cur[MAXN];
    queue<int>q;
    int bfs(){
        rep(i,1,T)dis[i]=INF;
        dis[S]=0;q.push(S);
        while(q.size()){
            int u=q.front();q.pop();
            for(int j=fst[u];j;j=nxt[j]){
                if(e[j].c==e[j].f)continue;
                int v=e[j].v;
                if(dis[v]>dis[u]+1){
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
        return dis[T]!=INF;
    }
    int dfs(int u,int f){
        if(!f || u==T)return f;
        int ret=0;
        for(int& j=cur[u];j;j=nxt[j]){
            int v=e[j].v;if(dis[v]!=dis[u]+1)continue;
            int val=dfs(v,min(f,e[j].c-e[j].f));
            ret+=val;f-=val;
            e[j].f+=val;e[op(j)].f-=val;
            if(!f)break;
        }
        return ret;
    }
    void dinic(){
        while(bfs()){
            rep(i,1,T)cur[i]=fst[i];
            dfs(S,INF);
        }
    }
};
set<int>V,E;
ll sum;

void graph_del(int u){
    V.erase(u);
    for(int j=fst[u];j;j=nxt[j])if(e[j].f && e[j].v<S)sum-=e[j].idx,E.erase(e[j].idx);
    cout<<"1\n";
    if(u<=L)cout<<u<<"\n";
    else cout<<-(u-L)<<"\n";
    cout<<sum<<"\n";
    fflush(stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>L>>R>>m>>q;
    S=L+R+1,T=S+1;
    rep(i,1,L)link(S,i,1,0);
    rep(i,1,R)link(L+i,T,1,0);
    rep(i,1,m){
        int u,v;cin>>u>>v;
        link(u,L+v,INF,i);
    }
    Dinic::dinic();
    Dinic::bfs();
    rep(i,1,L)if(Dinic::dis[i]==INF)V.insert(i);
    rep(i,L+1,L+R)if(Dinic::dis[i]!=INF)V.insert(i);
    for(auto u:V)for(int j=fst[u];j;j=nxt[j])if(e[j].f && e[j].v<S)sum+=e[j].idx,E.insert(e[j].idx);
    
    rep(i,1,q){
        int op;cin>>op;
        if(op==1){
            graph_del(*V.begin());
        }else{
            cout<<E.size()<<"\n";  
            for(auto u:E)cout<<u<<" ";cout<<"\n";fflush(stdout);
        }
    }
    

    return 0;
}