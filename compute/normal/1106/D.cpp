#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
vector<int> G[maxn];
bool vis[maxn];
int main()
{
	int n,m;
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	priority_queue<int,vector<int>,greater<int> >  q;
	vector<int> ans;
	q.push(1);
	while(!q.empty())
	{
		int cur=q.top();q.pop();
		if(vis[cur]) continue;
		ans.push_back(cur);
		vis[cur]=1;
		for(int i=0;i<G[cur].size();i++)
		{
			int v=G[cur][i];
			if(!vis[v]) q.push(v);
		}
	}
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	puts("");
}