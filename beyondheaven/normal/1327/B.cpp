#include<bits/stdc++.h>
#define MaxN 100123
int T,n,cnt;
std::vector<int>G[MaxN];
bool match1[MaxN],match2[MaxN];
inline void Solve()
{
	scanf("%d",&n);cnt=0;
	for(int i=1,k;i<=n;++i)
	{
		G[i].clear();match1[i]=match2[i]=false;
		scanf("%d",&k);
		for(int j=1,x;j<=k;++j)
		{
			scanf("%d",&x);
			G[i].push_back(x);
		}
	}
	for(int i=1;i<=n;++i)
	for(auto v:G[i])
	if(!match2[v])
	{
		match1[i]=match2[v]=true;
		++cnt;
		break;
	}
	if(cnt==n)puts("OPTIMAL");
	else
	{
		puts("IMPROVE");
		for(int i=1;i<=n;++i)
		if(!match1[i])
		for(int j=1;j<=n;++j)
		if(!match2[j])
		{
			printf("%d %d\n",i,j);
			return;
		}
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)Solve();
	return 0;
}