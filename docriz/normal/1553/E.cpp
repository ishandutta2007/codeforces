#include<bits/stdc++.h>
using namespace std;
int T,n,m,cnt[300005],pos[300005],vis[300005];
int a[300005];
vector<int>ans;
void opt(int x)
{
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]+x<=n)pos[i]=a[i]+x;
		else pos[i]=a[i]+x-n;
	}
	int rg=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		rg++;
		int p=i;
		while(!vis[p])vis[p]=1,p=pos[p];
	}
	if(n-rg<=m)ans.push_back(x);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		ans.clear();
		for(int i=0;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)cnt[(n+i-a[i])%n]++;
		for(int i=0;i<n;i++)if(cnt[i]>=n/3)opt(i);
		sort(ans.begin(),ans.end());
		printf("%d",ans.size());
		for(int i=0;i<ans.size();i++)printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}