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
int a[200005],pos[200005];
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
long long c(int x,int y){
    long long ans=1;
    for(int i=1;i<=x;i++) ans*=i,ans%=mod;
    for(int i=1;i<=y;i++) ans*=qpow(i,mod-2),ans%=mod;
    for(int i=1;i<=x-y;i++) ans*=qpow(i,mod-2),ans%=mod;
    return ans;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
        pos[n+1]=0;
        int add=0;
        for(int i=1;i<n;i++){
            if(pos[a[i]+1]>pos[a[i+1]+1]) add++;
        }
        int tot=k-1;
        tot-=add;
        if(tot<0){
            puts("0");
            continue;
        }
        tot+=n+1;
        printf("%lld\n",c(tot-1,n));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp