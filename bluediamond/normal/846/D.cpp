#include <bits/stdc++.h>

using namespace std;

const int N=500+5;

int n,m,k,q;
int r[N*N],c[N*N],t[N*N];

inline bool ok(int when)
{
    int is[N][N];
    int dp[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            is[i][j]=0;
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=q;i++)
    {
        if(t[i]<=when)
        {
            is[r[i]][c[i]]=1;
        }
    }
    int mx=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            if(is[i][j])
            {
                dp[i][j]=1+min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
            }
            else
            {
                dp[i][j]=0;
            }
            mx=max(mx,dp[i][j]);
        }
    }
    if(mx>=k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>r[i]>>c[i]>>t[i];
    }
    int r=-1,pas=(1<<30);
    bool g=0;
    while(pas)
    {
        if(ok(r+pas)==0)
        {
            r+=pas;
        }
        else
        {
            g=1;
        }
        pas/=2;
    }
    if(g)
    {
        r++;
        cout<<r<<"\n";
    }
    else
    {
        cout<<"-1\n";
    }
    return 0;
}