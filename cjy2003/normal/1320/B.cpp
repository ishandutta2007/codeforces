#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct bian
{
	int nxt,to;
}bi[400040];
int n,m,k,p[200020],head[200020],num,dis[200020],f[200020];
int ans1,ans2;
inline void add(int from,int to)
{
	bi[++num]=bian{head[from],to};
	head[from]=num;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		add(y,x);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;++i)scanf("%d",&p[i]);
	queue<int>q;
	q.push(p[k]);dis[p[k]]=1;
	int x,y;
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(int i=head[x];i;i=bi[i].nxt)
		{
			y=bi[i].to;
			if(!dis[y])dis[y]=dis[x]+1,f[y]=x,q.push(y);
			else if(dis[x]+1==dis[y])f[y]=0;
		}
	}
	for(int i=1;i<k;++i)
	{
		if(dis[p[i]]!=dis[p[i+1]]+1)++ans1,++ans2;
		else if(!f[p[i]])++ans2;
	}
	printf("%d %d",ans1,ans2);
	return 0;
}