#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int,int> > mst[200005];
int vertexU[200005];
int vertexV[200005];
int weight[200005];
int n,m;
ll ans;

int father[200005];
int find(int x){
    if(father[x]==0){
        return x;
    }else{
        return father[x]=find(father[x]);
    }
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    father[x]=y;
}
bool same(int x,int y){
    return find(x)==find(y);
}

struct edge{
    int u,v,cost;
};
bool cmpEdge(const edge & e1,const edge & e2){
    return e1.cost<e2.cost;
}
edge edges[200005];
void kruskalMST(){
    sort(edges+1,edges+1+m,cmpEdge);
    for(int i=1;i<=m;i++){
        edge e=edges[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            ans+=e.cost;
            mst[e.u].push_back(make_pair(e.v,e.cost));
            mst[e.v].push_back(make_pair(e.u,e.cost));
        }
    }
}

int parent[20][200005];
int maxEdge[20][200005];
int depth[200005];

void dfsLCA(int v,int p,int d){
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<mst[v].size();i++){
        if(mst[v][i].first!=p){
            maxEdge[0][mst[v][i].first]=mst[v][i].second;
            dfsLCA(mst[v][i].first,v,d+1);
        }
    }
}

void init(){
    dfsLCA(1,-1,0);
    maxEdge[0][1]=-1;
    for(int k=0;k+1<20;k++){
        for(int v=1;v<=n;v++){
            if(parent[k][v]<0)parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
    for(int k=0;k+1<20;k++){
        for(int v=1;v<=n;v++){
            if(parent[k][v]<0)maxEdge[k+1][v]=-1;
            else maxEdge[k+1][v]=max(maxEdge[k][v],maxEdge[k][parent[k][v]]);
        }
    }
}

int lca(int u,int v){
    if(depth[u]>depth[v])swap(u,v);
    for(int k=0;k<20;k++){
        if((depth[v]-depth[u])>>k&1){
            v=parent[k][v];
        }
    }
    if(u==v)return u;
    for(int k=19;k>=0;k--){
        if(parent[k][u]!=parent[k][v]){
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}

int bigEdge(int u,int v){
    int res=0;
    for(int k=19;k>=0;k--){
        if((depth[v]-depth[u])>>k&1){
            res=max(res,maxEdge[k][v]);
            v=parent[k][v];
        }
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>vertexU[i]>>vertexV[i]>>weight[i];
        edges[i]=edge{vertexU[i],vertexV[i],weight[i]};
    }
    kruskalMST();
    init();
    cerr<<"MST SZ: "<<ans<<endl;
    for(int i=1;i<=m;i++){
        int u=vertexU[i];
        int v=vertexV[i];
        int KaguraMea=lca(u,v);
        int e=max(bigEdge(KaguraMea,u),bigEdge(KaguraMea,v));
        cout<<ans-e+weight[i]<<endl;
    }

    return 0;
}