#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
struct edge{int nx,t;}e[MN*2+5];
int n,h[MN+5],en=1,s[MN+5],w[MN+5],z[MN+5];
long long ans;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void dfs(int x,int fa)
{
	s[x]=1;
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
		dfs(e[i].t,x),s[x]+=z[i>>1]=s[e[i].t],ans+=1LL*z[i>>1]*(n-z[i>>1])*w[i>>1];
}
int main()
{
	int i,x,y;
	for(n=read(),i=1;i<n;++i)ins(read(),read()),w[i]=read();
	dfs(1,0);
	for(i=read();i--;)x=read(),y=read(),ans-=1LL*z[x]*(n-z[x])*(w[x]-y),w[x]=y,
		printf("%.10lf\n",6.*ans/n/(n-1));
}