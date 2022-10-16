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
const int MAXN=1e3+10,MAXM=3e6+10,INF=1e9;
int n,m,t[MAXN];
map<int,int>f,g,idx;
vector<int>L,R;
vector<array<int,2> >ret;
void output();
int S,T,tot;
namespace G{
    struct Edge{int u,v,c,f;}edge[MAXM];
    int fst[MAXN],nxt[MAXM],tot,n;
    void adde(int u,int v,int c){
        edge[++tot]=(Edge){u,v,c,0};
        nxt[tot]=fst[u];fst[u]=tot;
    }
    void link(int u,int v,int c){adde(u,v,c);adde(v,u,0);}
    int dis[MAXN],cur[MAXN],ans;
    queue<int>q;
    int bfs(){
        rep(i,1,n)dis[i]=INF;
        dis[S]=0;q.push(S);
        while(q.size()){
            int u=q.front();q.pop();
            for(int j=fst[u];j;j=nxt[j]){
                if(edge[j].c==edge[j].f)continue;
                int v=edge[j].v;if(dis[v]==INF){
                    dis[v]=dis[u]+1;q.push(v);
                }
            }
        }
        return dis[T]!=INF;
    }  
    int dfs(int u,int f){
        if(u==T || !f)return f;
        int ret=0;
        for(int& j=cur[u];j;j=nxt[j]){
            int v=edge[j].v;if(dis[v]!=dis[u]+1)continue;
            int val=dfs(v,min(f,edge[j].c-edge[j].f));
            edge[j].f+=val;edge[op(j)].f-=val;
            f-=val;ret+=val;
            if(!f)break;
        }
        return ret;
    }
    void dinic(){
        while(bfs()){
            rep(i,1,n)cur[i]=fst[i];
            ans+=dfs(S,INF);
        }
    }
    void solve(){
        rep(i,1,tot){
            int u=edge[i].u,v=edge[i].v;
            if(u<=2 || v<=2)continue;
            if(edge[i].c==0)continue;
            u=g[u],v=g[v];
            int k=edge[i].f;f[v]-=k;
            while(k--)ret.push_back({2*u+v,u+v});
        }
        for(auto u:L){
            int k=f[u];
            while(k--)ret.push_back({3*u,2*u});
        }
    }
};
int main(){
    cin>>n>>m;
    rep(i,1,n)cin>>t[i],f[t[i]]++;sort(t+1,t+1+n);
    if(t[n]>=(m+1)/2){cout<<-1;return 0;}
    for(auto p:f){
        int num=p.first;
        if(num<=(m/3))L.push_back(num);
        else R.push_back(num);
    }
    //build graph
    S=1;T=tot=2;
    for(auto p:f)idx[p.first]=++tot,g[tot]=p.first;
    for(auto u:R){
        G::link(S,idx[u],f[u]);
        for(auto v:L){
            if(u*2+v<=m && u%v==0){
                G::link(idx[u],idx[v],INF);
            }
        }
    }
    for(auto u:L)G::link(idx[u],T,f[u]);
    G::n=tot;G::dinic();
    int req=0;for(auto u:R)req+=f[u];
    if(G::ans != req){cout<<-1;return 0;}
    G::solve();
    output();
    return 0;
}
void output(){
    cout<<ret.size()<<'\n';
    for(auto u:ret)cout<<u[0]<<' '<<u[1]<<'\n';
}