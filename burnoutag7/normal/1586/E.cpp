#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
    int n;
    vector<int> fa,sz;

    UnionFind(int _n=0){
        fa.resize((n=_n)+1);
        sz.resize(n+1,1);
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }

    int size(int x){
        return sz[find(x)];
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        fa[x]=y;
        if(y!=x)sz[y]+=sz[x];
    }
};

int n,m,dep[300005],fa[300005],tag[300005],ans;
vector<int> g[300005];
vector<vector<int>> ansv;

void pdfs(int x,int p){
    fa[x]=p;
    dep[x]=dep[p]+1;
    for(int y:g[x])if(y!=p){
        pdfs(y,x);
    }
}

void dfs(int x){
    int cnt=0;
    for(int y:g[x])if(y!=fa[x]){
        dfs(y);
        cnt+=tag[y];
    }
    ans+=cnt/2;
    if(!tag[x])ans+=cnt&1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    UnionFind uf(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(uf.find(x)!=uf.find(y)){
            uf.unite(x,y);
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
    }
    pdfs(1,0);
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        bool swt=dep[u]<dep[v];
        if(dep[u]<dep[v])swap(u,v);
        vector<int> cur,rcur;
        while(dep[u]>dep[v]){
            tag[u]^=1;
            cur.emplace_back(u);
            u=fa[u];
        }
        while(u!=v){
            tag[u]^=1;
            cur.emplace_back(u);
            tag[v]^=1;
            rcur.emplace_back(v);
            u=fa[u];
            v=fa[v];
        }
        cur.emplace_back(u);
        reverse(rcur.begin(),rcur.end());
        for(int x:rcur)cur.emplace_back(x);
        if(swt)reverse(cur.begin(),cur.end());
        ansv.emplace_back(cur);
    }
    if(!*max_element(tag+1,tag+1+n)){
        cout<<"YES\n";
        for(auto &v:ansv){
            cout<<v.size()<<'\n';
            for(int x:v)cout<<x<<' ';
            cout<<'\n';
        }
        return 0;
    }
    cout<<"NO\n";
    dfs(1);
    cout<<ans;

    return 0;
}