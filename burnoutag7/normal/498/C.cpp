#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge{
    int to,cap,rev;
    edge(){
        to=cap=rev=0;
    }
    edge(int _t,int _c,int _r){
        to=_t;
        cap=_c;
        rev=_r;
    };
};

vector<edge> g[205];
int iter4dinic[205];
int level4dinic[205];

inline void addedge(const int &from,const int &to,const int &cap){
    g[from].emplace_back(to,cap,g[to].size());
    g[to].emplace_back(from,0,g[from].size()-1);
}

inline void bfs4dinic(const int &src){
    memset(level4dinic,-1,sizeof(level4dinic));
    queue<int> q;
    q.emplace(src);
    level4dinic[src]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(edge &e:g[x])if(e.cap&&level4dinic[e.to]==-1){
            level4dinic[e.to]=level4dinic[x]+1;
            q.emplace(e.to);
        }
    }
}

int dfs4dinic(const int &x,const int &dst,const int &flow){
    if(x==dst)return flow;
    for(int &i=iter4dinic[x];i<g[x].size();i++){
        edge &e=g[x][i];
        if(e.cap&&level4dinic[x]<level4dinic[e.to]&&flow){
            int cflow=dfs4dinic(e.to,dst,min(flow,e.cap));
            e.cap-=cflow;
            g[e.to][e.rev].cap+=cflow;
            if(cflow)return cflow;
        }
    }
    return 0;
}

ll dinic(const int &src,const int &dst){
    ll flow=0;
    while(true){
        bfs4dinic(src);
        if(level4dinic[dst]==-1)break;
        memset(iter4dinic,0,sizeof(iter4dinic));
        int cflow=0;
        while(cflow=dfs4dinic(src,dst,1145141919))flow+=cflow;
    }
    return flow;
}

int n,m,src,dst,tot;
vector<pair<int,int>> pdvs[105];
map<pair<int,int>,int> mp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    src=0;dst=1;tot=1;
    for(int i=1;i<=n;i++){
        static int tmp;
        cin>>tmp;
        for(int pd=2;pd*pd<=tmp;pd++){
            if(tmp%pd==0){
                pdvs[i].emplace_back(pd,0);
                while(tmp%pd==0){
                    tmp/=pd;
                    pdvs[i].back().second++;
                }
            }
        }
        if(tmp>1)pdvs[i].emplace_back(tmp,1);
        for(pair<int,int> &p:pdvs[i]){
            mp[make_pair(i,p.first)]=++tot;
            if(i&1)addedge(src,mp[make_pair(i,p.first)],p.second);
            else addedge(mp[make_pair(i,p.first)],dst,p.second);
        }
    }
    while(m--){
        static int l,r;
        cin>>l>>r;
        if(r&1)swap(l,r);
        for(int i=0,j=0;i<pdvs[l].size();i++){
            while(j<pdvs[r].size()&&pdvs[r][j].first<pdvs[l][i].first)j++;
            if(j==pdvs[r].size())break;
            if(pdvs[r][j].first==pdvs[l][i].first){
                addedge(mp[make_pair(l,pdvs[l][i].first)],mp[make_pair(r,pdvs[r][j].first)],min(pdvs[l][i].second,pdvs[r][j].second));
            }
        }
    }
    cout<<dinic(src,dst)<<endl;

    return 0;
}