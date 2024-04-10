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
#define MN 50
#define MX 5000
typedef long double ld;
int f[MN+5],s[MN+5];
ld p[MN+5],F[MN+5][MX+5];
int main()
{
	int n,m,t,i,j;ld l,r,mid,ans;
	n=read();m=read();
	for(i=1;i<=n;++i)f[i]=read(),s[i]=read(),p[i]=(ld)read()/100;
	for(l=0,r=1e18,t=1;t<=100;++t)
	{
		mid=(l+r)/2;
		for(j=m+1;j<=MX;++j)F[n+1][j]=1e200;
		for(i=n;i;--i)for(j=0;j<=(i-1)*100;++j)
			F[i][j]=p[i]*(f[i]+F[i+1][j+f[i]])+(1-p[i])*(s[i]+min(F[i+1][j+s[i]],mid));
		if(mid<F[1][0])l=mid;else r=mid;
	}
	printf("%.10lf",(double)(l+r)/2);
}