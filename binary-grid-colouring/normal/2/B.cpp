#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int dp[1100][1100][2];
void dfs(int i,int j)
{
	if(i == 1 && j == 1) return ;
	if(i > 1 && j > 1 )
	{
		if(dp[i-1][j][k] < dp[i][j-1][k]){
			dfs(i-1,j);
			cout<<"D";
		}
		else {
			dfs(i,j-1);
			cout<<"R";
		}
	}
	else if(i > 1)
	{
		dfs(i-1,j);
		cout<<"D";
	}
	else if(j > 1)
	{
		dfs(i,j-1);
		cout<<"R";
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	int a;
	int x;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a);
			if(a==0){
				x=i;
			}
			while(a > 0 && a % 2==0){
				dp[i][j][0]++;
				a /= 2;
			}
			while(a > 0 && a % 5==0){
				dp[i][j][1]++;
				a /= 5;
			}
			for(int k=0;k<2;k++)
			{
				if(i > 1 && j > 1){
					dp[i][j][k] += min(dp[i-1][j][k],dp[i][j-1][k]);
				}
				else if(i > 1){
					dp[i][j][k] += dp[i-1][j][k];
				}
				else if(j > 1)
				{
					dp[i][j][k] += dp[i][j-1][k];
				}
			}
		}
	}
	k = dp[n][n][0] > dp[n][n][1];
	if(x && dp[n][n][k] > 1)
	{
		cout<<1<<endl;
		for(int i=1;i<x;i++) cout<<"D";
		for(int i=1;i<n;i++) cout<<"R";
		for(int i=x;i<n;i++) cout<<"D";
	}
	else 
	{
		cout<<dp[n][n][k]<<endl;
		dfs(n,n);
	}
	cout<<endl;
	return 0;
}