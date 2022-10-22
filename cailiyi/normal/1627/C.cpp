#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,d[N+5],val[N+5],x,last=2;
vector<pair<int,int> > e[N+5];
void dfs(int x,int fa)
{
	for(pair<int,int> edge:e[x]) if(edge.first!=fa)
		val[edge.second]=last=5-last,dfs(edge.first,x);
}
inline int find()
{
	int ret;
	for(int i=1;i<=n;++i)
	{
		if(d[i]>2) return -1;
		if(d[i]==1) ret=i;
	}
	return ret;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i) d[i]=0,e[i].clear();
		for(int i=1,u,v;i<n;++i)
		{
			scanf("%d %d",&u,&v);
			e[u].push_back({v,i}),++d[u];
			e[v].push_back({u,i}),++d[v];
		}
		if((x=find())==-1) {puts("-1");continue;}
		dfs(x,0);
		for(int i=1;i<n;++i) printf("%d ",val[i]);
		putchar('\n');
	}
	return 0;
}