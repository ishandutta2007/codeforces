#include<bits/stdc++.h>
using namespace std;

int n;
long long r1,r2,r3,d,a[1000005],seckill[1000005],dp[1000005],ans,sum;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>r1>>r2>>r3>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        seckill[i]=min(r1*a[i]+r1,r2)+r1;
        dp[i]=min(r1*a[i]+r3,seckill[i]+(d<<1))+dp[i-1];
        if(i>=2)dp[i]=min(dp[i],dp[i-2]+seckill[i-1]+seckill[i]+(d<<1));
    }
    ans=dp[n];
    for(int i=n-1;i>=1;i--){
        sum+=seckill[i];
        ans=min(ans,min(r1*a[n]+r3,seckill[n]+(d<<1))+dp[i-1]+sum+d*(n-i));
    }
    cout<<ans+d*(n-1)<<endl;

    return 0;
}