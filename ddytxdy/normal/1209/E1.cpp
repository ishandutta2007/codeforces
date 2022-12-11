#include<bits/stdc++.h>
using namespace std;
const int N=110;
int t,n,m,a[N][N],mx,dp[20][N],f[20][N];
void solve(){
    scanf("%d%d",&n,&m);mx=1<<n;
    memset(dp,0,sizeof(dp));
    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
    for(int i=0;i<m;i++)
        for(int j=0;j<mx;j++)
            for(int k=0;k<n;k++){
                int dat=0;
                for(int l=0;l<n;l++)if((j>>l)&1)dat+=a[(l+k)%n][i];
                f[j][i]=max(f[j][i],dat);
            }
    for(int i=0;i<mx;i++)dp[i][0]=f[i][0];
    for(int i=1;i<m;i++)
        for(int j=0;j<mx;j++){
            dp[j][i]=dp[j][i-1];
            for(int k=j;k;k=(k-1)&j)
                dp[j][i]=max(dp[j][i],dp[j^k][i-1]+f[k][i]);
        }
    printf("%d\n",dp[mx-1][m-1]);
}
int main(){
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}