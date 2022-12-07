#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, A, B;
        cin>>n>>A>>B;
        string s;
        cin>>s;
        s.push_back('0');
        int dp[n+1][2], go[2][2]={{A+B, 2*A+2*B}, {2*A+B, A+2*B}};
        for(int a=0; a<=n; a++) for(int i=0; i<2; i++) dp[a][i]=inf;
        dp[0][0]=B;
        for(int a=0; a<n; a++)
        {
            for(int i=0; i<2; i++)
            {
                for(int j=0; j<2; j++)
                {
                    if(j==1 or (j==0 and s[a+1]=='0' and s[a]=='0')) dp[a+1][j]=min(dp[a+1][j], dp[a][i]+go[i][j]);
                }
            }
        }
        cout<<dp[n][0]<<"\n";
    }
}