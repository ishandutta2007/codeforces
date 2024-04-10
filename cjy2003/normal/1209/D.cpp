#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
queue<int>q;
vector<int>E[200020];
int n,k,ans,x[100010],y[100010];
bool vis[100010],used[200020];
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;++i)
	{
		scanf("%d %d",&x[i],&y[i]);
		E[x[i]].push_back(i);
		E[y[i]].push_back(i);
	}
	for(int i=1;i<=k;++i)
	{
		if(vis[i])continue;
		for(auto p:E[x[i]])
			if(!vis[p])vis[p]=1,q.push(p);
		for(auto p:E[y[i]])
			if(!vis[p])vis[p]=1,q.push(p);
		int p;
		while(!q.empty())
		{
			p=q.front();q.pop();
			if(used[x[p]]&&used[y[p]])
			{
				++ans;
				continue;
			}
			if(!used[x[p]])
				for(auto a:E[x[p]])
					if(!vis[a])vis[a]=1,q.push(a);
			if(!used[y[p]])
				for(auto a:E[y[p]])
					if(!vis[a])vis[a]=1,q.push(a);
			used[x[p]]=used[y[p]]=1;
		}
	}
	printf("%d",ans);
	return 0;
}