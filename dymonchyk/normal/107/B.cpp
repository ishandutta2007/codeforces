#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

#define ll long long

using namespace std;

double dp[1001][101]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,h,cnt[1002],sum=0;
    cin >> n >> m >> h;
    for(int i=0;i<m;i++)
    {
        cin >> cnt[i];
        sum+=cnt[i];
    }
    if (n>sum)
    {
        printf("-1.0\n");
        return 0;
    }
    sum-=cnt[--h];
    cnt[h]--; n--;
    dp[0][0]=1.0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=cnt[h];j++)
        {
            if (dp[i][j]>1e-20)
            {
                double prob=1.0*(cnt[h]-j)/(sum+cnt[h]-i);
                dp[i+1][j+1]+=dp[i][j]*prob;
                dp[i+1][j]+=dp[i][j]*(1-prob);
            }
        }
    double res=0;
    for(int i=1;i<=cnt[h];i++)
        res+=dp[n][i];
    printf("%.7lf\n",res);
    return 0;
}