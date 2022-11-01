#include<bits/stdc++.h>
using namespace std;

struct edge{
    int to,flow,id;
    edge(int _to,int _flow,int _id){
        to=_to;flow=_flow;id=_id;
    }
};

int n;
vector<edge> g[10050];
bool vis[10050];
int dis[10050];
int iter[10050];

inline void addedge(const int &from,const int &to,const int &flow){
    edge foo(to,flow,g[to].size()),bar(from,0,g[from].size());
    g[from].push_back(foo);
    g[to].push_back(bar);
}

int dfs(int x,int cf){
    if(x==1)return cf;
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
    for(;;){//cerr<<"CFLOW: "<<mxf<<endl;
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
        if(dis[1]==-1){
            return mxf;
        }
        int tmp;
        while(tmp=dfs(0,114514))mxf+=tmp;
    }
}

int m,q;
pair<int,int> uq[10005];
int cuq[10005][5];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    for(int i=1;i<=q;i++){
        cin>>uq[i].first>>uq[i].second;
    }
    uq[q+1].first=m;uq[q+1].second=n;
    sort(uq+1,uq+2+q);
    int cur=0;
    for(int i=1;i<=q+1;i++){
        if(uq[i].first==uq[i-1].first&&uq[i].second!=uq[i-1].second){
            cout<<"unfair"<<endl;
            return 0;
        }
        if(uq[i].first-uq[i-1].first<uq[i].second-uq[i-1].second){
            cout<<"unfair"<<endl;
            return 0;
        }
        if(uq[i].second<uq[i-1].second){
            cout<<"unfair"<<endl;
            return 0;
        }
        while(cur<uq[i].first){
            cuq[i][(++cur)%5]++;
        }
        addedge(0,i+6,uq[i].second-uq[i-1].second);
        addedge(i+6,2,cuq[i][0]);
        addedge(i+6,3,cuq[i][1]);
        addedge(i+6,4,cuq[i][2]);
        addedge(i+6,5,cuq[i][3]);
        addedge(i+6,6,cuq[i][4]);
    }
    addedge(2,1,n/5);
    addedge(3,1,n/5);
    addedge(4,1,n/5);
    addedge(5,1,n/5);
    addedge(6,1,n/5);
    cout<<(dinic()==n?"fair":"unfair")<<endl;

    return 0;
}