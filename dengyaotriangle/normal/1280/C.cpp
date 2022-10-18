#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n;
vector<pair<int,int> > adj[maxn];
int sz[maxn];
long long dp[maxn];
vector<int> cen;
int mxs[maxn];
long long dp2[maxn];

void dfs(int u){
    sz[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i].first;
        int w=adj[u][i].second;
        if(!sz[v]){
            dfs(v);
            sz[u]+=sz[v];
            dp[u]+=dp[v];
            mxs[u]=max(mxs[u],sz[v]);
            if(sz[v]&1)dp[u]+=w;
        }
    }
    mxs[u]=max(mxs[u],n+n-sz[u]);
}
void dfs2(int u,int f){
    sz[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i].first;
        if(v!=f){
            dfs2(v,u);
            dp2[u]+=dp2[v];
            dp2[u]+=sz[v]*(long long)(adj[u][i].second);
            sz[u]+=sz[v];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cen.clear();
        for(int i=1;i<=n+n;i++){adj[i].clear();dp[i]=0;sz[i]=0;mxs[i]=0;}
        for(int i=1;i<=n+n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        dfs(1);
        cout<<dp[1]<<' ';
        long long ans2=0;int mi=0x3f3f3f3f;
        for(int i=1;i<=n+n;i++){
            if(mxs[i]<mi)mi=mxs[i];
        }
        for(int i=1;i<=n+n;i++){
            if(mxs[i]==mi)cen.push_back(i);
        }
        if(cen.size()==2){
            for(int i=1;i<=n+n;i++){sz[i]=0;dp2[i]=0;}
            int u=cen[0],v=cen[1];
            dfs2(v,u);
            dfs2(u,v);
            long long el=0;
            for(int i=0;i<adj[u].size();i++){
                if(adj[u][i].first==v)el=adj[u][i].second;
            }
            ans2=el*n+dp2[u]+dp2[v];
        }else{
            for(int i=1;i<=n+n;i++){sz[i]=0;dp2[i]=0;}
            int rt=cen[0];
            dfs2(rt,0);
            for(int i=0;i<adj[rt].size();i++){
                int v=adj[rt][i].first;
                int w=adj[rt][i].second;
                ans2+=dp2[v];
                ans2+=sz[v]*(long long)w;
            }
        }
        cout<<ans2<<'\n';
    }
    return 0;
}