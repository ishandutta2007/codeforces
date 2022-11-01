#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge{
    int to,cap,cost,rev;
    edge(){
        to=cap=cost=rev=0;
    }
    edge(int _t,int _c,int _w,int _r){
        to=_t;
        cap=_c;
        cost=_w;
        rev=_r;
    };
};

const int N=105;

vector<edge> g[N];
int iter[N],dis[N];
bool vis[N];

void addedge(int from,int to,int cap,int cost){
    g[from].emplace_back(to,cap,cost,g[to].size());
    g[to].emplace_back(from,0,-cost,g[from].size()-1);
}

bool getdis(int S,int T){
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    q.emplace(S);
    dis[S]=0;
    vis[S]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(edge &e:g[x])if(e.cap&&dis[e.to]>dis[x]+e.cost){
            dis[e.to]=dis[x]+e.cost;
            if(!vis[e.to]){
                vis[e.to]=1;
                q.emplace(e.to);
            }
        }
    }
    return dis[T]!=0x3f3f3f3f;
}

pair<ll,int> dfs(int x,int T,int flow){
    if(x==T)return {0,flow};
    vis[x]=1;
    pair<ll,int> res;
    for(int &i=iter[x];i<g[x].size();i++){
        edge &e=g[x][i];
        if(!vis[e.to]&&e.cap&&dis[x]+e.cost==dis[e.to]&&flow){
            pair<ll,int> cur=dfs(e.to,T,min(e.cap,flow));
            res.first+=cur.first+cur.second*e.cost;
            res.second+=cur.second;
            e.cap-=cur.second;
            g[e.to][e.rev].cap+=cur.second;
            flow-=cur.second;
        }
    }
    vis[x]=0;
    return res;
}

pair<ll,ll> mcf(int S,int T){
    pair<ll,ll> res;
    while(getdis(S,T)){
        memset(iter,0,sizeof(iter));
        pair<ll,int> cur;
        while((cur=dfs(S,T,1e9))!=make_pair(0ll,0)){
            res.first+=cur.first;
            res.second+=cur.second;
        }
    }
    return res;
}

int n,q,mn[55],mx[55];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    fill(mn+1,mn+1+n,1);
    fill(mx+1,mx+1+n,n);
    for(int i=0;i<q;i++){
        int typ,l,r,v;
        cin>>typ>>l>>r>>v;
        for(int i=l;i<=r;i++){
            typ==1?mn[i]=max(mn[i],v):mx[i]=min(mx[i],v);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n-1;j+=2)addedge(0,i,1,j);
        for(int j=mn[i];j<=mx[i];j++)addedge(j,i+n,1,0);
        addedge(i+n,n*2+1,1,0);
    }
    auto ans=mcf(0,n*2+1);
    if(ans.second!=n)ans.first=-1;
    cout<<ans.first;

    return 0;
}