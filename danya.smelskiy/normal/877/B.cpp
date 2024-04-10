#include <bits/stdc++.h>
using namespace std;
string s;
int dp[10000][3];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for (int i=1;i<=s.size();++i) {
        for (int j=0;j<=2;++j)
            dp[i][j]=dp[i-1][j];
        if (s[i-1]=='a') {
            ++dp[i][0];
            ++dp[i][2];
            dp[i][2]=max(dp[i][2],dp[i-1][1]+1);
        } else dp[i][1]++;
        dp[i][1]=max(dp[i][1],dp[i][0]);
        dp[i][2]=max(dp[i][2],dp[i][1]);
    }
    int n=s.size();
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));
}