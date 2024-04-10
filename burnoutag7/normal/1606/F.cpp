#include<bits/stdc++.h>
using namespace std;

int n,q,f[200005][455],qv[200005],qk[200005],ans[200005],sz[200005];
vector<int> g[200005];

void dfs1(int x,int p){
    for(int y:g[x])if(y!=p){
        dfs1(y,x);
        for(int k=0;k<=450;k++){
            f[x][k]+=max(1,f[y][k]-k);
        }
    }
}

int tmp[455];

void dfs2(int x,int p){
    for(int y:g[x])if(y!=p){
        dfs2(y,x);
        memcpy(tmp,f[x],min(450,sz[x])*4+4);
        for(int i=0;i<=min(450,sz[x]);i++)tmp[i]=f[x][i];
        for(int i=min(450,sz[x]);i>=0;i--)for(int j=0;j<=sz[y]&&i+j+1<=min(450,sz[x]+sz[y]);j++){
            f[x][i+j+1]=max(f[x][i+j+1],f[x][i]+f[y][j]);
        }
        for(int i=0;i<=min(450,sz[x]);i++)f[x][i]=max(f[x][i],tmp[i]+1);
        sz[x]+=sz[y];
    }
    sz[x]++;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>qv[i]>>qk[i];
    }
    dfs1(1,-1);
    for(int i=1;i<=q;i++)if(qk[i]<=450){
        ans[i]=f[qv[i]][qk[i]];
    }
    memset(f,0,sizeof(f));
    dfs2(1,-1);
    for(int i=1;i<=q;i++)if(qk[i]>450){
        for(int j=0;j<=450;j++)ans[i]=max(ans[i],f[qv[i]][j]-qk[i]*j);
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';

    return 0;
}