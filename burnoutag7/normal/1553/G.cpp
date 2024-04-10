#include<bits/stdc++.h>
using namespace std;

const int V=1e6;

struct UnionFind{
    int sz;
    vector<int> fa;

    UnionFind(int _sz=1){
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
}uf(2*V);

int n,m,q,a[150005];
vector<int> dvs[1000005];
set<int> g[2*V];

void getdvs(int x){
    if(!dvs[x].empty())return;
    int tmp=x;
    for(int j=2;j*j<=tmp;j++)if(tmp%j==0){
        while(tmp%j==0){
            tmp/=j;
            dvs[x].emplace_back(j);
        }
    }
    if(tmp>1){
        dvs[x].emplace_back(tmp);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        getdvs(a[i]);
        for(int x:dvs[a[i]]){
            uf.unite(x+V,a[i]);
        }
    }
    for(int i=1;i<=n;i++){
        getdvs(a[i]+1);
        for(int x:dvs[a[i]+1]){
            for(int y:dvs[a[i]+1]){
                int u=uf.find(x+V),v=uf.find(y+V);
                if(u!=v){
                    g[u].emplace(v);
                    g[v].emplace(u);
                }
            }
            int u=uf.find(x+V),v=uf.find(a[i]);
            if(u!=v){
                g[u].emplace(v);
                g[v].emplace(u);
            }
        }
    }
    while(q--){
        int x,y,u,v;
        cin>>x>>y;
        u=uf.find(a[x]);
        v=uf.find(a[y]);
        if(u==v){
            cout<<"0\n";
        }else
        if(g[u].find(v)!=g[u].end()){
            cout<<"1\n";
        }else
        cout<<"2\n";
    }

    return 0;
}