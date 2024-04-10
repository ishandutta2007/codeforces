#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

ll qpow(ll a,ll n){
    a%=mod;
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int n,k,a[300005],oa[300005],top[300005],f[300005][2],hav[300005],typ[300005];
vector<int> col[300005],g[300005];
int dep[300005];
int fa[300005][19];

void dfs4lca(int x,int p,int cd){
    fa[x][0]=p;
    dep[x]=cd;
    for(int y:g[x])if(y!=p){
        dfs4lca(y,x,cd+1);
    }
}

void init4lca(){
    dfs4lca(1,-1,0);
    for(int j=0;j<18;j++){
        for(int i=1;i<=n;i++){
            if(fa[i][j]==-1)fa[i][j+1]=-1;
            else fa[i][j+1]=fa[fa[i][j]][j];
        }
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=18;i>=0;i--){
        if(fa[x][i]!=-1&&dep[fa[x][i]]>=dep[y])x=fa[x][i];
    }
    if(x==y)return x;
    for(int i=18;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}

void dfs(int x,int p){
    hav[x]=!!a[x];
    bool alv=!a[x];
    for(int y:g[x])if(y!=p){
        dfs(y,x);
        hav[x]|=hav[y];
        if(typ[y])alv&=typ[y]==-1;
    }
    if(!hav[x]){
        typ[x]=0;
        return;
    }else if(a[x]&&top[a[x]]!=x)typ[x]=a[x];
    else typ[x]=-1;
    if(alv){
        ll prod=1;
        for(int y:g[x])if(y!=p&&typ[y]){
            prod=prod*(f[y][0]+f[y][1])%mod;
        }
        f[x][0]=prod;
        for(int y:g[x])if(y!=p&&typ[y]){
            f[x][1]=(f[x][1]+prod*qpow(f[y][0]+f[y][1],mod-2)%mod*f[y][1])%mod;
        }
    }else{
        ll prod=1;
        for(int y:g[x])if(y!=p){
            if(typ[y]==-1)prod=prod*(f[y][0]+f[y][1])%mod;
            if(typ[y]>0)prod=prod*f[y][1]%mod;
        }
        f[x][1]=prod;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        col[a[i]].emplace_back(i);
        oa[i]=a[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    init4lca();
    for(int c=1;c<=k;c++)if(col[c].size()>1){
        int &anc=top[c];
        anc=lca(col[c][0],col[c][1]);
        for(int i=2;i<col[c].size();i++){
            anc=lca(anc,col[c][i]);
        }
        if(a[anc]&&a[anc]!=c){
            cout<<0;
            return 0;
        }else a[anc]=c;
        for(int x:col[c])if(x!=anc){
            int y=fa[x][0];
            while(y!=-1){
                if(a[y]&&a[y]!=c){
                    cout<<0;
                    return 0;
                }
                if(a[y])break;
                a[y]=c;
                y=fa[y][0];
            }
        }
    }else top[c]=col[c][0];
    dfs(1,-1);
    cout<<f[1][1];

    return 0;
}