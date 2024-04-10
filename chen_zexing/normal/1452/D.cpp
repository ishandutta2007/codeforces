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
#include <unordered_set>
#define hash hassh
using namespace std;
long long mod=998244353,ans[200005];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    ans[0]=1;
    ans[1]=qpow(2,mod-2);
    ans[2]=qpow(4,mod-2);
    long long sum0=(qpow(8,mod-2)+ans[2]*qpow(2,mod-2)%mod)%mod;
    long long sum1=ans[1]*qpow(2,mod-2)%mod;
    for(int i=3;i<=n;i++){
        if(i%2){
            ans[i]=sum0;
            sum1=sum1*qpow(4,mod-2)%mod;
            sum1=(sum1+ans[i]*qpow(2,mod-2)%mod)%mod;
        }
        else{
            ans[i]=sum1;
            sum0=sum0*qpow(4,mod-2)%mod;
            sum0=(sum0+ans[i]*qpow(2,mod-2)%mod)%mod;
        }
    }
    printf("%lld\n",ans[n]);
    return 0;
}