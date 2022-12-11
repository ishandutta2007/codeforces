#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct bian
{
	int to,nxt;
}bi[400040];
vector<int>d[200020];
queue<int>q;
int n,w,x,y,head[200020],num,ans=1,p;
int vis[200020],jl,dis1[200020],dis2[200020];
bool bj[200020],bj1[200020],flag;
inline void add(int from,int to)
{
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
}
void bfs(int v)
{
	q.push(v);
	bj[v]=1;
	p=v;
	dis1[v]=1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(int i=head[x];i;i=bi[i].nxt)
		{
			y=bi[i].to;
			if(vis[y]!=jl||bj[y])continue;
			bj[y]=1;
			dis1[y]=dis1[x]+1;
			q.push(y);
			if(dis1[y]>dis1[p])p=y;
		}
	}
	dis2[p]=1;
	q.push(p);
	bj1[p]=1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(int i=head[x];i;i=bi[i].nxt)
		{
			y=bi[i].to;
			if(vis[y]!=jl||bj1[y])continue;
			bj1[y]=1;
			dis2[y]=dis2[x]+1;
			q.push(y);
			if(dis2[y]>ans)ans=dis2[y];
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&w);
		flag|=w!=1;
		x=w;
		for(int j=2;j*j<=w;++j)
			if(x%j==0)
			{
				d[j].push_back(i);
				while(x%j==0)x/=j;
			}
		if(x>1)d[x].push_back(i);
	}
	if(!flag)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=2;i<=200000;++i)
		if(d[i].size())
		{
			w=d[i].size();
		//	for(int j=0;j<w;++j)
		//		printf("%d ",d[i][j]);
		//	printf("\n");
			++jl;
			for(int j=0;j<w;++j)
			{
				vis[d[i][j]]=jl;
				bj[d[i][j]]=0;
				bj1[d[i][j]]=0;
				dis1[d[i][j]]=dis2[d[i][j]]=0;
			}
			for(int j=0;j<w;++j)
				if(!bj[d[i][j]])
					bfs(d[i][j]);
		}
	printf("%d",ans);
	return 0;
}