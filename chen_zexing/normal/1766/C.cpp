#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[2][200005];
int dp[2][200005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,cnt=0,f=1;
        scanf("%d",&n);
        scanf("%s",s[0]+1),scanf("%s",s[1]+1);
        dp[0][0]=dp[1][0]=1;
        for(int i=1;i<=n;i++){
            if(s[0][i]=='B'&&s[1][i]=='B'){
                dp[0][i]=dp[1][i-1];
                dp[1][i]=dp[0][i-1];
            }
            else if(s[0][i]=='B') dp[0][i]=dp[0][i-1],dp[1][i]=0;
            else dp[1][i]=dp[1][i-1],dp[0][i]=0;
        }
        puts(dp[0][n]||dp[1][n]?"YES":"NO");
    }
    return 0;
}