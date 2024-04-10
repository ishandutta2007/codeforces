#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[20][21];
int a[20][20];
int g[20][20],cost[20][20];
int dp[1<<20];

int main(){

    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",s[i]);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",a[i]+j);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        int mx=0;
        for(int k=0;k<n;k++){
            if(s[i][j]==s[k][j]){
                g[i][j]|=1<<k;
                cost[i][j]+=a[k][j];
                mx=max(mx,a[k][j]);
            }
        }
        cost[i][j]-=mx;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(register int s=0;s<1<<n;s++){
        register int p=0;
        for(register int i=0;i<n;i++)if(s>>i&1^1){p=i;break;}
        for(register int i=0;i<m;i++){
            dp[s|1<<p]=min(dp[s|1<<p],dp[s]+a[p][i]);
            dp[s|g[p][i]]=min(dp[s|g[p][i]],dp[s]+cost[p][i]);
        }
    }
    printf("%lld\n",dp[(1<<n)-1]);

    return 0;
}