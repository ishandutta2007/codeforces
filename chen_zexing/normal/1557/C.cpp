#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
using namespace std;
long long mod=1e9+7;
long long fac[200005],ifac[200005];
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
    if(n<m) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
long long temp;
long long solve(int n,int k){
    if(k==0) return 1;
    long long ans;
    if(n%2==0){
        ans=temp;
        ans*=solve(n,k-1),ans%=mod;
        ans+=qpow(2,1LL*n*(k-1)),ans%=mod;
        return ans;
    }
    else{
        ans=temp;
        ans++,ans*=solve(n,k-1),ans%=mod;
        return ans;
    }
}
int main() {
    fac[0]=ifac[0]=1;
    for(int i=1;i<=200000;i++) fac[i]=fac[i-1]*i%mod,ifac[i]=qpow(fac[i],mod-2);
    int T = 1;
    cin >> T;
    while (T--){
        int n,k;
        cin>>n>>k;
        temp=0;
        for(int i=0;i<n;i+=2) temp+=c(n,i),temp%=mod;
        printf("%lld\n",solve(n,k));
    }
    return 0;
}
//
/// 
//01
//
//!