#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int n,m,a[500050];
vector<int>E[500050];
set<int>s[500050];
int q[500050],h,t;
bool vis[500050];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,x,y;i<=m;++i)scanf("%d %d",&x,&y),E[x].emplace_back(y),E[y].emplace_back(x);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	h=0,t=0;
	for(int i=1;i<=n;++i)if(a[i]==1)q[++t]=i,vis[i]=1;
	while(h<t)
	{
		int x=q[++h];
		for(auto y:E[x])
		{
			if(a[x]==a[y])
			{
				printf("-1");
				exit(0);
			}
			if(a[x]<a[y])
			{
				s[y].insert(a[x]);
				if(s[y].size()==a[y]-1&&!vis[y])q[++t]=y,vis[y]=1;
			}
		}
	}
	if(t!=n)
	{
		printf("-1");
		exit(0);
	}
	for(int i=1;i<=n;++i)printf("%d ",q[i]);
	return 0;
}