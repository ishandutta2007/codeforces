#include<cstdio>
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define MN 200000
int a[MN+5],l[MN+5],r[MN+5],fa[MN+5];
int main()
{
	int n,t,k,i,j,mn=1,mx=1;a[0]=1;
	n=read();t=read();k=read();
	for(i=1;i<=t;++i)
	{
		a[i]=read();
		if(a[i]>a[i-1])mn+=a[i]-a[i-1];
		mx+=a[i]-1;
	}
	if(k<mn||k>mx)return 0*puts("-1");
	l[0]=r[0]=1;k-=mn;
	for(i=1;i<=t;++i)
	{
		for(j=1;j<=a[i];++j)
			fa[r[i-1]+j]=l[i-1]+j-1<r[i-1]?l[i-1]+j-1:r[i-1];
		mx=r[i-1]-l[i-1];if(a[i]-1<mx)mx=a[i]-1;
		if(k>=mx)
		{
			k-=mx;
			for(j=1;j<=a[i];++j)fa[r[i-1]+j]=l[i-1];
		}
		else
		{
			for(j=0;j<k;++j)
				fa[r[i-1]+j+2]=l[i-1];
			k=0;
		}
		l[i]=r[i-1]+1;r[i]=r[i-1]+a[i];
	}
	printf("%d\n",n);
	for(i=2;i<=n;++i)printf("%d %d\n",fa[i],i);
}