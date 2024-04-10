#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1000006;
const int mdn=998244353;
const int inv2=(mdn+1)/2;
const int inv6=(mdn+1)/6;
int dp[maxn],pfx[maxn];
int n;
int main(){
    cin>>n;
    dp[0]=pfx[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        dp[i]=(dp[i]+dp[i-1]*(long long)(i-2<0?0:pfx[i-2]))%mdn;
        dp[i]=(dp[i]+dp[i-1]*(long long)(dp[i-1]+1)%mdn*inv2)%mdn;
        pfx[i]=(pfx[i-1]+dp[i])%mdn;
    }
    int ans=dp[n];
    int uans=0;
    int fc=n-2<0?0:pfx[n-2];
    uans=(uans+dp[n-1]*(long long)fc%mdn*(fc+1)%mdn*inv2)%mdn;
    uans=(uans+dp[n-1]*(long long)(dp[n-1]+1)%mdn*inv2%mdn*(long long)fc)%mdn;
    uans=(uans+dp[n-1]*(long long)(dp[n-1]+1)%mdn*(dp[n-1]+2)%mdn*inv6)%mdn;
    ans=(ans+uans*2ll)%mdn;
    for(int i=1;i<=n;i++){
        int s1=n-i-1;
        int cur=1;
        if(s1>=0)cur=dp[s1];
        int ch=dp[i];if(i)ch=(ch+mdn-dp[i-1]);
        ans=(ans+cur*(long long)ch)%mdn;
    }
    cout<<ans;
    return 0;
}