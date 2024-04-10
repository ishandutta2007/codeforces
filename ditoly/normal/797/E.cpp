#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
#define MK 350
int a[MN+5],f[MK+5][MN+5];
int main()
{
	int n=read(),q,i,k,ans;
	for(i=1;i<=n;++i)a[i]=read();
	for(k=1;k<=MK;++k)for(i=n;i;--i)f[k][i]=i+a[i]+k>n?1:f[k][i+a[i]+k]+1;
	for(q=read();q--;)
	{
		i=read();k=read();
		if(k<=MK)printf("%d\n",f[k][i]);
		else{for(ans=0;i<=n;i+=a[i]+k)++ans;printf("%d\n",ans);}
	}
}