#include<bits/stdc++.h>
using namespace std;

struct edge{
    int to,flow,id;
    edge(int _to,int _flow,int _id){
        to=_to;flow=_flow;id=_id;
    }
};

int n;
vector<edge> g[205];
bool vis[205];
int dis[205];
int iter[205];

inline void addedge(const int &from,const int &to,const int &flow){
    edge foo(to,flow,g[to].size()),bar(from,0,g[from].size());
    g[from].push_back(foo);
    g[to].push_back(bar);
}

int dfs(int x,int cf){
    if(x==(n<<1|1))return cf;
    for(int &i=iter[x];i<g[x].size();i++){
        edge &e=g[x][i];
        if(e.flow!=0&&dis[e.to]>dis[x]){
            int d=dfs(e.to,min(cf,e.flow));
            if(d){
                e.flow-=d;
                g[e.to][e.id].flow+=d;
                return d;
            }
        }
    }
    return 0;
}

int dinic(){
    int mxf=0;
    for(;;){
        queue<int> q;
        q.push(0);
        memset(dis,-1,sizeof(dis));
        memset(iter,0,sizeof(iter));
        dis[0]=0;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int i=0;i<g[x].size();i++){
                int y=g[x][i].to;
                if(g[x][i].flow!=0&&dis[y]==-1){
                    dis[y]=dis[x]+1;
                    q.push(y);
                }
            }
        }
        if(dis[n<<1|1]==-1){
            return mxf;
        }
        int tmp;
        while(tmp=dfs(0,114514))mxf+=tmp;
    }
}

int m;
int a[105];
int b[105];
int roam[105][105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[0]+=a[i];
        addedge(0,i,a[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        b[0]+=b[i];
        addedge(i+n,n<<1|1,b[i]);
        addedge(i,i+n,114514);
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        addedge(u,v+n,114514);
        addedge(v,u+n,114514);
    }
    if(dinic()!=b[0]||a[0]!=b[0]){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<g[0].size();i++){
        int &x=g[0][i].to;
        for(int i=0;i<g[x].size();i++){
            if(g[x][i].to)roam[x][g[x][i].to-n]=114514-g[x][i].flow;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<roam[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}