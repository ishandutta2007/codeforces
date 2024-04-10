#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,inf,d[200],mfp[200],ans[200];
ll f[200][200],g[200][200],mf[200];
vector<int> gr[200];

void dfs(int x,int p){
    fill(f[x],f[x]+n+1,inf);
    fill(g[x],g[x]+n+1,inf);
    for(int i=0;i<n;i++)g[x][i]=d[i];
    for(int y:gr[x])if(y!=p){
        dfs(y,x);
        for(int i=0;i<n;i++)g[x][i]+=min(g[y][i+1],mf[y]);
    }
    f[x][0]=g[x][0];
    for(int y:gr[x])if(y!=p){
        for(int i=1;i<n;i++){
            if(g[x][i]-min(g[y][i+1],mf[y])+f[y][i-1]<f[x][i]){
                f[x][i]=g[x][i]-min(g[y][i+1],mf[y])+f[y][i-1];
            }
        }
    }
    mf[x]=*min_element(f[x],f[x]+n);
}

void prtg(int x,int p,int av,int cd);

int prtf(int x,int p,int cd){//cerr<<"prtf: "<<x<<' '<<p<<' '<<cd<<'\n';
    int fp=-1;
    if(cd==0){
        ans[x]=x;
    }else{
        for(int y:gr[x])if(y!=p){
            if(f[x][cd]==g[x][cd]-min(g[y][cd+1],mf[y])+f[y][cd-1]){
                ans[x]=prtf(y,x,cd-1);
                fp=y;
                break;
            }
        }
    }
    for(int y:gr[x])if(y!=p&&y!=fp){
        if(g[y][cd+1]<mf[y])prtg(y,x,ans[x],cd+1);
        else prtf(y,x,min_element(f[y],f[y]+n)-f[y]);
    }
    return ans[x];
}

void prtg(int x,int p,int av,int cd){//cerr<<"prtg: "<<x<<' '<<p<<' '<<av<<'\n';
    ans[x]=av;
    for(int y:gr[x])if(y!=p){
        if(g[y][cd+1]<mf[y])prtg(y,x,ans[x],cd+1);
        else prtf(y,x,min_element(f[y],f[y]+n)-f[y]);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>d[0];
    for(int i=1;i<n;i++)cin>>d[i];
    inf=*max_element(d,d+n)*n+1;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        gr[u].emplace_back(v);
        gr[v].emplace_back(u);
    }
    dfs(1,-1);
    cout<<mf[1]<<'\n';
    prtf(1,-1,min_element(f[1],f[1]+n)-f[1]);
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    cout<<'\n';

    return 0;
}