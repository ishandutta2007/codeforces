#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long mod=998244353;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,cnt=0,bad=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt+=a[i];
        for(int i=1;i<=n-cnt;i++) if(a[i]) bad++;
        long long ans=0,tot=1LL*n*(n-1)%mod*qpow(2,mod-2)%mod;
        for(int i=1;i<=bad;i++) ans+=tot*qpow(1LL*i*i%mod,mod-2)%mod,ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}