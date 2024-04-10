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
long long mod=1000000007,fac[200005];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long inv(long long x){
    return qpow(x,mod-2);
}
long long c(int n,int m){
    if(n<m) return 0;
    return fac[n]*inv(fac[m])%mod*inv(fac[n-m])%mod;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--){
        int n,l,r;
        cin>>n>>l>>r;
        fac[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
        if(n%2==0){
            long long ans=0;
            int mn=min(1-l,r-n),mx=min(n/2+1-l,r-n/2);
            long long before=0;
            for(int i=mx;i>=mn;i--){
                int lft=max(1,i+l),rt=min(n,r-i);
                long long temp=c(rt-lft+1,n/2-lft+1);
                temp-=before;
                before+=temp,before%=mod,before+=mod,before%=mod;
                temp=(temp%mod+mod)%mod;
                ans+=temp*i%mod,ans%=mod;
            }
            cout<<ans<<endl;
        }
        else{
            long long ans=0;
            int mn,mx;
            mn=min(1-l,r-n),mx=min(n/2+1-l,r-n/2);
            long long before=0;
            for(int i=mx;i>=mn;i--){
                int lft=max(1,i+l),rt=min(n,r-i);
                long long temp=c(rt-lft+1,n/2-lft+1);
                temp-=before;
                before+=temp,before%=mod,before+=mod,before%=mod;
                temp=(temp%mod+mod)%mod;
                ans+=temp*i%mod,ans%=mod;
            }
            mn=min(1-l,r-n),mx=min(n/2+2-l,r-n/2-1);
            before=0;
            for(int i=mx;i>=mn;i--){
                int lft=max(1,i+l),rt=min(n,r-i);
                long long temp=c(rt-lft+1,n/2+1-lft+1);
                temp-=before;
                before+=temp,before%=mod,before+=mod,before%=mod;
                temp=(temp%mod+mod)%mod;
                ans+=temp*i%mod,ans%=mod;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}