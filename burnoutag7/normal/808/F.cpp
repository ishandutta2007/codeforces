#include<bits/stdc++.h>
using namespace std;

struct edge_d{
    int to,cap,rev;
    edge_d(){
        to=cap=rev=0;
    }
    edge_d(int _t,int _c,int _r){
        to=_t;
        cap=_c;
        rev=_r;
    };
};

vector<edge_d> g[105];
int iter_d[105];
int lvl_d[105];

inline void addedge(int from,int to,int cap){
    g[from].emplace_back(to,cap,g[to].size());
    g[to].emplace_back(from,0,g[from].size()-1);
}

inline void bfs_d(int src){
    memset(lvl_d,-1,sizeof(lvl_d));
    queue<int> q;
    q.emplace(src);
    lvl_d[src]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(edge_d &e:g[x])if(e.cap&&lvl_d[e.to]==-1){
            lvl_d[e.to]=lvl_d[x]+1;
            q.emplace(e.to);
        }
    }
}

int dfs_d(int x,int dst,int flow){
    if(x==dst)return flow;
    for(int &i=iter_d[x];i<g[x].size();i++){
        edge_d &e=g[x][i];
        if(e.cap&&lvl_d[x]<lvl_d[e.to]&&flow){
            int cflow=dfs_d(e.to,dst,min(flow,e.cap));
            e.cap-=cflow;
            g[e.to][e.rev].cap+=cflow;
            if(cflow)return cflow;
        }
    }
    return 0;
}

int dinic(int src,int dst){
    int flow=0;
    while(true){
        bfs_d(src);
        if(lvl_d[dst]==-1)break;
        memset(iter_d,0,sizeof(iter_d));
        int cflow=0;
        while(cflow=dfs_d(src,dst,1145141919))flow+=cflow;
    }
    return flow;
}

int n,k,p[105],c[105],lv[105];

bool isprime(int x){
    for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}

bool check(int l){
    for(int i=0;i<=n+1;i++)g[i].clear();
    int mx1=-1,sum=0;
    for(int i=1;i<=n;i++)if(lv[i]<=l){
        if(c[i]==1){
            if(mx1==-1)mx1=i;
            else if(p[mx1]<p[i])mx1=i;
        }else if(c[i]&1)addedge(0,i,p[i]),sum+=p[i];
        else addedge(i,n+1,p[i]),sum+=p[i];
        if(c[i]&1)for(int j=1;j<=n;j++)if(lv[j]<=l&&c[j]&1^1){
            if(isprime(c[i]+c[j]))addedge(i,j,1145141919);
        }
    }
    if(mx1!=-1)addedge(0,mx1,p[mx1]),sum+=p[mx1];
    return k<=sum-dinic(0,n+1);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>c[i]>>lv[i];
    }
    int l=1,r=n,m,res=-1;
    while(l<=r){
        m=l+r>>1;
        if(check(m)){
            r=m-1;
            res=m;
        }else{
            l=m+1;
        }
    }
    cout<<res;

    return 0;
}