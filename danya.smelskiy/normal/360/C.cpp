#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n,m;
string s;
long long dp[2005][2005][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>s;
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=m;++j) {
            dp[i][j][0]=(dp[i-1][j][1]*(long long)(s[i-1]-'a'))%md;
            for (int k=0;i-k-1>=0 && j-((k+1)*(n-i+1))>=0;++k)
                dp[i][j][0]=(dp[i][j][0]+dp[i-k-1][j-((k+1)*(n-i+1))][0]*(long long)('z'-s[i-1]))%md;
            dp[i][j][1]=(dp[i][j][0]+dp[i-1][j][1]);
            if (dp[i][j][1]>=md) dp[i][j][1]-=md;
        }
    }
    cout<<dp[n][m][1];
}