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
char s[2005][2005];
long long dp[2005][2005][2],av[2005][2005][2],suf[2005][2005][2],mod=1e9+7;//01;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        if(s[n][m]=='R'){
            puts("0");
            continue;
        }
        if(n==1&&m==1){
            puts("1");
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=m;j>=1;j--){
                if(j==m) av[i][j][0]=0;
                else av[i][j][0]=av[i][j+1][0]+(s[i][j+1]!='R');
            }
        for(int i=1;i<=m;i++)
            for(int j=n;j>=1;j--){
                if(j==n) av[j][i][1]=0;
                else av[j][i][1]=av[j+1][i][1]+(s[j+1][i]!='R');
            }
        for(int i=n;i>=1;i--)
            for(int j=m;j>=1;j--){
                if(i==n&&j==m) dp[i][j][0]=dp[i][j][1]=1;
                else{
                    dp[i][j][0]=(suf[i][j+1][1]-suf[i][j+av[i][j][0]+1][1])%mod;
                    dp[i][j][1]=(suf[i+1][j][0]-suf[i+av[i][j][1]+1][j][0])%mod;
                }
                //cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
                suf[i][j][0]=(suf[i+1][j][0]+dp[i][j][0])%mod;
                suf[i][j][1]=(suf[i][j+1][1]+dp[i][j][1])%mod;
            }
        printf("%lld\n",((dp[1][1][0]+dp[1][1][1])%mod+mod)%mod);
    }
    return 0;
}
//
/// 
//01
//