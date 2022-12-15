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
long long fac[400005],inv[400005],mod=1e9+7;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long c(long long a,long long b){
    return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        fac[0]=inv[0]=1;
        for(int i=1;i<=400000;i++) fac[i]=fac[i-1]*i%mod,inv[i]=qpow(fac[i],mod-2);
        int n;
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
             scanf("%d",&a[i]);
        if(a[0]==0){
            puts("0");
            continue;
        }
        long long ans=0;
        for(int i=0;i<=n;i++) ans+=c(i+a[i],i+1),ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
//cf