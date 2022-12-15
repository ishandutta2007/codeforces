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
long long mod=998244353;
long long c[2005][2005];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int a[2005];
int main() {
    int n,k;
    cin>>n>>k;
    if(n==1){
        puts("0");
        return 0;
    }
    c[0][0]=c[1][0]=c[1][1]=1;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++)
        for(int j=0;j<=i;j++)
            c[i][j]=j==0?1:(c[i-1][j-1]+c[i-1][j])%mod;
    int t=0;
    for(int i=1;i<=n;i++) t+=i==n?a[i]!=a[1]:a[i]!=a[i+1];
    long long ans=qpow(k,n-t);
    long long cnt=0;
    for(int i=0;i<t;i++){
        long long temp=qpow(k-2,i);
        temp=temp*c[t][i]%mod;
        long long ccnt=0;
        for(int j=(t-i)/2+1;j<=t-i;j++) ccnt+=c[t-i][j],ccnt%=mod;
        temp*=ccnt,temp%=mod;
        cnt+=temp,cnt%=mod;
    }
    printf("%lld\n",ans*cnt%mod);
    return 0;
}