#include<cstdio>
#include<algorithm>
using namespace std;
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
#define MN 2000
#define MX 200000
struct P{int x,y;}p[MN+5];
bool cmp(const P&a,const P&b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
mint f[MX+5],r[MX+5],v[MN+5];
inline mint F(int n,int m){return f[n+m]*r[n]*r[m];}
int main()
{
	int h,w,n,i,j;
	for(f[0]=i=1;i<=MX;++i)f[i]=f[i-1]*i;
	for(r[i=MX]=~f[MX];i--;)r[i]=r[i+1]*(i+1);
	h=read();w=read();n=read();
	for(i=1;i<=n;++i)p[i].x=read(),p[i].y=read();
	sort(p+1,p+n+1,cmp);
	p[0]=(P){1,1};p[++n]=(P){h,w};
	for(v[0]=MOD-1,i=1;i<=n;++i)for(j=0;j<i;++j)
		if(p[j].x<=p[i].x&&p[j].y<=p[i].y)v[i]-=v[j]*F(p[i].x-p[j].x,p[i].y-p[j].y);
	printf("%d",v[n]);
}