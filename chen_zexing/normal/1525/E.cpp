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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[50005][25];
long long mod=998244353;
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
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[j][i]);
        long long fac=1;
        for(int i=1;i<=n;i++) fac=fac*i%mod;
        long long ans=0;
        for(int i=1;i<=m;i++){
            sort(a[i]+1,a[i]+n+1);
            long long temp=1;
            for(int j=1;j<=n;j++) temp*=max(a[i][j]-j,0),temp%=mod;
            temp*=qpow(fac,mod-2),temp%=mod;
            temp=(1-temp+mod)%mod;
            ans=(ans+temp)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp