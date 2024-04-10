#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

const int N=3e5+7,inf=1e9+7;
int a[N],dp[2][50],now,n;

void gmin(int &a,int b){if(a>b)a=b;}

int main()
{
    scanf("%d",&n);
    F(i,1,n)scanf("%d",a+i),a[i]/=100;
    now=0;F(i,1,40)dp[now][i]=inf;
    F(i,1,n)
    {
        now^=1;F(j,0,40)dp[now][j]=inf;
        F(j,0,40)
        {
            gmin(dp[now][j+a[i]/10],dp[now^1][j]+a[i]);//
            gmin(dp[now][j-a[i]+max(a[i]-j,0)],dp[now^1][j]+max(a[i]-j,0));//
        }
    }
    int ans=inf;
    F(i,0,40)gmin(ans,dp[now][i]);
    printf("%d00\n",ans);
    return 0;
}