#include<bits/stdc++.h>
using namespace std;
int T,n,m,ed[250010][3],dis[510][510];
void solve(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=1e9;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&ed[i][0],&ed[i][1],&ed[i][2]);
        dis[ed[i][0]][ed[i][1]]=dis[ed[i][1]][ed[i][0]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }long long ans=1e18;
    for(int i=1;i<=m;i++){
        int x=ed[i][0],y=ed[i][1];
        ans=min(ans,1ll*(dis[1][x]+dis[y][n]+1)*ed[i][2]);
        for(int j=1;j<=n;j++) ans=min(ans,1ll*(dis[x][j]+dis[1][j]+dis[j][n]+2)*ed[i][2]);
        swap(x,y);
        ans=min(ans,1ll*(dis[1][x]+dis[y][n]+1)*ed[i][2]);
        for(int j=1;j<=n;j++) ans=min(ans,1ll*(dis[x][j]+dis[1][j]+dis[j][n]+2)*ed[i][2]);
    }
    printf("%lld\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}