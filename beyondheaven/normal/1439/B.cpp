#include<bits/stdc++.h>
#define MaxN 100123

int n,m,k;
std::unordered_set<int>G[MaxN];
int deg[MaxN];

inline bool CheckClique(int x)
{
	std::vector<int>V({x});
	for(int y:G[x])V.emplace_back(y);
	
	for(int u:V)
	for(int v:V)
	if(u<v&&(!G[u].count(v)))return false;
	return true;
}

inline void Solve()
{
	for(int i=1;i<=n;++i)G[i].clear();
	memset(deg,0,sizeof(deg));
	
	scanf("%d%d%d",&n,&m,&k);
	
	std::vector<std::pair<int,int>>input;
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		input.emplace_back(std::make_pair(u,v));
	}
	
	if((1LL*k*(k-1)/2)>m)return puts("-1"),void();
	
	for(auto&p:input)
	{
		G[p.first].insert(p.second);
		G[p.second].insert(p.first);
		++deg[p.first];
		++deg[p.second];
	}
	
	int cnt=0;
	std::queue<int>q;
	for(int i=1;i<=n;++i)
	if(deg[i]<k)
	{
		if(deg[i]==k-1&&CheckClique(i))
		{
			puts("2");
			for(int x:G[i])
			printf("%d ",x);
			printf("%d\n",i);
			return;
		}
		q.push(i);
		++cnt;
	}
	
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:G[u])
		{
			G[v].erase(u);
			if((--deg[v])==k-1)
			{
				if(CheckClique(v))
				{
					puts("2");
					for(int x:G[v])
					printf("%d ",x);
					printf("%d\n",v);
					return;
				}
				q.push(v);
				++cnt;
			}
		}
	}
	
	if(cnt<n)
	{
		std::vector<int>ans;
		for(int i=1;i<=n;++i)
		if(deg[i]>=k)ans.emplace_back(i);
		
		printf("1\n%d\n",static_cast<int>(ans.size()));
		for(int i:ans)
		printf("%d ",i);
		puts("");
	}
	else puts("-1");
}

int main()
{
	int T;scanf("%d",&T);
	while(T--)Solve();
	return 0;
}