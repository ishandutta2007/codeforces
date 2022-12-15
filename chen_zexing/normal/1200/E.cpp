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
string s[100005];
long long mod=998244353,mod2=1000000007;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long qpow2(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod2;
        b>>=1;
        a=a*a%mod2;
    }
    return ans;
}
long long fac[1000005],fac2[1000005],inv,inv2;
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>s[i];
        fac[0]=fac2[0]=1;
        for(int i=1;i<=1e6;i++) fac[i]=fac[i-1]*137%mod;
        for(int i=1;i<=1e6;i++) fac2[i]=fac2[i-1]*137%mod2;
        inv=qpow(137,mod-2),inv2=qpow2(137,mod2-2);
        for(int i=2;i<=n;i++){
            int l=min(s[1].size(),s[i].size());
            long long h1=0,h2=0,h3=0,h4=0;
            int f=0;
            for(int j=s[1].size()-l;j<s[1].size();j++) h1+=(long long)(s[1][j])*fac[s[1].size()-j]%mod,h1%=mod,h3+=(long long)(s[1][j])*fac2[s[1].size()-j]%mod2,h3%=mod2;
            for(int j=0;j<l;j++) h2+=(long long)(s[i][j])*fac[l-j]%mod,h2%=mod,h4+=(long long)(s[i][j])*fac2[l-j]%mod2,h4%=mod2;
            for(int j=l;j>=1;j--){
                if(h1==h2&&h3==h4){
                    f=j;
                    break;
                }
                h1-=(long long)(s[1][s[1].size()-j])*fac[j]%mod;
                h1%=mod,h1+=mod,h1%=mod;
                h2-=(long long)(s[i][j-1])*137%mod,h2%=mod,h2*=inv,h2%=mod;
                h2+=mod,h2%=mod;
                h3-=(long long)(s[1][s[1].size()-j])*fac2[j]%mod2;
                h3%=mod2,h3+=mod2,h3%=mod2;
                h4-=(long long)(s[i][j-1])*137%mod2,h4%=mod2,h4*=inv2,h4%=mod2;
                h4+=mod2,h4%=mod2;
            }
            for(int j=f;j<s[i].size();j++) s[1]+=s[i][j];
        }
        cout<<s[1]<<endl;
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