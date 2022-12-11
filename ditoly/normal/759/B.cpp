#include<cstdio>
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define MN 100000
#define INF 0x7fffffff
int a[MN+5],f[MN+5];
int main()
{
	int n=read(),i,l,r,mid,t;
	a[0]=-INF;
	for(i=1;i<=n;++i)
	{
		a[i]=read();f[i]=f[i-1]+20;
		for(l=0,r=i-1;l<=r;)
		{
			mid=l+r>>1;
			if(a[mid]<=a[i]-90)t=mid,l=mid+1;
			else r=mid-1;
		}
		if(f[t]+50<f[i])f[i]=f[t]+50;
		for(l=0,r=i-1;l<=r;)
		{
			mid=l+r>>1;
			if(a[mid]<=a[i]-1440)t=mid,l=mid+1;
			else r=mid-1;
		}
		if(f[t]+120<f[i])f[i]=f[t]+120;
		printf("%d\n",f[i]-f[i-1]);
	}
}