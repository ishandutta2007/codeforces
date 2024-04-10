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

    void clear(){
        sz.assign(n+1,1);
        iota(fa.begin(),fa.end(),0);
    }
}uf;

int n,m,u[200005],v[200005],w[200005];

bool check(int x){
    uf.clear();
    for(int i=1;i<=m;i++)if((w[i]&x)==w[i]){
        uf.unite(u[i],v[i]);
    }
    return uf.size(1)==n;
}

void mian(){
    cin>>n>>m;
    uf=UnionFind(n);
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    int ans=(1<<30)-1;
    for(int i=29;i>=0;i--)if(check(ans^1<<i))ans^=1<<i;
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}