#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005;
const int maxl=20;

struct dat{
    int mi,smi,mx,smx;
};


int n;
int dep[maxn],fa[maxn][maxl],dfn[maxn],id[maxn],c1;
vector<int> adj[maxn];
dat d[maxn][maxl];
int lg2[maxn];

dat nwdat(){
    dat nw;nw.mi=nw.smi=0x3f3f3f3f;nw.mx=nw.smx=0;
    return nw;
}
dat mrg(dat a,dat b){
    dat nw=nwdat();
    nw.mi=min(a.mi,b.mi);
    nw.mx=max(a.mx,b.mx);
    if(a.mi>nw.mi)nw.smi=min(nw.smi,a.mi);
    if(b.mi>nw.mi)nw.smi=min(nw.smi,b.mi);
    if(a.smi>nw.mi)nw.smi=min(nw.smi,a.smi);
    if(b.smi>nw.mi)nw.smi=min(nw.smi,b.smi);
    if(a.mx<nw.mx)nw.smx=max(nw.smx,a.mx);
    if(b.mx<nw.mx)nw.smx=max(nw.smx,b.mx);
    if(a.smx<nw.mx)nw.smx=max(nw.smx,a.smx);
    if(b.smx<nw.mx)nw.smx=max(nw.smx,b.smx);
    return nw;
}

void dfs(int u){
    dfn[u]=++c1;
    id[c1]=u;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        dfs(v);
    }
}

int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i=maxl-1;i>=0;i--){
        if(dep[fa[u][i]]>=dep[v]){
            u=fa[u][i];
        }
    }
    if(u==v)return dep[u]-1;
    for(int i=maxl-1;i>=0;i--){
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];v=fa[v][i];
        }
    }
    return dep[fa[u][0]]-1;
}

dat qry(int l,int r){
    int sz=(r-l+1),lg=lg2[sz];
    return mrg(d[l][lg],d[r-(1<<lg)+1][lg]);
}
int main(){
    ios::sync_with_stdio(0);
    lg2[1]=0;
    for(int i=2;i<maxn;i++)lg2[i]=lg2[i>>1]+1;
    int q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    dep[1]=1;
    dfs(1);
    for(int i=1;i<=n;i++){
        d[i][0]=nwdat();d[i][0].mx=d[i][0].mi=dfn[i];
    }
    for(int i=1;i<maxl;i++){
        for(int j=1;j<=n;j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
            if(j+(1<<i)-1<=n)d[j][i]=mrg(d[j][i-1],d[j+(1<<(i-1))][i-1]);
        }
    }
    // for(int i=1;i<=n;i++)cerr<<dfn[i]<<' ';
    // cerr<<'\n';
    while(q--){
        int l,r;
        cin>>l>>r;
        dat f=qry(l,r);
        cerr<<lg2[r-l+1]<<'\n';
        int ans1=lca(id[f.smi],id[f.mx]);
        int ans2=lca(id[f.smx],id[f.mi]);
   //     cerr<<f.mx<<','<<f.smx<<'/'<<f.mi<<','<<f.smi<<endl;
        if(ans1>ans2){
            cout<<id[f.mi]<<' '<<ans1<<'\n';
        }else cout<<id[f.mx]<<' '<<ans2<<'\n';
    }
    return 0;
}