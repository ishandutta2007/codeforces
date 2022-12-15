#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
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
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[200005];
long long dp[200005][2],mod=998244353;
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
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        dp[0][0]=0;
        for(int i=1;i<=n;i++) dp[i][0]=(qpow(k-1,i)-dp[i-1][0])%mod;
        dp[0][1]=1;
        for(int i=1;i<=n;i++) dp[i][1]=(qpow(k-1,i)-dp[i-1][1])%mod;
        long long ans=1;
        vector <int> v[2];
        for(int i=1;i<=n;i++) v[i%2].push_back(a[i]);
        for(int i=3;i<=n;i++) if(a[i]==a[i-2]&&a[i]!=-1){
                puts("0");
                exit(0);
            }
        for(int i=0;i<2;i++) {
            int pre=0,cnt=0;
            for (int j = 0; j <= v[i].size(); j++){
                if(j==v[i].size()){
                    if(!cnt) break;
                    if(pre==0) ans*=qpow(k-1,cnt-1)*k%mod,ans%=mod;
                    else ans*=qpow(k-1,cnt)%mod,ans%=mod;
                }
                else{
                    if(v[i][j]==-1) cnt++;
                    else{
                        if(cnt){
                            if(pre==0) ans*=qpow(k-1,cnt),ans%=mod;
                            else if(pre==v[i][j]) ans*=dp[cnt][0],ans%=mod;
                            else ans*=dp[cnt][1],ans%=mod;
                        }
                        pre=v[i][j],cnt=0;
                    }
                }
            }
        }
        printf("%lld\n",(ans+mod)%mod);
    }
    return 0;
}
//
/// 
//01
//