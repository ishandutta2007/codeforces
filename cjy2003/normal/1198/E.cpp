#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int S=0,T=1,inf=0x3f3f3f3f;
struct bian
{
	int to,nxt,f;
}bi[100010];
int n,m,ans;
int lx[110],ly[110],cntx,cnty,p[51][4];
int head[210],num=1,dep[210];
bool mp[110][110];
inline void add(int from,int to,int f)
{
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
	bi[num].f=f;
}
inline void ADD(int from,int to,int f)
{
	add(from,to,f);
	add(to,from,0);
}
queue<int>q;
bool bfs()
{
	memset(dep,0,sizeof(dep));
	dep[S]=1;q.push(S);
	int x,y;
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(int i=head[x];i;i=bi[i].nxt)
			if(bi[i].f)
			{
				y=bi[i].to;
				if(!dep[y])
				{
					dep[y]=dep[x]+1;
					q.push(y);
				}
			}
	}
	return dep[T]!=0;
}
int dfs(int v,int last)
{
	if(v==T)
	{
		ans+=last;
		return last;
	}
	int now=0,u;
	for(int i=head[v];i;i=bi[i].nxt)
		if(bi[i].f)
		{
			u=bi[i].to;
			if(dep[u]!=dep[v]+1)continue;
			int dmin=dfs(u,min(last,bi[i].f));
			last-=dmin,now+=dmin;
			bi[i].f-=dmin,bi[i^1].f+=dmin;
			if(!last)break;
		}
	return now;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d %d",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
		lx[++cntx]=p[i][0]-1;lx[++cntx]=p[i][2];
		ly[++cnty]=p[i][1]-1;ly[++cnty]=p[i][3];
	}
	sort(lx+1,lx+1+cntx);
	sort(ly+1,ly+1+cnty);
	cntx=unique(lx+1,lx+1+cntx)-lx-1;
	cnty=unique(ly+1,ly+1+cnty)-ly-1;
	for(int i=1;i<=cntx;++i)ADD(S,i+1,lx[i]-lx[i-1]);
	for(int i=1;i<=cnty;++i)ADD(i+cntx+1,T,ly[i]-ly[i-1]);
	for(int i=1;i<=m;++i)
	{
		p[i][0]=lower_bound(lx+1,lx+1+cntx,p[i][0]-1)-lx+1;
		p[i][1]=lower_bound(ly+1,ly+1+cnty,p[i][1]-1)-ly+1;
		p[i][2]=lower_bound(lx+1,lx+1+cntx,p[i][2])-lx;
		p[i][3]=lower_bound(ly+1,ly+1+cnty,p[i][3])-ly;
		for(int j=p[i][0];j<=p[i][2];++j)
			for(int k=p[i][1];k<=p[i][3];++k)
				if(!mp[j][k])
				{
					ADD(j+1,k+1+cntx,inf);
					mp[j][k]=1;
				}
	}
	while(bfs())
		while(dfs(S,inf));
	printf("%d",ans);
	return 0;
}