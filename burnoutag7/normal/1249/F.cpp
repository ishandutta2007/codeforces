#include<bits/stdc++.h>
using namespace std;

int n,k,w[205],f[205][205];
vector<int> g[205];

void dfs(int x,int p){
    f[x][0]=w[x];
    for(int y:g[x])if(y!=p){
        dfs(y,x);
        vector<int> nf(k+1,0);
        for(int i=1;i<=k;i++){
            nf[i]=f[y][i-1]+f[x][max(i,k-i)];
        }
        for(int i=0;i<=k;i++){
            nf[i]=max(nf[i],f[y][max(i,k-i)-1]+f[x][i]);
        }
        f[x][k]=nf[k];
        for(int i=k-1;i>=0;i--)f[x][i]=max(f[x][i+1],nf[i]);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    k++;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,-1);
    cout<<f[1][0];

    return 0;
}