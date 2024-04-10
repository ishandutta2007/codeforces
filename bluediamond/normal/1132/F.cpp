#include <bits/stdc++.h>

using namespace std;

const int N=500+7;
int n;
int v[N];
string s;
int dp[N][N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>s;
        for(int i=1;i<=n;i++)
        {
                v[i]=(s[i-1]-'a');
        }
        for(int l=2;l<=n;l++)
        {
                for(int st=1;st+l-1<=n;st++)
                {
                        int dr=st+l-1;
                        dp[st][dr]=n;
                        for(int k=st;k<dr;k++)
                        {
                                dp[st][dr]=min(dp[st][dr],dp[st][k]+dp[k+1][dr]+(v[k]!=v[dr]));
                        }
                }
        }
        cout<<dp[1][n]+1<<"\n";
        return 0;
}