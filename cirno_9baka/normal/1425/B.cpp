#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,N=10005;
int n,m,r,k,i,j,head[N],Next[N*2],adj[N*2],s,a[N],vis[N],u,v;
long long ans,dp[4005][2],dp2[4005][2],ddp[4005];
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int fa)
{
	if(vis[i])
		return;
	int j;
	vis[i]=1;
	++s;
	//cout<<endl;
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa)
			dfs(adj[j],i);
}
void dfs2(int l,int r)
{
	if(l==r)
	{
		int i;
		for(i=2000-a[l]+2;i<=2000+a[l]-2;++i)
			ans=(ans+ddp[i]*2)%M;
		/*cout<<ans<<' '<<a[l]<<endl;
		for(i=2000-5;i<=2000+5;++i)
			cout<<dp[i]<<' ';
		cout<<endl;*/
		return;
	}
	int mid=l+r>>1;
	int i,j;
	long long dp2[4005],tmp[4005];
	memcpy(tmp,ddp,sizeof(tmp));
	for(i=l;i<=mid;++i)
	{
		for(j=0;j<=4000;++j)
			dp2[j]=ddp[j];
		for(j=0;j<=4000-a[i];++j)
			dp2[j]=dp2[j]+ddp[j+a[i]];
		for(j=a[i];j<=4000;++j)
			dp2[j]=dp2[j]+ddp[j-a[i]];
		for(j=0;j<=4000;++j)
			ddp[j]=dp2[j]%M;
	}
	dfs2(mid+1,r);
	memcpy(ddp,tmp,sizeof(ddp));
	for(i=mid+1;i<=r;++i)
	{
		for(j=0;j<=4000;++j)
			dp2[j]=ddp[j];
		for(j=0;j<=4000-a[i];++j)
			dp2[j]=dp2[j]+ddp[j+a[i]];
		for(j=a[i];j<=4000;++j)
			dp2[j]=dp2[j]+ddp[j-a[i]];
		for(j=0;j<=4000;++j)
			ddp[j]=dp2[j]%M;
	}
	dfs2(l,mid);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	vis[1]=1;
	k=0;
	for(j=head[1];j;j=Next[j])
		if(!vis[adj[j]])
		{
			s=0;
			dfs(adj[j],1);
			a[++k]=s+1;
		}
	/*for(i=1;i<=k;++i)
		cout<<a[i]<<' ';
	cout<<endl;*/
	ddp[2000]=1;
	dfs2(1,k);
	memset(dp,0,sizeof(dp));
	dp[2000][0]=1;
	for(i=1;i<=k;++i)
	{
		for(j=0;j<=4000;++j)
			dp2[j][0]=dp2[j][1]=0;
		for(j=0;j<=4000-a[i];++j)
		{
			dp2[j][0]=dp2[j][0]+dp[j+a[i]][0];
			dp2[j][1]=dp2[j][1]+dp[j+a[i]-1][0];
			dp2[j][1]=dp2[j][1]+dp[j+a[i]][1];
		}
		for(j=a[i];j<=4000;++j)
		{
			dp2[j][0]=dp2[j][0]+dp[j-a[i]][0];
			dp2[j][1]=dp2[j][1]+dp[j-a[i]+1][0];
			dp2[j][1]=dp2[j][1]+dp[j-a[i]][1];
		}
		for(j=0;j<=4000;++j)
		{
			dp[j][0]=dp2[j][0]%M;
			dp[j][1]=dp2[j][1]%M;
		}
		/*for(j=2000-10;j<=2000+10;++j)
			cout<<dp2[j][1]<<' ';
		cout<<endl;*/
	}
	//cout<<dp[2000]<<endl;
	ans+=dp[2000][0]+dp[2000][1]*2;
	cout<<(ans%M+M)%M;
}