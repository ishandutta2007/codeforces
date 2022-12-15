#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
long long mod=998244353;
int a[300005];
long long pre[300005],fac[300005],inv[300005];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long C(int n,int m) {
    if(n<m) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
long long A(int n,int m){
    if(n<m) return 0;
    return fac[n]*inv[n-m]%mod;
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        map <long long,int> mp;
        int n,m,cnt=0;
        cin>>n>>m;
        fac[0]=inv[0]=1;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
        for(int i=1;i<=300000;i++) fac[i]=fac[i-1]*i%mod,inv[i]=qpow(fac[i],mod-2);
        if(pre[n]%2){
            printf("%lld\n",qpow(m,n));
            continue;
        }
        for(int i=1;i<=n;i++){
            if(mp[pre[i]-pre[n]/2]) cnt++;
            mp[pre[i]]=1;
        }
        long long ans=0;
        for(int i=0;i<=min(cnt,m);i++){
            ans+=C(m,i)*A(cnt,i)%mod*(cnt!=i?qpow(A(m-i,2),cnt-i):1)%mod*qpow(m-i,n-cnt*2)%mod;
            ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}