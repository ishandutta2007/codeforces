#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
struct Edge{
	int from,to,w;
}edge[maxn];
vector<int> G[maxn];
vector<int> ans;
int topo[maxn];
int ind[maxn];
int n,m;
vector<int> e;
bool check(int cur)
{
	e.clear();
	memset(topo,0,sizeof(topo));
	int tot=0;
	memset(ind,0,sizeof(ind));
	for(int i=0;i<=n;i++)
		G[i].clear();
	for(int i=0;i<m;i++)
	{
		if(edge[i].w<=cur) continue;
		G[edge[i].from].push_back(edge[i].to);
		ind[edge[i].to]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++) if(ind[i]==0) q.push(i);
	while(!q.empty())
	{
		int cur=q.front();q.pop();
		topo[cur]=++tot;
		for(int i=0;i<G[cur].size();i++)
		{
			int v=G[cur][i];
			ind[v]--;
			if(ind[v]==0) q.push(v);
		}
	}
	for(int i=0;i<m;i++)
	{
		auto ed=edge[i];
		if(ed.w<=cur)
		{
			if(topo[ed.to]<topo[ed.from]) e.push_back(i);
		}
		else{
			if(topo[ed.to]<topo[ed.from]||topo[ed.to]==0||topo[ed.from]==0) return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0,u,v,w;i<m;i++)
		scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].w);
	int l=0,r=1e9+1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid,ans=e;
		else l=mid+1;
	}
	printf("%d %d\n",r,(int)ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]+1);
}