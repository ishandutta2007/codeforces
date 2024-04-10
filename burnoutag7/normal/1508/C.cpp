#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
    int sz;
    vector<int> fa;

    UnionFind(int _sz=100000){
        fa.resize((sz=_sz)+1);
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }

    bool unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return false;
        fa[x]=y;
        return true;
    }
}all,ori;

typedef long long ll;

int n,nw;
ll mxm,m;
set<int> g[200005],vis;
vector<pair<int,pair<int,int>>> ew;

void dfs(int x){
    vis.erase(x);
    for(int y=0;vis.lower_bound(y)!=vis.end();y++){
        y=*vis.lower_bound(y);
        if(g[x].find(y)==g[x].end()){
            all.unite(x,y);
            dfs(y);
            m++;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    all=ori=UnionFind(n);
    mxm=n*(n-1ll)/2;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].emplace(v);
        g[v].emplace(u);
        nw^=w;
        ew.emplace_back(w,make_pair(u,v));
    }
    for(int i=1;i<=n;i++)vis.emplace(i);
    while(!vis.empty())dfs(*vis.begin());
    if(m<mxm)nw=0;
    sort(ew.begin(),ew.end());
    ll sum=0;
    for(pair<int,pair<int,int>> &p:ew)if(all.unite(p.second.first,p.second.second)){
        ori.unite(p.second.first,p.second.second);
        sum+=p.first;
    }else if(ori.unite(p.second.first,p.second.second)){
        nw=min(nw,p.first);
    }
    cout<<sum+nw;

    return 0;
}