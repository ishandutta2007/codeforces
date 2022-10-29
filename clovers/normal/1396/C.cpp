#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=(int)5e18;
void checkmin(int &x,int y){if(x>y) x=y;}
const int N=1000005;
int n,r1,r2,r3,d,a[N];
int dp[N][2];

signed main(){
    scanf("%lld%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),dp[i][0]=dp[i][1]=inf;
    dp[0][0]=0;
    dp[0][1]=inf;
    checkmin(r1,r2); checkmin(r1,r3);
    for(int i=1;i<=n;i++){
        checkmin(dp[i][0],r1*a[i]+r3+dp[i-1][0]);
        checkmin(dp[i][0],r2+dp[i-1][1]+r1*2+d*2);
        checkmin(dp[i][0],r1*(a[i]+1)+dp[i-1][1]+r1*2+d*2);
        int tmp=2*d; if(i==n) tmp=d;
        checkmin(dp[i][0],r1*a[i]+r3+dp[i-1][1]+tmp+r1);
        checkmin(dp[i][1],min(r2,r1*(a[i]+1))+dp[i-1][0]);
        //cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    int ans=min(dp[n][0],dp[n][1]+d*2+r1);
    cout<<ans+(n-1)*d<<endl;
    return 0;
}