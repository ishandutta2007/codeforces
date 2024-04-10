#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,sz[200005],dep[200005],cnt[2],ans,x[200005],y[200005];
vector<long long> bi[200005];
void dfs(long long x,long long fa)
{
	sz[x]=1;
	cnt[dep[x]&1]++;
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]==fa) continue;
		dep[bi[x][i]]=dep[x]+1;
		dfs(bi[x][i],x);
		sz[x]+=sz[bi[x][i]];
	}
}
int main()
{
	scanf("%I64d",&n);
	for (i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&x[i],&y[i]);
		bi[x[i]].push_back(y[i]);
		bi[y[i]].push_back(x[i]); 
	}
	dfs(1,0);
	for (i=1;i<n;i++)
	{
		ans+=min(sz[x[i]],sz[y[i]])*(n-min(sz[x[i]],sz[y[i]]));
	}
	if ((ans+(cnt[0]*cnt[1]))&1) return -1;
	printf("%I64d\n",(ans+(cnt[0]*cnt[1]))/2);
	return 0;
}