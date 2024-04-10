#include<bits/stdc++.h>
using namespace std;

bool ko_no_prime_da(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}

struct edge{
    int to,flow,id;
    edge(int _to,int _flow,int _id){
        to=_to;flow=_flow;id=_id;
    }
};

int n,ans;
vector<edge> g[205];
vector<int> ng[205];
vector<int> ansv[70];
bool vis[205];
int dis[205];
int a[205];
set<int> odd,even;

inline void addedge(int from,int to,int flow){
    edge foo(to,flow,g[to].size()),bar(from,0,g[from].size());
    g[from].push_back(foo);
    g[to].push_back(bar);
}

int dfs(int x,int cf){
    if(x==n+1)return cf;
    for(int i=0;i<g[x].size();i++){
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
        if(dis[n+1]==-1){
            return mxf;
        }
        mxf+=dfs(0,0x3f3f3f3f);
    }
}

void ngdfs(int x){
    vis[x]=true;
    ansv[ans].push_back(x);
    for(int i=0;i<ng[x].size();i++){
        int y=ng[x][i];
        if(!vis[y]){
            ngdfs(y);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]&1){
            odd.insert(i);
            addedge(0,i,2);
        }else{
            even.insert(i);
            addedge(i,n+1,2);
        }
    }
    for(set<int>::iterator i=odd.begin();i!=odd.end();i++){
        for(set<int>::iterator j=even.begin();j!=even.end();j++){
            if(ko_no_prime_da(a[*i]+a[*j])){
                addedge(*i,*j,1);
            }
        }
    }
    int mxf=dinic();
    cerr<<"MXF: "<<mxf<<endl;
    if(mxf!=2*even.size()){
        cout<<"Impossible"<<endl;
        return 0;
    }
    for(int x=1;x<=n;x++){
        if(!(a[x]&1))continue;
        for(int i=0;i<g[x].size();i++){
            int y=g[x][i].to,flow=g[x][i].flow;
            if(flow==0){
                ng[x].push_back(y);
                ng[y].push_back(x);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ++ans;
            ngdfs(i);
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++){
        cout<<ansv[i].size()<<' ';
        for(int j=0;j<ansv[i].size();j++){
            cout<<ansv[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}