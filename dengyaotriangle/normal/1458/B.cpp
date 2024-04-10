#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=105;

int dp[maxn][maxn*maxn];
int a[maxn],b[maxn];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i]>>a[i];
    }
    int s=accumulate(a+1,a+1+n,0);
    memset(dp,0xc0,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            for(int k=b[i];k<=n*100;k++){
                dp[j][k]=max(dp[j][k],dp[j-1][k-b[i]]+a[i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        double ans=0;
        for(int j=0;j<=n*100;j++){
            ans=max(ans,min((double)j,(dp[i][j]+s)*0.5));
        }
        cout<<ans<<' ';
    }
    return 0;
}