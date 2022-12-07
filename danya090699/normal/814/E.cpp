#include <bits/stdc++.h>
using namespace std;
const int osn=1e9+7, sz=51;
int dp[sz][sz][sz][sz], dp2[sz][sz][sz][sz];
void pl(int &a, int b)
{
    a+=b;
    if(a>=osn) a-=osn;
}
int um(int a, int b){return (1ll*a*b)%osn;}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q, x1=1, x2=0, x3=1, x4=0;
    cin>>n;
    for(int a=0; a<=n; a++)
    {
        for(int b=0; b<=n; b++)
        {
            for(int c=0; c<=n; c++)
            {
                for(int d=0; d<=n; d++)
                {
                    dp[a][b][c][d]=0;
                    dp2[a][b][c][d]=0;
                }
            }
        }
    }
    cin>>q;
    if(q==3) swap(x1, x2);
    cin>>q;
    if(q==3) swap(x3, x4);
    dp[x1][x2][x3][x4]=1;
    for(int i=2; i<n; i++)
    {
        cin>>q;
        for(int a=0; a<=n; a++)
        {
            for(int b=0; b<=n; b++)
            {
                for(int c=0; c<=n; c++)
                {
                    for(int d=0; d<=n; d++)
                    {
                        if(dp[a][b][c][d]!=0)
                        {
                            if(a==0 and b==0 and (c>0 or d>0)) pl(dp[c][d][0][0], dp[a][b][c][d]);
                            for(int t=0; t<2; t++)
                            {
                                int cu=um(dp[a][b][c][d], b), na=a+1, nb=b-1;
                                if(t==0)
                                {
                                    cu=um(dp[a][b][c][d], a), na=a-1, nb=b;
                                }
                                if(na>=0 and nb>=0)
                                {
                                    if(q==2)
                                    {
                                        pl(dp2[na][nb][c+1][d], cu);
                                        if(c>0) pl(dp2[na][nb][c-1][d], um(cu, c));
                                        if(d>0) pl(dp2[na][nb][c+1][d-1], um(cu, d));
                                    }
                                    else
                                    {
                                        pl(dp2[na][nb][c][d+1], cu);
                                        if(c>0) pl(dp2[na][nb][c][d], um(cu, c));
                                        if(c>1) pl(dp2[na][nb][c-2][d], um(cu, c*(c-1)/2));
                                        if(d>0) pl(dp2[na][nb][c+2][d-1], um(cu, d));
                                        if(d>1) pl(dp2[na][nb][c+2][d-2], um(cu, d*(d-1)/2));
                                        if(c>0 and d>0) pl(dp2[na][nb][c][d-1], um(cu, c*d));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int a=0; a<=n; a++)
        {
            for(int b=0; b<=n; b++)
            {
                for(int c=0; c<=n; c++)
                {
                    for(int d=0; d<=n; d++)
                    {
                        dp[a][b][c][d]=dp2[a][b][c][d];
                        dp2[a][b][c][d]=0;
                    }
                }
            }
        }
    }
    cout<<dp[0][0][0][0];
}