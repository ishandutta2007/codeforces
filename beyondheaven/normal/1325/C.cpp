#include<cstdio>
#include<vector>
#include<algorithm>
#define MaxN 100123
int n;
std::vector<int>G[MaxN];
int ans[MaxN],cnt;
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(i);
		G[v].push_back(i);
	}
	if(std::all_of(G+1,G+n+1,[](std::vector<int>&v){return v.size()<=2;}))
	for(int i=0;i<n-1;++i)printf("%d\n",i);
	else
	{
		std::fill(ans+1,ans+n+1,-1);
		int rt=static_cast<int>(std::find_if(G+1,G+n+1,[](std::vector<int>&v){return v.size()>2;})-G);
		for(auto e:G[rt])ans[e]=cnt++;
		for(int i=1;i<n;++i)printf("%d\n",(ans[i]==-1?cnt++:ans[i]));
	}
	return 0;
}