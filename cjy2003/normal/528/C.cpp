#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian{int nxt,to;}bi[1000010];
int n,m,head[100010],num,d[100010],p[100010][2],tot,all;
bool used[500050],vis[100010];
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
inline void ADD(int x,int y){/*printf("ad %d %d\n",x,y);*/add(x,y),add(y,x);}
void work(int x)
{
	static int q[100010],h,t;
	h=0,t=1,q[1]=x,vis[x]=1;
	int y,cnt=0;
	while(h<t)
	{
		x=q[++h];
		for(int i=head[x];i;i=bi[i].nxt)
		{
			y=bi[i].to;++d[y];++cnt;
			if(!vis[y])vis[y]=1,q[++t]=y;
		}
	}
	cnt/=2;
	static int st[100010],tp;
	tp=0;
//	printf("x%d\n",x);
//	for(int i=1;i<=n;++i)printf("%d ",d[i]);printf("\n");
	for(int i=1;i<=t;++i)if(d[q[i]]&1)st[++tp]=q[i];
	if(!tp)
	{
		if(cnt&1)ADD(q[1],q[1]);
	}
	else
	{
		all+=cnt;
		for(int i=2;i<tp;i+=2)ADD(st[i],st[i+1]),++all;
		p[++tot][0]=st[1],p[tot][1]=st[tp];
	}
}
int st[500050],tp;
void dfs(int v)
{
	vis[v]=1;
	for(int &i=head[v];i;i=bi[i].nxt)
		if(!used[(i+1)/2])
		{
			used[(i+1)/2]=1;
			dfs(bi[i].to);
		}
	st[++tp]=v;
}
void solve(int x)
{
	tp=0;
	dfs(x);
	st[0]=st[tp-1];
	for(int i=1;i<tp;i+=2)printf("%d %d\n%d %d\n",st[i-1],st[i],st[i+1],st[i]);
}
int main()
{
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		ADD(x,y);
	}
	for(int i=1;i<=n;++i)if(!vis[i])work(i);
	p[tot+1][0]=p[1][0];
	for(int i=1;i<=tot;++i)ADD(p[i][1],p[i+1][0]),++all;
	if(all&1)ADD(p[1][0],p[1][0]);
	memset(vis+1,0,n);
	printf("%d\n",num/2);
	for(int i=1;i<=n;++i)if(!vis[i])solve(i);
	return 0;
}