#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en,d[MN+5],X,Y,q[MN+5],qn,u[MN+5],ax[MN+5],ay[MN+5],cnt;
long long ans;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void dfs(int x,int fa)
{
	if((d[x]=d[fa]+1)>d[X])X=x;
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)dfs(e[i].t,x);
}
bool get(int x,int fa)
{
	if(x==Y)return u[q[++qn]=x]=1;
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
		if(get(e[i].t,x))return u[q[++qn]=x]=1;
	return 0;
}
void solve(int x,int fa,int to)
{
	if(!u[x])d[x]=d[fa]+1;
	for(int i=h[x];i;i=e[i].nx)
		if(e[i].t!=fa&&!u[e[i].t])solve(e[i].t,x,to);
	if(!u[x])ans+=d[x],ax[++cnt]=x,ay[cnt]=to;
}
int main()
{
	int n=read(),i;
	for(i=1;i<n;++i)ins(read(),read());
	dfs(1,0);Y=X;X=0;dfs(Y,0);get(X,0);
	for(i=1;i<=qn/2;++i)d[q[i]]=qn-i,solve(q[i],0,q[qn]);
	for(;i<=qn;++i)d[q[i]]=i-1,solve(q[i],0,q[1]);
	for(i=1;i<qn;++i)ans+=qn-i,ax[++cnt]=q[i],ay[cnt]=q[qn];
	printf("%lld\n",ans);
	for(i=1;i<n;++i)printf("%d %d %d\n",ax[i],ay[i],ax[i]);
}