#include<bits/stdc++.h>
using namespace std;
#define N 2000
#define pb push_back
int n,m,a[N+1],b[N+1],nums[2*N+1],hav[2*N+1][2*N+1],dp[2*N+1][2*N+1];
vector<int>llis[2*N+1];
int path[2*N+1][2*N+1];
void dfs(int x=m,int y=1){
//	cout<<y<<" "<<y+x-1<<"\n";
	if(x==1)return;
	if(hav[y][y+x-1])printf("%d ",hav[y][y+x-1]);
	~path[x][y]?dfs(path[x][y]-y+1,y),dfs(y+x-path[x][y],path[x][y]):dfs(x-1,y+1);
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",a+i,b+i),a[i]=a[i]-b[i],b[i]=a[i]+2*b[i],
		nums[i]=a[i],nums[i+n]=b[i];
//	cout<<2*n<<":\n";for(i=1;i<=n;i++)cout<<a[i]<<" "<<b[i]<<"\n";
	sort(nums+1,nums+2*n+1);m=unique(nums+1,nums+2*n+1)-1-nums;
	for(i=1;i<=n;i++)
		a[i]=lower_bound(nums+1,nums+m+1,a[i])-nums,
		b[i]=lower_bound(nums+1,nums+m+1,b[i])-nums,
		hav[a[i]][b[i]]=i,llis[a[i]].pb(b[i]);
//	cout<<m<<":\n";for(i=1;i<=n;i++)cout<<a[i]<<" "<<b[i]<<"\n";
	for(i=1;i<=m;i++)sort(llis[i].begin(),llis[i].end());
	for(i=2;i<=m;i++)for(j=1;j+i-1<=m;j++){
		dp[i][j]=dp[i-1][j+1];path[i][j]=-1;
		for(int k=0,mid;k<llis[j].size()&&(mid=llis[j][k])<j+i-1;k++)
			if(dp[mid-j+1][j]+dp[j+i-mid][mid]>dp[i][j])
				dp[i][j]=dp[mid-j+1][j]+dp[j+i-mid][mid],path[i][j]=mid;
		if(hav[j][j+i-1])dp[i][j]++;
	}
//	for(i=1;i<=m;i++){for(j=1;j+i-1<=m;j++)printf("dp[%d][%d]=%d\t",i,j,dp[i][j]);puts("");}
	printf("%d\n",dp[m][1]);
	dfs();
	return 0;
}
/*1
4
1 1
2 2
4 1
5 1
*/