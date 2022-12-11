#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cassert>
using namespace std;
struct bian
{
	int nxt,to,id;
}bi[2020],bi1[6060];
int n,m,k,w[110],c[1010],b[1010][2],head[110],num,cnt[1010],head1[110],num1,d[110];
bool vis[110],used[3030];
int st[3030],tp;
inline void add(int from,int to)
{
	bi[++num]=bian{head[from],to};
	head[from]=num;
}
inline void add1(int from,int to,int id)
{
	bi1[++num1]=bian{head1[from],to,id};
	head1[from]=num1;++d[to];
//	printf("%d %d\n",from,to);
}
void dfs(int v)
{
	vis[v]=1;
	for(int i=head1[v],u;i;i=bi1[i].nxt)
	{
		u=bi1[i].to;
		if(!vis[u])dfs(u);
	}
}
void dfs1(int v,int fb)
{
//	printf("%d ",v);
	for(int &i=head1[v],u;i;i=bi1[i].nxt)
		if(!used[(i+1)/2])
		{
			used[(i+1)/2]=1;
		//	if(v==74||bi1[i].to==74)printf("%d %d %d\n",v,bi1[i].to,c1);
			u=bi1[i].to;
			dfs1(u,bi1[i].id);
		}
	st[++tp]=fb;
}
void recolor(int c1,int c2)
{
//	printf("%d %d\n",c1,c2);
	memset(head1,0,n+1<<2);num1=0;
	memset(d,0,n+1<<2);
	memset(vis,0,n+1);
	for(int i=1;i<=m;++i)if(c[i]==c1||c[i]==c2)add1(b[i][0],b[i][1],i),add1(b[i][1],b[i][0],i);
	for(int i=1;i<=n;++i)
		if(d[i]&1)
		{
			add1(0,i,0);add1(i,0,0);
//			printf("%d ",i);
			if(!vis[i])dfs(i);
		}
//	printf("\n");
	for(int i=1;i<=n;++i)
		if(!vis[i])
		{
			dfs(i);
//			printf("%d ",i);
			add1(0,i,0),add1(i,0,0);
			add1(0,i,0),add1(i,0,0);
		}
//	printf("\n");
	memset(used+1,0,num1/2);
	dfs1(0,0);
	while(tp)c[st[tp]]=tp&1?c1:c2,--tp;
	for(int i=1;i<=num1/2;++i)assert(used[i]);
}
int main()
{
	srand(time(0)+(unsigned long long)(new char));
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
		c[i]=rand()%k+1;
		b[i][0]=x,b[i][1]=y;
	}
	while(1)
	{
	//	printf("!\n");
		bool ok=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=head[i];j;j=bi[j].nxt)++cnt[c[(j+1)/2]];
			int mi=1,mx=1,cmx,cmi;
			for(int j=2;j<=k;++j)
			{
				if(cnt[j]>cnt[mx])mx=j;
				if(cnt[j]<cnt[mi])mi=j;
			}
			cmx=cnt[mx],cmi=cnt[mi];
			for(int j=head[i];j;j=bi[j].nxt)--cnt[c[(j+1)/2]];
			if(cmx-cmi>2)ok=0,recolor(mi,mx);
		}
		if(ok)break;
	}
	for(int i=1;i<=m;++i)printf("%d\n",c[i]);
	return 0;
}