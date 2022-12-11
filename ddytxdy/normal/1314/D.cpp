#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N][N],n,k,col[N],ans=2e9,dis[12][N];
void dfs(int x,int now,int val){
    if(val+dis[k-now][x]>=ans)return;
    if(now==k-1){ans=val+a[x][1];return;}
    for(int i=1;i<=n;i++)if(i!=x){
        if(col[i]==-1)
            col[i]=col[x]^1,
            dfs(i,now+1,val+a[x][i]),
            col[i]=-1;
        else if(col[i]^col[x])dfs(i,now+1,val+a[x][i]);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    memset(dis,0x3f,sizeof(dis));dis[0][1]=0;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            for(int l=1;l<=n;l++)if(j^l)
                dis[i][l]=min(dis[i][l],dis[i-1][j]+a[l][j]);
    memset(col,-1,sizeof(col));
    col[1]=0;dfs(1,0,0);cout<<ans;
    return 0;
}