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
int a[300005];
long long mod=998244353;
bool cmp(int a,int b){
    return a<b;
}
long long multi[300005];
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
    for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
    sort(a+1,a+n*2+1,cmp);
    long long ans=0;
    for(int i=1;i<=n;i++) ans-=a[i];
    for(int i=n+1;i<=n*2;i++) ans+=a[i];
    ans%=mod;
    multi[0]=1;
    for(int i=1;i<=n*2;i++) multi[i]=multi[i-1]*i%mod;
    ans=ans*multi[n*2]%mod*qpow(multi[n],mod-2)%mod*qpow(multi[n],mod-2)%mod;
    printf("%lld\n",ans);
    return 0;
}