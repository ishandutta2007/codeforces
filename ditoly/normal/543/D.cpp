#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
const int MOD=1e9+7;
struct mint{int x;mint(int x=0):x(x){}};
inline mint operator+  (mint a,mint b){return a.x+b.x<MOD?a.x+b.x:a.x+b.x-MOD;}
inline mint operator-  (mint a){return MOD-a.x;}
inline mint operator-  (mint a,mint b){return a+-b;}
inline mint operator*  (mint a,mint b){return 1LL*a.x*b.x%MOD;}
inline mint operator<< (mint x,int y){mint r=1;for(;y;y>>=1,x=x*x)if(y&1)r=r*x;return r;}
inline mint operator~  (mint x){return x<<MOD-2;}
inline mint operator/  (mint a,mint b){return a*~b;}
inline mint&operator+= (mint&a,mint b){return a=a+b;}
inline mint&operator-= (mint&a,mint b){return a=a-b;}
inline mint&operator*= (mint&a,mint b){return a=a*b;}
inline mint&operator<<=(mint&x,int y){return x=x<<y;}
inline mint&operator/= (mint&a,mint b){return a=a/b;}
#define MN 200000
struct edge{int nx,t;}e[MN*2+5];
struct data
{
	mint f;int c;
	inline mint x(){return c?0:f;}
	inline void operator*=(mint x){x.x?f*=x:++c;}
	inline void operator/=(mint x){x.x?f/=x:--c;}
}f[MN+5];
int h[MN+5],en;mint ans[MN+5];
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void dp(int x,int fa)
{
	f[x].f=1;
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
		dp(e[i].t,x),f[x]*=f[e[i].t].x()+1;
}
void solve(int x,int fa)
{
	ans[x]=f[x].x();
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
	{
		f[x]/=f[e[i].t].x()+1;
		f[e[i].t]*=f[x].x()+1;
		solve(e[i].t,x);
		f[e[i].t]/=f[x].x()+1;
		f[x]*=f[e[i].t].x()+1;
	}
}
int main()
{
	int n=read(),i;
	for(i=2;i<=n;++i)ins(read(),i);
	dp(1,0);solve(1,0);
	for(i=1;i<=n;++i)printf("%d ",ans[i]);
}