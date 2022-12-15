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
long long dp[2005][2005][2],mod=1000000007;
char s[2005];
int a[2005],l,m,d;
void dfs(int x){
    if(x==1){
        for(int i=1;i<a[1];i++) if(i!=d) dp[x][i%m][0]++;
        if(a[1]!=d) dp[x][a[1]%m][1]++;
        return;
    }
    dfs(x-1);
    for(int i=0;i<10;i++){
        if(x%2&&i==d||x%2==0&&i!=d) continue;
        for(int j=0;j<m;j++) {
            dp[x][(j * 10 + i)%m][0] += dp[x - 1][j][0];
            if(i<a[x]) dp[x][(j*10+i)%m][0]+=dp[x-1][j][1];
            dp[x][((j * 10) + i)%m][0]%=mod;
            if(i==a[x]) dp[x][(j*10+i)%m][1]+=dp[x-1][j][1],dp[x][(j*10+i)%m][1]%=mod;
        }
    }
    //for(int i=0;i<m;i++) cout<<dp[x][i][0]<<" "<<dp[x][i][1]<<endl;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int f=1;
        cin>>m>>d;
        scanf("%s",s+1);
        l=strlen(s+1);
        for(int i=1;i<=l;i++) a[i]=s[i]-'0';
        for(int i=1;i<=l;i++) if(a[i]!=d&&i%2==0||a[i]==d&&i%2) f=0;
        int t=0;
        for(int i=1;i<=l;i++) t=(t*10+a[i])%m;
        if(t) f=0;
        dfs(l);
        long long temp=(dp[l][0][0]+dp[l][0][1])%mod;
        memset(dp,0,sizeof(dp));
        scanf("%s",s+1);
        for(int i=1;i<=l;i++) a[i]=s[i]-'0';
        dfs(l);
        printf("%lld\n",((dp[l][0][0]+dp[l][0][1]-temp+f)%mod+mod)%mod);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp