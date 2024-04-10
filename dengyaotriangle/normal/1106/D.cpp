#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005;

int n,m;
vector<int> adj[maxn];
bool vis[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<int,vector<int>,greater<int> > q;
    vis[1]=1;
    q.push(1);
    while(!q.empty()){
        int u=q.top();q.pop();
        cout<<u<<' ';
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(!vis[v]){
                q.push(v);
                vis[v]=1;
            }
        }
    }
    return 0;
}