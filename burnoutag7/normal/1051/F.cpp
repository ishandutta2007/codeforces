#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
    int n;
    vector<int> fa;

    UnionFind(int _n=0){
        fa.resize((n=_n)+1);
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        fa[x]=y;
    }
};

typedef long long ll;

int n,m,hson[100005],fa[100005],sz[100005],top[100005];
vector<pair<int,int>> g[100005];
vector<pair<pair<int,int>,int>> e;
ll dep[100005];

int hldprec(int x,int p,ll d){
    dep[x]=d;
    sz[x]=1;
    for(auto &[y,z]:g[x])if(y!=p&&z>0){
        sz[x]+=hldprec(y,x,d+z);
        fa[y]=x;
        if(sz[y]>sz[hson[x]]){
            hson[x]=y;
        }
    }
    return sz[x];
}

void hlddec(int x,int head){
    top[x]=head;
    if(hson[x]){
        hlddec(hson[x],head);
        for(auto &[y,z]:g[x])if(y!=fa[x]&&y!=hson[x]&&z>0){
            hlddec(y,y);
        }
    }
}

int lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]]){
            u=fa[top[u]];
        }else{
            v=fa[top[v]];
        }
    }
    return dep[u]<dep[v]?u:v;
}

ll dis(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}

void gdis(int s,ll *d){
    memset(d+1,0x3f,n*sizeof(ll));
    d[s]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.emplace(0,s);
    while(!q.empty()){
        int x=q.top().second;
        ll cd=q.top().first;
        q.pop();
        if(cd>d[x])continue;
        for(auto &[y,z]:g[x])if(d[y]>cd+abs(z)){
            q.emplace(d[y]=cd+abs(z),y);
        }
    }
}

ll ds[25][100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    UnionFind uf(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(uf.find(u)!=uf.find(v)){
            uf.unite(u,v);
            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
        }else{
            e.emplace_back(make_pair(u,v),w);
            g[u].emplace_back(v,-w);
            g[v].emplace_back(u,-w);
        }
    }
    for(int i=0;i<e.size();i++){
        gdis(e[i].first.first,ds[i]);
    }
    hldprec(1,-1,0);
    hlddec(1,1);
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        ll ans=dis(u,v);
        for(int i=0;i<e.size();i++){
            ans=min(ans,ds[i][u]+ds[i][v]);
        }
        cout<<ans<<'\n';
    }

    return 0;
}