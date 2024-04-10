#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+5;

int n;
int a[N];
int b[N];
int lft[N];
int dp[N][2*N*N];
int mi_cost[N][2*N*N];

inline void upd(int i,int j,int x,int y)
{
    if(dp[i][j]>x)
    {
        dp[i][j]=x;
        mi_cost[i][j]=y;
    }
    if(dp[i][j]==x)
    {
        mi_cost[i][j]=min(mi_cost[i][j],y);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<2*N*N;j++)
        {
            dp[i][j]=(1<<30);
            mi_cost[i][j]=(1<<30);
        }
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        lft[i]=b[i]-a[i];
    }
    upd(1,10000+lft[1],1,0);
    upd(1,10000-a[1],0,a[1]);
    for(int i=2;i<=n;i++)
    {
        for(int cnt=0;cnt<2*N*N;cnt++)
        {
            upd(i,cnt+lft[i],dp[i-1][cnt]+1,mi_cost[i-1][cnt]);
            upd(i,cnt-a[i],dp[i-1][cnt],mi_cost[i-1][cnt]+a[i]);
        }
    }
    int mi=(1<<30);
    for(int cnt=0;cnt<=10000;cnt++)
    {
        mi=min(mi,dp[n][10000+cnt]);
    }
    cout<<mi<<" ";
    int co=(1<<30);
    for(int cnt=0;cnt<=10000;cnt++)
    {
        if(dp[n][10000+cnt]==mi)
        {
            co=min(co,mi_cost[n][10000+cnt]);
        }
    }
    cout<<co<<"\n";
    return 0;
}