#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;

int n,k;
vector<int> adj[maxn];
stack<int> stk;
bool ins[maxn];
int fa[maxn];
int dep[maxn];
void dfs(int u){
    stk.push(u);
    ins[u]=1;
    int mv=0;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==fa[u])continue;
        if(ins[v]){
            if(dep[v]>dep[mv])mv=v;
        }
    }
    if(mv){
        vector<int> x;
        while(1){
            int u=stk.top();stk.pop();
            x.push_back(u);
            if(u==mv)break;
        }
        if(x.size()<=k){
            cout<<2<<endl<<x.size()<<endl;
            for(int i=0;i<x.size();i++)cout<<x[i]<<' ';
        }else{
            cout<<1<<endl;
            for(int i=0;i<=k-1;i+=2)cout<<x[i]<<' ';
        }
        exit(0);
    }
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==fa[u])continue;
        if(!ins[v]){
            dep[v]=dep[u]+1;
            fa[v]=u;
            dfs(v);
        }
    }
    stk.pop();
}

vector<int> c[2];
void dfsx(int u,int f,bool g){
    c[g].push_back(u);
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v!=f){
            dfsx(v,u,!g);
        }
    }
}
int main(){
    int m;cin>>n>>m>>k;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);adj[v].push_back(u);
    }
    dep[1]=1;
    dfs(1);
    dfsx(1,0,0);
    if(c[0].size()<c[1].size())swap(c[0],c[1]);
    cout<<1<<endl;
    for(int i=0;i<(k+1)/2;i++)cout<<c[0][i]<<' ';
    return 0;
}