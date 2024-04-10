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

typedef long long ll;

int n,w[1000005],rnk[1000005],dfn[1000005];
vector<int> bg[1000005],sg[1000005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    {
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)v[i]={w[i+1],i+1};
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)dfn[i+1]=v[i].second,rnk[v[i].second]=i+1;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        if(rnk[u]>rnk[v]){
            sg[u].emplace_back(v);
            bg[v].emplace_back(u);
        }else{
            sg[v].emplace_back(u);
            bg[u].emplace_back(v);
        }
    }
    ll ans=0;
    //calc max
    UnionFind uf(n);
    for(int i=1;i<=n;i++){
        int u=dfn[i],sum=1;
        ll cur=0;
        for(int v:sg[u]){
            cur-=(ll)uf.size(v)*(uf.size(v)-1)/2;
            sum+=uf.size(v);
            uf.unite(u,v);
        }
        cur+=(ll)sum*(sum-1)/2;
        ans+=w[u]*cur;
    }
    //calc min
    uf=UnionFind(n);
    for(int i=n;i>=1;i--){
        int u=dfn[i],sum=1;
        ll cur=0;
        for(int v:bg[u]){
            cur-=(ll)uf.size(v)*(uf.size(v)-1)/2;
            sum+=uf.size(v);
            uf.unite(u,v);
        }
        cur+=(ll)sum*(sum-1)/2;
        ans-=w[u]*cur;
    }
    cout<<ans;

    return 0;
}