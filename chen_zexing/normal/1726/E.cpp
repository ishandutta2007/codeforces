#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
long long sing[300005],pr[300005],mod=998244353;
long long fac[600005],inv[600005];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long c(int a,int b){
    if(a<b) return 0;
    return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        cin>>n;
        fac[0]=inv[0]=1;
        for(int i=1;i<=n*2;i++) fac[i]=fac[i-1]*i%mod,inv[i]=qpow(fac[i],mod-2);
        pr[0]=pr[1]=1;
        for(int i=2;i<=n;i++) pr[i]=pr[i-1]*(i*2-1)%mod;
        sing[1]=sing[0]=1;
        for(int i=2;i<=n;i++) sing[i]=(sing[i-1]+sing[i-2]*(i-1))%mod;
        long long ans=0;
        for(int i=0;i*4<=n;i++){
            long long temp=i==0?1:c(i*2+(n-i*4),n-i*4);
            //cout<<temp<<endl;
            //cout<<n<<" "<<i<<" "<<temp<<endl;
            temp*=pr[i]%mod,temp%=mod;
            if(i) temp*=qpow(2,i),temp%=mod;
            temp*=sing[n-i*4],temp%=mod;
            //cout<<i<<" "<<temp<<endl;
            ans+=temp,ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}