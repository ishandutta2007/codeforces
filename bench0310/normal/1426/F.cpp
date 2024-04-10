#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    s="$"+s;
    const ll mod=1000000007;
    vector<array<ll,4>> dp(n+1,{0,0,0,0});
    dp[0][0]=1;
    auto add=[&](ll &a,ll b){a=(a+b)%mod;};
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(s[i]=='?') for(int j=1;j<=3;j++) dp[i][j]=(3*dp[i][j])%mod;
        if(s[i]=='a'||s[i]=='?') add(dp[i][1],dp[i-1][0]);
        if(s[i]=='b'||s[i]=='?') add(dp[i][2],dp[i-1][1]);
        if(s[i]=='c'||s[i]=='?') add(dp[i][3],dp[i-1][2]);
        dp[i][0]=((s[i]=='?'?3:1)*dp[i-1][0])%mod;
    }
    cout << dp[n][3] << "\n";
    return 0;
}