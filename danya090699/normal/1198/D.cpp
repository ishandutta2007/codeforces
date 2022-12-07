#include <bits/stdc++.h>
using namespace std;
const int sz=51;
int dp[sz][sz][sz][sz], su[sz][sz];
int f(int lx, int rx, int ly, int ry)
{
    if(dp[lx][rx][ly][ry]==-1)
    {
        int q=su[rx+1][ry+1]-su[rx+1][ly]-su[lx][ry+1]+su[lx][ly];

        if(q)
        {
            dp[lx][rx][ly][ry]=max((rx-lx+1), (ry-ly+1));

            if((rx-lx+1)>(ry-ly+1))
            {
                for(int a=lx; a+1<=rx; a++)
                {
                    dp[lx][rx][ly][ry]=min(dp[lx][rx][ly][ry], f(lx, a, ly, ry)+f(a+1, rx, ly, ry));
                }
            }
            else
            {
                for(int a=ly; a+1<=ry; a++)
                {
                    dp[lx][rx][ly][ry]=min(dp[lx][rx][ly][ry], f(lx, rx, ly, a)+f(lx, rx, a+1, ry));
                }
            }
        }
        else dp[lx][rx][ly][ry]=0;
    }
    return dp[lx][rx][ly][ry];
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            char sy;
            cin>>sy;
            if(sy=='#') su[a+1][b+1]=1;
            su[a+1][b+1]+=su[a+1][b]+su[a][b+1]-su[a][b];
        }
    }
    for(int lx=0; lx<n; lx++)
    {
        for(int rx=lx; rx<n; rx++)
        {
            for(int ly=0; ly<n; ly++)
            {
                for(int ry=ly; ry<n; ry++) dp[lx][rx][ly][ry]=-1;
            }
        }
    }
    cout<<f(0, n-1, 0, n-1);
}