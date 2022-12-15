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
using namespace std;
long long ans,multi[200005],mod=998244353;
long long c[200005];
long long qpow(long long a,long long b)
{
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long cc(int n,int m){
    return multi[n]*qpow(multi[m],mod-2)%mod*qpow(multi[n-m],mod-2)%mod;
}
int main() {
    int n,m;
    cin>>n>>m;
    multi[0]=1;
    for(int i=1;i<=200000;i++) multi[i]=multi[i-1]*i%mod;
    for(int i=n-2;i<=m-1;i++) c[i]=multi[i]*qpow(multi[n-2],mod-2)%mod*qpow(multi[i-n+2],mod-2)%mod;
    long long sum=0;
    for(int i=n-2;i<=m-1;i++) sum=(sum+c[i])%mod;
    for(int i=2;i<n;i++){
        ans+=1LL*sum*(n-2)%mod*cc(n-3,i-2)%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}