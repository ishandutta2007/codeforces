//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int n2, m2, n, m, mod=1e9+7;
void pl(int &a, int x)
{
    a+=x;
    if(a>=mod) a-=mod;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n2>>m2;
    n=n2, m=m2;
    char fi2[n2][m2];
    for(int a=0; a<n2; a++) for(int b=0; b<m2; b++) cin>>fi2[a][b];
    if(n2>m2) swap(n, m);
    char fi[n][m];
    if(n2>m2)
    {
        for(int a=0; a<n; a++) for(int b=0; b<m; b++) fi[a][b]=fi2[b][a];
    }
    else
    {
        for(int a=0; a<n; a++) for(int b=0; b<m; b++) fi[a][b]=fi2[a][b];
    }
    int sz=(1<<n);
    int dp[sz][2][2], dp2[sz][2][2];
    for(int a=0; a<sz; a++)
    {
        for(int b=0; b<2; b++)
        {
            for(int c=0; c<2; c++)
            {
                dp[a][b][c]=0, dp2[a][b][c]=0;
            }
        }
    }
    dp[0][0][0]=1;
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<n; b++)
        {
            int cu=(1<<b);
            for(int c=0; c<sz; c++)
            {
                int x=(c&(sz-1-cu)), x2=(c|cu);
                for(int d=0; d<2; d++)
                {
                    for(int e=0; e<2; e++)
                    {
                        int va=dp[c][d][e];
                        if(fi[b][a]=='x')
                        {
                            pl(dp2[x][0][e], va);
                        }
                        else
                        {
                            int nc=c, nd=d, ne=e;
                            if(d==0 and (c&cu)==0) ne++;
                            if(b==n-1) nd=0;
                            if(ne<2) pl(dp2[nc][nd][ne], va);
                            nc=x2, nd=1, ne=e;
                            if(b==n-1) nd=0;
                            pl(dp2[nc][nd][ne], va);
                        }
                    }
                }
            }
            for(int c=0; c<sz; c++)
            {
                for(int d=0; d<2; d++)
                {
                    for(int e=0; e<2; e++)
                    {
                        dp[c][d][e]=dp2[c][d][e], dp2[c][d][e]=0;
                    }
                }
            }
        }
    }
    int an=0;
    for(int a=0; a<sz; a++)
    {
        an=(an+dp[a][0][0])%mod;
        an=(an+dp[a][0][1])%mod;
    }
    cout<<an;
}