#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int i,j,k,n,m,a[maxn];
double dp[maxn][maxn],f[maxn][2],ans;
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i]>a[j])dp[i][j]=1;
	for(i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		for(j=1;j<=n;j++)dp[x][j]=dp[y][j]=(dp[x][j]+dp[y][j])/2,dp[j][x]=dp[j][y]=(dp[j][x]+dp[j][y])/2;
		dp[x][y]=dp[y][x]=0.5;
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)ans+=dp[i][j];
	printf("%.8f",ans);
	return 0;
}