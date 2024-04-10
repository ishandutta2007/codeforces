#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
namespace flow
{
	const int S=0,T=1,inf=0x3f3f3f3f;
	int Flow;
	struct edge
	{
		int nxt,to,f;
	}e[500010];
	int head[100010],num=1,dep[100010],cur[100010],tot=2;
	inline void add(int from,int to,int f){e[++num]=edge{head[from],to,f};head[from]=num;}
	inline void ADD(int from,int to,int f){add(from,to,f),add(to,from,0);}
	bool bfs()
	{
		static int q[100010],h,t;
		memset(dep,0,tot<<2);
		memcpy(cur,head,tot<<2);
		h=0,t=1,q[t]=S,dep[S]=1;
		int x,y;
		while(h<t)
		{
			x=q[++h];
			for(int i=head[x];i;i=e[i].nxt)if(e[i].f&&!dep[y=e[i].to])dep[y]=dep[x]+1,q[++t]=y;
		}
		return dep[T]!=0;
	}
	int dfs(int v,int last)
	{
		if(v==T)
		{
			Flow+=last;
			return last;
		}
		int now=0;
		for(int &i=cur[v],u;i;i=e[i].nxt)
			if(e[i].f&&dep[u=e[i].to]==dep[v]+1)
			{
				int dmin=dfs(u,min(last,e[i].f));
				e[i].f-=dmin,e[i^1].f+=dmin;
				last-=dmin,now+=dmin;
				if(!last)break;
			}
		return now;
	}
}using namespace flow;
int n,m;
char mp[210][210];
int id[210][210];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",mp[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			id[i][j]=tot++,tot++;
	int cnt=0,cntb=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(mp[i][j]=='#')
			{
				ADD(id[i][j],id[i][j]+1,inf);
				ADD(id[i][j]+1,id[i][j],inf);
				if(mp[i+1][j]=='#')ADD(S,id[i][j],1),ADD(id[i][j],id[i+1][j]+1,1);
				if(mp[i][j+1]=='#')ADD(id[i][j]+1,T,1),ADD(id[i][j+1],id[i][j]+1,1);
				cnt+=mp[i+1][j]=='#';
				cnt+=mp[i][j+1]=='#';
				++cntb;
			}
	// for(int i=0;i<tot;++i)
		// for(int j=head[i];j;j=e[j].nxt)
			// if(e[j].f)printf("%d %d\n",i,e[j].to);
	while(bfs())
		while(dfs(S,0x3f3f3f3f));
	// printf("%d\n",Flow);
	printf("%d\n",cntb-cnt+Flow);
	return 0;
}