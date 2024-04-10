#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n,m;
vector<int> adj[maxn];
int d[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)adj[i].clear(),d[i]=0;
        for(int i=1;i<=m;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(d[i]==2){
                ans.push_back(i);
            }else for(int v:adj[i])d[v]=max(d[v],d[i]+1);
        }
        cout<<ans.size()<<'\n';
        for(int u:ans)cout<<u<<' ';
        cout<<'\n';
    }
    return 0;
}