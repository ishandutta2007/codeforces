#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long fac[1000005],inv[1000005];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long c(int n,int m){
    if(n<m) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n,k;
        cin>>n>>k;
        fac[0]=inv[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod,inv[i]=qpow(fac[i],mod-2);
        if(k==0){
            printf("%lld\n",qpow(3,n));
            continue;
        }
        long long ans=0;
        for(int i=1;i<=k;i++){
            if(k+i-1<=n&&i>=2) ans+=c(k-1,i-1)*c(n-k-1,i-2)%mod*qpow(3,n-i*2+1)%mod,ans%=mod;
            if(k+i<=n) ans+=c(k-1,i-1)*c(n-k-1,i-1)%mod*qpow(3,n-i*2+1)%mod,ans%=mod;
            if(k+i<=n) ans+=c(k-1,i-1)*c(n-k-1,i-1)%mod*qpow(3,n-i*2)%mod,ans%=mod;
            if(k+i+1<=n) ans+=c(k-1,i-1)*c(n-k-1,i)%mod*qpow(3,n-i*2)%mod,ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}