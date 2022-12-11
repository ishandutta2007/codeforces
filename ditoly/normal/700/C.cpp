#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 1000
#define MM 60000
struct edge{int nx,t,w;}e[MM+5];
int h[MN+5],en=1,s,t,o[MN+5],u[MM+5],ans=2e9+1,ax,ay,d[MN+5],l[MN+5],cnt;
inline void ins(int x,int y,int w)
{
	e[++en]=(edge){h[x],y,w};h[x]=en;
	e[++en]=(edge){h[y],x,w};h[y]=en;
}
void tj(int x,int fa,int k)
{
	d[x]=l[x]=++cnt;
	for(int i=h[x];i;i=e[i].nx)if(!u[i]&&i!=fa)
	{
		if(d[e[i].t])l[x]=min(l[x],d[e[i].t]);
		else
		{
			tj(e[i].t,i^1,k),l[x]=min(l[x],l[e[i].t]);
			if(l[e[i].t]>d[x]&&d[t]&&d[t]>=d[e[i].t])
				if(e[i].w+e[k].w<ans)ans=e[i].w+e[k].w,ax=i>>1,ay=k>>1;
		}
	}
}
bool dfs(int x)
{
	int i,O=x==t;o[x]=1;
	for(i=h[x];i;i=e[i].nx)if(!o[e[i].t]&&dfs(e[i].t))
	{
		u[i]=u[i^1]=O=1;
		memset(d,cnt=0,sizeof(d));
		tj(s,0,i);
		if(!d[t]&&e[i].w<ans)ans=e[i].w,ax=i>>1,ay=0;
		u[i]=u[i^1]=0;
	}
	return O;
}
int main()
{
	int n,m,i,x,y;
	n=read();m=read();s=read();t=read();
	for(i=1;i<=m;++i)x=read(),y=read(),ins(x,y,read());
	if(!dfs(s))return 0*puts("0\n0");
	if(ans>2e9)return 0*puts("-1");
	printf("%d\n",ans);
	if(ay)printf("2\n%d %d",ax,ay);else printf("1\n%d",ax);
}