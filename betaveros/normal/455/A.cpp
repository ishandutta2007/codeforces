#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    long long dp[100005], n, i, c, count[100005];
    while(scanf("%I64d",&n)!=EOF)
    {
        memset(count,0,sizeof(count));
        for(i=0; i<n; i++)
            scanf("%I64d",&c), count[c]++;
        dp[0]=0;
        dp[1]=1*count[1];
        dp[2]=2*count[2];
        for(i=3; i<=100000; i++)
        {
            dp[i]=max(dp[i-2],dp[i-3])+i*count[i];
        }
        printf("%I64d\n",max(dp[99999],dp[100000]));
    }
    return 0;
}