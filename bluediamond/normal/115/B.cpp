#include <bits/stdc++.h>

using namespace std;

const int N=150+5;
int n,m,v[N][N];

bool gol(int r)
{
    for(int c=1;c<=m;c++)
        if(v[r][c])
            return 0;
    return 1;
}

int get_first(int r)
{
    for(int c=1;c<=m;c++)
        if(v[r][c])
            return c;
    return m;
}

int get_last(int r)
{
    for(int c=m;c>=1;c--)
        if(v[r][c])
            return c;
    return 1;
}

int dp[N][N];
bool valid[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dp[i][j]=(1<<30);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        for(int j=1;j<=m;j++)
            v[i][j]=(a[j-1]=='W');
    }
    while(gol(n)==1)
    {
        n--;
        if(n==0)
        {
            cout<<"0\n";
            return 0;
        }
    }
    int last=get_last(1);
    bool fgol=gol(1);
    for(int c=1;c<=m;c++)
    {
        dp[1][c]=c-1;
        if(fgol)
        {
            valid[1][c]=1;
            continue;
        }
        if(c>=last)
            valid[1][c]=1;
    }
    for(int r=2;r<=n;r++)
    {
        if(r%2==0)
        {
            int first=get_first(r);
            int last=get_last(r);
            for(int c=m;c>=1;c--)
            {
                if(valid[r][c+1])
                {
                    valid[r][c]=1;
                    dp[r][c]=min(dp[r][c],dp[r][c+1]+1);
                }
                if(c>=last && valid[r-1][c])
                {
                    valid[r][c]=1;
                    dp[r][c]=min(dp[r][c],dp[r-1][c]+1);
                }
            }
            for(int c=first+1;c<=m;c++)
                valid[r][c]=0;
        }
        if(r%2==1)
        {
            int first=get_first(r);
            int last=get_last(r);
            for(int c=1;c<=m;c++)
            {
                if(valid[r][c-1])
                {
                    valid[r][c]=1;
                    dp[r][c]=min(dp[r][c],dp[r][c-1]+1);
                }
                if(c<=first && valid[r-1][c])
                {
                    valid[r][c]=1;
                    dp[r][c]=min(dp[r][c],dp[r-1][c]+1);
                }
            }
            for(int c=1;c<last;c++)
                valid[r][c]=0;
        }
    }
    int ans=(1<<30);
    for(int c=1;c<=m;c++)
        if(valid[n][c])
            ans=min(ans,dp[n][c]);
    for(int r=1;r<=n;r++)
    {
     //   for(int )
    }
    cout<<ans<<"\n";
    return 0;
}