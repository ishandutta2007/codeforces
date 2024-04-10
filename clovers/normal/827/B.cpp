#include<bits/stdc++.h>
using namespace std;
const int N=200001;

int n,k,dp[N],dep[N],mxdep[N];
vector<int> v[N];

void dfs(int u,int f)
{
	mxdep[u]=dep[u];
	int max1=0,max2=0;
	for(int i=0;i<(int)v[u].size();i++)
	{
		int to=v[u][i];
		if(to==f) continue;
		dep[to]=dep[u]+1;
		dfs(to,u);
		mxdep[u]=max(mxdep[u],mxdep[to]);
		int dis=mxdep[to]-dep[u];
		if(max1<dis) max2=max1,max1=dis;
		else if(max2<dis) max2=dis;
	}
	dp[u]=max(max1,max1+max2);
	//cout<<u<<" "<<max1<<" "<<max2<<endl;
}

int main()
{
	scanf("%d%d",&n,&k);
	int cnt=1,now=1;
	while(cnt<n)
	{
		if(now==1) for(int i=cnt+1;i<=min(cnt+k,n);i++) v[now].push_back(i);
		else v[now].push_back(cnt+1);
		if(now==1) cnt+=k;
		else cnt++;
		now++;
	}
	dfs(1,-1);
	int ans=0;
	for(int i=1;i<=n;i++) 
	{
		//for(int j=0;j<(int)v[i].size();j++) cout<<v[i][j]<<" "; cout<<endl;
		//cout<<i<<" "<<dp[i]<<endl;
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(int)v[i].size();j++) 
			printf("%d %d\n",i,v[i][j]);
	}
}