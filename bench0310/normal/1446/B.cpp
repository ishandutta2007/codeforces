#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    a="$"+a;
    b="$"+b;
    vector<vector<int>> one(n+2,vector<int>(26,n+1));
    for(int i=n;i>=1;i--)
    {
        one[i]=one[i+1];
        one[i][a[i]-'a']=i;
    }
    vector<vector<int>> two(m+2,vector<int>(26,m+1));
    for(int i=m;i>=1;i--)
    {
        two[i]=two[i+1];
        two[i][b[i]-'a']=i;
    }
    auto mx=[](int &x,int y){x=max(x,y);};
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mx(dp[i+1][j],dp[i][j]-1);
            mx(dp[i][j+1],dp[i][j]-1);
            int ntwo=two[j+1][a[i+1]-'a'];
            if(ntwo!=m+1) mx(dp[i+1][ntwo],dp[i][j]+4-1-(ntwo-j));
            int none=one[i+1][b[j+1]-'a'];
            if(none!=n+1) mx(dp[none][j+1],dp[i][j]+4-1-(none-i));
        }
    }
    int res=0;
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) mx(res,dp[i][j]);
    cout << res << "\n";
    return 0;
}