#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int n,m,q,dfn[100005],low[100005],ibcc[100005],bccsz[100005],dfncnt,bcccnt;
vector<pair<int,int>> g[100005];
vector<int> ng[100005];
int st[100005],stcnt;

void getbcc(int x,int pe){
    dfn[x]=low[x]=++dfncnt;
    st[stcnt++]=x;
    for(pair<int,int> &e:g[x])if(!dfn[e.first]){
        getbcc(e.first,e.second);
        low[x]=min(low[x],low[e.first]);
    }else if(e.second!=pe){
        low[x]=min(low[x],dfn[e.first]);
    }
    if(dfn[x]==low[x]){
        ibcc[x]=++bcccnt;
        bccsz[bcccnt]++;
        int y;
        while((y=st[--stcnt])!=x){
            ibcc[y]=bcccnt;
            bccsz[bcccnt]++;
        }
    }
}

int dep[100005];
int fa[100005][17];

void dfs4lca(int x,int p,int cd){
    fa[x][0]=p;
    dep[x]=cd;
    for(int &y:ng[x])if(y!=p){
        dfs4lca(y,x,cd+1);
    }
}

void init4lca(){
    dfs4lca(1,0,0);
    for(int j=0;j<16;j++){
        for(int i=1;i<=bcccnt;i++){
            if(fa[i][j]==0)fa[i][j+1]=0;
            else fa[i][j+1]=fa[fa[i][j]][j];
        }
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=16;i>=0;i--){
        if(fa[x][i]!=0&&dep[fa[x][i]]>=dep[y])x=fa[x][i];
    }
    if(x==y)return x;
    for(int i=16;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}

int pre[100005];

void dfs(int x,int p){
    pre[x]+=pre[p];
    for(int &y:ng[x])if(y!=p){
        dfs(y,x);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b,i);
        g[b].emplace_back(a,i);
    }
    getbcc(1,0);
    for(int x=1;x<=n;x++){
        for(pair<int,int> &e:g[x]){
            if(ibcc[x]!=ibcc[e.first]){
                ng[ibcc[x]].emplace_back(ibcc[e.first]);
            }
        }
    }
    init4lca();
    for(int i=1;i<=bcccnt;i++)pre[i]+=bccsz[i]>=2;
    dfs(1,0);
    cin>>q;
    while(q--){
        int u,v,anc;
        cin>>u>>v;
        u=ibcc[u];
        v=ibcc[v];
        anc=lca(u,v);
        cout<<qpow(2,pre[u]+pre[v]-pre[anc]-pre[fa[anc][0]])<<'\n';
    }

    return 0;
}