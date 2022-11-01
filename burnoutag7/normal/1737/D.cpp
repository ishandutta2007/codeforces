#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,dis[505][505],u[250005],v[250005],w[250005];

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fill(dis[i]+1,dis[i]+1+n,1e9);
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        dis[u[i]][v[i]]=dis[v[i]][u[i]]=1;
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
    }
    ll ans=1e18;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)if(dis[j][1]!=1e9&&dis[j][n]!=1e9&&dis[j][u[i]]!=1e9){
            ans=min(ans,(ll)w[i]*(dis[j][1]+dis[j][n]+min(dis[j][u[i]],dis[j][v[i]])+2));
        }
        if(dis[u[i]][1]!=1e9&&dis[u[i]][n]!=1e9){
            ans=min(ans,(ll)w[i]*(dis[u[i]][1]+dis[v[i]][n]+1));
            ans=min(ans,(ll)w[i]*(dis[u[i]][n]+dis[v[i]][1]+1));
        }
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}