//
//
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

int n,m;
set<int> g1[3005],g2[3005];

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
}uf;

void dfs(int x,vector<int> &v){
    while(!g1[x].empty()){
        int y=*g1[x].begin();
        g1[x].erase(y);
        g1[y].erase(x);
        dfs(y,v);
    }
    v.emplace_back(x);
}

void printeven(int c){
    vector<int> v;
    dfs(c,v);
    v.emplace_back(-1);
    for(int i:g2[c]){
        v.emplace_back(i);
        v.emplace_back(c);
    }
    cout<<v.size()<<'\n';
    for(int x:v)cout<<x<<' ';
    exit(0);
}

void printodd(int c){
    int x=-1,y=-1;
    for(int i=1;i<=n;i++)if(g1[i].size()&1){
        if(x==-1)x=i;
        else y=i;
    }
    if(x!=c&&y!=c)return;
    printeven(c);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g1[u].emplace(v);
        g1[v].emplace(u);
    }
    for(int c=1;c<=n;c++){
        vector<int> adj;
        for(int i:g1[c])adj.emplace_back(i);
        for(int i:adj)if(g1[i].size()&1){
            g1[c].erase(i);
            g1[i].erase(c);
            g2[c].emplace(i);
            g2[i].emplace(c);
        }
        for(int i:adj){
            if(g1[c].find(i)==g1[c].end()){
                g1[c].emplace(i);
                g1[i].emplace(c);
                g2[c].erase(i);
                g2[i].erase(c);
            }else{
                g1[c].erase(i);
                g1[i].erase(c);
                g2[c].emplace(i);
                g2[i].emplace(c);
            }
            uf=UnionFind(n);
            for(int x=1;x<=n;x++)for(int y:g1[x])uf.unite(x,y);
            int root=-1;
            for(int x=1;x<=n;x++)if(!g1[x].empty()){
                if(root==-1)root=uf.find(x);
                else if(root!=uf.find(x))root=0;
            }
            if(root){
                int odd=0;
                for(int i=1;i<=n;i++)odd+=g1[i].size()&1;
                if(odd==0)printeven(c);
                else if(odd<=2)printodd(c);
            }
            if(g1[c].find(i)==g1[c].end()){
                g1[c].emplace(i);
                g1[i].emplace(c);
                g2[c].erase(i);
                g2[i].erase(c);
            }else{
                g1[c].erase(i);
                g1[i].erase(c);
                g2[c].emplace(i);
                g2[i].emplace(c);
            }
        }
        uf=UnionFind(n);
        for(int x=1;x<=n;x++)for(int y:g1[x])uf.unite(x,y);
        int root=-1;
        for(int x=1;x<=n;x++)if(!g1[x].empty()){
            if(root==-1)root=uf.find(x);
            else if(root!=uf.find(x))root=0;
        }
        if(root){
            int odd=0;
            for(int i=1;i<=n;i++)odd+=g1[i].size()&1;
            if(odd==0)printeven(c);
            else if(odd<=2)printodd(c);
        }
        for(int i:adj)if(g1[c].find(i)==g1[c].end()){
            g1[c].emplace(i);
            g1[i].emplace(c);
            g2[c].erase(i);
            g2[i].erase(c);
        }
    }
    cout<<'0';

    return 0;
}