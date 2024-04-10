#include<bits/stdc++.h>
using namespace std;

struct edge{
    int to,cap,cost,rev;
    edge(){
        to=cap=cost=rev=0;
    }
    edge(int _t,int _c,int _cc,int _r){
        to=_t;
        cap=_c;
        cost=_cc;
        rev=_r;
    }
};

int V;
vector<edge> g[2005];
int h[2005];
int dist[2005];
int prevv[2005],preve[2005];

int addedge(const int &from,const int &to,const int &cap,const int &cost){
    g[from].emplace_back(to,cap,cost,g[to].size());
    g[to].emplace_back(from,0,-cost,g[from].size()-1);
    return g[from].size()-1;
}

int min_cost_flow(const int &src,const int &dst,int flow){
    int res=0;
    memset(h,0,sizeof(h));
    while(flow>0){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        memset(dist,0x3f,sizeof(dist));
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
        if(dist[dst]==0x3f3f3f3f)return -1;
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

int n,k,src,dst;
int s[1005],t[1005],c[1005];
vector<int> dsc;
vector<pair<int,int>> ansv;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i]>>c[i];
        t[i]=s[i]+t[i];
        dsc.emplace_back(s[i]);
        dsc.emplace_back(t[i]);
    }
    sort(dsc.begin(),dsc.end());
    dsc.erase(unique(dsc.begin(),dsc.end()),dsc.end());
    src=1;
    dst=dsc.size();
    for(int i=src;i<dst;i++){
        addedge(i,i+1,k,0);
    }
    for(int i=1;i<=n;i++){
        s[i]=lower_bound(dsc.begin(),dsc.end(),s[i])-dsc.begin()+1;
        t[i]=lower_bound(dsc.begin(),dsc.end(),t[i])-dsc.begin()+1;
        ansv.emplace_back(s[i],addedge(s[i],t[i],1,-c[i]));
    }
    cerr<<-min_cost_flow(src,dst,k)<<endl;
    for(pair<int,int> &p:ansv){
        cout<<(g[p.first][p.second].cap==0)<<' ';
    }

    return 0;
}