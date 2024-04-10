#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
int a[MN+5],f[MN+5];
bool check(int x,int y,int xx,int yy,int l,int r)
{
	int ax,ay,i,j,k;
	for(ax=1;ax*x<xx;++ax);
	for(ay=1;ay*y<yy;++ay);
	memset(f,0,sizeof(f));f[1]=1;
	for(i=l;i<=r;++i)
		for(j=ax;j;--j)
		{
			k=min(1LL*j*a[i],1LL*ax);
			f[k]=max(f[k],f[j]);
			k=min(1LL*f[j]*a[i],1LL*ay);
			f[j]=max(f[j],k);
		}
	return f[ax]>=ay;
}
int main()
{
	int xx,yy,x,y,n,l,i;
	xx=read();yy=read();x=read();y=read();n=read();
	for(i=1;i<=n;++i)a[i]=read(); 
	sort(a+1,a+n+1);
	for(l=n+1;l;--l)if(check(x,y,xx,yy,l,n)||check(y,x,xx,yy,l,n))return 0*printf("%d",n-l+1);
	puts("-1");
}