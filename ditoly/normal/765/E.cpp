#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 200000
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en,d[MN+5],d1[MN+5],d2[MN+5],c[MN+5],g;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void cal(int x,int d)
{
	if(!d1[x])d1[x]=d;else if(d1[x]!=d)
	if(!d2[x])d2[x]=d;else if(d2[x]!=d)g=1;
}
void pre(int x,int f)
{
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=f)
	{
		pre(e[i].t,x);
		if(d[e[i].t]>=d[x])c[x]=d[x],d[x]=d[e[i].t];
		else if(d[e[i].t]>c[x])c[x]=d[e[i].t];
		cal(x,d[e[i].t]);
	}
	++d[x];++c[x];
}
void dfs(int x,int f,int fd)
{
	if(f)cal(x,fd);
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=f)
		dfs(e[i].t,x,max(fd+1,d[x]==d[e[i].t]+1?c[x]:d[x]));
}
int main()
{
	int n=read(),i,ans;
	for(i=1;i<n;++i)ins(read(),read());
	pre(1,0);dfs(1,0,0);
	if(g)return 0*puts("-1");
	for(ans=d1[1]+d2[1],i=2;i<=n;++i)ans=min(ans,d1[i]+d2[i]);
	while(ans%2==0)ans/=2;
	printf("%d",ans);
}