#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll mod;
    cin >> n >> mod;
    auto add=[&](ll a,ll b){return (a+b)%mod;};
    auto madd=[&](ll &a,ll b){a=add(a,b);};
    auto mul=[&](ll a,ll b){return (a*b)%mod;};
    //turn on segments implicitly, actual computer ids are fixed at the end
    vector dp(n+3,vector(n+2,ll(0)));
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            //add a new segment
            madd(dp[i+1][j+1],mul(j+1,dp[i][j]));
            //extend a segment by one
            madd(dp[i+1][j],mul(2*j,dp[i][j]));
            //extend a segment by two (one computer turns on automatically)
            madd(dp[i+2][j],mul(2*j,dp[i][j]));
            //merge two segments by extending one of them (one computer turns on automatically)
            if(j>=2) madd(dp[i+2][j-1],mul(2*(j-1),dp[i][j]));
            //merge two segments by adding a new segment between them (two computers turn on automatically)
            if(j>=2) madd(dp[i+3][j-1],mul(j-1,dp[i][j]));
        }
    }
    cout << dp[n][1] << "\n";
    return 0;
}