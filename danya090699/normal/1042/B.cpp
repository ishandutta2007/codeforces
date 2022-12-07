#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int dp[n+1][8];
    for(int a=0; a<=n; a++) for(int b=0; b<8; b++) dp[a][b]=inf;
    dp[0][0]=0;
    for(int a=0; a<n; a++)
    {
        int w, mask=0;
        string s;
        cin>>w>>s;
        for(int b=0; b<s.size(); b++)
        {
            if(s[b]=='A') mask+=1;
            if(s[b]=='B') mask+=2;
            if(s[b]=='C') mask+=4;
        }
        for(int b=0; b<8; b++)
        {
            dp[a+1][b|mask]=min(dp[a+1][b|mask], dp[a][b]+w);
            dp[a+1][b]=min(dp[a+1][b], dp[a][b]);
        }
    }
    if(dp[n][7]==inf) cout<<-1;
    else cout<<dp[n][7];
}