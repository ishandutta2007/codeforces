#include<bits/stdc++.h>
using namespace std;

int ans[100010];
//dpijij 
int main()
{
	int n,m;
	int x;
	cin>>n>>m;
	int a[n+5][m+5];
	int dp[n+5][m+5];
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			a[i][j]=x;
		}
	}
	for(int i=1;i<=m;i++)dp[1][i] = 1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]>=a[i-1][j]) dp[i][j]=dp[i-1][j]+1;
			else dp[i][j]=1;
		}
	}
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans[i]=max(ans[i],dp[i][j]);
		}
	}
	int q;
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		if(y-x+1 <= ans[y])puts("Yes");
		else puts("No");
	}
	return 0;
}