#include <bits/stdc++.h>
#define db(x) cout << x << '\n';
using namespace std;

int ma[20][2],dp[20][2],x;
string mm[20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=n-1;i>=0;i--)
    {
        cin >> mm[i];
        for(int j=0;j<m+2;j++)
        {
            if(mm[i][j]=='1')
            {
                ma[i][1]=j,x=max(x,i);
                if(!ma[i][0])
                    ma[i][0]=j;
            }
        }
    }

    if(x>=1)
    {
        dp[1][1]=m+2;
        dp[1][0]=2*ma[0][1]+1;
        for(int i=2;i<=x;i++)
        {
            if(!ma[i-1][0])
                ma[i-1][0]=m+1;
            dp[i][0]=min(dp[i-1][0]+2*ma[i-1][1],dp[i-1][1]+m+1)+1,dp[i][1]=min(dp[i-1][1]+2*(m+1-ma[i-1][0]),dp[i-1][0]+m+1)+1;
        }
        db(min(dp[x][0]+ma[x][1],dp[x][1]+m+1-ma[x][0]));
    }
    else
        db(ma[0][1])
    return 0;
}