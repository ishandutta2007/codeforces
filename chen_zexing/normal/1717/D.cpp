#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long fac[100005],inv[100005];
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
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n,k;
        cin>>n>>k;
        fac[0]=inv[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod,inv[i]=qpow(fac[i],mod-2);
        k=min(n,k);
        long long ans=0;
        for(int i=0;i<=k;i++) ans+=c(n,i),ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}