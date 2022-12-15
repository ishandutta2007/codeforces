#pragma GCC optimize("Ofast,unroll-loops")
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
long long mod=1e9+7;
long long fac[1000005];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long c(long long n,long long m){
    return fac[n]*qpow(fac[m],mod-2)%mod*qpow(fac[n-m],mod-2)%mod;
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        fac[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
        m=n-m;
        if(m==0){
            printf("%lld\n",1LL*n*k%mod);
            continue;
        }
        long long iv2=qpow(2,mod-2);
        long long ans=0;
        for(int dif=0;dif<=n-m;dif++){
            long long v=1LL*k*dif%mod;
            //cout<<dif<<endl;
            long long base=v*qpow(iv2,n-dif)%mod;
            ans+=base*c(n-dif-1,m-1)%mod,ans%=mod;
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}
//unordered_map
//cf