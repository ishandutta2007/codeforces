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
const int MAXN=3e4+10,MAXM=3e5+10,INF=1e9;
struct E{
    int u,v,c,f;
}edge[MAXM];
int fst[MAXN],nxt[MAXM],tot;
void adde(int u,int v,int c){
    edge[++tot]=(E){u,v,c,0};
    nxt[tot]=fst[u];fst[u]=tot;
}
void link(int u,int v,int c){
    adde(u,v,c);
    adde(v,u,0);
}
int n,m,s[MAXN],b[MAXN],u[MAXN],v[MAXN],a[MAXN];
int S,T;

namespace Dinic{
    int dis[MAXN],cur[MAXN];
    queue<int>q;
    int bfs(){
        rep(i,1,T)dis[i]=INF;
        dis[S]=0;q.push(S);
        while(q.size()){
            int u=q.front();q.pop();
            for(int j=fst[u];j;j=nxt[j]){
                if(edge[j].c==edge[j].f)continue;
                int v=edge[j].v;
                if(dis[v]>dis[u]+1){
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
        return dis[T]!=INF;
    }
    int dfs(int u,int f){
        if(u==T || !f)return f;
        int res=0;
        for(int& j=cur[u];j;j=nxt[j]){
            int v=edge[j].v;
            if(dis[v]!=dis[u]+1)continue;
            int val=dfs(v,min(f,edge[j].c-edge[j].f));
            res+=val;f-=val;edge[j].f+=val;edge[op(j)].f-=val;
            if(!f)break;
        }
        return res;
    }

    int dinic(){
        int res=0;
        while(bfs()){
            rep(i,1,T)cur[i]=fst[i];
            res+=dfs(S,INF);
        }
        return res;
    }
};
int main(){
    cin>>n>>m;
    rep(i,1,n)cin>>s[i];
    rep(i,1,n)cin>>b[i];
    rep(i,1,m){
        cin>>u[i]>>v[i];
        a[u[i]]--;a[v[i]]--;
    }
    ll sum=0;
    rep(i,1,n)if(s[i]==1){
        if(a[i]>b[i] || odd((b[i]-a[i]))){
            cout<<"NO\n";
            return 0;
        }
        sum+=(b[i]-a[i])/2;
    }

    S=n+m+1,T=S+1;
    rep(i,1,m)link(S,n+i,1);
    int deg=0;
    rep(i,1,m)if(s[u[i]]==1 && s[v[i]]==1)link(n+i,u[i],1),link(n+i,v[i],1),deg++;
    rep(i,1,n)if(s[i]==1)link(i,T,(b[i]-a[i])/2);
    
    if(Dinic::dinic()!=deg){
        cout<<"NO\n";
        return 0;
    }
    rep(i,1,m)if(s[u[i]]==0 || s[v[i]]==0){
        if(s[u[i]]==1)link(n+i,u[i],1);
        if(s[v[i]]==1)link(n+i,v[i],1);
    }
    if(Dinic::dinic()!=sum-deg){
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";
    rep(i,1,m){
        if(s[u[i]]==0 && s[v[i]]==0){
            cout<<u[i]<<" "<<v[i]<<"\n";
            continue;
        }
        int tag=0;
        for(int j=fst[i+n];j;j=nxt[j]){
            if(edge[j].f==1 && edge[j].v==u[i])tag=1;
            else if(edge[j].f==1 && edge[j].v==v[i])tag=-1;
        }

        if(tag==1)cout<<v[i]<<" "<<u[i]<<"\n";
        else if(tag==-1)cout<<u[i]<<" "<<v[i]<<"\n";
        else{
            if(s[u[i]]==1)cout<<u[i]<<" "<<v[i]<<"\n";
            else cout<<v[i]<<" "<<u[i]<<"\n";
        }
    }

    return 0;
}