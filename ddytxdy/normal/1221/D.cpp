#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+50;
int q,n,a[N],b[N];LL dp[N][3],ans;
void cmin(LL &x,LL y){y<x?x=y:0;}
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);ans=1e18;
        for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
        for(int i=2;i<=n;i++)dp[i][0]=dp[i][1]=dp[i][2]=1e18;
        dp[1][0]=0;dp[1][1]=b[1];dp[1][2]=2*b[1];
        for(int i=2;i<=n;i++){
            for(int j=0;j<3;j++){
                int now=a[i]+j;
                for(int k=0;k<3;k++){
                    int la=a[i-1]+k;
                    if(now!=la)cmin(dp[i][j],dp[i-1][k]+j*b[i]);
                }
            }
        }
        for(int i=0;i<3;i++)cmin(ans,dp[n][i]);
        cout<<ans<<endl;
    }
    return 0;
}