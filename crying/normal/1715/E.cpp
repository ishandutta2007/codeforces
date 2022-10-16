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
const ll MAXN=1e5+10,MAXK=25,INF=1e18;
ll n,m,k;
vector<array<ll,2> >e[MAXN];
ll dis[MAXK][MAXN],vis[MAXN];
struct Node{
    ll u,d;
    bool operator<(const Node& n2)const{
        return d>n2.d;
    }
};
priority_queue<Node>pq;
void dij(ll* d){
    memset(vis,0,sizeof vis);
    rep(i,1,n)pq.push((Node){i,d[i]});
    while(pq.size()){
        int u=pq.top().u;pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto p:e[u]){
            int v=p[0],w=p[1];
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push((Node){v,d[v]});
            }
        }
    }
}
int top;
array<ll,2>st[MAXN];
db calc(ll X1,ll Y1,ll X2,ll Y2){
    return 1.00*(Y2-Y1)/(X2-X1);
}
void add(ll X,ll Y){
    while(top>=2 && calc(st[top-1][0],st[top-1][1],st[top][0],st[top][1])>=calc(st[top][0],st[top][1],X,Y))top--;
    st[++top]={X,Y};
}
array<ll,2>qry(ll K){
    int L=1,R=top-1,ret=top;
    while(L<=R){
        int mid=(L+R)>>1;
        if(calc(st[mid][0],st[mid][1],st[mid+1][0],st[mid+1][1])>=K){
            ret=mid;R=mid-1;
        }else{
            L=mid+1;
        }
    }
    return st[ret];
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    rep(i,1,m){
        int u,v,w;cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    rep(i,0,k)rep(j,1,n)dis[i][j]=INF;
    dis[0][1]=0;
    dij(dis[0]);
    rep(i,1,k){
        //i-1->i
        top=0;
        per(j,n,1){
            ll X=-j,Y=dis[i-1][j]+1ll*j*j;
            add(X,Y);
        }
        rep(j,1,n)if(top){
            array<ll,2>ret=qry(-2*j);
            ll K=-ret[0],B=ret[1];
            dis[i][j]=min(dis[i][j],K*(-2*j)+B+1ll*j*j);
        }
        //dij
        dij(dis[i]);
    }
    rep(i,1,n)cout<<dis[k][i]<<" ";
    return 0;
}