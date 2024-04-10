#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MOD=998244353;
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
#define MN 30
struct pol{int n;mint x[MN+5];pol(){n=0;memset(x,0,sizeof(x));}};
struct ff{int n,p[MN*MN+5];pol f[MN*MN+5];ff(){n=0;memset(p,0,sizeof(p));};}F;
mint C[MN+5][MN+5];
void tr(pol&x)
{
	for(int i=0;i<=x.n;++i)for(int j=i;++j<=x.n;)
		x.x[i]+=((j-i)&1?MOD-1:1)*x.x[j]*C[j][i];
}
ff tr(ff x)
{
	for(int i=1;i<=x.n;++i)x.p[i]+=1e6,tr(x.f[i]);
	return x;
}
pol operator-(pol a,pol b)
{
	pol c;c.n=max(a.n,b.n);
	for(int i=0;i<=c.n;++i)c.x[i]=a.x[i]-b.x[i];
	return c;
}
ff operator-(ff a,ff b)
{
	ff c;int i=1,j=1;
	while(i<=a.n||j<=b.n)
	{
		int x=i<=a.n?a.p[i]:1e9,y=j<=b.n?b.p[j]:1e9;
		c.f[c.n++]=a.f[i-1]-b.f[j-1];c.p[c.n]=min(x,y);
		if(x<=y)++i;if(y<=x)++j;
	}
	return c;
}
void sm(pol&x)
{
	for(int i=++x.n;i;--i)x.x[i]=x.x[i-1]/i;x.x[0]=0;
}
mint cal(pol&p,mint x)
{
	mint res=0,z=1;
	for(int i=0;i<=p.n;++i)res+=z*p.x[i],z*=x;
	return res;
}
void sm(ff&x,int d)
{
	mint s=0;
	while(x.p[x.n]>=d)x.f[x.n--]=pol();
	x.p[++x.n]=d;
	for(int i=1;i<=x.n;++i)
	{
		sm(x.f[i]);x.f[i].x[0]=s-=cal(x.f[i],x.p[i]/mint(1e6));
		if(i<x.n)s=cal(x.f[i],x.p[i+1]/mint(1e6));
	}
}
int main()
{
	int n,i,j;double r;
	scanf("%d",&n);
	for(i=0;i<=n;++i)for(C[i][0]=j=1;j<=i;++j)C[i][j]=C[i-1][j]+C[i-1][j-1];
	F.f[1].x[0]=F.n=1;
	for(i=1;i<=n;++i)scanf("%lf",&r),sm(F=F-tr(F),int(r*1e6+0.5));
	printf("%d",F.f[F.n].x[0]);
}