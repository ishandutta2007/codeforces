#include<iostream>

using namespace std;

const int N=51;

int dp[N][2][2];
int a[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);

    int sum=0;
    for(int i=n;i>=1;--i)
    {
        sum+=a[i];
        dp[i][0][0]=max(dp[i+1][1][0]+a[i],dp[i+1][0][0]);
        dp[i][0][1]=sum-dp[i][0][0];
        dp[i][1][1]=max(dp[i+1][0][1]+a[i],dp[i+1][1][1]);
        dp[i][1][0]=sum-dp[i][1][1];
    }

    printf("%d %d\n",dp[1][0][1],dp[1][0][0]);
}