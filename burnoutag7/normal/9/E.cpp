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

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        fa[x]=y;
    }
};

int n,m,g[55][55],deg[55],szv[55],sze[55];
vector<pair<int,int>> ansv;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    UnionFind uf(n);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u][v]=++g[v][u];
        deg[u]++;
        deg[v]++;
        uf.unite(u,v);
    }
    if(*max_element(deg+1,deg+1+n)>2||n<m){
        cout<<"NO\n";
        return 0;
    }
    for(int i=1;i<=n;i++)szv[uf.find(i)]++,sze[uf.find(i)]+=deg[i];
    for(int i=1;i<=n;i++)if(szv[i]&&szv[i]*2==sze[i]&&szv[i]!=n){
        cout<<"NO\n";
        return 0;
    }
    for(int it=1;it<n-m;it++){
        bool f=true;
        for(int x=1;x<=n&&f;x++)for(int y=x+1;y<=n;y++)if(uf.find(x)!=uf.find(y)&&deg[x]<=1&&deg[y]<=1){
            g[x][y]=++g[y][x];
            deg[x]++;
            deg[y]++;
            uf.unite(x,y);
            ansv.emplace_back(x,y);
            f=false;
            break;
        }
    }
    bool f=true;
    for(int x=1;x<=n&&f;x++)for(int y=x+1;y<=n;y++)if(deg[x]<=1&&deg[y]<=1){
        g[x][y]=++g[y][x];
        deg[x]++;
        deg[y]++;
        uf.unite(x,y);
        ansv.emplace_back(x,y);
        f=false;
        break;
    }
    if(n==1&&ansv.size()+m==0){
        ansv.emplace_back(1,1);
    }
    cout<<"YES\n"<<ansv.size()<<'\n';
    for(pair<int,int> &p:ansv)cout<<p.first<<' '<<p.second<<'\n';

    return 0;
}