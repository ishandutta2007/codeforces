#include<bits/stdc++.h>
using namespace std;

struct unionfind{
    int n;
    vector<int> fa,sz;

    unionfind(int _n=0){
        fa.resize((n=_n)+1);
        sz.resize(n+1);
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }

    int size(int x){
        return sz[find(x)];
    }

    void add(int x){
        sz[find(x)]++;
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        fa[x]=y;
        if(y!=x)sz[y]+=sz[x];
    }
};

int n;
multiset<int> g[600005];
bool use[300005];
vector<int> grid[2];
string ans[4];

void dfs(int x,vector<int> &v){
    v.emplace_back(x);
    while(!g[x].empty()){
        int y=*g[x].begin();
        g[x].erase(g[x].begin());
        g[y].erase(g[y].find(x));
        dfs(y,v);
        v.emplace_back(x);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    unionfind uf(2*n);
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace(v);
        g[v].emplace(u);
        uf.unite(u,v);
        uf.add(u);
    }
    for(int i=1;i<=2*n;i++)if(uf.find(i)==i&&uf.size(i)){
        if(uf.size(i)==1){
            cout<<"-1\n";
            return 0;
        }
        vector<int> v;
        dfs(i,v);
        v.pop_back();
        int m=v.size();
        for(int i=0;i<m/2;i++){
            grid[0].emplace_back(v[i]);
            grid[1].emplace_back(v[m-1-i]);
        }
        for(int i=0;i+1<m/2;i+=2){
            ans[0]+="LR";
            ans[1]+="LR";
        }
        if(m/2&1){
            ans[0]+='U';
            ans[1]+='D';
        }
        ans[2]+='U';
        ans[3]+='D';
        for(int i=1;i+1<m/2;i+=2){
            ans[2]+="LR";
            ans[3]+="LR";
        }
        if(m/2&1^1){
            ans[2]+='U';
            ans[3]+='D';
        }
    }
    cout<<"2 "<<grid[0].size()<<'\n';
    for(int x:grid[0])cout<<x<<' ';
    cout<<'\n';
    for(int x:grid[1])cout<<x<<' ';
    cout<<'\n';
    cout<<ans[0]<<'\n';
    cout<<ans[1]<<'\n';
    cout<<ans[2]<<'\n';
    cout<<ans[3]<<'\n';

    return 0;
}