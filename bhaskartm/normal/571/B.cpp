#include<bits/stdc++.h>
using namespace std;
int n,k,a[300005],dp[5005][5005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int sum=a[n]-a[1],x=n%k,y=k-x,t=n/k;
	for(int i=1;i<n;i++)a[i]=a[i+1]-a[i];
	for(int i=0;i<=x;i++)for(int j=0;j<=y;j++)
	{
		if(i)dp[i][j]=max(dp[i][j],dp[i-1][j]+a[(i-1)*(t+1)+j*t]);
		if(j)dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i*(t+1)+(j-1)*t]);
	}
	printf("%d\n",sum-dp[x][y]);
	return 0;
}