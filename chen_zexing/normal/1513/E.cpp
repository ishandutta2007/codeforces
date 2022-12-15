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
int a[100005];
long long mul[100005];
long long mod=1000000007;
map <int,int> mp,f;
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
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        long long tot=0;
        cin>>n;
        mul[0]=1;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),tot+=a[i],mp[a[i]]++,mul[i]=mul[i-1]*i%mod;
        if(tot%n){
            puts("0");
            continue;
        }
        int tar=tot/n;
        if(n==1){
            puts("1");
            continue;
        }
        int c[3]={};
        for(int i=1;i<=n;i++){
            if(a[i]<tar) c[0]++;
            else if(a[i]>tar) c[1]++;
            else c[2]++;
        }
        long long ans;
        if(c[0]==0&&c[1]==0){
            ans=1;
        }
        else if(c[0]==1||c[1]==1) {
            ans=1;
            for (int i = 1; i <= c[0] + c[1]; i++) ans=ans*i%mod;
        }
        else {
            ans = 2;
            for (int i = 1; i <= c[0]; i++) ans = ans * i % mod;
            for (int i = 1; i <= c[1]; i++) ans = ans * i % mod;
        }
        for(int i=1;i<=c[2];i++) ans=ans*(c[0]+c[1]+i)%mod;
        for(int i=1;i<=n;i++)
            if(!f[a[i]]){
                f[a[i]]=1;
                ans=ans*qpow(mul[mp[a[i]]],mod-2)%mod;
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