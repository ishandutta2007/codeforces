#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
int a[200005];
long long fac[200005],inv[200005];
long long mod=1e9+7;
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
    return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int cnt[31];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,odd=0;
        long long ans=0;
        scanf("%d",&n);
        fac[0]=1,inv[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod,inv[i]=qpow(fac[i],mod-2);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            int now=0;
            while(a[i]%2==0) a[i]/=2,now++;
            cnt[now]++;
            if(now==0) odd++;
        }
        ans+=(qpow(2,odd)-1)*qpow(2,n-odd)%mod;
        int pre=0;
        for(int i=1;i<=30;i++){
            //cout<<i<<" "<<cnt[i]<<endl;
            pre+=cnt[i];
            for(int j=2;j<=cnt[i];j+=2) ans+=c(cnt[i],j)*qpow(2,n-odd-pre)%mod,ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}