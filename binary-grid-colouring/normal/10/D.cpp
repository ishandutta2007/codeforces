#include<bits/stdc++.h>
using namespace std;
int dp[567],a[567],b[567],step[567];
int n,m;
void print(int x)
{
	if(x==0)return;
	print(step[x]);
	printf("%d ",b[x]);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int j=1;j<=m;j++){
		cin>>b[j];
	}
	for(int i=1;i<=n;i++)
	{
		int pos=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j])
			{
				dp[j]=dp[pos]+1;
				step[j]=pos;
			}
			else if(a[i]>b[j] && dp[j] > dp[pos])
			{
				pos=j;
			}
		}
	}
	int x=0;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(dp[i]>ans)
		{
			ans=dp[i];
			x=i;
		}
	}
	cout<<ans<<endl;
	print(x);
	return 0;
}