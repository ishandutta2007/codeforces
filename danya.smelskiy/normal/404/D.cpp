#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
string s;
long long dp[1000002][5];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    if (s[0]=='2') {
        cout<<0;
        return 0;
    }
    else if (s[0]=='0') dp[0][0]=1;
    else if (s[0]=='1') dp[0][2]=1;
    else if (s[0]=='*') dp[0][4]=1;
    else {
        dp[0][0]=1;
        dp[0][2]=1;
        dp[0][4]=1;
    }
    for (int i=1;i<s.size();++i) {
        if (s[i]=='0') dp[i][0]=(dp[i-1][0]+dp[i-1][1])%md;
        else if (s[i]=='1') {
            dp[i][1]=dp[i-1][4];
            dp[i][2]=(dp[i-1][1]+dp[i-1][0])%md;
        } else if (s[i]=='2') {
            dp[i][3]=dp[i-1][4];
        } else if (s[i]=='*') {
            dp[i][4]=(dp[i-1][4]+dp[i-1][2]+dp[i-1][3])%md;
        } else {
            dp[i][0]=(dp[i-1][0]+dp[i-1][1])%md;
            dp[i][1]=dp[i-1][4];
            dp[i][2]=(dp[i-1][1]+dp[i-1][0])%md;
            dp[i][3]=(dp[i-1][4]);
            dp[i][4]=(dp[i-1][4]+dp[i-1][2]+dp[i-1][3])%md;
        }
    }
    int n=s.size()-1;
    if (s[n]=='2') {
        cout<<0;
        return 0;
    }
    long long ans=dp[n][0]+dp[n][1]+dp[n][4];
    ans%=md;
    cout<<ans;
}