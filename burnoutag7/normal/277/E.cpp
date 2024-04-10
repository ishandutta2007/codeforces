#include<bits/stdc++.h>
using namespace std;

struct edge{
    int to,cap,rev;
    double cost;
    edge(){
        to=cap=cost=rev=0;
    }
    edge(int _t,int _c,double _cc,int _r){
        to=_t;
        cap=_c;
        cost=_cc;
        rev=_r;
    }
};

vector<edge> g[805];
double h[805],dist[805];
int prevv[805],preve[805];

void addedge(const int &from,const int &to,const int &cap,const double &cost){
    g[from].emplace_back(to,cap,cost,g[to].size());
    g[to].emplace_back(from,0,-cost,g[from].size()-1);
}

double min_cost_flow(const int &V,const int &src,const int &dst,int flow){
    double res=0;
    memset(h,0,sizeof(h));
    while(flow>0){
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        fill(dist,dist+805,1e18);
        dist[src]=0;
        pq.emplace(0,src);
        while(!pq.empty()){
            int x=pq.top().second,cd=pq.top().first;
            pq.pop();
            if(cd>dist[x])continue;
            for(int i=0;i<g[x].size();i++){
                edge &e=g[x][i];
                if(e.cap&&dist[e.to]>dist[x]+e.cost+h[x]-h[e.to]){
                    dist[e.to]=dist[x]+e.cost+h[x]-h[e.to];
                    prevv[e.to]=x;
                    preve[e.to]=i;
                    pq.emplace(dist[e.to],e.to);
                }
            }
        }
        if(dist[dst]==1e18)return -1;
        for(int v=0;v<=V;v++){
            h[v]+=dist[v];
        }
        int cflow=flow;
        for(int v=dst;v!=src;v=prevv[v]){
            cflow=min(cflow,g[prevv[v]][preve[v]].cap);
        }
        flow-=cflow;
        res+=cflow*h[dst];
        for(int v=dst;v!=src;v=prevv[v]){
            g[prevv[v]][preve[v]].cap-=cflow;
            g[v][g[prevv[v]][preve[v]].rev].cap+=cflow;
        }
    }
    return res;
}

int n;
pair<int,int> p[405];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].first>>p[i].second;
        addedge(0,i<<1,2,0);
        addedge(i<<1|1,1,1,0);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)if(p[i].second>p[j].second){
            addedge(i<<1,j<<1|1,1,sqrt(abs(p[i].first-p[j].first)*abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second)*abs(p[i].second-p[j].second)));
        }
    }
    cout<<fixed<<setprecision(10)<<min_cost_flow(n<<1|1,0,1,n-1)<<endl;

    return 0;
}