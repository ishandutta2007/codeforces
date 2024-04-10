#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=1005,E=262144;
int n,m,i,j,k,l,t[N],num,f[105][105][305],vis[105][105];
int dp[105][305],ans;
struct str{
	int x,y;
}a[N];
bool cmp(str a,str b)
{
	return a.x<b.x;
}
void dfs(int l,int r)
{
	if(vis[l][r])
		return;
	vis[l][r]=1;
	int i,j,k;
	if(l==r)
	{
		int x=lower_bound(t+1,t+1+num,a[l].x-a[l].y)-t;
		int y=lower_bound(t+1,t+1+num,a[l].x)-t;
		int z=lower_bound(t+1,t+1+num,a[l].x+a[l].y)-t;
		for(i=x;i<y;++i)
			f[l][r][i]=y;
		for(i=y;i<=num;++i)
			f[l][r][i]=z;
		return;
	}
	for(i=l;i<r;++i)
	{
		dfs(l,i);
		dfs(i+1,r);
		for(j=1;j<=num;++j)
		{
			f[l][r][j]=max(f[l][r][j],f[i+1][r][f[l][i][j]]);
			f[l][r][j]=max(f[l][r][j],f[l][i][f[i+1][r][j]]);
			f[l][r][j]=max(f[l][r][j],f[i+1][r][j]);
			f[l][r][j]=max(f[l][r][j],f[l][i][j]);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		t[++k]=a[i].x;
		t[++k]=a[i].x-a[i].y;
		t[++k]=a[i].x+a[i].y;
	}
	sort(a+1,a+1+n,cmp);
	sort(t+1,t+1+k);
	t[0]=-1000000001;
	for(i=1;i<=k;++i)
		if(t[i]!=t[num])
			t[++num]=t[i];
	dfs(1,n);
	for(i=1;i<=n;++i)
	{
		for(k=i;k>=1;--k)
			for(j=1;j<=num;++j)
				dp[i][f[k][i][j]]=max(dp[i][f[k][i][j]],dp[k-1][j]+t[f[k][i][j]]-t[j]);
		for(j=1;j<=num;++j)
		{
			dp[i][j]=max(dp[i][j],dp[i][j-1]);
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans;	
}