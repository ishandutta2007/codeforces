#include <bits/stdc++.h>
#define int short int
using namespace std;
const int inf=1e4;
int mi(int x, int y)
{
    return (x<y ? x : y);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int dp[n][n+1][26], dp2[n][n];
    for(int a=0; a<n; a++) for(int b=0; b<26; b++) dp[a][a][b]=0;
    for(int a=1; a<=n; a++)
    {
        for(int l=0; l+a<=n; l++)
        {
            dp2[l][a]=inf;
            for(int b=0; b<26; b++)
            {
                dp[l][l+a][b]=inf;
                if(s[l+a-1]-'a'==b) dp[l][l+a][b]=dp[l][l+a-1][b];
                for(int c=1; c<a; c++) dp[l][l+a][b]=mi(dp[l][l+a][b], dp[l][l+a-c][b]+dp2[l+a-c][c]);
                dp2[l][a]=mi(dp2[l][a], dp[l][l+a][b]+1);
            }
            for(int b=0; b<26; b++) dp[l][l+a][b]=mi(dp[l][l+a][b], dp2[l][a]);
        }
    }
    cout<<dp2[0][n];
}