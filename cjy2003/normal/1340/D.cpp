#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int nxt,to;
}bi[200020];
int n,head[100010],num,d[100010],cnt;
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
void dfs(int v,int fa,int in)
{
	printf("%d %d\n",v,in);
	int lim=max(in,d[v]),cur=in;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		if(cur==lim)cur=lim-d[v],printf("%d %d\n",v,cur);
		dfs(u,v,cur+1);++cur;
		printf("%d %d\n",v,cur);
	}
	if(cur==lim&&v!=1)cur=lim-d[v],printf("%d %d\n",v,cur);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);++d[x],++d[y];
	}
	printf("%d\n",n+2*(n-1));
	dfs(1,0,0);
	return 0;
}