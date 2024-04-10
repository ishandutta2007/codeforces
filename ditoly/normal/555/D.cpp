#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return f?x:-x;
}
#define MN 200000
int a[MN+5],b[MN+5],c[MN+5];
int main()
{
	int n,m,i,x,y,z,l;
	n=read();m=read();
	for(i=1;i<=n;++i)c[i]=a[i]=read();sort(a+1,a+n+1);
	for(i=1;i<=n;++i)b[c[i]=lower_bound(a+1,a+n+1,c[i])-a]=i;
	while(m--)
	{
		x=c[read()];l=read();
		while(true)
		{
			y=upper_bound(a+1,a+n+1,a[x]+l)-a-1;l-=a[y]-a[x];
			z=lower_bound(a+1,a+n+1,a[y]-l)-a;l-=a[y]-a[z];
			if(y==z)break;
			if(x==z)l%=(a[y]-a[z])*2;
			x=z;
		}
		printf("%d\n",b[y]);
	}
}