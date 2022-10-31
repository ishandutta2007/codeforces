#include <bits/stdc++.h>
using namespace std;
string s;
int dp[100005][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    int n=s.size();
    for (int i=1;i<=n;++i) {
        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-1][1];
        if (s[i-1]>='a' && s[i-1]<='z') ++dp[i][0];
        else ++dp[i][1];
    }
    int a=0,b=0;
    int ans=min(dp[n][0],dp[n][1]);
    for (int i=n;i>0;--i) {
        if (s[i-1]>='A' && s[i-1]<='Z') ++a;
        ans=min(ans,dp[i-1][0]+a);
    }
    cout<<ans;
}