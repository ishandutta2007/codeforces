#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=405;
const int maxm=606;
const int mdn=998244353;

int n,m;
vector<int> adj[maxn];
int d[maxn][maxn],fa[maxn][maxn];
pair<int,int> e[maxm];
int f[maxn];
bool vis[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;e[i]=make_pair(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(d,-1,sizeof(d));
    for(int i=1;i<=n;i++){
        d[i][i]=0;
        queue<int> q;q.push(i);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int j=0;j<adj[u].size();j++){
                int v=adj[u][j];
                if(d[i][v]==-1){
                    d[i][v]=d[i][u]+1;
                    fa[i][v]=u;
                    q.push(v);
                }else if(d[i][v]==d[i][u]+1){
                    fa[i][v]=-1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++)f[k]=vis[k]=0;
            for(int k=1;k<=m;k++){
                int u=e[k].first,v=e[k].second;
                bool x1=d[i][u]==d[i][v]+1;
                bool x2=d[i][u]==d[i][v]-1;
                bool y1=d[j][u]==d[j][v]+1;
                bool y2=d[j][u]==d[j][v]-1;
                if(x1&y1){
                    f[u]++;
                }else if(x2&y2){
                    f[v]++;
                }
            }
            int ans=1;
            if(i!=j){
                for(int t=j;t!=i;t=fa[i][t]){
                    if(t==-1){ans=0;break;}
                    vis[t]=1;
                }
                vis[i]=1;
            }else vis[i]=1;
            if(ans){
                for(int k=1;k<=n;k++)if(!vis[k])ans=ans*(long long)f[k]%mdn;
            }
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
    return 0;
}