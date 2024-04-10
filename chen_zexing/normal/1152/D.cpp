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
long long dp[1005][2005][2],mod=1000000007;
void solve(int nd,int rest){
    if(nd<0||rest<=0||rest<nd){
        if(nd<0) return;
        if(rest<nd) dp[nd][rest][0]=dp[nd][rest][1]=0;
        if(rest==0&&nd==0) dp[nd][rest][0]=1,dp[nd][rest][1]=0;
        return;
    }
    if(dp[nd][rest][0]!=-1) return;
    solve(nd+1,rest-1),solve(nd-1,rest-1);
    dp[nd][rest][0]=1,dp[nd][rest][1]=0;
    dp[nd][rest][0]+=dp[nd+1][rest-1][1];
    if(nd) dp[nd][rest][0]+=dp[nd-1][rest-1][1];
    dp[nd][rest][0]%=mod;
    dp[nd][rest][1]+=dp[nd+1][rest-1][0];
    if(nd) dp[nd][rest][1]+=dp[nd-1][rest-1][0];
    dp[nd][rest][1]%=mod;
    //cout<<nd<<" "<<rest<<endl;
    //cout<<dp[nd][rest][0]<<" "<<dp[nd][rest][1]<<endl;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        solve(0,n*2);
        //cout<<dp[0][n*2][0]<<" "<<dp[0][n*2][1]<<endl;
        cout<<dp[0][n*2][1];
    }
    return 0;
}
//
/// 
//01
//