#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
long long pre[100005];
int f[100005],bad[100005],cnt[100005];
long long fac[100005];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
vector <int> v[100005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        long long ans=0;
        int n;
        cin>>n;
        for(int i=2;i<=n;i++) {
            if(!f[i]){
                for(int j=i;j<=n;j+=i) f[j]=1,cnt[j]++;
                for(long long j=1LL*i*i;j<=n;j+=1LL*i*i) bad[j]=1;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j+=i)
                v[j].push_back(i);
        for(int i=2;i<=n;i++)
            if(!bad[i])
                for(int j=i*2;j<=n;j+=i)
                    fac[j]+=cnt[i]%2?(j-1)/i:-(j-1)/i;
        for(int i=1;i<=n-2;i++){
            for(auto t:v[n-i]){
                ans+=1LL*i*t/gcd(i,t)%mod*((n-i)/t-1-fac[(n-i)/t])%mod,ans%=mod;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}