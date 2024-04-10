#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long dp[1000005],p[1000005],suf[1000005],ans[1000005];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int main(){
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        long long iv2=qpow(2,mod-2);
        for(int i=1;i<=n;i++){
            dp[i]=qpow(iv2,(i-1)/2);
            if(i!=n) dp[i]=dp[i]*iv2%mod;
        }
        suf[n+1]=0;
        for(int i=n;i;i--){
            if(i*2>n) p[i]=1;
            else p[i]=suf[i+1]-suf[i*2]*qpow(iv2,i-1)%mod;
            suf[i]=(suf[i+1]+p[i])%mod*iv2%mod;
            //cout<<i<<" "<<suf[i]<<endl;
            ans[i]=dp[i]*p[i]%mod;
        }
        for(int i=1;i<=n;i++) printf("%lld\n",(ans[i]%mod+mod)%mod);
        long long sum=0;
        for(int i=1;i<=n;i++) sum=(sum+ans[i])%mod;
        sum=(sum+mod)%mod;
        //cout<<sum<<endl;
    }
    return 0;
}