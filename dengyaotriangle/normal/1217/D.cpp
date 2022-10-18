#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=5005;

int n,m;
vector<pair<int,int> > adj[maxn];
int ans[maxn];
int ct=0;
long long g[maxn];
int eu[maxn],ev[maxn];
int idg[maxn];

bool topo(){
    queue<int> q;
    for(int i=1;i<=n;i++) if(idg[i]==0) q.push(i);
    for(int i=1;i<=n;i++){
        if(q.empty()) return 0;
        int f=q.front();q.pop();
        for(int j=0;j<adj[f].size();j++){
            int v=adj[f][j].first;
            idg[v]--;
            if(idg[v]==0) q.push(v);
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)g[i]=i;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(make_pair(v,i));
        eu[i]=u;ev[i]=v;
        idg[v]++;
    }
    if(topo()){
        cout<<1<<'\n';
        while(m--)cout<<"1 ";
    }else{
        for(int i=1;i<=m;i++){
            if(g[eu[i]]>g[ev[i]]){
                ans[i]=1;
            }else{
                ans[i]=2;
            }
        }
        cout<<2<<'\n';
        for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    }
    return 0;
}