#include <bits/stdc++.h>

using namespace std;

const int nax=5000+7;
int lcp[nax][nax];
int dp[nax];
int n,a,b;
string s;

int main()
{
        cin>>n>>a>>b>>s;
        s="."+s;
        for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                        if(s[i]==s[j])
                                lcp[i][j]=1+lcp[i-1][j-1];
        for(int i=1;i<=n;i++)
        {
                dp[i]=a+dp[i-1];
                for(int j=1;j<i;j++)
                {
                        int kol=min(i-j,lcp[i][j]);
                        dp[i]=min(dp[i],dp[i-kol]+b);
                }
        }
        cout<<dp[n]<<"\n";
        return 0;
}