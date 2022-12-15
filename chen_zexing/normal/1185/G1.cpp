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
long long dp[33005][230][4],mod=1000000007;
int t[20],g[20],n;
long long solve(int con,int rest,int type){
    if(con==0||rest<=0) return rest==0;
    if(dp[con][rest][type]!=-1) return dp[con][rest][type];
    dp[con][rest][type]=0;
    for(int i=1;i<=n;i++)
        if(((1<<(i-1))&con)&&g[i]!=type)
            dp[con][rest][type]+=solve(con-(1<<(i-1)),rest-t[i],g[i]);
    return dp[con][rest][type]%=mod;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>t[i]>>g[i];
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve((1<<n)-1,m,0));
    }
    return 0;
}
//
/// 
//01
//