#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s="$"+s+"$";
        vector d(n+2,vector(n+2,int(-1)));
        d[n+1][n+1]=0;
        for(int i=n+1;i>=1;i--)
        {
            for(int j=n+1;j>=1;j--)
            {
                if(i==j) continue;
                if(s[i]!=s[j]) d[i][j]=0;
                else d[i][j]=1+d[i+1][j+1];
            }
        }
        int res=0;
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            dp[i]=(n-i+1);
            for(int j=1;j<i;j++)
            {
                int x=i+d[i][j];
                if(x<=n&&s[j+d[i][j]]<s[x]) dp[i]=max(dp[i],dp[j]+(n-x+1));
            }
            res=max(res,dp[i]);
        }
        cout << res << "\n";
    }
    return 0;
}