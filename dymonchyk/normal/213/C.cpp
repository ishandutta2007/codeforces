#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define ll long long

using namespace std;

int D[302][302]={0};
int dp[2][302][302]={0};
int dp2[2][302][302]={0};

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&D[i][j]);
        if (n==1) {
            printf("%d\n",D[0][0]);
            continue;
        }
//        memset(dp,0,sizeof(dp));
        for(int i=0;i<2;++i)
            for(int j=0;j<=n;++j)
                for(int t=0;t<=n;++t)
                    dp[i][j][t]=-2000000000;
        dp[0][0][0]=D[0][0];
        int cur=0,next=1;
        for(int t=1;t<n;t++)
        {
            for(int i=0;i<t;++i)
            {
                for(int j=i;j<t;++j)
                {
                    for(int dx=0;dx<2;++dx)
                        for(int dy=0;dy<2;++dy)
                            dp[next][i+dx][j+dy]=max(dp[next][i+dx][j+dy],dp[cur][i][j]+D[i+dx][t-i-dx]+(i+dx==j+dy&&t-i-dx==t-j-dy ? 0 : D[j+dy][t-j-dy]));
                }
            }
            cur^=1; next^=1;
            for(int j=0;j<=n;++j)
                for(int i=0;i<=n;++i)
                    dp[next][j][i]=-2000000000;
        }
        for(int i=0;i<n;i++)
            for(int j=0;i+j<n;j++)
                swap(D[i][j],D[n-1-j][n-1-i]);
        for(int i=0;i<2;++i)
            for(int j=0;j<=n;++j)
                for(int t=0;t<=n;++t)
                    dp2[i][j][t]=-2000000000;
        dp2[0][0][0]=D[0][0];
        cur=0,next=1;
        for(int t=1;t<n;t++)
        {
            for(int i=0;i<t;++i)
            {
                for(int j=i;j<t;++j)
                {
                    for(int dx=0;dx<2;++dx)
                        for(int dy=0;dy<2;++dy)
                            dp2[next][i+dx][j+dy]=max(dp2[next][i+dx][j+dy],dp2[cur][i][j]+D[i+dx][t-i-dx]+(i+dx==j+dy&&t-i-dx==t-j-dy ? 0 : D[j+dy][t-j-dy]));
                }
            }
            cur^=1; next^=1;
            for(int j=0;j<=n;++j)
                for(int i=0;i<=n;++i)
                    dp2[next][j][i]=-2000000000;
        }
        int best=-2000000000;
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                best=max(best,dp[cur][i][j]+dp2[cur][i][j]-D[i][n-1-i]-(i==j ? 0 : D[j][n-1-j]));
        printf("%d\n",best);
    }
    return 0;
 }