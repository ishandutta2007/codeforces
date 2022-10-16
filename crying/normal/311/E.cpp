#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=3e4+10,MAXM=3e5+10,INF=1e9;
struct Edge{
    int u,v,c,f;
}edge[MAXM];
int fst[MAXN],nxt[MAXM],tot;
int n,m,g,a[MAXN],v[MAXN],b[MAXN],s,t;
int ans,dis[MAXN],cur[MAXN];
queue<int>q;
void addedge(int u,int v,int c){
    edge[++tot]=(Edge){u,v,c,0};
    nxt[tot]=fst[u];fst[u]=tot;
}
int bfs(){
    rep(i,1,t)dis[i]=INF;
    dis[s]=0;q.push(s);
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
    return dis[t]!=INF;
}
int dfs(int u,int f){
    if(u==t || f==0)return f;
    int ret=0;
    for(int& j=cur[u];j;j=nxt[j]){
        int v=edge[j].v;
        if(dis[v]!=dis[u]+1)continue;
        int val=dfs(v,min(f,edge[j].c-edge[j].f));
        ret+=val;f-=val;
        edge[j].f+=val;edge[op(j)].f-=val;
        if(f==0)break;
    }
    return ret;
}
void dinic(){
    while(bfs()){
        rep(i,1,t)cur[i]=fst[i];
        ans-=dfs(s,INF);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&g);
    s=n+m+1,t=n+m+2;
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,n)scanf("%d",&v[i]);
    rep(i,1,n){
        if(!a[i])addedge(s,i,v[i]),addedge(i,s,0);
        else addedge(i,t,v[i]),addedge(t,i,0);
    }
    rep(i,1,m){
        int tag,w,flag,k;
        scanf("%d%d%d",&tag,&w,&k);
        rep(j,1,k)scanf("%d",&b[j]);
        scanf("%d",&flag);
        ans+=w;
        if(!tag){
            addedge(s,n+i,w+flag*g);addedge(n+i,s,0);
            rep(j,1,k)addedge(n+i,b[j],INF),addedge(b[j],n+i,0);
        }else{
            addedge(n+i,t,w+flag*g);addedge(t,n+i,0);
            rep(j,1,k)addedge(b[j],n+i,INF),addedge(n+i,b[j],0);
        }
    }
    dinic();
    printf("%d",ans);
    return 0;
}