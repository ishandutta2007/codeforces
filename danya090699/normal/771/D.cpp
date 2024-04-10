#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, vq=0, kq=0, inf=1e9;
    cin>>n;
    char ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        if(ar[a]=='V') vq++;
        if(ar[a]=='K') kq++;
    }
    int dp[n+1][vq+1][kq+1][2];
    for(int a=0; a<=n; a++)
    {
        for(int b=0; b<=vq; b++)
        {
            for(int c=0; c<=kq; c++)
            {
                dp[a][b][c][0]=inf, dp[a][b][c][1]=inf;
            }
        }
    }
    dp[0][0][0][0]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<=vq; b++)
        {
            for(int c=0; c<=kq; c++)
            {
                for(int d=0; d<2; d++)
                {
                    if(dp[a][b][c][d]!=inf)
                    {
                        int xq=a-b-c, v=0, k=0, x=0, le=0, add1=-1, add2=-1, add3=-1;
                        bool us[n];
                        for(int i=0; i<n; i++)
                        {
                            if(ar[i]=='V')
                            {
                                if(v==b) add1=le;
                                if(v>=b) le++;
                                v++;
                            }
                            else if(ar[i]=='K')
                            {
                                if(k==c) add2=le;
                                if(k>=c) le++;
                                k++;
                            }
                            else
                            {
                                if(x==xq) add3=le;
                                if(x>=xq) le++;
                                x++;
                            }
                        }
                        if(add1!=-1) dp[a+1][b+1][c][1]=min(dp[a+1][b+1][c][1], dp[a][b][c][d]+add1);
                        if(add2!=-1 and d!=1) dp[a+1][b][c+1][0]=min(dp[a+1][b][c+1][0], dp[a][b][c][d]+add2);
                        if(add3!=-1) dp[a+1][b][c][0]=min(dp[a+1][b][c][0], dp[a][b][c][d]+add3);
                    }
                }
            }
        }
    }
    cout<<min(dp[n][vq][kq][0], dp[n][vq][kq][1]);
}