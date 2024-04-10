#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s[2];
    cin>>s[0]>>s[1];
    int n=s[0].size();
    s[0].push_back('X');
    s[1].push_back('X');
    int dp[n+1][4];
    for(int a=0; a<=n; a++)
    {
        for(int b=0; b<4; b++) dp[a][b]=-1;
    }
    dp[0][0]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<4; b++)
        {
            if(dp[a][b]!=-1)
            {

                int p[4]={1, 1, 1, 1};
                if(b==1 or b==3 or s[0][a]=='X') p[0]=0;
                if(b==2 or b==3 or s[1][a]=='X') p[1]=0;
                if(s[0][a+1]=='X') p[2]=0;
                if(s[1][a+1]=='X') p[3]=0;
                if(p[0] and p[1] and p[2]) dp[a+1][1]=max(dp[a+1][1], dp[a][b]+1);
                if(p[0] and p[2] and p[3]) dp[a+1][3]=max(dp[a+1][3], dp[a][b]+1);
                if(p[1] and p[2] and p[3]) dp[a+1][3]=max(dp[a+1][3], dp[a][b]+1);
                if(p[0] and p[1] and p[3]) dp[a+1][2]=max(dp[a+1][2], dp[a][b]+1);
                dp[a+1][0]=max(dp[a+1][0], dp[a][b]);
            }
        }
        //for(int b=0; b<4; b++) cout<<dp[a+1][b]<<" ";
        //cout<<"\n";
    }
    cout<<dp[n][0];
}