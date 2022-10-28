#include<iostream>
using namespace std;

int a[10001];
int pos[1000001];
int dp[4001][4001];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
        pos[a[i]]=-1;
    }
    int ans=1;
    for(int i=n;i>=1;--i)
    {
        dp[i][i]=1;
        for(int j=n;j>i;--j)
        {
            dp[i][j]=1+(pos[a[i]]==-1?1:dp[j][pos[a[i]]]);
            pos[a[j]]=j;
            ans=max(ans,dp[i][j]);
        }
        for(int j=1;j<=n;++j)
            pos[a[j]]=-1;
    }
    printf("%d\n",ans);
}