#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005];
long long pre[100005],fac[100005],inv[100005];
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
long long c(int n,int m){
    if(n<m) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        map <long long,int> mp[2];
        int n;
        scanf("%d",&n);
        fac[0]=inv[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod,inv[i]=qpow(fac[i],mod-2);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
        if(pre[n]==0){
            printf("%lld\n",qpow(2,n-1));
            continue;
        }
        for(int i=1;i<=n&&pre[i]*2<pre[n];i++) mp[0][pre[i]]++;
        for(int i=n-1;i&&(pre[n]-pre[i])*2<pre[n];i--) mp[1][pre[n]-pre[i]]++;
        long long ans=1;
        for(auto t:mp[0]){
            //cout<<t.first<<" "<<t.second<<endl;
            int mn=min(t.second,mp[1][t.first]);
            long long tmp=0;
            for(int i=0;i<=mn;i++) tmp+=c(t.second,i)*c(mp[1][t.first],i)%mod,tmp%=mod;
            ans=ans*tmp%mod;
        }
        int cnt=0;
        for(int i=1;i<=n;i++) if(pre[i]*2==pre[n]) cnt++;
        ans=ans*qpow(2,cnt)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}