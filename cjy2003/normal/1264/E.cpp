#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int S=51,T=52;
struct bian{int nxt,to,f,w;}bi[100010];
int n,m,d[51];
bool a[51][51],bj[51][51];
int head[60],num=1;
inline void add(int from,int to,int f,int w){bi[++num]=bian{head[from],to,f,w};head[from]=num;}
inline void ADD(int from,int to,int f,int w){add(from,to,f,w),add(to,from,0,-w);}
int dis[60],fb[60];
bool in[60];
bool spfa()
{
	queue<int>q;
	memset(dis,0x3f,sizeof(dis));
	dis[S]=0,q.push(S);
	int x,y;
	while(!q.empty())
	{
		x=q.front();q.pop();in[x]=0;
		for(int i=head[x];i;i=bi[i].nxt)
			if(bi[i].f)
			{
				y=bi[i].to;
				if(dis[x]+bi[i].w<dis[y])
				{
					dis[y]=dis[x]+bi[i].w;fb[y]=i;
					if(!in[y])q.push(y),in[y]=1;
				}
			}
	}
	return dis[T]<0;
}
int main()
{
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		++d[x];a[x][y]=1,bj[x][y]=bj[y][x]=1;
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(!bj[i][j])ADD(i,j,1,0),++d[j];
	for(int i=1;i<=n;++i)
	{
		for(int j=d[i];j<n;++j)ADD(S,i,1,j-1);
		for(int j=1;j<d[i];++j)ADD(i,T,1,1-j);
	}
	while(spfa())
	{
		int x=T;
		while(x!=S)--bi[fb[x]].f,++bi[fb[x]^1].f,x=bi[fb[x]^1].to;
	}
	for(int i=1;i<=n;++i)
		for(int j=head[i];j;j=bi[j].nxt)
			if(bi[j].to<=n)
			{
				if(bi[j].f)a[bi[j].to][i]=1;
				else a[i][bi[j].to]=1;
			}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)putchar(a[i][j]^48);
		printf("\n");
	}
	return 0;
}