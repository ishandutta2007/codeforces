#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector s(n+1,vector(n+1,ll(0)));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> s[i][j];
            s[i][j]+=s[i][j-1];
        }
    }
    auto sum=[&](int i,int l,int r)->ll{return (s[i][r]-s[i][l-1]);};
    vector cost(n+1,vector(n+1,ll(0)));
    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            for(int i=l;i<=r;i++) 
            {
                cost[l][r]+=sum(i,1,l-1);
                cost[l][r]+=sum(i,r+1,n);
            }
        }
    }
    vector dp(n+2,vector(n+2,array<ll,2>{0,0}));
    for(int sz=1;sz<=n;sz++)
    {
        for(int l=1;l+sz-1<=n;l++)
        {
            int r=l+sz-1;
            dp[l][r][0]=(1ll<<60);
            for(int i=l;i<=r;i++) dp[l][r]=min(dp[l][r],{dp[l][i-1][0]+dp[i+1][r][0]+cost[l][r],i});
        }
    }
    vector<int> p(n+1,0);
    function<void(int,int,int)> go=[&](int l,int r,int u)
    {
        if(l>r) return;
        for(int i=l;i<=r;i++)
        {
            if(dp[l][i-1][0]+dp[i+1][r][0]+cost[l][r]==dp[l][r][0])
            {
                p[i]=u;
                go(l,i-1,i);
                go(i+1,r,i);
                break;
            }
        }
    };
    go(1,n,0);
    for(int i=1;i<=n;i++) cout << p[i] << " \n"[i==n];
    return 0;
}