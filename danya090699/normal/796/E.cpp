#include <bits/stdc++.h>
using namespace std;
int de(int a, int b)
{
    int res=a/b;
    if(a%b!=0) res++;
    return res;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, p, k, q, x, inf=-1e9;
    cin>>n>>p>>k;
    bool g1[n], g2[n];
    for(int a=0; a<n; a++)
    {
        g1[a]=0, g2[a]=0;
    }
    cin>>q;
    for(int a=0; a<q; a++)
    {
        cin>>x;
        x--;
        g1[x]=1;
    }
    cin>>q;
    for(int a=0; a<q; a++)
    {
        cin>>x;
        x--;
        g2[x]=1;
    }
    p=min(p, de(n, k)*2);
    int dp[p+1][k][k], dp2[p+1][k][k];
    for(int a=0; a<=p; a++)
    {
        for(int b=0; b<k; b++)
        {
            for(int c=0; c<k; c++)
            {
                dp[a][b][c]=inf, dp2[a][b][c]=inf;
            }
        }
    }
    dp[0][0][0]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<=p; b++)
        {
            for(int c=0; c<k; c++)
            {
                for(int d=0; d<k; d++)
                {
                    if(dp[b][c][d]!=inf)
                    {
                        int va1=g1[a], va2=g2[a], nc=c-1, nd=d-1;
                        if(nc==-1)
                        {
                            nc=0, va1=0;
                        }
                        if(nd==-1)
                        {
                            nd=0, va2=0;
                        }
                        dp2[b][nc][nd]=max(dp2[b][nc][nd], dp[b][c][d]+(va1|va2));
                        if(b!=p)
                        {
                            if(c==0) dp2[b+1][k-1][nd]=max(dp2[b+1][k-1][nd], dp[b][c][d]+(g1[a]|va2));
                            if(d==0) dp2[b+1][nc][k-1]=max(dp2[b+1][nc][k-1], dp[b][c][d]+(va1|g2[a]));
                        }
                    }
                }
            }
        }
        for(int b=0; b<=p; b++)
        {
            for(int c=0; c<k; c++)
            {
                for(int d=0; d<k; d++)
                {
                    dp[b][c][d]=dp2[b][c][d];
                    dp2[b][c][d]=inf;
                }
            }
        }
    }
    int an=inf;
    for(int a=0; a<=p; a++)
    {
        for(int b=0; b<k; b++)
        {
            for(int c=0; c<k; c++)
            {
                an=max(an, dp[a][b][c]);
            }
        }
    }
    cout<<an;
}