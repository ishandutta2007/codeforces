#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
struct Edge{
	int to;
	long long w;
	int num;
	bool operator <(const Edge& a)const
	{
		return w>a.w;
	}
};
vector<Edge> G[maxn];
bool vis[maxn];
int main()
{
	int n,m,k;
	memset(vis,0,sizeof(vis));
	scanf("%d%d%d",&n,&m,&k);
	long long w;
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d%lld",&u,&v,&w);
		G[u].push_back(Edge {v,w,i});
		G[v].push_back(Edge {u,w,i});
	}
	priority_queue<Edge> q;
	int cnt=0;
	int now=1;
	vis[now]=1;
	vector<int> ans;
	long long weigh=0;
	while(cnt<k)
	{
		for(int i=0;i<G[now].size();i++)
		{
			Edge& v=G[now][i];
			if(!vis[v.to])
			{
				q.push(Edge {v.to,v.w+weigh,v.num});
			}
		}
		if(cnt&&q.empty()) break;
		Edge temp=q.top();q.pop();
		while(!q.empty()&&vis[temp.to])
		{
			temp=q.top();q.pop();
		}
		if(q.empty()&&vis[temp.to]) break;
		vis[temp.to]=1;
		now=temp.to;
		weigh=temp.w;
		ans.push_back(temp.num);
		cnt++;
	}
	printf("%d\n",cnt);
	for(int i=0;i<ans.size();i++)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;

}