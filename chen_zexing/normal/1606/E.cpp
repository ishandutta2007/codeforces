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
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
long long mod=998244353;
long long pv[505][505],c[505][505];
long long dp[505][505];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int n,k;
long long solve(int n,int x){
    if(n==0) return 1;
    if(n==1) return 0;
    if(dp[n][x]!=-1) return dp[n][x];
    if(x<=n-1) return dp[n][x]=pv[x][n];
    dp[n][x]=0;
    for(int i=0;i<=n;i++){
        dp[n][x]+=pv[n-1][i]*c[n][i]%mod*solve(n-i,x-n+1)%mod;
        //cout<<n<<" "<<i<<" "<<x<<" "<<dp[n][x]<<endl;
        dp[n][x]%=mod;
    }
    //cout<<n<<" "<<x<<" "<<dp[n][x]<<endl;
    return dp[n][x];
}
int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=max(n,k);i++)
            for(int j=0;j<=max(n,k);j++)
                pv[i][j]=qpow(i,j);
        c[0][0]=c[1][0]=c[1][1]=1;
        for(int i=2;i<=n;i++){
            c[i][0]=1;
            for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(n,k));
    }
    return 0;
}
//
/// 
//01
//