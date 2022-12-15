#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
long long mul[500005];
long long mod=998244353;
long long qpow(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int main() {
    mul[0]=1;
    mul[1]=1;
    for(int i=2;i<=500000;i++) mul[i]=mul[i-1]*i%mod;
    int n,k;
    long long ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        if(1LL*i*k<=n)
        {
            int t=n/i-1;
            long long cnt=mul[t];
            cnt=cnt*qpow(mul[t-k+1],mod-2)%mod;
            cnt=cnt*qpow(mul[k-1],mod-2)%mod;
            ans=ans+cnt;
            ans%=mod;
        }
    cout<<ans<<endl;
    return 0;

}