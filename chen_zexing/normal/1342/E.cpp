#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#define hash hassh
using namespace std;
long long mod=998244353,multi[200005];
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
    return multi[n]*qpow(multi[m],mod-2)%mod*qpow(multi[n-m],mod-2)%mod;
}
int main() {
    long long n,k;
    cin>>n>>k;
    multi[0]=1;
    for(int i=1;i<=n;i++) multi[i]=multi[i-1]*i%mod;
    if(k>=n) puts("0");
    else if(k==0){
        printf("%lld\n",multi[n]);
    }
    else{
        long long ans=c(n,n-k),cnt=0,now;
        for(int i=0;i<n-k;i++)
        {
            now=qpow(n-k-i,n)*c(n-k,i)%mod;
            if(i%2==0) cnt+=now;
            else cnt-=now;
            cnt%=mod;
        }
        cnt%=mod;
        if(cnt<0) cnt+=mod;
        printf("%lld\n",ans*cnt*2%mod);
    }
    return 0;
}