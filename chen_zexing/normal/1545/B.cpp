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
using namespace std;
long long fac[100005],mod=998244353;
char s[100005];
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
    return fac[n]*qpow(fac[m],mod-2)%mod*qpow(fac[n-m],mod-2)%mod;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        fac[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
        int cnt0=0,cnt1=0,now=0,f=0;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='1') now++;
            else{
                cnt0++;
                if(now%2) cnt1++;
                now=0;
            }
        }
        if(now%2) cnt1++;
        //cout<<cnt0<<" "<<cnt1<<endl;
        printf("%lld\n",c(cnt0+(n-cnt0-cnt1)/2,cnt0));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//