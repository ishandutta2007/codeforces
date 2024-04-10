#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000+5;

int n,m;
int l,r;

int f[N][2];
int dp[N][N][2];

int co(int i,int x)
{
    return f[i][1-x];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) for(int k=0;k<2;k++) dp[i][j][k]=(1<<30);
    cin>>m>>n>>l>>r;
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=n;j++)
        {
            int x=0;
            if(s[j-1]=='.') x=1;
            f[j][x]++;
        }
    }
    dp[1][1][0]=co(1,0);
    dp[1][1][1]=co(1,1);
    /**for(int i=1;i<=n;i++)
    {
        for(int ant=1;ant<=r;ant++)
        {
            for(int x=0;x<=1;x++)
            {
                if(dp[i][ant][x]!=(1<<30))
                {
                    cout<<i<<" , "<<ant<<" , "<<x<<" : "<<dp[i][ant][x]<<"\n";
                }
            }
        }
    }**/
    for(int i=1;i<n;i++)
    {
        for(int x=0;x<=1;x++)
        {
            for(int ant=1;ant<=r;ant++)
            {
                if(ant<r)
                {
                    dp[i+1][ant+1][x]=min(dp[i+1][ant+1][x],dp[i][ant][x]+co(i+1,x));
                }
                if(ant>=l)
                {
                    dp[i+1][1][1-x]=min(dp[i+1][1][1-x],dp[i][ant][x]+co(i+1,1-x));
                }
            }
        }
    }

    int res=(1<<30);
    for(int f=l;f<=r;f++)
    {
        for(int x=0;x<=1;x++)
        {
            res=min(res,dp[n][f][x]);
        }
    }
    cout<<res<<"\n";
    return 0;
}
/**

**/